#include "ModbusRtuMaster.h"
#include <QDebug>
#include <QDataStream>
#include <QEventLoop>
#include <QTimer>

ModbusRtuMaster::ModbusRtuMaster(QSerialPort *serialPort, QObject *parent)
    : QObject(parent), serialPort(serialPort)
{
    connect(serialPort, &QSerialPort::readyRead, this, &ModbusRtuMaster::handleReadyRead);
}





QVector<quint16> ModbusRtuMaster::readHoldingRegisters(int address, int startReg, int numRegs)
{
    QVector<quint16> result;

    if (!serialPort->isOpen()) {
        qWarning() << "Serial port is not open!";
        return result;
    }

    // Формируем запрос на чтение регистров хранения
    QByteArray request;
    QDataStream stream(&request, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::BigEndian);

    stream << quint8(address);              // Адрес устройства
    stream << quint8(0x03);                 // Код функции для чтения регистров хранения
    stream << quint16(startReg);            // Начальный регистр для чтения
    stream << quint16(numRegs);             // Количество регистров для чтения

    quint16 crc = calculateCRC(request);    // Вычисляем CRC
    stream << crc;

    sendRequest(request);                   // Отправляем запрос

    // Ожидаем ответ
    if (!waitForResponse()) {
        qWarning() << "Timeout waiting for response!";
        return result;
                          }

    // Получаем ответ
    QByteArray responseData = serialPort->readAll();

    // Проверяем длину ответа
    if (responseData.size() < 5 + 2 * numRegs) {
        qWarning() << "Invalid response length!";
        return result;
    }

    // Проверяем CRC ответа
    if (!calculateCRC(responseData)) {
        qWarning() << "CRC check failed!";
        return result;
    }

    // Извлекаем данные из ответа
    QDataStream responseStream(responseData);
    responseStream.setByteOrder(QDataStream::BigEndian);

    quint8 slaveAddress;
    quint8 functionCode;
    responseStream >> slaveAddress;
    responseStream >> functionCode;

    if (functionCode == 0x03) {
        quint8 byteCount;
        responseStream >> byteCount;

        for (int i = 0; i < byteCount / 2; ++i) {
            quint16 regValue;
            responseStream >> regValue;
            result.append(regValue);
        }
    } else {
        qWarning() << "Unexpected function code in response!";
    }

    return result;
}

QVector<quint16> ModbusRtuMaster::readInputRegisters(int address, int startReg, int numRegs)
{
    QVector<quint16> result;

    if (!serialPort->isOpen()) {
        qWarning() << "Serial port is not open!";
        return result;
    }

    // Формируем запрос на чтение регистров ввода
    QByteArray request;
    QDataStream stream(&request, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::BigEndian);

    stream << quint8(address);              // Адрес устройства
    stream << quint8(0x04);                 // Код функции для чтения регистров ввода
    stream << quint16(startReg);            // Начальный регистр для чтения
    stream << quint16(numRegs);             // Количество регистров для чтения

    quint16 crc = calculateCRC(request);    // Вычисляем CRC
    stream << crc;

    sendRequest(request);                   // Отправляем запрос

    // Ожидаем ответ
    if (!waitForResponse()) {
        qWarning() << "Timeout waiting for response!";
        return result;
    }

    // Получаем ответ
    QByteArray responseData = serialPort->readAll();

    // Проверяем длину ответа
    if (responseData.size() < 5 + 2 * numRegs) {
        qWarning() << "Invalid response length!";
        return result;
    }

    // Проверяем CRC ответа
    if (!calculateCRC(responseData)) {
        qWarning() << "CRC check failed!";
        return result;
    }

    // Извлекаем данные из ответа
    QDataStream responseStream(responseData);
    responseStream.setByteOrder(QDataStream::BigEndian);

    quint8 slaveAddress;
    quint8 functionCode;
    responseStream >> slaveAddress;
    responseStream >> functionCode;

    if (functionCode == 0x04) {
        quint8 byteCount;
        responseStream >> byteCount;

        for (int i = 0; i < byteCount / 2; ++i) {
            quint16 regValue;
            responseStream >> regValue;
            result.append(regValue);
        }
    } else {
        qWarning() << "Unexpected function code in response!";
    }

    return result;
}


