#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>

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
    void on_prev_btn_clicked();

    void on_next_btn_clicked();

private:
    Ui::MainWindow *ui;

    QList<QPixmap> images;
    qint32 index = 0;
};
#endif // MAINWINDOW_H
