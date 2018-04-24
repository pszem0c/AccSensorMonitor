#include "sensordevice.h"
#include "sensordeviceview.h"

SensorDevice::SensorDevice(quint32 _address, qint32 _port) {
    address = _address;
    port = _port;
    sensorValue = new qint16[4];
    sensorTransform = new quint8[4];
}

SensorDevice::~SensorDevice() {
    delete[] sensorValue;
    delete sensorDeviceView;
}

void SensorDevice::setSensorValue(qint16 *_sensorValue) {
    for (int i = 0; i < 4; i++) {
        sensorValue[i] = _sensorValue[sensorTransform[i]];
    }
}

void SensorDevice::setSensorTransform(quint8 *transform) {
    std::copy(transform, transform+4, sensorTransform);
}

void SensorDevice::setView(SensorDeviceView *view) {
    sensorDeviceView = view;
}

SensorDeviceView *SensorDevice::getView() {
    return sensorDeviceView;
}

quint8 *SensorDevice::getSensorTransform() {
    return sensorTransform;
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
