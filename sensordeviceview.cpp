#include "sensordeviceview.h"
#include <QPainter>
#include <QHostAddress>
#include <QString>
#include <QMenu>
#include <QContextMenuEvent>

SensorDeviceView::SensorDeviceView(QWidget *parent) : QWidget(parent) {
    sensorValue = new qint16[32];
    std::fill(sensorValue, sensorValue+32, 0);
    parentHeight = parent->geometry().height();
    parentWidth = parent->geometry().width();
    setFixedSize(parentWidth-40, 410);
}

SensorDeviceView::~SensorDeviceView() {
    delete[] sensorValue;
}

void SensorDeviceView::setSensorValue(qint16 *val) {
    std::copy(val, val+32, sensorValue);
}

void SensorDeviceView::setAddress(QString address) {
   deviceAddress = address;
}

void SensorDeviceView::setPort(qint32 port) {
    devicePort = port;
}


void SensorDeviceView::paintEvent(QPaintEvent *event) {
    // ustawienie rysowania
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen = QPen(Qt::black);
    pen.setWidth(3);
    painter.setPen(pen);

    //rysowanie obówdki
    QRect sensorRectangle = QRect(5, 5, parentWidth-50, 400);
    painter.drawRect(sensorRectangle);

    //rysowanie nazwy
    QString deviceName = QString(deviceAddress + ":" + QString::number(devicePort));
    painter.drawText(10, 20, deviceName);


    //rysowanie wartości
    qint32 x, y;
    x = 10;
    y = 30;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            qint32 val = (((float)sensorValue[(i*8)+j]-(std::numeric_limits<qint16>::min()))/(std::numeric_limits<qint16>::max()-(std::numeric_limits<qint16>::min())))*255;
            //QBrush brush = QBrush(QColor(sensorValue[(i*8)+j], sensorValue[(i*8)+j], sensorValue[(i*8)+j]));
            QBrush brush = QBrush(QColor(val, val, val));
            painter.drawText(x,y+70, QString::number(sensorValue[i*8+j]));
            QRect  valueRectangle = QRect(x, y, 50, 50);
            painter.drawRect(valueRectangle);
            painter.fillRect(valueRectangle, brush);
            x+=60;
        }
        y+= 80;
        x=10;
    }
}

QSize SensorDeviceView::sizeHint() {
    return QSize(parentWidth-40, 410);
}

QSize SensorDeviceView::minimumSizeHint() {
    return QSize(parentWidth-40, 410);
}

void SensorDeviceView::contextMenuEvent(QContextMenuEvent *event) {
    QMenu contextMenu(this);

    QAction action("Usuń", this);
    contextMenu.addAction(&action);
    contextMenu.exec(mapToGlobal(event->pos()));

    qDebug() << "context event: " << deviceAddress;
}

