#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>

#include "sensorview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    showMaximized();
    windowHeight = this->size().height();
    windowWidth = this->size().width();
    mainLayout = new QHBoxLayout(parent);
    scrollArea = new QScrollArea(mainLayout->widget());

    sensorList = new QWidget(scrollArea);
    sensorList->setLayout(new QVBoxLayout);
    sensorList->setGeometry(0, 0, windowWidth-200, 100);
    settings = new QWidget();
    settings->setGeometry(0,0,150,400);
    settings->setLayout(new QVBoxLayout);

    ui->centralWidget->setLayout(mainLayout);
    mainLayout->addWidget(settings);
    mainLayout->addWidget(scrollArea);

    scrollArea->setWidget(sensorList);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    sensorList->layout()->addWidget(new SensorView(sensorList));
}

MainWindow::~MainWindow()
{
    delete ui;
}
