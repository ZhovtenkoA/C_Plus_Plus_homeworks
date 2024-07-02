#ifndef DATADISPLAYWIDGET_H
#define DATADISPLAYWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include  <QPushButton>

class DataDisplayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DataDisplayWidget(QWidget *parent = nullptr);
    void appendData(const QString &data); // Публичный метод для добавления данных

private:
    QTableWidget *tableWidget;
    QPushButton *clearButton;

private slots:
    void clearData();
};

#endif // DATADISPLAYWIDGET_H
