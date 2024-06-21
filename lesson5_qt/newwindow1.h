#ifndef NEWWINDOW1_H
#define NEWWINDOW1_H

#include <QWidget>
#include <QRandomGenerator>
#include <QTimer>

namespace Ui {
class NewWindow1;
}

class NewWindow1 : public QWidget
{
    Q_OBJECT

public:
    explicit NewWindow1(QWidget *parent = nullptr);
    ~NewWindow1();

private:
    Ui::NewWindow1 *ui;

    QString random_color();

    QTimer* timer;

    void timer_tick();

};

#endif // NEWWINDOW1_H
