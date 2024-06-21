#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::timer_tick);

    ui->hint->setText("Press on time: "+QString::number(win_time));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}


void MainWindow::on_press_clicked()//|10.000000 - 10.000001| <= 0.00001
{
    if(timer->isActive()){
        timer->stop();
        if(abs(miliseconds/1000 - win_time) <= 0.0001){
            QMessageBox::information(this, "Result", "You won!");
        }
        else{
            QMessageBox::critical(this, "Result", "You lose!");
        }
        return;
    }

    miliseconds = 0;
    timer->start(1);


}

void MainWindow::timer_tick()
{
    miliseconds++;
    ui->label->setText(QString::number(miliseconds/1000));
}

