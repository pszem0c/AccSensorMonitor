#include "createdevicedialog.h"
#include "ui_createdevicedialog.h"
#include "QString"

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
    quint8* transform = new quint8[4];
    transform[0] = ui->comboBox0->currentText().toUShort();
    transform[1] = ui->comboBox1->currentText().toUShort();
    transform[2] = ui->comboBox2->currentText().toUShort();
    transform[3] = ui->comboBox3->currentText().toUShort();
    emit createDevice(ui->addressEdit->text(), transform);
    close();
}
