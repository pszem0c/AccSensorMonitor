#ifndef SENSORLOGGER_H
#define SENSORLOGGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QList>

class SensorDevice;

class SensorLogger : public QObject {
    Q_OBJECT
private:
    QFile logFile;
    QTextStream logStream;

public:
    explicit SensorLogger(QObject *parent = nullptr);
    ~SensorLogger();

    void openLog(QString fileName);
    void writeToLog(QList<SensorDevice*> sensorList);

signals:

public slots:
    void writeToLogSlot(QList<SensorDevice*> sensorList);
};

#endif // SENSORLOGGER_H
