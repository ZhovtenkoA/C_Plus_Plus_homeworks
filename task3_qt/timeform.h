#ifndef TIMEFORM_H
#define TIMEFORM_H

#include <QWidget>
#include <QDateTime>

namespace Ui {
class TimeForm;
}

class TimeForm : public QWidget
{
    Q_OBJECT

public:
    explicit TimeForm(QWidget *parent = nullptr);
    ~TimeForm();

private:
    Ui::TimeForm *ui;
};

#endif // TIMEFORM_H
