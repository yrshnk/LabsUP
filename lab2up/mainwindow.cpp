#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QPixmap>
#include <QLabel>
#include <QFileDialog>
#include <QCloseEvent>
#include <QMenu>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(4);
    QStringList headers = {"Model", "Speed (km/h)", "Price ($)", "Image"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    loadCars();
    applySearchFilter();

    connect(ui->searchModelLineEdit, &QLineEdit::textChanged, this, &MainWindow::applySearchFilter);
    connect(ui->searchSpeedLineEdit, &QLineEdit::textChanged, this, &MainWindow::applySearchFilter);
    connect(ui->searchPriceLineEdit, &QLineEdit::textChanged, this, &MainWindow::applySearchFilter);
    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &MainWindow::on_tableWidget_cellClicked);
    connect(ui->tableWidget, &QWidget::customContextMenuRequested, this, &MainWindow::showContextMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
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
        QMessageBox::warning(this, "Error", "Could not open cars.txt for writing.");
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

void MainWindow::refreshTable()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(filteredIndexes.size());

    for (int i = 0; i < filteredIndexes.size(); ++i) {
        int realIndex = filteredIndexes[i];
        const Car &car = carList[realIndex];
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(car.model));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(car.speed) + " km/h"));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem("$" + QString::number(car.price, 'f', 2)));

        QLabel *imageLabel = new QLabel;
        QPixmap pixmap(car.imagePath);
        if (!pixmap.isNull()) {
            imageLabel->setPixmap(pixmap.scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            imageLabel->setText("No Image");
            imageLabel->setAlignment(Qt::AlignCenter);
        }
        ui->tableWidget->setCellWidget(i, 3, imageLabel);
    }
    ui->tableWidget->resizeRowsToContents();
}

void MainWindow::applySearchFilter()
{
    QString modelFilter = ui->searchModelLineEdit->text();
    QString speedFilter = ui->searchSpeedLineEdit->text();
    QString priceFilter = ui->searchPriceLineEdit->text();

    filteredIndexes.clear();

    for (int i = 0; i < carList.size(); ++i) {
        const Car &car = carList[i];

        bool modelMatch = car.model.contains(modelFilter, Qt::CaseInsensitive);
        bool speedMatch = QString::number(car.speed).contains(speedFilter);
        bool priceMatch = QString::number(car.price, 'f', 2).contains(priceFilter);

        if (modelMatch && speedMatch && priceMatch) {
            filteredIndexes.append(i);
        }
    }

    refreshTable();
}

int MainWindow::getRealIndexFromFiltered(int filteredRow) const
{
    if (filteredRow < 0 || filteredRow >= filteredIndexes.size())
        return -1;
    return filteredIndexes[filteredRow];
}

void MainWindow::on_addButton_clicked()
{
    carList.append(Car("", 0, 0.0, ""));
    applySearchFilter();

    int newFilteredRow = filteredIndexes.indexOf(carList.size() - 1);
    if (newFilteredRow != -1) {
        ui->tableWidget->selectRow(newFilteredRow);
    }
}

void MainWindow::on_removeButton_clicked()
{
    int filteredRow = ui->tableWidget->currentRow();
    int realIndex = getRealIndexFromFiltered(filteredRow);

    if (realIndex != -1) {
        carList.removeAt(realIndex);
        applySearchFilter();
    } else {
        QMessageBox::information(this, "Remove Car", "Please select a valid car to remove.");
    }
}

