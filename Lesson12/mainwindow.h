#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "phone.h"
#include "phonesaver.h"
#include "phonereader.h"

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
    void on_save_clicked();

private:
    Ui::MainWindow *ui;
    PhoneSaver saver;
    PhoneReader reader;

    bool validate_form();
    Phone get_form_data();
    void clear_form();

};
#endif // MAINWINDOW_H