QVector<bool> ModbusRtuMaster::readCoils(int address, int startReg, int numRegs)
{
    QVector<bool> result;

    if (!serialPort->isOpen()) {
        qWarning() << "Serial port is not open!";
        return result;
    }

    // Формируем запрос на чтение катушек
    QByteArray request;
    QDataStream stream(&request, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::BigEndian);

    stream << quint8(address);              // Адрес устройства
    stream << quint8(0x01);                 // Код функции для чтения катушек
    stream << quint16(startReg);            // Начальный регистр для чтения
    stream << quint16(numRegs);             // Количество катушек для чтения

    quint16 crc = calculateCRC(request);    // Вычисляем CRC
    stream << crc;

    sendRequest(request);                   // Отправляем запрос

    // Ожидаем ответ
      if (!waitForResponse()) {
        qWarning() << "Timeout waiting for response!";
          return result;
                               }

    // Получаем ответ
    QByteArray responseData = serialPort->readAll();

    // Проверяем длину ответа
    if (responseData.size() < 5 + numRegs / 8 + 1) {
        qWarning() << "Invalid response length!";
        return result;
    }

    // Проверяем CRC ответа
    if (!calculateCRC(responseData)) {
        qWarning() << "CRC check failed!";
        return result;
    }

    // Извлекаем данные из ответа
    QDataStream responseStream(responseData);
    responseStream.setByteOrder(QDataStream::BigEndian);

    quint8 slaveAddress;
    quint8 functionCode;
    responseStream >> slaveAddress;
    responseStream >> functionCode;

    if (functionCode == 0x01) {
        quint8 byteCount;
        responseStream >> byteCount;

        QByteArray coilData;
        responseStream.readRawData(coilData.data(), byteCount);

        for (int i = 0; i < numRegs; ++i) {
            if (coilData.at(i / 8) & (1 << (i % 8))) {
                result.append(true);
            } else {
                result.append(false);
            }
        }
    } else {
        qWarning() << "Unexpected function code in response!";
    }

    return result;
}

