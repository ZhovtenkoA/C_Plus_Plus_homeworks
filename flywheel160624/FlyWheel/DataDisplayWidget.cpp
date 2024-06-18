#include "DataDisplayWidget.h"

DataDisplayWidget::DataDisplayWidget(QWidget *parent)
    : QWidget(parent)
{
    dataTextEdit = new QTextEdit(this);
    dataTextEdit->setReadOnly(true);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(dataTextEdit);
    setLayout(mainLayout);
}

void DataDisplayWidget::appendData(const QString &data)
{
    dataTextEdit->append(data);
}
