#include "sensorvalueview.h"
#include <QPainter>

SensorValueView::SensorValueView(QWidget *parent) : QWidget(parent) {
    sensorValue = new qint16[32];
    std::fill(sensorValue, sensorValue+32, 0);
    parentHeight = parent->geometry().height();
    parentWidth = parent->geometry().width();
}

SensorValueView::~SensorValueView() {
    delete[] sensorValue;
}

void SensorValueView::setSensorVale(qint16 *val) {
    std::copy(val, val+32, sensorValue);
}


void SensorValueView::paintEvent(QPaintEvent *event) {
    // ustawienie rysowania
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen = QPen(Qt::black);
    pen.setWidth(3);
    painter.setPen(pen);

    //rysowanie obówdki
    QRect sensorRectangle = QRect(5, 5, parentWidth-30, 300);
    painter.drawRect(sensorRectangle);

    //rysowanie nazwy
    painter.drawText(10, 20, "X.X.X.X:PORT");


    //rysowanie wartości
    qint32 x, y;
    x = 10;
    y = 30;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            QBrush brush = QBrush(QColor(sensorValue[(i*8)+j], sensorValue[(i*8)+j], sensorValue[(i*8)+j]));
            QRect  valueRectangle = QRect(x, y, 50, 50);
            painter.drawRect(valueRectangle);
            painter.fillRect(valueRectangle, brush);
            x+=60;
        }
        y+= 60;
        x=10;
    }
}

QSize SensorValueView::sizeHint() {
    return QSize(parentWidth-10, 500);
}

QSize SensorValueView::minimumSizeHint() {
    return QSize(parentWidth-10, 500);
}
