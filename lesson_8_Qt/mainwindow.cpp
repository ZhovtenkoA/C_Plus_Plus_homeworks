#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    db = QSqlDatabase::addDatabase("QSQLITE");

    QString filename = "sql_auth.db";
    db.setDatabaseName(filename);
    table_model = new QSqlTableModel;
    users_model = new QSqlTableModel;

    if(!db.open()){
        QMessageBox::critical(this, "Error", db.lastError().text());
        // ui->save->setEnabled(false);
        // ui->remove->setEnabled(false);
        // ui->clocks_table->setEnabled(false);
    }

    // table_model = new QSqlTableModel();
    QStringList tables = db.tables();
    qDebug() << tables;

    if(tables.contains("verification")){
        QString table = "verification";

        table_model->setTable(table);
        table_model->select();
    }

    if(tables.contains("users")){
        QString table = "users";

        users_model->setTable(table);
        users_model->select();
    }

    ui->tableView->setModel(table_model);
    ui->users->setModel(users_model);





}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_add_btn_clicked()
{
    qint32 id = ui->id->value();
    QString email = ui->email->text();
    qint32 verification_code  = ui->verification_code->value();
    bool email_confirmation = ui->email_confirmation->isChecked();

    QSqlQuery querry;

    querry.prepare("INSERT INTO verification (email, verification_code, email_confirmation) VALUES (?,?,?)");
    querry.addBindValue(email);
    querry.addBindValue(verification_code);
    querry.addBindValue(email_confirmation);
    querry.exec();

    qDebug()<<querry.lastError();

    table_model->select();





}


void MainWindow::on_add_user_clicked()
{


    QString email = ui->users_email->text();
    QString pasword = ui->pasword->text();

    QString access_token = "131313";
    QString refresh_token = "sdfgfdfgh";
    QString role = "user";

    QSqlQuery querry;

    querry.prepare("INSERT INTO users (email, pasword, access_token,refresh_token,role ) VALUES (?,?,?,?,?)");
    querry.addBindValue(email);
    querry.addBindValue(pasword);
    querry.addBindValue(access_token);
    querry.addBindValue(refresh_token);
    querry.addBindValue(role);
    querry.exec();

    qDebug()<<querry.lastError();

    users_model->select();

}

