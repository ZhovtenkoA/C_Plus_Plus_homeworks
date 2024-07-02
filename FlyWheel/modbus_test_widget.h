
#ifndef MODBUSTESTWIDGET_H
#define MODBUSTESTWIDGET_H

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
    explicit ModbusTestWidget(QSerialPort *serialPort, QWidget *parent = nullptr);
 void updateResult(const QString &result);


signals:
    void readButtonClicked(const QString &regType, int address, int regNumber);

private slots:
    void onReadButtonClicked();
    void handleReadRequest(const QString &regType, int address, int regNumber);
   // void updateResult(const QString &result);
    void updateSentData(const QString &data);
    void updateReceivedData(const QString &data);

private:
    QByteArray createModbusRequest(const QString &regType, int address, int regNumber);

    QSerialPort *serialPort;
    QLineEdit *addressLineEdit;
    QLineEdit *registerLineEdit;
    QComboBox *registerTypeComboBox;
    QPushButton *readButton;
    QLabel *resultLabel;
    QTextEdit *sentDataTextEdit;
    QTextEdit *receivedDataTextEdit;
};

#endif // MODBUSTESTWIDGET_H
