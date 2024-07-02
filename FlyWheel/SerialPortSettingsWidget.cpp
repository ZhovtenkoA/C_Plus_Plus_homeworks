#include "SerialPortSettingsWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>

SerialPortSettingsWidget::SerialPortSettingsWidget(QWidget *parent)
    : QWidget(parent), serialPort(new QSerialPort(this))
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // ComboBox для выбора порта
    portComboBox = new QComboBox(this);
    updateAvailablePorts();
    mainLayout->addWidget(new QLabel("Select COM Port:", this));
    mainLayout->addWidget(portComboBox);

    // ComboBox для выбора скорости передачи данных
    baudRateComboBox = new QComboBox(this);
    baudRateComboBox->addItems({"9600", "19200", "38400", "57600", "115200","128000"});
    mainLayout->addWidget(new QLabel("Baud Rate:", this));
    mainLayout->addWidget(baudRateComboBox);

    // ComboBox для выбора количества бит данных
    dataBitsComboBox = new QComboBox(this);
    dataBitsComboBox->addItems({"8", "7", "6", "5"});
    mainLayout->addWidget(new QLabel("Data Bits:", this));
    mainLayout->addWidget(dataBitsComboBox);

    // ComboBox для выбора четности
    parityComboBox = new QComboBox(this);
    parityComboBox->addItems({"No Parity", "Even Parity", "Odd Parity", "Mark Parity", "Space Parity"});
    mainLayout->addWidget(new QLabel("Parity:", this));
    mainLayout->addWidget(parityComboBox);

    // ComboBox для выбора стоп-бит
    stopBitsComboBox = new QComboBox(this);
    stopBitsComboBox->addItems({"1", "1.5", "2"});
    mainLayout->addWidget(new QLabel("Stop Bits:", this));
    mainLayout->addWidget(stopBitsComboBox);

    // ComboBox для выбора управления потоком
    flowControlComboBox = new QComboBox(this);
    flowControlComboBox->addItems({"No Flow Control", "Hardware Flow Control", "Software Flow Control"});
    mainLayout->addWidget(new QLabel("Flow Control:", this));
    mainLayout->addWidget(flowControlComboBox);

    // Кнопка для обновления списка портов
    QPushButton *refreshButton = new QPushButton("Refresh Ports", this);
    mainLayout->addWidget(refreshButton);
    connect(refreshButton, &QPushButton::clicked, this, &SerialPortSettingsWidget::updateAvailablePorts);

    // Кнопка для применения настроек
    applyButton = new QPushButton("Apply Settings", this);
    connect(applyButton, &QPushButton::clicked, this, &SerialPortSettingsWidget::applySettings);
    mainLayout->addWidget(applyButton);

    // Кнопка для подключения
    connectButton = new QPushButton("Connect", this);
    connect(connectButton, &QPushButton::clicked, this, &SerialPortSettingsWidget::connectToPort);
    mainLayout->addWidget(connectButton);

    // Кнопка для отключения
    disconnectButton = new QPushButton("Disconnect", this);
    disconnectButton->setEnabled(false);
    connect(disconnectButton, &QPushButton::clicked, this, &SerialPortSettingsWidget::disconnectFromPort);
    mainLayout->addWidget(disconnectButton);

    // Подключение сигнала об ошибке COM порта к слоту отображения диалога
    connect(this, &SerialPortSettingsWidget::comPortNotFound, this, [this]() {
        showErrorDialog("ERROR - COM порт не найден");
    });

    // Подключение слота для чтения данных из COM порта
    connect(serialPort, &QSerialPort::readyRead, this, &SerialPortSettingsWidget::readData);
}

QSerialPort* SerialPortSettingsWidget::getSerialPort() const
{
    return serialPort;
}

void SerialPortSettingsWidget::updateAvailablePorts()
{
    portComboBox->clear();
    const auto ports = QSerialPortInfo::availablePorts();
    if (ports.isEmpty()) {
        qDebug() << "No available ports found.";
        emit comPortNotFound();
    } else {
        for (const QSerialPortInfo &info : ports) {
            portComboBox->addItem(info.portName());
        }
    }
}

void SerialPortSettingsWidget::applySettings()
{
    serialPort->setPortName(portComboBox->currentText());
    serialPort->setBaudRate(baudRateComboBox->currentText().toInt());
    serialPort->setDataBits(static_cast<QSerialPort::DataBits>(dataBitsComboBox->currentText().toInt()));
    serialPort->setParity(static_cast<QSerialPort::Parity>(parityComboBox->currentIndex()));
    serialPort->setStopBits(static_cast<QSerialPort::StopBits>(stopBitsComboBox->currentIndex() + 1));
    serialPort->setFlowControl(static_cast<QSerialPort::FlowControl>(flowControlComboBox->currentIndex()));

    qDebug() << "Settings applied to serial port" << serialPort->portName();
}
void SerialPortSettingsWidget::printCurrentSettings()
{
    qDebug() << "Current settings:"
             << "\nPort Name:" << serialPort->portName()
             << "\nBaud Rate:" << serialPort->baudRate()
             << "\nData Bits:" << serialPort->dataBits()
             << "\nParity:" << serialPort->parity()
             << "\nStop Bits:" << serialPort->stopBits()
             << "\nFlow Control:" << serialPort->flowControl();
}

void SerialPortSettingsWidget::connectToPort()
{
    if (serialPort->isOpen()) {
        serialPort->close();
        qDebug() << "Serial port" << serialPort->portName() << "was already open and is now closed.";
    }

    applySettings(); // Применяем настройки перед подключением

    if (serialPort->portName().isEmpty()) {
        emit comPortNotFound();
        qDebug() << "No port name specified.";
        return;
    }

    printCurrentSettings();

    if (serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Serial port" << serialPort->portName() << "opened successfully.";
        connectButton->setEnabled(false);
        disconnectButton->setEnabled(true);
    } else {
        qCritical() << "Failed to open serial port" << serialPort->portName() << ", error:" << serialPort->errorString();
        showErrorDialog("Failed to open serial port " + serialPort->portName());
    }
}


void SerialPortSettingsWidget::disconnectFromPort()
{
    if (serialPort->isOpen()) {
        serialPort->close();
        qDebug() << "Serial port" << serialPort->portName() << "closed.";
        connectButton->setEnabled(true);
        disconnectButton->setEnabled(false);
    } else {
        qCritical() << "Serial port" << serialPort->portName() << "is not open.";
    }
}

void SerialPortSettingsWidget::showErrorDialog(const QString &message)
{
    QMessageBox::critical(this, "Error", message);
}




void SerialPortSettingsWidget::readData()
{
    if (!serialPort->isOpen()) {
        qDebug() << "Serial port is not open.";
        return;
    }

    QByteArray data = serialPort->readAll();
  //  qDebug() << "Data received from COM port:" << data;
    emit dataReceived(data);

}
