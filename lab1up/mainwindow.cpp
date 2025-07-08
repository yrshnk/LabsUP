#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    conversionList << "Radians -> Degrees"
                   << "Radians -> Minutes"
                   << "Radians -> Seconds"
                   << "Radians -> Grads"
                   << "Radians -> Mils"
                   << "Degrees -> Radians"
                   << "Minutes -> Radians"
                   << "Seconds -> Radians"
                   << "Grads -> Radians"
                   << "Mils -> Radians";

    ui->comboBox->addItems(conversionList);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::convert);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::showAboutDialog);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::convert() {
    bool ok = false;
    qreal input = ui->inputEdit->toPlainText().toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid number.");
        return;
    }

    QString selected = ui->comboBox->currentText();
    qreal result = 0.0;

    if (selected.startsWith("Radians")) {
        result = fromRadians(input, selected);
    } else {
        result = toRadians(input, selected);
    }

    QString resultStr = QString::number(result, 'f', 6);
    ui->resultLabel->setText("Result: " + resultStr);

    if (ui->checkBox->isChecked()) {
        logResult(selected + ": " + QString::number(input) + " => " + resultStr);
    }
}

qreal MainWindow::toRadians(qreal value, const QString &unit) {
    if (unit.contains("Degrees")) return value * (M_PI / 180.0);
    if (unit.contains("Minutes")) return value * (M_PI / (180.0 * 60.0));
    if (unit.contains("Seconds")) return value * (M_PI / (180.0 * 3600.0));
    if (unit.contains("Grads")) return value * (M_PI / 200.0);
    if (unit.contains("Mils")) return value * (M_PI / 3200.0);
    return 0.0;
}

qreal MainWindow::fromRadians(qreal value, const QString &unit) {
    if (unit.contains("Degrees")) return value * (180.0 / M_PI);
    if (unit.contains("Minutes")) return value * (180.0 * 60.0 / M_PI);
    if (unit.contains("Seconds")) return value * (180.0 * 3600.0 / M_PI);
    if (unit.contains("Grads")) return value * (200.0 / M_PI);
    if (unit.contains("Mils")) return value * (3200.0 / M_PI);
    return 0.0;
}

void MainWindow::logResult(const QString &entry) {
    QFile file("log.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << entry << "\n";
    }
}

void MainWindow::showAboutDialog() {
    QMessageBox::information(this, "About",
                             "Angle Units Converter\n"
                             "Converts between radians and degrees, minutes, seconds, grads, mils.\n"
                             "Uses qreal type and Qt widgets.");
}
