#include "sensordevice.h"

SensorDevice::SensorDevice(quint32 _address, qint32 _port) {
    address = _address;
    port = _port;
    sensorValue = new qint16[32];

}

SensorDevice::~SensorDevice() {
    delete[] sensorValue;
    delete sensorDeviceView;
}

void SensorDevice::setSensorValue(qint16 *_sensorValue) {
    std::copy(_sensorValue, _sensorValue+32, sensorValue);
}

void SensorDevice::setView(SensorDeviceView *view) {
    sensorDeviceView = view;
}

SensorDeviceView *SensorDevice::getView() {
    return sensorDeviceView;
}

qint16 *SensorDevice::getSensorValue() {
    return sensorValue;
}

quint32 SensorDevice::getAddress() {
    return address;
}

qint32 SensorDevice::getPort() {
    return port;
}
