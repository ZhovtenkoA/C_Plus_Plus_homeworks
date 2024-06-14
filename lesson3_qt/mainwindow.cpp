#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    new_window = new NewWindow1;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete new_window;
}

void MainWindow::on_new_window_clicked()
{
    new_window->show();
}


void MainWindow::on_another_window_clicked()
{
    NewWindow1* another_window = new NewWindow1;
    another_window->show();
}

