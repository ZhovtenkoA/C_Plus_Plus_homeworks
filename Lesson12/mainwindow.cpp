#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , saver("phones.txt")
    , reader("phones.txt")

{
    ui->setupUi(this);

    QVector<Phone> phones = reader.read_all();

    for(Phone& phone: phones){
        qDebug() << phone.model << phone.brand << phone.memory << phone.ram;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_save_clicked()
{
    if(validate_form()){
        Phone phone = get_form_data();
        saver.save(phone);
        ui->statusbar->showMessage("Saved!", 3000);
        clear_form();
    }
}

bool MainWindow::validate_form()// "  ddd   " -> "ddd"
{
    ui->model->setStyleSheet("");
    if(ui->model->text().trimmed() == ""){
        ui->model->setStyleSheet("background-color: rgb(255, 10, 10);");
        return false;
    }

    return true;
}

Phone MainWindow::get_form_data()
{
    Phone phone;
    phone.model = ui->model->text().trimmed();
    phone.brand = ui->brand->currentText();
    phone.memory = ui->memory->value();
    phone.ram = ui->ram->value();

    return phone;
}

void MainWindow::clear_form()
{
    ui->model->setText("");
    ui->brand->setCurrentIndex(0);
    ui->memory->setValue(0);
    ui->ram->setValue(0);
}

