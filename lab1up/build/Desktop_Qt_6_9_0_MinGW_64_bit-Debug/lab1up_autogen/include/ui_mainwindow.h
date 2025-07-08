/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *inputLayout;
    QLabel *inputLabel;
    QTextEdit *inputEdit;
    QHBoxLayout *comboLayout;
    QLabel *comboLabel;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QLabel *resultLabel;
    QMenuBar *menubar;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 250);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        inputLayout = new QHBoxLayout();
        inputLayout->setObjectName("inputLayout");
        inputLabel = new QLabel(centralwidget);
        inputLabel->setObjectName("inputLabel");

        inputLayout->addWidget(inputLabel);

        inputEdit = new QTextEdit(centralwidget);
        inputEdit->setObjectName("inputEdit");
        inputEdit->setMaximumHeight(50);

        inputLayout->addWidget(inputEdit);


        verticalLayout->addLayout(inputLayout);

        comboLayout = new QHBoxLayout();
        comboLayout->setObjectName("comboLayout");
        comboLabel = new QLabel(centralwidget);
        comboLabel->setObjectName("comboLabel");

        comboLayout->addWidget(comboLabel);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");

        comboLayout->addWidget(comboBox);


        verticalLayout->addLayout(comboLayout);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");

        verticalLayout->addWidget(checkBox);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        resultLabel = new QLabel(centralwidget);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setAlignment(Qt::AlignCenter);
        resultLabel->setFrameShape(QFrame::Panel);
        resultLabel->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(resultLabel);

        verticalLayout->setStretch(3, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 22));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName("menuOptions");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Angle Units Converter", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        inputLabel->setText(QCoreApplication::translate("MainWindow", "Enter value:", nullptr));
        comboLabel->setText(QCoreApplication::translate("MainWindow", "Select conversion:", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Save result to log.txt", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Convert", nullptr));
        resultLabel->setText(QCoreApplication::translate("MainWindow", "Result:", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
