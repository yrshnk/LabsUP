#include "mainwindow.h"
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QObject *parent)
    : QObject(parent)
{
    loadCars();
    applySearchFilter();
}

MainWindow::~MainWindow()
{
    saveCars();
}

void MainWindow::loadCars()
{
    QFile file("cars.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        carList.clear();
        return;
    }

    carList.clear();
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split(';');
        if (parts.size() >= 4) {
            QString model = parts[0];
            bool okSpeed = false, okPrice = false;
            int speedInt = parts[1].toInt(&okSpeed);
            double price = parts[2].toDouble(&okPrice);
            QString imagePath = parts[3];

            if (okSpeed && okPrice && speedInt >= 0 && speedInt <= 127 && price >= 0.0) {
                carList.append(Car(model, speedInt, price, imagePath));
            }
        }
    }
    file.close();
}

void MainWindow::saveCars()
{
    QFile file("cars.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        return;
    }

    QTextStream out(&file);
    for (const Car &car : qAsConst(carList)) {
        out << car.model << ';'
            << QString::number(car.speed) << ';'
            << QString::number(car.price, 'f', 2) << ';'
            << car.imagePath << '\n';
    }
    file.close();
}

void MainWindow::applySearchFilter()
{
    filteredIndexes.clear();

    for (int i = 0; i < carList.size(); ++i) {
        filteredIndexes.append(i);
    }
}

bool MainWindow::validateCarData(const QString &model, int speed, double price)
{
    if (model.trimmed().isEmpty())
        return false;
    if (speed < 0 || speed > 127)
        return false;
    if (price < 0)
        return false;
    return true;
}

int MainWindow::getRealIndexFromFiltered(int filteredRow) const
{
    if (filteredRow < 0 || filteredRow >= filteredIndexes.size())
        return -1;
    return filteredIndexes[filteredRow];
}
