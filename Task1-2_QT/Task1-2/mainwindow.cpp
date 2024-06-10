#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load_text();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_1_clicked()
{
    ui->Text_output->setText("First!");
}


void MainWindow::on_button_2_clicked()
{
    ui->Text_output->setText("Second!");
}


void MainWindow::on_mul_btn_clicked()
{
    QString text = ui->text_input->text();

    QString text_number = ui->int_input->text();

    qint32 num = text_number.toInt();

    QString result;
    for (int i = 0; i < num; i++) {
        result += text;
    }
    ui->second_output->setText(result);
}


void MainWindow::save_text()
{
    QString text = ui->saver_edit->text();
    QFile file("text.txt");
    if(!file.open(QFile::WriteOnly)) return;

    QTextStream ts(&file);
    ts <<text;
    file.close();
}

void MainWindow::load_text()
{
    QFile file("text.txt");
    QString text;
    if(!file.open(QFile::ReadOnly)) return;
    QTextStream ts(&file);
    ts>>text;
    ui->saver_edit->setText(text);
    file.close();
}


void MainWindow::on_actionText_save_triggered()
{
    save_text();
}

