#ifndef MODBUSRTUMASTER_H
#define MODBUSRTUMASTER_H

#include <QObject>
#include <QSerialPort>
#include <QByteArray>

class ModbusRtuMaster : public QObject
{
    Q_OBJECT

public:
    explicit ModbusRtuMaster(QSerialPort *serialPort, QObject *parent = nullptr);
   // ModbusRtuMaster(QSerialPort *serialPort);




    QVector<quint16> readHoldingRegisters(int address, int startReg, int numRegs);
    QVector<quint16> readInputRegisters(int address, int startReg, int numRegs);
    QVector<bool> readDiscreteInputs(int address, int startReg, int numRegs);
    QVector<bool> readCoils(int address, int startReg, int numRegs);

   bool waitForResponse();

    bool writeSingleHoldingRegister(quint8 slaveAddress, quint16 address, quint16 value);
    bool writeMultipleHoldingRegisters(quint8 slaveAddress, quint16 startAddress, const QVector<quint16> &values);
    bool writeSingleCoil(quint8 slaveAddress, quint16 address, bool value);
    bool writeMultipleCoils(quint8 slaveAddress, quint16 startAddress, const QVector<bool> &values);
    void sendModbusException(quint8 slaveAddress, quint8 functionCode, quint8 exceptionCode);
     quint16 calculateCRC(const QByteArray &data);

signals:
    void responseReceived(const QByteArray &response);
    void errorOccurred(const QString &error);

private slots:
    void handleReadyRead();

private:
    QSerialPort *serialPort;
    QByteArray requestData;
    QByteArray responseData;

  //  quint16 calculateCRC(const QByteArray &data);
    void sendRequest(const QByteArray &request);
};

#endif // MODBUSRTUMASTER_H
