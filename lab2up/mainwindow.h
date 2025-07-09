#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "car.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_updateButton_clicked();
    void on_addPhotoButton_clicked();
    void on_sortModelButton_clicked();
    void on_sortSpeedButton_clicked();
    void on_sortPriceButton_clicked();
    void on_tableWidget_cellClicked(int row, int column);
    void applySearchFilter();
    void showContextMenu(const QPoint &pos);
    void on_checkArraySizeButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<Car> carList;

    QVector<int> filteredIndexes;

    void loadCars();
    void saveCars();
    void refreshTable();
    bool validateCarData(const QString &model, int speed, double price);

    int getRealIndexFromFiltered(int filteredRow) const;
};

#endif // MAINWINDOW_H
