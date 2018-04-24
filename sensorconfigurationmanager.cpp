#include "sensorconfigurationmanager.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QList>
#include "sensordevice.h"

SensorConfigurationManager::SensorConfigurationManager(){

}

void SensorConfigurationManager::saveConfiguration(QString fileName, QList<SensorDevice *> sensorList) {
    QFile file(fileName);    
    if (file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QTextStream stream(&file);
        for (QList<SensorDevice*>::iterator it = sensorList.begin(); it != sensorList.end(); it++) {
            stream << (*it)->getAddress() << ","
                   << (qint32)((*it)->getSensorTransform()[0]) << ","
                   << (qint32)((*it)->getSensorTransform()[1]) << ","
                   << (qint32)((*it)->getSensorTransform()[2]) << ","
                   << (qint32)((*it)->getSensorTransform()[3]) << "," << endl;
        }
    }
}

QList<SensorDevice *> SensorConfigurationManager::loadConfiguration(QString fileName) {
    QFile file(fileName);
    QList<SensorDevice*> result;
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while(!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList args = line.split(",");
            quint32 ipAddress = ((QString)args.at(0)).toUInt();
            SensorDevice* sensorDevice = new SensorDevice(ipAddress, 1026);
            quint8 transform[4] = {((QString)args.at(1)).toUInt(),
                                   ((QString)args.at(2)).toUInt(),
                                   ((QString)args.at(3)).toUInt(),
                                   ((QString)args.at(4)).toUInt()};
            sensorDevice->setSensorTransform(transform);
            result.append(sensorDevice);
        }
    }
    return result;
}
