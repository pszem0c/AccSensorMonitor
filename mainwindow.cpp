#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>
#include <QDebug>

#include "sensormanager.h"
#include "udpsocketlistener.h"
#include "udppacketparser.h"
#include "createdevicedialog.h"


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

    udpSocketListener = new UdpSocketListener;
    udpPacketParser = new UdpPacketParser;

    connect(udpSocketListener, SIGNAL(dataReceived(UdpPacket)), udpPacketParser, SLOT(parseData(UdpPacket)));
    connect(udpPacketParser, SIGNAL(dataParsed(SensorPacket)), sensorManager, SLOT(updateDevice(SensorPacket)));
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
