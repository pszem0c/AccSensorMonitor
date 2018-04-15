#include "sensormanager.h"
#include <QList>

SensorManager::SensorManager(QObject *parent) : QObject(parent) {
    sensorList = QList<SensorDevice*>();
}

void SensorManager::addSensor(SensorDevice *sensorDevice) {
    sensorList.append(sensorDevice);
}
