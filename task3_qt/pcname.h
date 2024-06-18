#ifndef PCNAME_H
#define PCNAME_H

#include <QWidget>
#include <QDialog>
#include <QSysInfo>

namespace Ui {
class PcName;
}

class PcName : public QWidget
{
    Q_OBJECT

public:
    explicit PcName(QWidget *parent = nullptr);
    ~PcName();

private:
    Ui::PcName *ui;
};

#endif // PCNAME_H
