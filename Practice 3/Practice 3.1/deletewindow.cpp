#include "deletewindow.h"
#include "ui_deletewindow.h"
#include "pricelist.h"

DeleteWindow::DeleteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteWindow)
{
    ui->setupUi(this);
    ui->lineEdit_service->setMaxLength(30);
    ui->lineEdit_surname->setMaxLength(15);
    ui->lineEdit_days->setInputMask("00000");
    ui->lineEdit_price->setInputMask("00000");
}

DeleteWindow::~DeleteWindow()
{
    delete ui;
}

void DeleteWindow::on_pushButton_delete_clicked()
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

    pricelist pr;
    std::ifstream fis("file.dat", std::ios::binary);
    QVector<pricelist> vect;

    while (fis.read(reinterpret_cast<char*>(&pr), sizeof(pricelist)))
    {
        vect.push_back(pr);
    }
    fis.close();

    bool key=false;
    QVector<pricelist>::iterator it = vect.begin();
    while (it!=vect.end())
    {
        if (it->Is_equally(service, surname, days, price))
        {
            it = vect.erase(it);
            key=true;
            break;
        }
        else ++it;
    }
    if (!key)
    {
        QMessageBox::information(0, "Информация", "Элемент не найден!"); return;
    }
    else
        QMessageBox::information(0, "Информация", "Элемент успешно удален!");

    std::ofstream fos("file.dat", std::ios::binary|std::ios::trunc);
    it = vect.begin();
    while (it!=vect.end())
    {
        fos.write(reinterpret_cast<char*>(it),sizeof(pricelist));
        ++it;
    }
    fos.close();

    ui->lineEdit_service->clear();
    ui->lineEdit_surname->clear();
    ui->lineEdit_days->clear();
    ui->lineEdit_price->clear();
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
