#ifndef SENSORCONFIGURATIONMANAGER_H
#define SENSORCONFIGURATIONMANAGER_H

#include <QString>
#include <QList>

class SensorDevice;

class SensorConfigurationManager {
private:
    SensorConfigurationManager();

public:
    static void saveConfiguration(QString fileName, QList<SensorDevice*> sensorList);
    static QList<SensorDevice*> loadConfiguration(QString fileName);
};

#endif // SENSORCONFIGURATIONMANAGER_H
