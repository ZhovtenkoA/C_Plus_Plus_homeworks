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
    SerialPortSettingsWidget(QWidget *parent = nullptr);

signals:
    void comPortNotFound();
    void dataReceived(const QString &data);

private slots:
    void updateAvailablePorts();
    void applySettings();
    void connectToPort();
    void disconnectFromPort();
    void showErrorDialog(const QString &message);
    void readData();


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
