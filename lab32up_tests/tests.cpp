#include <QtTest>
#include "mainwindow.h"

class MainWindowTests : public QObject
{
    Q_OBJECT

private slots:
    void test_validateCarData_valid();
    void test_validateCarData_invalid();
    void test_loadCars();
    void test_saveCars();
};

void MainWindowTests::test_validateCarData_valid()
{
    MainWindow mw;
    QVERIFY(mw.validateCarData("Ford", 100, 5000.0));
}

void MainWindowTests::test_validateCarData_invalid()
{
    MainWindow mw;
    QVERIFY(!mw.validateCarData("", 100, 5000.0));         // пустой модель
    QVERIFY(!mw.validateCarData("BMW", -5, 5000.0));       // скорость отрицательная
    QVERIFY(!mw.validateCarData("BMW", 130, 5000.0));      // скорость > 127
    QVERIFY(!mw.validateCarData("BMW", 100, -10.0));       // цена отрицательная
}

void MainWindowTests::test_loadCars()
{
    QFile file("cars.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "Tesla;120;50000.0;image1.jpg\n";
        out << "BMW;100;30000.0;image2.jpg\n";
        file.close();
    }

    MainWindow mw;
    mw.loadCars();
    auto &cars = mw.getCarList();

    QCOMPARE(cars.size(), 2);
    QCOMPARE(cars[0].model, QString("Tesla"));
    QCOMPARE(cars[1].model, QString("BMW"));
}

void MainWindowTests::test_saveCars()
{
    MainWindow mw;
    mw.getCarList().append(Car("Audi", 110, 40000.0, "image3.jpg"));
    mw.getCarList().append(Car("Mercedes", 105, 45000.0, "image4.jpg"));

    mw.saveCars();

    QFile file("cars.txt");
    QVERIFY(file.open(QIODevice::ReadOnly | QIODevice::Text));
    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    QVERIFY(content.contains("Audi;110;40000.00;image3.jpg"));
    QVERIFY(content.contains("Mercedes;105;45000.00;image4.jpg"));
}

QTEST_MAIN(MainWindowTests)
#include "tests.moc"