void MainWindow::on_updateButton_clicked()
{
    int filteredRow = ui->tableWidget->currentRow();
    int realIndex = getRealIndexFromFiltered(filteredRow);

    if (realIndex == -1)
        return;

    QTableWidgetItem *modelItem = ui->tableWidget->item(filteredRow, 0);
    QTableWidgetItem *speedItem = ui->tableWidget->item(filteredRow, 1);
    QTableWidgetItem *priceItem = ui->tableWidget->item(filteredRow, 2);

    if (!modelItem || !speedItem || !priceItem)
        return;

    QString newModel = modelItem->text();
    QString speedText = speedItem->text().replace(" km/h", "").trimmed();
    QString priceText = priceItem->text().replace("$", "").trimmed();

    bool okSpeed = false, okPrice = false;
    int speedInt = speedText.toInt(&okSpeed);
    double price = priceText.toDouble(&okPrice);

    if (!validateCarData(newModel, speedInt, price)) {
        QMessageBox::warning(this, "Invalid Data", "Please enter valid data:\n"
                                                   "- Model cannot be empty\n"
                                                   "- Speed: 0 to 127\n"
                                                   "- Price must be >= 0");
        return;
    }

    carList[realIndex].model = newModel;
    carList[realIndex].speed = speedInt;
    carList[realIndex].price = price;

    refreshTable();
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

void MainWindow::on_addPhotoButton_clicked()
{
    int filteredRow = ui->tableWidget->currentRow();
    int realIndex = getRealIndexFromFiltered(filteredRow);

    if (realIndex == -1) {
        QMessageBox::information(this, "Select Row", "Please select a car row to add photo.");
        return;
    }

    QString fileName = QFileDialog::getOpenFileName(this, "Select Car Photo", "", "Images (*.png *.jpg *.bmp)");
    if (!fileName.isEmpty()) {
        carList[realIndex].imagePath = fileName;
        refreshTable();
    }
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    if (column == 3 && row >= 0) {
        int realIndex = getRealIndexFromFiltered(row);
        if (realIndex == -1)
            return;

        QString imagePath = carList[realIndex].imagePath;
        if (imagePath.isEmpty()) {
            QMessageBox::information(this, "Image", "No image available for this car.");
            return;
        }

        QPixmap pixmap(imagePath);
        if (pixmap.isNull()) {
            QMessageBox::information(this, "Image", "Failed to load image.");
            return;
        }

        QLabel *imageLabel = new QLabel;
        imageLabel->setPixmap(pixmap.scaled(300, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        imageLabel->setWindowTitle("Car Image");
        imageLabel->setAttribute(Qt::WA_DeleteOnClose);
        imageLabel->show();
    }
}

void MainWindow::showContextMenu(const QPoint &pos)
{
    QModelIndex index = ui->tableWidget->indexAt(pos);
    if (!index.isValid())
        return;

    QMenu menu(this);
    QAction *removeAction = menu.addAction("Remove Car");
    QAction *aboutAction = menu.addAction("About");

    QAction *selectedAction = menu.exec(ui->tableWidget->viewport()->mapToGlobal(pos));

    if (selectedAction == removeAction) {
        int filteredRow = index.row();
        int realIndex = getRealIndexFromFiltered(filteredRow);

        if (realIndex != -1) {
            carList.removeAt(realIndex);
            applySearchFilter();
        }
    } else if (selectedAction == aboutAction) {
        QMessageBox::about(this, "About Application",
                           "This application manages antique cars.\n"
                           "You can add, delete, search, and sort cars.\n"
                           "Created using Qt.");
    }
}


void MainWindow::on_sortModelButton_clicked()
{
    std::sort(carList.begin(), carList.end(), [](const Car &a, const Car &b) {
        return a.model.toLower() < b.model.toLower();
    });
    applySearchFilter();
}

void MainWindow::on_sortSpeedButton_clicked()
{
    std::sort(carList.begin(), carList.end(), [](const Car &a, const Car &b) {
        return a.speed < b.speed;
    });
    applySearchFilter();
}

void MainWindow::on_sortPriceButton_clicked()
{
    std::sort(carList.begin(), carList.end(), [](const Car &a, const Car &b) {
        return a.price < b.price;
    });
    applySearchFilter();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    saveCars();
    event->accept();
}

void MainWindow::on_checkArraySizeButton_clicked()
{
    int size = carList.size();
    QMessageBox::information(this, "Array Size", QString("Current number of cars: %1").arg(size));
}
