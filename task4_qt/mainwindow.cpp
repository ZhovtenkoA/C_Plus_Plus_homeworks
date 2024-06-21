#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::on_start_clicked()
{
    toggleTimer();
}

void MainWindow::toggleTimer()
{
    if (timer->isActive()) {
        timer->stop();
        ui->start->setText("Старт");
        ui->textEdit_hour->setReadOnly(false);
        ui->textEdit_minute->setReadOnly(false);
        ui->textEdit_seconds->setReadOnly(false);
    } else {
        int hours = ui->textEdit_hour->toPlainText().toInt();
        int minutes = ui->textEdit_minute->toPlainText().toInt();
        int seconds = ui->textEdit_seconds->toPlainText().toInt();

         int totalMilliseconds = (hours * 3600 + minutes * 60 + seconds) * 1000;
        remainingMilliseconds = totalMilliseconds;

        if (totalMilliseconds > 0) {
            timer->start(1);
            updateTimer();
            ui->start->setText("Стоп");
            ui->textEdit_hour->setReadOnly(true);
            ui->textEdit_minute->setReadOnly(true);
            ui->textEdit_seconds->setReadOnly(true);
        }
    }
}

void MainWindow::updateTimer()
{

    //remainingMilliseconds = timer->remainingTime();
    remainingMilliseconds--;
    int hours = remainingMilliseconds / 3600000;
    int minutes = (remainingMilliseconds % 3600000) / 60000;
    int seconds = (remainingMilliseconds % 60000) / 1000;

    ui->textEdit_hour->setPlainText(QString::number(hours));
    ui->textEdit_minute->setPlainText(QString::number(minutes));
    ui->textEdit_seconds->setPlainText(QString::number(seconds));

}

