#include "sensormanager.h"
#include <QList>
#include <QHostAddress>
#include <sensordeviceview.h>
#include <sensordevice.h>
#include <QVBoxLayout>

SensorManager::SensorManager(QObject *parent) : QObject(parent) {
    sensorList = QList<SensorDevice*>();
}

SensorManager::~SensorManager() {
    for(QList<SensorDevice*>::iterator it = sensorList.begin(); it != sensorList.end(); it++) {
        delete *it;
    }
    sensorList.clear();
}

void SensorManager::setDeviceLayout(QVBoxLayout *layout) {
    deviceLayout = layout;
}

void SensorManager::addDevice(QString address, qint32 port) {
    quint32 ipAddress = QHostAddress(address).toIPv4Address();
    SensorDevice* sensorDevice = new SensorDevice(ipAddress, port);
    addDevice(sensorDevice);
}

void SensorManager::addDevice(SensorDevice *sensorDevice) {
    sensorList.append(sensorDevice);
    SensorDeviceView* sensorDeviceView = new SensorDeviceView(deviceLayout->parentWidget());
    sensorDevice->setView(sensorDeviceView);
    sensorDeviceView->setAddress(QHostAddress(sensorDevice->getAddress()).toString());
    sensorDeviceView->setPort(sensorDevice->getPort());
    deviceLayout->addWidget(sensorDeviceView);
    //deviceLayout->addItem(new QSpacerItem(100,20, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

void SensorManager::updateDevice(SensorPacket packet) {
    for(QList<SensorDevice*>::iterator it = sensorList.begin(); it != sensorList.end(); it++) {
        if(((*it)->getAddress() == packet.senderAddress)) {
            (*it)->setSensorValue(packet.sensor);
            (*it)->getView()->setSensorValue(packet.sensor);
            (*it)->getView()->repaint();
            break;
        }
    }
}

void SensorManager::addDeviceSlot(QString address) {
    addDevice(address, 1026);
}
