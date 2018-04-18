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

void SensorManager::updateDevice(SensorPacket packet) {
    for(QList<SensorDevice*>::iterator it = sensorList.begin(); it != sensorList.end(); it++) {
        if(((*it)->getAddress() == packet.senderAddress)) {
            (*it)->setSensorValue(packet.sensor);
            (*it)->getView()->setSensorValue((*it)->getSensorValue());
            (*it)->getView()->repaint();
        }
    }
}

void SensorManager::addDeviceSlot(QString address, quint8 *transform) {
    addDevice(address, 1026, transform);
}

void SensorManager::removeDevice(SensorDeviceView *sensorDeviceView) {
    for(QList<SensorDevice*>::iterator it = sensorList.begin(); it != sensorList.end(); it++) {
        if((*it)->getView() == sensorDeviceView) {
            (*it)->getView()->setVisible(false);
        }
    }
}
