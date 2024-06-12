#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "food.h"

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
    void on_save_button_clicked();

private:
    Ui::MainWindow *ui;

    bool is_valid();
    Food get_food();
    void clear_form();

};
#endif // MAINWINDOW_H
