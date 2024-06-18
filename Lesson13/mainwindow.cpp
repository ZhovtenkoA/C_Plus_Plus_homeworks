#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    unique = new UniqueWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete unique;
    for(UniqueWindow* window: to_delete){
        delete window;
    }
}


void MainWindow::on_unique_clicked()
{
    unique->show();
}


void MainWindow::on_many_clicked()
{
    UniqueWindow* many = new UniqueWindow();
    many->show();

    to_delete.append(many);
}


void MainWindow::on_modal_clicked()
{
    ModalWindow modal;

    modal.exec();

}


void MainWindow::on_info_clicked()
{
    QMessageBox::information(this, "Info window", "This is info window!");

}


void MainWindow::on_error_clicked()
{
    QMessageBox::critical(this, "Error window", "This is error window!");
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

