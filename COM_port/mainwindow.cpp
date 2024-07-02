#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    serialPort(new QSerialPort(this)),
    modbusRtuMaster(new ModbusRtuMaster(serialPort, this))
{
    ui->setupUi(this);

    // Создаем вкладку для разных функциональностей
    tabWidget = new QTabWidget(this);
    setCentralWidget(tabWidget);

    // Виджет настроек последовательного порта
    serialPortSettingsWidget = new SerialPortSettingsWidget(this);
    tabWidget->addTab(serialPortSettingsWidget, "Настройки последовательного порта");

    // Виджет теста MODBUS
    modbusTestWidget = new ModbusTestWidget(serialPort, this);
    tabWidget->addTab(modbusTestWidget, "Тест MODBUS");

    // Виджет отображения данных
    dataDisplayWidget = new DataDisplayWidget(this);
    tabWidget->addTab(dataDisplayWidget, "Отображение данных");

    // Подключаем сигнал нажатия кнопки чтения в ModbusTestWidget к слоту MainWindow
    connect(modbusTestWidget, &ModbusTestWidget::readButtonClicked,
            this, &MainWindow::onReadButtonClicked);

    // Подключаем сигнал получения данных к слоту отображения данных
    connect(serialPortSettingsWidget, &SerialPortSettingsWidget::dataReceived,
            dataDisplayWidget, &DataDisplayWidget::appendData);

    // Создаем и настраиваем кнопку настроек
    QPushButton *settingsButton = new QPushButton("Настройки соединения", this);
    connect(settingsButton, &QPushButton::clicked, this, &MainWindow::openSerialPortSettings);

    // Размещаем кнопку настроек в верхней панели окна
    QWidget *topWidget = new QWidget(this);
    QVBoxLayout *topLayout = new QVBoxLayout(topWidget);
    topLayout->addWidget(settingsButton);
    setMenuWidget(topWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onReadButtonClicked(const QString &regType, int address, int regNumber)
{
    QVector<quint16> result16;
    QVector<bool> resultBool;

    if (regType == "Holding Registers") {
        result16 = modbusRtuMaster->readHoldingRegisters(address, regNumber, 1);
    } else if (regType == "Input Registers") {
        result16 = modbusRtuMaster->readInputRegisters(address, regNumber, 1);
    } else if (regType == "Discrete Inputs") {
        resultBool = modbusRtuMaster->readDiscreteInputs(address, regNumber, 1);
    } else if (regType == "Coils") {
        resultBool = modbusRtuMaster->readCoils(address, regNumber, 1);
    }

    if (!result16.isEmpty()) {
        modbusTestWidget->updateResult(QString::number(result16[0]));
        emit dataReceived(QString::number(result16[0]));
    } else if (!resultBool.isEmpty()) {
        modbusTestWidget->updateResult(resultBool[0] ? "True" : "False");
        emit dataReceived(resultBool[0] ? "True" : "False");
    } else {
        modbusTestWidget->updateResult("Ошибка чтения");
        emit dataReceived("Ошибка чтения");
    }
}

void MainWindow::openSerialPortSettings()
{
    tabWidget->setCurrentWidget(serialPortSettingsWidget);
}

void MainWindow::handleReadyRead()
{
    if (serialPort->isOpen()) {
        QByteArray data = serialPort->readAll();
        QString dataStr = QString::fromUtf8(data);
        qDebug() << "Data received from COM port:" << dataStr;  // Диагностика для проверки входящих данных
        emit dataReceived(dataStr);
    } else {
        qDebug() << "Serial port is not open.";
    }
}
