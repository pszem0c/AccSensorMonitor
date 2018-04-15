#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>

#include "sensorview.h"

#include "sensorvalueview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    showMaximized();
    windowHeight = this->size().height();
    windowWidth = this->size().width();
    /*mainLayout = new QHBoxLayout(this);
    scrollArea = new QScrollArea(mainLayout->widget());

    sensorList = new QWidget(scrollArea);
    sensorList->setLayout(new QVBoxLayout(this));
    sensorList->setGeometry(0, 0, windowWidth-200, 200);
    settings = new QWidget(this);
    settings->setGeometry(0,0,150,400);
    settings->setLayout(new QVBoxLayout(this));

    ui->centralWidget->setLayout(mainLayout);
    mainLayout->addWidget(settings);
    mainLayout->addWidget(scrollArea);

    scrollArea->setWidget(sensorList);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    SensorView* sens = new SensorView(sensorList);
    sens->setup(nullptr);
    sensorList->layout()->addWidget(sens);*/

    ui->scrollAreaWidgetContents->setLayout(new QHBoxLayout(this));
    ui->scrollAreaWidgetContents->layout()->addWidget(new SensorValueView(ui->scrollAreaWidgetContents));

}

MainWindow::~MainWindow()
{
    delete ui;
}
