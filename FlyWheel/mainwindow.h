#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QTabWidget>
#include "modbus_test_widget.h"
#include "SerialPortSettingsWidget.h"
#include "ModbusRtuMaster.h"
#include "DataDisplayWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onReadButtonClicked(const QString &regType, int address, int regNumber);
    void openSerialPortSettings();
    void handleReadyRead();  // Новый слот для обработки данных из COM-порта

signals:
    void dataReceived(const QString &data);

private:
    Ui::MainWindow *ui;
    QTabWidget *tabWidget;
    SerialPortSettingsWidget *serialPortSettingsWidget;
    ModbusTestWidget *modbusTestWidget;
    DataDisplayWidget *dataDisplayWidget;
    QSerialPort *serialPort;
    ModbusRtuMaster *modbusRtuMaster;
};

#endif // MAINWINDOW_H