QVector<bool> ModbusRtuMaster::readDiscreteInputs(int address, int startReg, int numRegs)
{
    QVector<bool> result;

    if (!serialPort->isOpen()) {
        qWarning() << "Serial port is not open!";
        return result;
    }

    // Формируем запрос на чтение дискретных входов
    QByteArray request;
    QDataStream stream(&request, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::BigEndian);

    stream << quint8(address);              // Адрес устройства
    stream << quint8(0x02);                 // Код функции для чтения дискретных входов
    stream << quint16(startReg);            // Начальный регистр для чтения
    stream << quint16(numRegs);             // Количество дискретных входов для чтения

    quint16 crc = calculateCRC(request);    // Вычисляем CRC
    stream << crc;

    sendRequest(request);                   // Отправляем запрос

    // Ожидаем ответ
    if (!waitForResponse()) {
        qWarning() << "Timeout waiting for response!";
        return result;
    }

    // Получаем ответ
    QByteArray responseData = serialPort->readAll();

    // Проверяем длину ответа
    if (responseData.size() < 5 + (numRegs + 7) / 8) {
        qWarning() << "Invalid response length!";
        return result;
    }

    // Проверяем CRC ответа
    if (!calculateCRC(responseData)) {
        qWarning() << "CRC check failed!";
        return result;
    }

    // Извлекаем данные из ответа
    QDataStream responseStream(responseData);
    responseStream.setByteOrder(QDataStream::BigEndian);

    quint8 slaveAddress;
    quint8 functionCode;
    quint8 byteCount;

    responseStream >> slaveAddress;
    responseStream >> functionCode;
    responseStream >> byteCount;

    quint8 byte = 0; // Инициализируем переменную byte значением по умолчанию
    for (int i = 0; i < numRegs; ++i) {
        if (i % 8 == 0) {
            responseStream >> byte;
        }
        bool value = byte & (1 << (i % 8));
        result.append(value);
    }

    return result;
}
/*
QVector<bool> ModbusRtuMaster::readDiscreteInputs(int address, int startReg, int numRegs)
{
    QVector<bool> result;

    if (!serialPort->isOpen()) {
        qWarning() << "Serial port is not open!";
        return result;
    }

    // Формируем запрос на чтение дискретных входов
    QByteArray request;
    QDataStream stream(&request, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::BigEndian);

    stream << quint8(address);              // Адрес устройства
    stream << quint8(0x02);                 // Код функции для чтения дискретных входов
    stream << quint16(startReg);            // Начальный регистр для чтения
    stream << quint16(numRegs);             // Количество дискретных входов для чтения

    quint16 crc = calculateCRC(request);    // Вычисляем CRC
    stream << crc;

    sendRequest(request);                   // Отправляем запрос

    // Ожидаем ответ
    if (!waitForResponse()) {
        qWarning() << "Timeout waiting for response!";
        return result;
    }

    // Получаем ответ
    QByteArray responseData = serialPort->readAll();

    // Проверяем длину ответа
    if (responseData.size() < 5 + (numRegs + 7) / 8) {
        qWarning() << "Invalid response length!";
        return result;
    }

    // Проверяем CRC ответа
    if (!calculateCRC(responseData)) {
        qWarning() << "CRC check failed!";
        return result;
    }

    // Извлекаем данные из ответа
    QDataStream responseStream(responseData);
    responseStream.setByteOrder(QDataStream::BigEndian);

    quint8 slaveAddress;
    quint8 functionCode;
    quint8 byteCount;

    responseStream >> slaveAddress;
    responseStream >> functionCode;
    responseStream >> byteCount;

    for (int i = 0; i < numRegs; ++i) {
        quint8 byte;
        if (i % 8 == 0) {
            responseStream >> byte;
        }
        bool value = byte & (1 << (i % 8));
        result.append(value);
    }

    return result;
}
*/
/*
QVector<bool> ModbusRtuMaster::readDiscreteInputs(int address, int startReg, int numRegs)
{
    QVector<bool> result;

    if (!serialPort->isOpen()) {
        qWarning() << "Serial port is not open!";
        return result;
    }

    // Формируем запрос на чтение дискретных входов
    QByteArray request;
    QDataStream stream(&request, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::BigEndian);

    stream << quint8(address);              // Адрес устройства
    stream << quint8(0x02);                 // Код функции для чтения дискретных входов
    stream << quint16(startReg);            // Начальный регистр для чтения
    stream << quint16(numRegs);             // Количество дискретных входов для чтения

    quint16 crc = calculateCRC(request);    // Вычисляем CRC
    stream << crc;

    sendRequest(request);                   // Отправляем запрос

    // Ожидаем ответ
    if (!waitForResponse()) {
        qWarning() << "Timeout waiting for response!";
        return result;
    }

    // Получаем ответ
    QByteArray responseData = serialPort->readAll();

    // Проверяем длину ответа
    if (responseData.size() < 5 + numRegs / 8 + 1) {
        qWarning() << "Invalid response length!";
        return result;
    }

    // Проверяем CRC ответа
    if (!calculateCRC(responseData)) {
        qWarning() << "CRC check failed!";
        return result;
    }

    // Извлекаем данные из ответа
    QDataStream responseStream(responseData);
    responseStream.setByteOrder(QDataStream::BigEndian);

    quint8 slaveAddress;
    quint8 functionCode;
    responseStream >> slaveAddress;
    responseStream >> functionCode;

    if (functionCode == 0x02) {
        quint8 byteCount;
        responseStream >> byteCount;

        QByteArray inputData;
        responseStream.readRawData(inputData.data(), byteCount);

        for (int i = 0; i < numRegs; ++i) {
            if (inputData.at(i / 8) & (1 << (i % 8))) {
                result.append(true);
            } else {
                result.append(false);
            }
        }
    } else {
        qWarning() << "Unexpected function code in response!";
    }

    return result;
}

*/



bool ModbusRtuMaster::writeSingleHoldingRegister(quint8 slaveAddress, quint16 address, quint16 value)
{
    QByteArray request;
    QDataStream stream(&request, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::BigEndian);

    stream << slaveAddress;
    stream << quint8(0x06); // Function code for Write Single Holding Register
    stream << address;
    stream << value;

    quint16 crc = calculateCRC(request);
    stream << crc;

    sendRequest(request);
    return true;
}

