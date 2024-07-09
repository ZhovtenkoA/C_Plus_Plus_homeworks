#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");

    QString filename = "task8.db";
    db.setDatabaseName(filename);
    table_model = new QSqlTableModel;

    if(!db.open()){
        QMessageBox::critical(this, "Error", db.lastError().text());
        // ui->save->setEnabled(false);
        // ui->remove->setEnabled(false);
        // ui->clocks_table->setEnabled(false);
    }

    // table_model = new QSqlTableModel();
    QStringList tables = db.tables();
    qDebug() << tables;

    if(tables.contains("employees")){
        QString table = "employees";

        table_model->setTable(table);
        table_model->select();
    }

    ui->tableView->setModel(table_model);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_tableView_clicked(const QModelIndex &index)
{

    row = index.row();
    ui->remove_btn->setEnabled(true);
}


void MainWindow::on_add_btn_clicked()
{
    QString firstname = ui->firstname->text();
    QString lastname = ui->lastname->text();
    qint32 birthday = ui->birthday->value();
    qint32 salary = ui->salary->value();
    QString position = ui->position->text();

    QSqlQuery querry;

    querry.prepare("INSERT INTO employees (firstname, lastname, birthday, salary, position ) VALUES (?,?,?,?,?)");
    querry.addBindValue(firstname);
    querry.addBindValue(lastname);
    querry.addBindValue(birthday);
    querry.addBindValue(salary);
    querry.addBindValue(position);
    querry.exec();

    qDebug()<<querry.lastError();

    table_model->select();
}


void MainWindow::on_remove_btn_clicked()
{
    if(row ==-1) return;
    QSqlRecord data = table_model->record(row);
    qint32 record_id = data.value(0).toInt();

    QSqlQuery querry;

    querry.prepare("DELETE FROM employees WHERE id =?");
    querry.addBindValue(record_id);
    querry.exec();

    qDebug()<<querry.lastError();

    table_model->select();
    row = -1;
    ui->remove_btn->setEnabled(false);
}


void MainWindow::on_patch_btn_clicked()
{


    if(row ==-1) return;
    QSqlRecord data = table_model->record(row);
    qint32 record_id = data.value(0).toInt();
    QString firstname = ui->firstname->text();
    QString lastname = ui->lastname->text();
    qint32 birthday = ui->birthday->value();
    qint32 salary = ui->salary->value();
    QString position = ui->position->text();

    QSqlQuery querry;

    querry.prepare("UPDATE employees SET firstname=?, lastname=?, birthday=?, salary=?, position=? WHERE id = ?");
    querry.addBindValue(firstname);
    querry.addBindValue(lastname);
    querry.addBindValue(birthday);
    querry.addBindValue(salary);
    querry.addBindValue(position);
    querry.addBindValue(record_id);
    querry.exec();

    qDebug()<<querry.lastError();

    table_model->select();
}

