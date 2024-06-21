#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    timer  = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::timer_tick);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

QString MainWindow::random_color()
{
    qint32 red = QRandomGenerator::global()->bounded(0, 255);
    qint32 green = QRandomGenerator::global()->bounded(0, 255);
    qint32 blue = QRandomGenerator::global()->bounded(0, 255);

    QString color = "rgb("+ QString::number(red)+","+ QString::number(green) + ","+ QString::number(blue)+")";
    return color;
}

void MainWindow::timer_tick()
{
    setStyleSheet("background-color: " + random_color());

}

void MainWindow::on_add_button_clicked()
{
    NewWindow1* window1 = new NewWindow1;
    window1->show();
}

