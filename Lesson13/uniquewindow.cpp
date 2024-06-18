#include "uniquewindow.h"
#include "ui_uniquewindow.h"

UniqueWindow::UniqueWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UniqueWindow)
{
    ui->setupUi(this);

    QString date = QDateTime::currentDateTime().toString();

    ui->time_label->setText(date);
}

UniqueWindow::~UniqueWindow()
{
    delete ui;
}
