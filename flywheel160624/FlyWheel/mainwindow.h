
/*
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showErrorComPortNotFound();

private:
    QTabWidget *tabWidget;
};

#endif // MAINWINDOW_H

*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include "SerialPortSettingsWidget.h"
#include "DataDisplayWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void openSerialPortSettings();
    void displayReceivedData(const QString &data);

private:
    QTabWidget *tabWidget;
    SerialPortSettingsWidget *serialPortSettingsWidget;
    DataDisplayWidget *dataDisplayWidget;
};

#endif // MAINWINDOW_H
