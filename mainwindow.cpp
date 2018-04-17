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
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollAreaWidgetContents->setLayout(new QVBoxLayout(ui->scrollAreaWidgetContents));
    ui->scrollAreaWidgetContents->layout()->setAlignment(Qt::AlignTop);
    sensorManager->setDeviceLayout((QVBoxLayout*)ui->scrollAreaWidgetContents->layout());

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
    connect(deviceDialog, SIGNAL(createDevice(QString)), sensorManager, SLOT(addDeviceSlot(QString)));
    deviceDialog->exec();

}
