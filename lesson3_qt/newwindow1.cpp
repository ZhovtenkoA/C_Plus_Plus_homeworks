#include "newwindow1.h"
#include "ui_newwindow1.h"

NewWindow1::NewWindow1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NewWindow1)
{
    ui->setupUi(this);
    setStyleSheet("background-color: " + random_color());
}

NewWindow1::~NewWindow1()
{
    delete ui;
}

QString NewWindow1::random_color()
{
    qint32 red = QRandomGenerator::global()->bounded(0, 255);
    qint32 green = QRandomGenerator::global()->bounded(0, 255);
    qint32 blue = QRandomGenerator::global()->bounded(0, 255);

    QString color = "rgb("+ QString::number(red)+","+ QString::number(green) + ","+ QString::number(blue)+")";
    return color;
}
