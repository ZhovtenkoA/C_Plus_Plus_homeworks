#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "uniquewindow.h"
#include "modalwindow.h"
#include <QVector>
#include <QMessageBox>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_unique_clicked();

    void on_many_clicked();

    void on_modal_clicked();

    void on_info_clicked();

    void on_error_clicked();

private:
    Ui::MainWindow *ui;

    UniqueWindow* unique;
    QVector<UniqueWindow*> to_delete;

    void closeEvent(QCloseEvent *event) override;
};
#endif // MAINWINDOW_H
