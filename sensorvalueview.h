#ifndef SENSORVALUEVIEW_H
#define SENSORVALUEVIEW_H

#include <QObject>
#include <QWidget>

class SensorValueView : public QWidget {
    Q_OBJECT
private:
    qint16* sensorValue;
    qint32 parentWidth;
    qint32 parentHeight;

public:
    explicit SensorValueView(QWidget *parent = nullptr);
    ~SensorValueView();

    void setSensorVale(qint16* val);

signals:



public slots:

protected:
    void paintEvent(QPaintEvent* event);
    QSize sizeHint();
    QSize minimumSizeHint();
};

#endif // SENSORVALUEVIEW_H
