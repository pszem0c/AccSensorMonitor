#ifndef SENSORVIEW_H
#define SENSORVIEW_H

#include <QWidget>

class SensorDevice;

class SensorView : public QWidget {
    Q_OBJECT
public:
    explicit SensorView(QWidget *parent = nullptr);

    void setup(SensorDevice* sensorDevice);



signals:

public slots:
};

#endif // SENSORVIEW_H
