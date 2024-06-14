#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , saver("items.txt")
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::change_back_color(){

    qint32  red, green, blue;

    red = ui->red_input_box->value();
    green = ui->green_input_box->value();
    blue = ui->blue_input_box->value();

    QString styleSheet = QString("background-color: rgb(%1, %2, %3);").arg(red).arg(green).arg(blue);
    this->setStyleSheet(styleSheet);

}


void MainWindow::on_change_color_button_clicked()
{
    change_back_color();
}


void MainWindow::on_pushButton_clicked()
{
    if(is_valid()){
        Items item = get_items();
        saver.save(item);
        ui->statusbar->showMessage("Saved!", 3000);
        clear_form();
    }
}


bool MainWindow::is_valid()
{
    if(ui->item_name->text().trimmed() == ""){
        ui->item_name->setStyleSheet("background-color: red;");
        return false;
    }
    return true;
}

Items MainWindow::get_items()
{
    Items item;
    item.name = ui->item_name->text().trimmed();
    item.price = ui->item_price->value();
    item.weight = ui->item_weight->value();


    return item;
}

void MainWindow::clear_form()
{
    ui->item_name->setText("");
    ui->item_price->setValue(0);
    ui->item_weight->setValue(0);

}
