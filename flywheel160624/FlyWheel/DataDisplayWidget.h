#ifndef DATADISPLAYWIDGET_H
#define DATADISPLAYWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
class DataDisplayWidget : public QWidget
{
    Q_OBJECT

public:
    DataDisplayWidget(QWidget *parent = nullptr);

public slots:
    void appendData(const QString &data);

private:
    QTextEdit *dataTextEdit;
};

#endif // DATADISPLAYWIDGET_H
