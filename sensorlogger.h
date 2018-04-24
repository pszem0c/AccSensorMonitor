#ifndef SENSORLOGGER_H
#define SENSORLOGGER_H

#include <QObject>

class SensorLogger : public QObject {
    Q_OBJECT
private:

public:
    explicit SensorLogger(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SENSORLOGGER_H
