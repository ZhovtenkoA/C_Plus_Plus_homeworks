#include "modbus_test_widget.h"
#include "modbusrtumaster.h" // Подключаем заголовочный файл, где реализована функция calculateCRC
#include <QVBoxLayout>
#include <QTextEdit>
#include <QDataStream>
#include <QDebug>

ModbusTestWidget::ModbusTestWidget(QSerialPort *serialPort, QWidget *parent)
    : QWidget(parent), serialPort(serialPort)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    addressLineEdit = new QLineEdit(this);
    addressLineEdit->setPlaceholderText("Введите адрес");
    layout->addWidget(addressLineEdit);

    registerLineEdit = new QLineEdit(this);
    registerLineEdit->setPlaceholderText("Введите номер регистра");
    layout->addWidget(registerLineEdit);

    registerTypeComboBox = new QComboBox(this);
    registerTypeComboBox->addItem("Holding Registers");
    registerTypeComboBox->addItem("Input Registers");
    registerTypeComboBox->addItem("Discrete Inputs");
    registerTypeComboBox->addItem("Coils");
    layout->addWidget(registerTypeComboBox);

    readButton = new QPushButton("Читать", this);
    layout->addWidget(readButton);

    resultLabel = new QLabel(this);
    layout->addWidget(resultLabel);

    sentDataTextEdit = new QTextEdit(this);
    sentDataTextEdit->setReadOnly(true);
    sentDataTextEdit->setPlaceholderText("Отправленные данные");
    layout->addWidget(sentDataTextEdit);

    receivedDataTextEdit = new QTextEdit(this);
    receivedDataTextEdit->setReadOnly(true);
    receivedDataTextEdit->setPlaceholderText("Принятые данные");
    layout->addWidget(receivedDataTextEdit);

    connect(readButton, &QPushButton::clicked, this, &ModbusTestWidget::onReadButtonClicked);
    connect(this, &ModbusTestWidget::readButtonClicked, this, &ModbusTestWidget::handleReadRequest); // Подключение сигнала к слоту
}

void ModbusTestWidget::onReadButtonClicked()
{
    int address = addressLineEdit->text().toInt();
    int regNumber = registerLineEdit->text().toInt();
    QString regType = registerTypeComboBox->currentText();

    emit readButtonClicked(regType, address, regNumber); // Отправляем сигнал о нажатии кнопки чтения
}

QByteArray ModbusTestWidget::createModbusRequest(const QString &regType, int address, int regNumber)
{
    QByteArray request;
    QDataStream stream(&request, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::BigEndian);

    uint8_t functionCode;
    uint16_t startAddress = static_cast<uint16_t>(regNumber);
    uint16_t quantity = 1; // количество регистров для чтения, можно изменить при необходимости

    // Определяем функцию Modbus в зависимости от типа регистра
    if (regType == "Holding Registers") {
        functionCode = 0x03; // Чтение удерживаемых регистров
    } else if (regType == "Input Registers") {
        functionCode = 0x04; // Чтение входных регистров
    } else if (regType == "Discrete Inputs") {
        functionCode = 0x02; // Чтение дискретных входов
    } else if (regType == "Coils") {
        functionCode = 0x01; // Чтение катушек
    } else {
        return request; // Возвращаем пустой запрос, если тип регистра не поддерживается
    }

    // Формируем запрос Modbus
    stream << static_cast<uint8_t>(address);  // Адрес устройства
    stream << functionCode;                   // Функция Modbus
    stream << startAddress;                   // Номер начального регистра
    stream << quantity;                       // Количество регистров

    // Вычисляем CRC с использованием функции из ModbusRtuMaster
    ModbusRtuMaster modbusMaster(serialPort); // Создаём объект ModbusRtuMaster с передачей serialPort
    uint16_t crc = modbusMaster.calculateCRC(request);
    stream << crc; // Добавляем CRC в конец запроса

    return request;
}

void ModbusTestWidget::handleReadRequest(const QString &regType, int address, int regNumber)
{
    qDebug() << "Handling read request. Type:" << regType << ", Address:" << address << ", Register:" << regNumber;

    QByteArray requestData = createModbusRequest(regType, address, regNumber);

    if (serialPort->isOpen()) {
        qDebug() << "Serial port is open. Sending request.";
        serialPort->write(requestData);
        updateSentData(requestData.toHex());

        if (serialPort->waitForReadyRead(1000)) { // Ожидание данных 1 секунду
            QByteArray responseData = serialPort->readAll();
            qDebug() << "Response received:" << responseData.toHex();
            updateReceivedData(responseData.toHex());

            // Обновление результата
            QString result = "Прочитанные данные: " + responseData.toHex();
            updateResult(result);
        } else {
            qDebug() << "No response received.";
            updateResult("No response received.");
        }
    } else {
        qDebug() << "Serial port is not open.";
        updateResult("Serial port is not open.");
    }
}

/*
void ModbusTestWidget::updateResult(const QString &result)
{
    resultLabel->setText(result);
}
*/

void ModbusTestWidget::updateResult(const QString &result)
{
    // Пример: обновление текстовой метки для отображения результата
    resultLabel->setText(result);

    // Пример: запись результата в лог
    qDebug() << "Result:" << result;

    // Пример: отправка сигнала о том, что результат обновлен
   // emit resultUpdated(result);
}

void ModbusTestWidget::updateSentData(const QString &data)
{
    sentDataTextEdit->append(data);
}

void ModbusTestWidget::updateReceivedData(const QString &data)
{
    receivedDataTextEdit->append(data);
}
