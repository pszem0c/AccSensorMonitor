#include "sensorlogger.h"
#include "sensordevice.h"

SensorLogger::SensorLogger(QObject *parent) : QObject(parent) {

}

SensorLogger::~SensorLogger() {

}

void SensorLogger::openLog(QString fileName) {
    logFile.setFileName(fileName);
    if (logFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        logStream.setDevice(&logFile);
    }
}

void SensorLogger::writeToLog(QList<SensorDevice *> sensorList) {
    if(logFile.isOpen()) {
        for (int i = 0; i < 4; i++) {
            for(QList<SensorDevice *>::iterator it = sensorList.begin(); it != sensorList.end(); it++) {
                logStream << (*it)->getSensorValue()[i] << " ";
            }
            logStream << "; ";
        }
        logStream << endl;
    }
}

void SensorLogger::writeToLogSlot(QList<SensorDevice *> sensorList) {
    writeToLog(sensorList);
}


