#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pc_name_window = new PcName;
    ui->os_label->setText(QSysInfo::prettyProductName());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_time_button_clicked()
{
    TimeForm* time_window = new TimeForm;
    time_window->show();
}



void MainWindow::on_pc_name_button_clicked()
{
    pc_name_window->show();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton answer = QMessageBox::question(
        this, "Closing", "Do you really want to close app?");

    if(answer == QMessageBox::Yes){
        event->accept();
        return;
    }

    event->ignore();
}

