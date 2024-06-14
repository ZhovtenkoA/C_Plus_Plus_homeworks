/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *model;
    QSpinBox *memory;
    QSpinBox *ram;
    QComboBox *brand;
    QPushButton *save;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(418, 441);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        model = new QLineEdit(centralwidget);
        model->setObjectName("model");
        model->setMaxLength(100);

        formLayout->setWidget(0, QFormLayout::FieldRole, model);

        memory = new QSpinBox(centralwidget);
        memory->setObjectName("memory");
        memory->setMaximum(1000);

        formLayout->setWidget(2, QFormLayout::FieldRole, memory);

        ram = new QSpinBox(centralwidget);
        ram->setObjectName("ram");

        formLayout->setWidget(3, QFormLayout::FieldRole, ram);

        brand = new QComboBox(centralwidget);
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->addItem(QString());
        brand->setObjectName("brand");

        formLayout->setWidget(1, QFormLayout::FieldRole, brand);


        verticalLayout->addLayout(formLayout);

        save = new QPushButton(centralwidget);
        save->setObjectName("save");

        verticalLayout->addWidget(save);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 418, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Model", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Brand", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Memory", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "RAM", nullptr));
        brand->setItemText(0, QCoreApplication::translate("MainWindow", "Samsung", nullptr));
        brand->setItemText(1, QCoreApplication::translate("MainWindow", "Lenovo", nullptr));
        brand->setItemText(2, QCoreApplication::translate("MainWindow", "Apple", nullptr));
        brand->setItemText(3, QCoreApplication::translate("MainWindow", "Other", nullptr));

        save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
