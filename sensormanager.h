#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include <QList>
#include <QString>
#include "sensorpacket.h"

class SensorDevice;
class QHBoxLayout;
class SensorDeviceView;

class SensorManager : public QObject {
    Q_OBJECT
private:
    QList<SensorDevice*> sensorList;
    QHBoxLayout* deviceLayout;


public:
    explicit SensorManager(QObject *parent = nullptr);
    ~SensorManager();

    void setDeviceLayout(QHBoxLayout* layout);
    void addDevice(QString address, qint32 port, quint8* transform);
    void addDevice(SensorDevice* sensorDevice);
    void addDevices(QList<SensorDevice*> list);
    QList<SensorDevice*> getSensorList();

signals:

public slots:
    void updateDevice(SensorPacket packet);
    void addDeviceSlot(QString address, quint8* transform);
    void removeDevice(SensorDeviceView* sensorDeviceView);
};

#endif // SENSORMANAGER_H
