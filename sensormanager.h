#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include <QList>
#include <QString>
#include "sensorpacket.h"

class SensorDevice;
class QVBoxLayout;
class SensorDeviceView;

class SensorManager : public QObject {
    Q_OBJECT
private:
    QList<SensorDevice*> sensorList;
    QVBoxLayout* deviceLayout;


public:
    explicit SensorManager(QObject *parent = nullptr);
    ~SensorManager();

    void setDeviceLayout(QVBoxLayout* layout);
    void addDevice(QString address, qint32 port);
    void addDevice(SensorDevice* sensorDevice);


signals:

public slots:
    void updateDevice(SensorPacket packet);
    void addDeviceSlot(QString address);
    void removeDevice(SensorDeviceView* sensorDeviceView);
};

#endif // SENSORMANAGER_H
