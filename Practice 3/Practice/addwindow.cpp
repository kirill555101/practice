#include "addwindow.h"
#include "ui_addwindow.h"
#include "product.h"

AddWindow::AddWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);
    ui->lineEdit_name->setMaxLength(30);
    ui->lineEdit_release->setInputMask("00.00.0000");
    ui->lineEdit_developer->setMaxLength(30);
    ui->lineEdit_memory->setInputMask("00000");
}

AddWindow::~AddWindow()
{
    delete ui;
}

void AddWindow::on_pushButton_add_clicked()
{
    if (ui->lineEdit_name->text().toStdString() == "" ||
            ui->lineEdit_release->text().toStdString() == "" ||
            ui->lineEdit_developer->text().toStdString() == "" ||
            ui->lineEdit_memory->text().toStdString() == "")
        return;

    std::string name = ui->lineEdit_name->text().toStdString();
    std::string release = ui->lineEdit_release->text().toStdString();
    std::string developer = ui->lineEdit_developer->text().toStdString();
    int memory = std::stoi(ui->lineEdit_memory->text().toStdString().c_str());

    if (release.size() < 10)
    {
        QMessageBox::warning(0,"Предупреждение", "Неправильный формат даты");
        return;
    }

    product pr(name, release, developer, memory);

    std::ofstream fos("file.dat", std::ios::binary | std::ios::app);
    fos.write(reinterpret_cast<char*>(&pr), sizeof(product));
    fos.close();

    ui->lineEdit_name->clear();
    ui->lineEdit_release->clear();
    ui->lineEdit_developer->clear();
    ui->lineEdit_memory->clear();
}

void AddWindow::on_pushButton_back_clicked()
{
    this->close();
    emit firstWindow();
}
