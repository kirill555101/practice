#include "addwindow.h"
#include "ui_addwindow.h"
#include "product.h"

AddWindow::AddWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);
    ui->lineEdit_name->setMaxLength(30);
    ui->lineEdit_entry->setInputMask("00.00.0000");
    ui->lineEdit_price->setInputMask("00000");
    ui->lineEdit_production->setInputMask("00000");
}

AddWindow::~AddWindow()
{
    delete ui;
}

void AddWindow::on_pushButton_add_clicked()
{
    if (ui->lineEdit_name->text().toStdString() == "" ||
            ui->lineEdit_entry->text().toStdString() == "" ||
            ui->lineEdit_price->text().toStdString() == "" ||
            ui->lineEdit_production->text().toStdString() == "")
        return;

    std::string name = ui->lineEdit_name->text().toStdString();
    std::string entry = ui->lineEdit_entry->text().toStdString();
    int price = std::stoi(ui->lineEdit_price->text().toStdString().c_str());
    int production = std::stoi(ui->lineEdit_production->text().toStdString().c_str());

    if (entry.size() < 10)
    {
        QMessageBox::warning(0,"Предупреждение", "Неправильный формат даты");
        return;
    }

    product pr(name, entry, price, production);

    std::ofstream fos("file.dat", std::ios::binary | std::ios::app);
    fos.write(reinterpret_cast<char*>(&pr), sizeof(product));
    fos.close();

    ui->lineEdit_name->clear();
    ui->lineEdit_entry->clear();
    ui->lineEdit_price->clear();
    ui->lineEdit_production->clear();
}

void AddWindow::on_pushButton_back_clicked()
{
    this->close();
    emit firstWindow();
}
