/*

#ifndef MODBUS_TEST_WIDGET_H
#define MODBUS_TEST_WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

class ModbusTestWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModbusTestWidget(QSerialPort *serialPort, QWidget *parent = nullptr);

signals:
    void readButtonClicked(const QString &regType, int address, int regNumber);

public slots:
    void updateResult(const QString &result);

private slots:
    void onReadButtonClicked();

private:
    QSerialPort *serialPort;
    QLineEdit *addressLineEdit;
    QLineEdit *registerLineEdit;
    QComboBox *registerTypeComboBox;
    QPushButton *readButton;
    QLabel *resultLabel;
};

#endif // MODBUS_TEST_WIDGET_H

*/
#ifndef MODBUS_TEST_WIDGET_H
#define MODBUS_TEST_WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>

class ModbusTestWidget : public QWidget
{
    Q_OBJECT

public:
    ModbusTestWidget(QSerialPort *serialPort, QWidget *parent = nullptr);

signals:
    void readButtonClicked(const QString &regType, int address, int regNumber);

public slots:
    void updateResult(const QString &result);
    void updateSentData(const QString &data);
    void updateReceivedData(const QString &data);

private slots:
    void onReadButtonClicked();

private:
    QSerialPort *serialPort;
    QLineEdit *addressLineEdit;
    QLineEdit *registerLineEdit;
    QComboBox *registerTypeComboBox;
    QPushButton *readButton;
    QLabel *resultLabel;
    QTextEdit *sentDataTextEdit;
    QTextEdit *receivedDataTextEdit;
};

#endif // MODBUS_TEST_WIDGET_H
