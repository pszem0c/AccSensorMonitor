#ifndef SENSORDEVICE_H
#define SENSORDEVICE_H

#include <QtGlobal>

class SensorDeviceView;

class SensorDevice {
private:
    qint16*     sensorValue;
    quint8*     sensorTransform;
    quint32     address;
    qint32      port;
    SensorDeviceView* sensorDeviceView;

public:
    SensorDevice(quint32 _address, qint32 _port);
    ~SensorDevice();

    void setSensorValue(qint16* _sensorValue);
    void setSensorTransform(quint8* transform);
    void setView(SensorDeviceView* view);
    SensorDeviceView* getView();
    quint8* getSensorTransform();
    qint16* getSensorValue();
    quint32 getAddress();
    qint32  getPort();

};

#endif // SENSORDEVICE_H
