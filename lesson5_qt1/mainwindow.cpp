#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_btn_clicked()
{
    QString worker = ui->edit_name->text() + " " + ui->combo_status->currentText();
    ui->workers_list->addItem(worker);
}


void MainWindow::on_remove_btn_clicked()
{
    auto workers_to_delete = ui->workers_list->selectedItems();
    if(workers_to_delete.size() != 1 ) return;
    delete workers_to_delete[0];
}


void MainWindow::on_workers_list_itemDoubleClicked(QListWidgetItem *item)
{

    QString double_clecked_worker =  item->text();
    if (double_clecked_worker.endsWith("Manager")) ui->statusbar->showMessage("selected worker is Manager", 2000);
    if (double_clecked_worker.endsWith("Employee")) ui->statusbar->showMessage("selected worker is Employee", 2000);
    if (double_clecked_worker.endsWith("Director")) ui->statusbar->showMessage("selected worker is Director", 2000);


}

