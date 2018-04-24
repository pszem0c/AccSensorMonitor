#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class SensorManager;
class UdpSocketListener;
class UdpPacketParser;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addDeviceButton_clicked();

    void on_saveConfigurationButton_clicked();

    void on_loadConfigurationButton_clicked();

private:
    Ui::MainWindow*     ui;
    SensorManager* sensorManager;
    UdpSocketListener* udpSocketListener;
    UdpPacketParser* udpPacketParser;
    qint64 windowHeight;
    qint64 windowWidth;

};

#endif // MAINWINDOW_H
