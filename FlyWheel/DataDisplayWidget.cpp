#include "datadisplaywidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QHeaderView>
#include <QDateTime>

DataDisplayWidget::DataDisplayWidget(QWidget *parent)
    : QWidget(parent),
    tableWidget(new QTableWidget(this)),
    clearButton(new QPushButton("Clear", this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tableWidget);
    layout->addWidget(clearButton);

    tableWidget->setColumnCount(2);
    tableWidget->horizontalHeader()->setVisible(false);
    tableWidget->horizontalHeader()->setStretchLastSection(true); // Растягиваем последний столбец

    connect(clearButton, &QPushButton::clicked, this, &DataDisplayWidget::clearData);
}

void DataDisplayWidget::appendData(const QString &data)
{
    QDateTime currentTime = QDateTime::currentDateTime();
    QString timeString = currentTime.toString("hh:mm:ss:zzz");

    int row = tableWidget->rowCount();
    tableWidget->insertRow(row);

    QTableWidgetItem *timeItem = new QTableWidgetItem(timeString);
    QTableWidgetItem *dataItem = new QTableWidgetItem(data);

    timeItem->setTextAlignment(Qt::AlignRight);

    // Устанавливаем данные в ячейки таблицы
    tableWidget->setItem(row, 0, timeItem); // Колонка 0 для времени
    tableWidget->setItem(row, 1, dataItem); // Колонка 1 для данных

    // Прокрутка содержимого в ячейке, если оно не помещается
    dataItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter); // Выравнивание текста в ячейке

    // Автоматический размер столбцов по содержимому
    tableWidget->resizeColumnsToContents();

    tableWidget->scrollToBottom();
}

void DataDisplayWidget::clearData()
{
    tableWidget->clearContents();
    tableWidget->setRowCount(0);
}
