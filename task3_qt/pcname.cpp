#include "pcname.h"
#include "ui_pcname.h"

PcName::PcName(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PcName)
{
    ui->setupUi(this);
    ui->pc_name->setText(QSysInfo::machineHostName());

}

PcName::~PcName()
{
    delete ui;
}
