

#include "mainwindow.h"
#include <QApplication>
#include "ModbusRtuMaster.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
      SerialPortSettingsWidget settingsWidget;
    MainWindow w;
    w.show();



    ModbusRtuMaster modbusMaster(settingsWidget.getSerialPort());

    QObject::connect(&modbusMaster, &ModbusRtuMaster::responseReceived, [](const QByteArray &response) {
        qDebug() << "MODBUS RTU Response:" << response;
    });

    QObject::connect(&modbusMaster, &ModbusRtuMaster::errorOccurred, [](const QString &error) {
        qDebug() << "Error:" << error;
    });

    // Пример отправки запроса на чтение регистров хранения
    if (settingsWidget.getSerialPort()->isOpen()) {
        modbusMaster.readHoldingRegisters(1, 0, 10);
    }

    return a.exec();
}



/*
#include <QApplication>
#include "SerialPortSettingsWidget.h"
#include "ModbusRtuMaster.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SerialPortSettingsWidget settingsWidget;
    settingsWidget.show();

    ModbusRtuMaster modbusMaster(settingsWidget.getSerialPort());

    QObject::connect(&modbusMaster, &ModbusRtuMaster::responseReceived, [](const QByteArray &response) {
        qDebug() << "MODBUS RTU Response:" << response;
    });

    QObject::connect(&modbusMaster, &ModbusRtuMaster::errorOccurred, [](const QString &error) {
        qDebug() << "Error:" << error;
    });

    // Пример отправки запроса на чтение регистров хранения
    if (settingsWidget.getSerialPort()->isOpen()) {
        modbusMaster.readHoldingRegisters(1, 0, 10);
    }

    return app.exec();
}
*/
