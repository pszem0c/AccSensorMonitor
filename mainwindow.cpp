#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>
#include <QDebug>
#include <QFileDialog>
#include <QList>
#include <QDateTime>

#include "sensormanager.h"
#include "udpsocketlistener.h"
#include "udppacketparser.h"
#include "createdevicedialog.h"
#include "sensorconfigurationmanager.h"
#include "sensorlogger.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    showMaximized();
    windowHeight = this->size().height();
    windowWidth = this->size().width();

    sensorManager = new SensorManager;
    ui->deviceLayout->setAlignment(Qt::AlignLeft);
    sensorManager->setDeviceLayout(ui->deviceLayout);

    sensorLogger = new SensorLogger;
    sensorLogger->openLog(QDateTime::currentDateTime().toString("ddMMyy-HHMM") + ".log");

    udpSocketListener = new UdpSocketListener;
    udpPacketParser = new UdpPacketParser;



    connect(udpSocketListener, SIGNAL(dataReceived(UdpPacket)), udpPacketParser, SLOT(parseData(UdpPacket)));
    connect(udpPacketParser, SIGNAL(dataParsed(SensorPacket)), sensorManager, SLOT(updateDevice(SensorPacket)));
    connect(sensorManager, SIGNAL(deviceUpdated(QList<SensorDevice*>)), sensorLogger, SLOT(writeToLogSlot(QList<SensorDevice*>)));
}

MainWindow::~MainWindow() {
    delete sensorManager;
    delete udpSocketListener;
    delete udpPacketParser;
    delete ui;
}

void MainWindow::on_addDeviceButton_clicked() {
    //sensorManager->addDevice("192.168.0.102", 1026);
    CreateDeviceDialog* deviceDialog = new CreateDeviceDialog(this);
    connect(deviceDialog, SIGNAL(createDevice(QString,quint8*)), sensorManager, SLOT(addDeviceSlot(QString,quint8*)));
    deviceDialog->exec();

}

void MainWindow::on_saveConfigurationButton_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Zapisz konfigurację"));
    SensorConfigurationManager::saveConfiguration(fileName, sensorManager->getSensorList());
}

void MainWindow::on_loadConfigurationButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Wczytaj konfigurację"));
    sensorManager->addDevices(SensorConfigurationManager::loadConfiguration(fileName));
}
