#ifndef MODALWINDOW_H
#define MODALWINDOW_H

#include <QDialog>
#include <QSysInfo>

namespace Ui {
class ModalWindow;
}

class ModalWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ModalWindow(QWidget *parent = nullptr);
    ~ModalWindow();

private:
    Ui::ModalWindow *ui;
};

#endif // MODALWINDOW_H
