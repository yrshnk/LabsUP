#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QVector>
#include <QString>
#include "car.h"

class MainWindow : public QObject
{
    Q_OBJECT

public:
    MainWindow(QObject *parent = nullptr);
    ~MainWindow();

    void loadCars();
    void saveCars();
    void applySearchFilter();
    bool validateCarData(const QString &model, int speed, double price);
    int getRealIndexFromFiltered(int filteredRow) const;

    QVector<Car> &getCarList() { return carList; }
    QVector<int> &getFilteredIndexes() { return filteredIndexes; }

private:
    QVector<Car> carList;
    QVector<int> filteredIndexes;
};

#endif // MAINWINDOW_H
