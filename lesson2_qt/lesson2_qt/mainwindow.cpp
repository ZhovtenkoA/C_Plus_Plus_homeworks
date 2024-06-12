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

void MainWindow::on_save_button_clicked()
{
    if(is_valid()){
        Food food = get_food();
        clear_form();
    }

}

bool MainWindow::is_valid()
{
    if(ui->name->text().trimmed() == ""){
        ui->name->setStyleSheet("background-color: red;");
        return false;
    }
    return true;
}

Food MainWindow::get_food()
{
    Food food;
    food.name = ui->name->text().trimmed();
    food.weight = ui->weight->value();
    food.callory = ui->callory->value();
    food.package = ui->package_2->currentText();

    return food;
}

void MainWindow::clear_form()
{
    ui->name->setText("");
    ui->weight->setValue(0);
    ui->callory->setValue(0);
    ui->package_2->setCurrentIndex(0);
}