bool ModbusRtuMaster::writeMultipleHoldingRegisters(quint8 slaveAddress, quint16 startAddress, const QVector<quint16> &values)
{
    QByteArray request;
    QDataStream stream(&request, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::BigEndian);

    stream << slaveAddress;
    stream << quint8(0x10); // Function code for Write Multiple Holding Registers
    stream << startAddress;
    stream << quint16(values.size()); // Number of registers
    stream << quint8(values.size() * 2); // Byte count

    for (quint16 value : values) {
        stream << value;
    }

    quint16 crc = calculateCRC(request);
    stream << crc;

    sendRequest(request);
    return true;
}

bool ModbusRtuMaster::writeSingleCoil(quint8 slaveAddress, quint16 address, bool value)
{
    QByteArray request;
    QDataStream stream(&request, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::BigEndian);

    stream << slaveAddress;
    stream << quint8(0x05); // Function code for Write Single Coil
    stream << address;
    stream << quint16(value ? 0xFF00 : 0x0000); // ON or OFF

    quint16 crc = calculateCRC(request);
    stream << crc;

    sendRequest(request);
    return true;
}

bool ModbusRtuMaster::writeMultipleCoils(quint8 slaveAddress, quint16 startAddress, const QVector<bool> &values)
{
    QByteArray request;
    QDataStream stream(&request, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::BigEndian);

    stream << slaveAddress;
    stream << quint8(0x0F); // Function code for Write Multiple Coils
    stream << startAddress;
    stream << quint16(values.size()); // Number of coils

    QByteArray coilData;
    quint8 currentByte = 0;
    int bitCount = 0;

    for (bool value : values) {
        if (value) {
            currentByte |= (1 << bitCount);
        }
        bitCount++;
        if (bitCount == 8) {
            coilData.append(currentByte);
            currentByte = 0;
            bitCount = 0;
        }
    }

    if (bitCount > 0) {
        coilData.append(currentByte);
    }

    stream << quint8(coilData.size()); // Byte count
    request.append(coilData);

    quint16 crc = calculateCRC(request);
    stream << crc;

    sendRequest(request);
    return true;
}

void ModbusRtuMaster::sendModbusException(quint8 slaveAddress, quint8 functionCode, quint8 exceptionCode)
{
    QByteArray response;
    QDataStream stream(&response, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::BigEndian);

    stream << slaveAddress;
    stream << quint8(functionCode | 0x80); // Exception response
    stream << exceptionCode;

    quint16 crc = calculateCRC(response);
    stream << crc;

    serialPort->write(response);
}

void ModbusRtuMaster::handleReadyRead()
{
    responseData.append(serialPort->readAll());

    // Here you can add code to parse the responseData according to MODBUS RTU protocol
    // and emit responseReceived signal if a complete response is received.
    // For simplicity, we assume the response is complete and emit the signal directly.

    if (!responseData.isEmpty()) {
        emit responseReceived(responseData);
        responseData.clear();
    }
}

quint16 ModbusRtuMaster::calculateCRC(const QByteArray &data)
{
    quint16 crc = 0xFFFF;

    for (int pos = 0; pos < data.size(); pos++) {
        crc ^= (quint8)data[pos];

        for (int i = 8; i != 0; i--) {
            if ((crc & 0x0001) != 0) {
                crc >>= 1;
                crc ^= 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }

    return crc;
}

void ModbusRtuMaster::sendRequest(const QByteArray &request)
{
    if (serialPort->write(request) == -1) {
        emit errorOccurred("Failed to write request to serial port");
    }
}

bool ModbusRtuMaster::waitForResponse()
{
    const int timeout = 3000; // Таймаут в миллисекундах (здесь 3 секунды)
    QTimer timer;
    QEventLoop loop;
    bool responseReceived = false;

    // Устанавливаем таймер для таймаута
    connect(&timer, &QTimer::timeout, &loop, [&responseReceived, &loop]() {
        responseReceived = false;
        loop.quit();
    });
    timer.start(timeout);

    // Ожидаем сигнала о приеме ответа
    connect(this, &ModbusRtuMaster::responseReceived, &loop, [&responseReceived, &timer, &loop]() {
        responseReceived = true;
        timer.stop();
        loop.quit();
    });

    // Ожидаем завершения цикла обработки событий
    loop.exec();

    return responseReceived;
}
