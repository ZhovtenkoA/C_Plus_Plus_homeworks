
/*

#include "mainwindow.h"
#include "serialportsettingswidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), tabWidget(new QTabWidget(this))
{
    // Create the main widget and layout
    QWidget *mainWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
    setCentralWidget(mainWidget);

    // Add the tab widget to the main layout
    mainLayout->addWidget(tabWidget);

    // Create a button to add new tabs (for demonstration purposes)
    QPushButton *addTabButton = new QPushButton("Add New Tab", this);
    connect(addTabButton, &QPushButton::clicked, this, [this]() {
        QWidget *newTab = new QWidget();
        QVBoxLayout *tabLayout = new QVBoxLayout(newTab);
        tabLayout->addWidget(new QLabel("New Tab Content"));
        tabWidget->addTab(newTab, QString("Tab %1").arg(tabWidget->count() + 1));
    });
    mainLayout->addWidget(addTabButton);

    // Example: Adding an initial tab
    QWidget *initialTab = new QWidget();
    QVBoxLayout *initialTabLayout = new QVBoxLayout(initialTab);
    initialTabLayout->addWidget(new QLabel("Initial Tab Content"));
    tabWidget->addTab(initialTab, "Initial Tab");

    // Add the serial port settings tab
    SerialPortSettingsWidget *serialPortTab = new SerialPortSettingsWidget();
    tabWidget->addTab(serialPortTab, "Serial Port Settings");

    // Add a button to simulate COM port not found error
 //   QPushButton *simulateErrorButton = new QPushButton("Simulate COM Port Error", this);
  //  connect(simulateErrorButton, &QPushButton::clicked, this, &MainWindow::showErrorComPortNotFound);
  //  mainLayout->addWidget(simulateErrorButton);
}

MainWindow::~MainWindow()
{
}

void MainWindow::showErrorComPortNotFound()
{
    QMessageBox::critical(this, "Error", "ERROR - COM порт не найден");
}
*/



#include "MainWindow.h"
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Создаем вкладку для настроек COM портов
    tabWidget = new QTabWidget(this);
    setCentralWidget(tabWidget); // Устанавливаем в центр главного окна

    // Создаем виджет для настройки COM портов
    serialPortSettingsWidget = new SerialPortSettingsWidget(this);
    tabWidget->addTab(serialPortSettingsWidget, "Настройки COM портов");

    // Создаем виджет для отображения данных
    dataDisplayWidget = new DataDisplayWidget(this);
    tabWidget->addTab(dataDisplayWidget, "Полученные данные");

    // Создаем кнопку "Настройка соединения"
    QPushButton *settingsButton = new QPushButton("Настройка соединения", this);
    connect(settingsButton, &QPushButton::clicked, this, &MainWindow::openSerialPortSettings);

    // Размещаем кнопку в верхней панели окна
    QWidget *topWidget = new QWidget(this);
    QVBoxLayout *topLayout = new QVBoxLayout(topWidget);
    topLayout->addWidget(settingsButton);
    setMenuWidget(topWidget); // Устанавливаем в верхнюю панель окна

    // Подключение сигнала от serialPortSettingsWidget к слоту для отображения данных
    connect(serialPortSettingsWidget, &SerialPortSettingsWidget::dataReceived, this, &MainWindow::displayReceivedData);
}

void MainWindow::openSerialPortSettings()
{
    tabWidget->setCurrentWidget(serialPortSettingsWidget);
}

void MainWindow::displayReceivedData(const QString &data)
{
    dataDisplayWidget->appendData(data);
}
