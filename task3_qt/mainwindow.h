#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pcname.h"
#include "timeform.h"
#include <QMessageBox>
#include <QCloseEvent>

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
    void on_time_button_clicked();

    void on_pc_name_button_clicked();

private:
    Ui::MainWindow *ui;
    PcName* pc_name_window;
    void closeEvent(QCloseEvent *event) override;
};
#endif // MAINWINDOW_H
