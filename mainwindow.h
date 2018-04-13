#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QHBoxLayout;
class QVBoxLayout;
class QScrollArea;
class QWiget;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow*     ui;
    QHBoxLayout*        mainLayout;
    QWidget*            sensorList;
    QWidget*            settings;
    QScrollArea*        scrollArea;
    qint64 windowHeight;
    qint64 windowWidth;

};

#endif // MAINWINDOW_H
