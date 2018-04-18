#ifndef SENSORDEVICEVIEW_H
#define SENSORDEVICEVIEW_H

#include <QObject>
#include <QWidget>
#include <QString>

class SensorDeviceView : public QWidget {
    Q_OBJECT
private:
    qint16* sensorValue;
    QString deviceAddress;
    qint32 devicePort;
    qint32 frameWidth;
    qint32 frameHeight;

public:
    explicit SensorDeviceView(QWidget *parent = nullptr);
    ~SensorDeviceView();

    void setSensorValue(qint16* val);
    void setAddress(QString address);
    void setPort(qint32 port);
    void setFrameWidth(qint32 w);
    void setFrameHeight(qint32 h);

signals:
    void removeDevice(SensorDeviceView*);

public slots:
    void removeAction(bool checked);

protected:
    void paintEvent(QPaintEvent* event);
    QSize sizeHint();
    QSize minimumSizeHint();
    void contextMenuEvent(QContextMenuEvent* event);

};

#endif // SENSORDEVICEVIEW_H
