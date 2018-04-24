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

void SensorManager::setDeviceLayout(QHBoxLayout *layout) {
    deviceLayout = layout;
}

void SensorManager::addDevice(QString address, qint32 port, quint8* transform) {
    quint32 ipAddress = QHostAddress(address).toIPv4Address();
    SensorDevice* sensorDevice = new SensorDevice(ipAddress, port);
    sensorDevice->setSensorTransform(transform);
    delete transform;
    addDevice(sensorDevice);
}

void SensorManager::addDevice(SensorDevice *sensorDevice) {
    sensorList.append(sensorDevice);
    SensorDeviceView* sensorDeviceView = new SensorDeviceView();
    connect(sensorDeviceView, SIGNAL(removeDevice(SensorDeviceView*)), this, SLOT(removeDevice(SensorDeviceView*)));
    sensorDevice->setView(sensorDeviceView);
    sensorDeviceView->setAddress(QHostAddress(sensorDevice->getAddress()).toString());
    sensorDeviceView->setPort(sensorDevice->getPort());
    deviceLayout->addWidget(sensorDeviceView);

}

void SensorManager::addDevices(QList<SensorDevice *> list) {
    for (QList<SensorDevice*>::iterator it = list.begin(); it != list.end(); it++) {
        addDevice(*it);
    }
}

QList<SensorDevice *> SensorManager::getSensorList() {
    return sensorList;
}

void SensorManager::updateDevice(SensorPacket packet) {
    for(QList<SensorDevice*>::iterator it = sensorList.begin(); it != sensorList.end(); it++) {
        if(((*it)->getAddress() == packet.senderAddress)) {
            (*it)->setSensorValue(packet.sensor);
            (*it)->getView()->setSensorValue((*it)->getSensorValue());
            (*it)->getView()->repaint();
        }
    }
    emit deviceUpdated(sensorList);
}

void SensorManager::addDeviceSlot(QString address, quint8 *transform) {
    addDevice(address, 1026, transform);
}

void SensorManager::removeDevice(SensorDeviceView *sensorDeviceView) {

}
