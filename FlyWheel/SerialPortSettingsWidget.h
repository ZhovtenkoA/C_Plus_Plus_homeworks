#ifndef SERIALPORTSETTINGSWIDGET_H
#define SERIALPORTSETTINGSWIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QComboBox>
#include <QPushButton>

class SerialPortSettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SerialPortSettingsWidget(QWidget *parent = nullptr);
    QSerialPort* getSerialPort() const;
    void printCurrentSettings();


signals:
    void dataReceived(const QString &data);
    void comPortNotFound();

private slots:
    void updateAvailablePorts();
    void applySettings();
    void connectToPort();
    void disconnectFromPort();
    void readData();
    void showErrorDialog(const QString &message);

private:
    QSerialPort *serialPort;
    QComboBox *portComboBox;
    QComboBox *baudRateComboBox;
    QComboBox *dataBitsComboBox;
    QComboBox *parityComboBox;
    QComboBox *stopBitsComboBox;
    QComboBox *flowControlComboBox;
    QPushButton *applyButton;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
};

#endif // SERIALPORTSETTINGSWIDGET_H

/*
class SerialPortSettingsWidget : public QWidget
{
    Q_OBJECT
    // ... ваш код ...

public:
    void printCurrentSettings();

private slots:
    void updateAvailablePorts();
    void applySettings();
    void connectToPort();
    void disconnectFromPort();
    void showErrorDialog(const QString &message);
    void readData();

signals:
    void comPortNotFound();
    void dataReceived(const QString &data);

private:
    QSerialPort *serialPort;
    QComboBox *portComboBox;
    QComboBox *baudRateComboBox;
    QComboBox *dataBitsComboBox;
    QComboBox *parityComboBox;
    QComboBox *stopBitsComboBox;
    QComboBox *flowControlComboBox;
    QPushButton *applyButton;
    QPushButton *connectButton;
    QPushButton *disconnectButton;

    void updateAvailablePorts();
    void applySettings();
    void connectToPort();
    void disconnectFromPort();
    void showErrorDialog(const QString &message);
    void readData();
};
*/
