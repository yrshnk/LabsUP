#include <QtTest/QtTest>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

class ConverterTest : public QObject {
    Q_OBJECT

private slots:
    void testToRadians();
    void testFromRadians();
    void testInverseConversions();
    void testButtonClickTriggersConversion();
};

void ConverterTest::testToRadians() {
    MainWindow mw(nullptr);
    QCOMPARE(mw.toRadians(180, "Degrees"), M_PI);
    QCOMPARE(mw.toRadians(60, "Minutes"), M_PI / 180.0);
    QCOMPARE(mw.toRadians(3200, "Mils"), M_PI);
}

void ConverterTest::testFromRadians() {
    MainWindow mw(nullptr);
    QCOMPARE(mw.fromRadians(M_PI, "Degrees"), 180.0);
    QCOMPARE(mw.fromRadians(M_PI / 180.0, "Minutes"), 60.0);
    QCOMPARE(mw.fromRadians(M_PI, "Mils"), 3200.0);
}

void ConverterTest::testInverseConversions() {
    MainWindow mw(nullptr);

    qreal val = 45.0;
    qreal rads = mw.toRadians(val, "Degrees");
    qreal deg = mw.fromRadians(rads, "Degrees");
    QVERIFY(std::fabs(val - deg) < 0.0001);

    val = 1000.0;
    rads = mw.toRadians(val, "Mils");
    qreal mils = mw.fromRadians(rads, "Mils");
    QVERIFY(std::fabs(val - mils) < 0.0001);
}

void ConverterTest::testButtonClickTriggersConversion() {
    MainWindow mw(nullptr);

    // Устанавливаем входное значение
    mw.getUi()->inputEdit->setPlainText("180");

    // Выбираем пункт конвертации: "Degrees -> Radians"
    int index = mw.getUi()->comboBox->findText("Degrees -> Radians");
    QVERIFY(index != -1);
    mw.getUi()->comboBox->setCurrentIndex(index);

    // Нажимаем кнопку "Convert"
    QTest::mouseClick(mw.getUi()->pushButton, Qt::LeftButton);

    // Проверяем результат (180 градусов -> pi радиан)
    QString resultText = mw.getUi()->resultLabel->text();
    QVERIFY(resultText.contains(QString::number(M_PI, 'f', 6)));
}

QTEST_MAIN(ConverterTest)
#include "tests.moc"
