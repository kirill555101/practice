#include "deletewindow.h"
#include "ui_deletewindow.h"
#include "product.h"

DeleteWindow::DeleteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteWindow)
{
    ui->setupUi(this);
    ui->lineEdit_name->setMaxLength(30);
    ui->lineEdit_entry->setInputMask("00.00.0000");
    ui->lineEdit_price->setInputMask("00000");
    ui->lineEdit_production->setInputMask("00000");
}

DeleteWindow::~DeleteWindow()
{
    delete ui;
}

void DeleteWindow::on_pushButton_delete_clicked()
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

    product pr;
    std::ifstream fis("file.dat", std::ios::binary);
    QVector<product> vect;

    while (fis.read(reinterpret_cast<char*>(&pr), sizeof(product)))
    {
        vect.push_back(pr);
    }
    fis.close();

    bool key=false;
    QVector<product>::iterator it = vect.begin();
    while (it!=vect.end())
    {
        if (it->Is_equally(name, entry, price, production))
        {
            it = vect.erase(it);
            key=true;
            break;
        }
        else ++it;
    }
    if (!key)
    {
        QMessageBox::information(0, "Информация", "Товар не найден!"); return;
    }
    else
        QMessageBox::information(0, "Информация", "Товар успешно удален!");

    std::ofstream fos("file.dat", std::ios::binary|std::ios::trunc);
    it = vect.begin();
    while (it!=vect.end())
    {
        fos.write(reinterpret_cast<char*>(it),sizeof(product));
        ++it;
    }
    fos.close();

    ui->lineEdit_name->clear();
    ui->lineEdit_entry->clear();
    ui->lineEdit_price->clear();
    ui->lineEdit_production->clear();
}

void DeleteWindow::on_pushButton_deleteall_clicked()
{
    std::ofstream fos("file.dat", std::ios::trunc);
    QMessageBox::information(0, "Информация", "Данные успешно удалены!");
    fos.close();
}

void DeleteWindow::on_pushButton_back_clicked()
{
    this->close();
    emit firstWindow();
}
