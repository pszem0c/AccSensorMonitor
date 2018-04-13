#include "sensorview.h"

#include <QVBoxLayout>
#include <QPushButton>


SensorView::SensorView(QWidget *parent) : QWidget(parent) {
    setGeometry(0, 0, parent->width()-1, 300);
    setLayout(new QVBoxLayout);
    layout()->addWidget(new QPushButton);
}
