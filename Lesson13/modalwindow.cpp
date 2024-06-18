#include "modalwindow.h"
#include "ui_modalwindow.h"

ModalWindow::ModalWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModalWindow)
{
    ui->setupUi(this);

    ui->os_label->setText(QSysInfo::prettyProductName());
    ui->name_label->setText(QSysInfo::machineHostName());
}

ModalWindow::~ModalWindow()
{
    delete ui;
}
