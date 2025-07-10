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
    Ui::MainWindow *getUi() const { return ui; }
    Ui::MainWindow *ui;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Сделаем публичными методы для тестов:
    qreal toRadians(qreal value, const QString &unit);
    qreal fromRadians(qreal value, const QString &unit);
     void testButtonClickTriggersConversion();

private slots:
    void convert();
    void showAboutDialog();

private:
    void logResult(const QString &entry);

    QStringList conversionList;
};

#endif // MAINWINDOW_H
