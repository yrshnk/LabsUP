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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QTableWidget *tableWidget;
    QHBoxLayout *searchLayout;
    QLineEdit *searchModelLineEdit;
    QLineEdit *searchSpeedLineEdit;
    QLineEdit *searchPriceLineEdit;
    QHBoxLayout *sortButtonsLayout;
    QPushButton *sortModelButton;
    QPushButton *sortSpeedButton;
    QPushButton *sortPriceButton;
    QHBoxLayout *buttonLayout;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *updateButton;
    QPushButton *addPhotoButton;
    QPushButton *checkArraySizeButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        tableWidget->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout->addWidget(tableWidget);

        searchLayout = new QHBoxLayout();
        searchLayout->setObjectName("searchLayout");
        searchModelLineEdit = new QLineEdit(centralwidget);
        searchModelLineEdit->setObjectName("searchModelLineEdit");

        searchLayout->addWidget(searchModelLineEdit);

        searchSpeedLineEdit = new QLineEdit(centralwidget);
        searchSpeedLineEdit->setObjectName("searchSpeedLineEdit");

        searchLayout->addWidget(searchSpeedLineEdit);

        searchPriceLineEdit = new QLineEdit(centralwidget);
        searchPriceLineEdit->setObjectName("searchPriceLineEdit");

        searchLayout->addWidget(searchPriceLineEdit);


        verticalLayout->addLayout(searchLayout);

        sortButtonsLayout = new QHBoxLayout();
        sortButtonsLayout->setObjectName("sortButtonsLayout");
        sortModelButton = new QPushButton(centralwidget);
        sortModelButton->setObjectName("sortModelButton");

        sortButtonsLayout->addWidget(sortModelButton);

        sortSpeedButton = new QPushButton(centralwidget);
        sortSpeedButton->setObjectName("sortSpeedButton");

        sortButtonsLayout->addWidget(sortSpeedButton);

        sortPriceButton = new QPushButton(centralwidget);
        sortPriceButton->setObjectName("sortPriceButton");

        sortButtonsLayout->addWidget(sortPriceButton);


        verticalLayout->addLayout(sortButtonsLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");

        buttonLayout->addWidget(addButton);

        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");

        buttonLayout->addWidget(removeButton);

        updateButton = new QPushButton(centralwidget);
        updateButton->setObjectName("updateButton");

        buttonLayout->addWidget(updateButton);

        addPhotoButton = new QPushButton(centralwidget);
        addPhotoButton->setObjectName("addPhotoButton");

        buttonLayout->addWidget(addPhotoButton);

        checkArraySizeButton = new QPushButton(centralwidget);
        checkArraySizeButton->setObjectName("checkArraySizeButton");

        buttonLayout->addWidget(checkArraySizeButton);


        verticalLayout->addLayout(buttonLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Antique Cars Manager", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "Antique Cars Table ", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Model", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Speed (km/h)", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Price ($)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        searchModelLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search by Model", nullptr));
        searchSpeedLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search by Speed", nullptr));
        searchPriceLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search by Price", nullptr));
        sortModelButton->setText(QCoreApplication::translate("MainWindow", "Sort by Model", nullptr));
        sortSpeedButton->setText(QCoreApplication::translate("MainWindow", "Sort by Speed", nullptr));
        sortPriceButton->setText(QCoreApplication::translate("MainWindow", "Sort by Price", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add Car", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "Remove Car", nullptr));
        updateButton->setText(QCoreApplication::translate("MainWindow", "Edit Car", nullptr));
        addPhotoButton->setText(QCoreApplication::translate("MainWindow", "Add Photo", nullptr));
        checkArraySizeButton->setText(QCoreApplication::translate("MainWindow", "Check Size", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
