#include "modbus_test_widget.h"
#include <QVBoxLayout>
#include <QTextEdit>

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
}

void ModbusTestWidget::onReadButtonClicked()
{
    int address = addressLineEdit->text().toInt();
    int regNumber = registerLineEdit->text().toInt();
    QString regType = registerTypeComboBox->currentText();

    emit readButtonClicked(regType, address, regNumber); // Отправляем сигнал о нажатии кнопки чтения
}

void ModbusTestWidget::updateResult(const QString &result)
{
    resultLabel->setText(result);
}

void ModbusTestWidget::updateSentData(const QString &data)
{
    sentDataTextEdit->append(data);
}

void ModbusTestWidget::updateReceivedData(const QString &data)
{
    receivedDataTextEdit->append(data);
}
