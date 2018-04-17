#include "createdevicedialog.h"
#include "ui_createdevicedialog.h"

CreateDeviceDialog::CreateDeviceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateDeviceDialog) {
    ui->setupUi(this);
    setWindowTitle("Dodaj urządzenie");
}

CreateDeviceDialog::~CreateDeviceDialog() {
    delete ui;
}

void CreateDeviceDialog::on_createButton_clicked() {
    emit createDevice(ui->addressEdit->text());
    close();
}
