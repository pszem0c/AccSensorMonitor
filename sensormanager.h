#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include <QList>
class SensorDevice;

class SensorManager : public QObject {
    Q_OBJECT
private:
    QList<SensorDevice*> sensorList;

public:
    explicit SensorManager(QObject *parent = nullptr);

    void addSensor(SensorDevice* sensorDevice);

signals:

public slots:
};

#endif // SENSORMANAGER_H
