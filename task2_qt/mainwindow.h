#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "items.h"
#include "save_items.h"

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
    void on_change_color_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void change_back_color();
    ItemsSaver saver;

    bool is_valid();
    Items get_items();
    void clear_form();
};
#endif // MAINWINDOW_H
