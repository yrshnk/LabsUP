#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void convert();
    void showSettingsDialog();
    void showAboutDialog();

private:
    qreal toRadians(qreal value, const QString &unit);
    qreal fromRadians(qreal value, const QString &unit);
    void logResult(const QString &entry);

    Ui::MainWindow *ui;
    QStringList conversionList;
};

#endif // MAINWINDOW_H
