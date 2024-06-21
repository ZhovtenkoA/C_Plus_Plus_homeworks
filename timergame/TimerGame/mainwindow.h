#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMessageBox>

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
    void on_press_clicked();

private:
    Ui::MainWindow *ui;

    QTimer* timer;
    qreal miliseconds = 0, win_time = 5.00;

    void timer_tick();
};
#endif // MAINWINDOW_H
