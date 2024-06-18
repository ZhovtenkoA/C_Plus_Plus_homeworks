#ifndef UNIQUEWINDOW_H
#define UNIQUEWINDOW_H

#include <QWidget>
#include <QDateTime>

namespace Ui {
class UniqueWindow;
}

class UniqueWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UniqueWindow(QWidget *parent = nullptr);
    ~UniqueWindow();

private:
    Ui::UniqueWindow *ui;
};

#endif // UNIQUEWINDOW_H
