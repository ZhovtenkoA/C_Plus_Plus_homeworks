#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlRecord>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_add_btn_clicked();

    void on_remove_btn_clicked();

    void on_patch_btn_clicked();

private:
    Ui::MainWindow *ui;

    QSqlDatabase db;
    QSqlTableModel* table_model , *users_model;
    qint32 row = -1;
};
#endif // MAINWINDOW_H
