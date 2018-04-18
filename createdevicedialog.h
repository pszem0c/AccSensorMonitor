#ifndef CREATEDEVICEDIALOG_H
#define CREATEDEVICEDIALOG_H

#include <QDialog>

namespace Ui {
class CreateDeviceDialog;
}

class CreateDeviceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateDeviceDialog(QWidget *parent = 0);
    ~CreateDeviceDialog();

private slots:
    void on_createButton_clicked();

signals:
    void createDevice(QString, quint8*);

private:
    Ui::CreateDeviceDialog *ui;
};

#endif // CREATEDEVICEDIALOG_H
