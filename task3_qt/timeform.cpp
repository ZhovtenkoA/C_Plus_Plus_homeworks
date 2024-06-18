#include "timeform.h"
#include "ui_timeform.h"

TimeForm::TimeForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TimeForm)
{
    ui->setupUi(this);
    // Получение текущей даты и времени
    QDateTime currentDateTime = QDateTime::currentDateTime();

    // Преобразование даты и времени в строку
    QString dateTimeString = currentDateTime.toString("dd.MM.yyyy hh:mm:ss");

    // Установка строки с датой и временем в виджет
    ui->time_form->setText(dateTimeString);
}

TimeForm::~TimeForm()
{
    delete ui;
}
