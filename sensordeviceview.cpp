#include "sensordeviceview.h"
#include <QPainter>
#include <QHostAddress>
#include <QString>
#include <QMenu>
#include <QContextMenuEvent>

SensorDeviceView::SensorDeviceView(QWidget *parent) : QWidget(parent) {
    sensorValue = new qint16[4];
    std::fill(sensorValue, sensorValue+4, 0);
    setFixedSize(120, 530);
}

SensorDeviceView::~SensorDeviceView() {
    delete[] sensorValue;
}

void SensorDeviceView::setSensorValue(qint16 *val) {
    std::copy(val, val+4, sensorValue);
}

void SensorDeviceView::setAddress(QString address) {
   deviceAddress = address;
}

void SensorDeviceView::setPort(qint32 port) {
    devicePort = port;
}

void SensorDeviceView::removeAction(bool checked) {
    emit removeDevice(this);
}


void SensorDeviceView::paintEvent(QPaintEvent *event) {
    // ustawienie rysowania
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen = QPen(Qt::gray);
    pen.setWidth(3);
    painter.setPen(pen);

    //rysowanie obówdki
    QRect sensorRectangle = QRect(5, 5, 110, 520);
    painter.drawRect(sensorRectangle);

    pen.setColor(Qt::black);
    painter.setPen(pen);

    //rysowanie nazwy
    QString deviceName = QString(deviceAddress);
    painter.drawText(10, 20, deviceName);


    //rysowanie wartości
    qint32 x, y;
    x = 10;
    y = 30;
    for (int i = 0; i < 4; ++i) {
        qint32 val = (((float)sensorValue[i]-(std::numeric_limits<qint16>::min()))/(std::numeric_limits<qint16>::max()-(std::numeric_limits<qint16>::min())))*255;
        QBrush brush = QBrush(QColor(val, val, val));
        painter.drawText(x,y+115, QString::number(sensorValue[i]));
        QRect  valueRectangle = QRect(x, y, 100, 100);
        painter.drawRect(valueRectangle);
        painter.fillRect(valueRectangle, brush);
        y+=120;
    }
}

QSize SensorDeviceView::sizeHint() {
    return QSize(120, 500);
}

QSize SensorDeviceView::minimumSizeHint() {
    return QSize(120, 500);
}

void SensorDeviceView::contextMenuEvent(QContextMenuEvent *event) {
    QMenu contextMenu(this);

    QAction action("Usuń", this);
    connect(&action, SIGNAL(triggered(bool)), this, SLOT(removeAction(bool)));
    contextMenu.addAction(&action);
    contextMenu.exec(mapToGlobal(event->pos()));
}

