#include "sensorview.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include "sensorvalueview.h"

SensorView::SensorView(QWidget *parent) : QWidget(parent) {
    setGeometry(0, 0, parent->width()-1, 300);
}

void SensorView::setup(SensorDevice *sensorDevice) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    setLayout(mainLayout);
    layout()->addWidget(new QLabel("X.X.X.X:PORT"));
    QHBoxLayout* hLayout;
    for (int i = 0; i < 4; i ++) {
        hLayout = new QHBoxLayout(this);
        hLayout->setAlignment(Qt::AlignCenter);
        for(int j = 0; j < 8; ++j) {
            SensorValueView* sensorValueView = new SensorValueView();
            hLayout->addWidget(sensorValueView);
            sensorValueView->repaint();
        }
        mainLayout->addLayout(hLayout);
    }
}
