#include "newwindow1.h"
#include "ui_newwindow1.h"

NewWindow1::NewWindow1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NewWindow1)
{
    ui->setupUi(this);
    timer  = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &NewWindow1::timer_tick);
    timer->start(QRandomGenerator::global()->bounded(300, 1000));
}

NewWindow1::~NewWindow1()
{
    delete ui;
    delete timer;
}


QString NewWindow1::random_color()
{
    qint32 red = QRandomGenerator::global()->bounded(0, 255);
    qint32 green = QRandomGenerator::global()->bounded(0, 255);
    qint32 blue = QRandomGenerator::global()->bounded(0, 255);

    QString color = "rgb("+ QString::number(red)+","+ QString::number(green) + ","+ QString::number(blue)+")";
    return color;
}

void NewWindow1::timer_tick()
{
    setStyleSheet("background-color: " + random_color());

}
