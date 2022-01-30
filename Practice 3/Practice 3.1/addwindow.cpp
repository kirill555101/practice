#include "addwindow.h"
#include "ui_addwindow.h"
#include "pricelist.h"

AddWindow::AddWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);
    ui->lineEdit_service->setMaxLength(30);
    ui->lineEdit_surname->setMaxLength(15);
    ui->lineEdit_days->setInputMask("00000");
    ui->lineEdit_price->setInputMask("00000");
}

AddWindow::~AddWindow()
{
    delete ui;
}

void AddWindow::on_pushButton_add_clicked()
{
    if ( ui->lineEdit_service->text().toStdString() == "" ||
            ui->lineEdit_surname->text().toStdString() == "" ||
            ui->lineEdit_days->text().toStdString() == "" ||
            ui->lineEdit_price->text().toStdString() == "")
        return;

    std::string service = ui->lineEdit_service->text().toStdString();
    std::string surname = ui->lineEdit_surname->text().toStdString();
    int days = std::stoi(ui->lineEdit_days->text().toStdString());
    int price = std::stoi(ui->lineEdit_price->text().toStdString());

    pricelist pr(service, surname, days, price);

    std::ofstream fos("file.dat", std::ios::binary | std::ios::app);
    fos.write(reinterpret_cast<char*>(&pr), sizeof(pricelist));
    fos.close();

    ui->lineEdit_service->clear();
    ui->lineEdit_surname->clear();
    ui->lineEdit_days->clear();
    ui->lineEdit_price->clear();
}

void AddWindow::on_pushButton_back_clicked()
{
    this->close();
    emit firstWindow();
}
