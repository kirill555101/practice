#include "gridwindow.h"
#include "ui_gridwindow.h"
#include "product.h"

QVector<product> vect;

GridWindow::GridWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GridWindow)
{
    ui->setupUi(this);
    ch = new ChartWindow();
    product pr;
    std::ifstream fis("file.dat", std::ios::binary);

    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Название продукта" << "Дата выпуска" << "Разработчик" << "Требуемая ОЗУ в Гб");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(0);

    int i=0;
    vect.clear();
    while (fis.read(reinterpret_cast<char*>(&pr), sizeof(pr)))
    {
        vect.push_back(pr);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(pr.Get_Name()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(pr.Get_Release()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(pr.Get_Developer()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(tr("%1").arg(pr.Get_Memory())));
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        i++;
    }
    fis.close();

    ui->lineEdit_memory->setInputMask("00000");
    ui->lineEdit_yearbegin->setInputMask("0000");
    ui->lineEdit_yearend->setInputMask("0000");
    ui->lineEdit_developer->setMaxLength(30);
    ui->lineEdit_memory->setCursorPosition(0);

}

GridWindow::~GridWindow()
{
    delete ui;
    delete ch;
}

void GridWindow::on_pushButton_back_clicked()
{
    this->close();
    emit firstWindow();
}

void GridWindow::on_pushButton_reset_clicked()
{
    ui->lineEdit_memory->clear();
    ui->lineEdit_yearbegin->clear();
    ui->lineEdit_yearend->clear();
    ui->lineEdit_developer->clear();
    ui->tableWidget->clear();

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Название продукта" << "Дата выпуска" << "Разработчик" << "Требуемая ОЗУ в Гб");
    ui->tableWidget->setRowCount(1);

    product pr;
    std::ifstream fis("file.dat", std::ios::binary);
    int i=0;
    vect.clear();
    while (fis.read(reinterpret_cast<char*>(&pr), sizeof(pr)))
    {
        vect.push_back(pr);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(pr.Get_Name()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(pr.Get_Release()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(pr.Get_Developer()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(tr("%1").arg(pr.Get_Memory())));
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        i++;
    }
    fis.close();

}

void GridWindow::on_pushButton_makechart_clicked()
{
    ch->show();
}

void GridWindow::on_pushButton_mostexacting_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Название продукта" << "Дата выпуска" << "Разработчик" << "Требуемая ОЗУ в Гб");
    ui->tableWidget->setRowCount(1);

    int count = 0;
    char *developer=new char[1];
    int memory;

    while (vect.size())
    {
        strcpy(developer, vect[0].Get_Developer());
        memory = vect[0].Get_Memory();
        product *pr = &vect[0];

        for (QVector<product>::iterator it = vect.begin(); it!=vect.end(); it++)
              if (memory < it->Get_Memory() && !strcmp(developer, it->Get_Developer()))
              {
                pr = it;
                memory = it->Get_Memory();
              }

        ui->tableWidget->setItem(count, 0, new QTableWidgetItem(pr->Get_Name()));
        ui->tableWidget->setItem(count, 1, new QTableWidgetItem(pr->Get_Release()));
        ui->tableWidget->setItem(count, 2, new QTableWidgetItem(pr->Get_Developer()));
        ui->tableWidget->setItem(count, 3, new QTableWidgetItem(tr("%1").arg(pr->Get_Memory())));
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        count++;

        QVector<product>::iterator it = vect.begin();
        while (it!=vect.end())
        {
            if (!strcmp(developer, it->Get_Developer()))
                it = vect.erase(it);
            else ++it;
        }

    }
    product pr;
    std::ifstream fis("file.dat", std::ios::binary);
    vect.clear();
    while (fis.read(reinterpret_cast<char*>(&pr), sizeof(pr)))
    {
        vect.push_back(pr);
    }
    fis.close();

}

void GridWindow::on_pushButton_developerfind_clicked()
{
    if (ui->lineEdit_developer->text().toStdString() == "" || ui->lineEdit_yearbegin->text().toStdString() == "" ||  ui->lineEdit_yearend->text().toStdString() == "") return;
    std::string developer = ui->lineEdit_developer->text().toStdString();
    int yearbegin = stoi(ui->lineEdit_yearbegin->text().toStdString());
    int yearend = stoi(ui->lineEdit_yearend->text().toStdString());

    bool key=false;
    for (int i=0; i < vect.size(); i++)
    {
        if (vect[i].Is_Released_In_Period(developer, yearbegin, yearend))
        {
            key=true;
            break;
        }
    }

    if (!key)
    {
        QMessageBox::information(0, "Информация", "Элементы не найдены!"); return;
    }

    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Название продукта" << "Дата выпуска" << "Разработчик" << "Требуемая ОЗУ в Гб");
    ui->tableWidget->setRowCount(1);


    for (int i=0, count=0; i < vect.size(); i++)
    {
        if (vect[i].Is_Released_In_Period(developer, yearbegin, yearend))
        {
            ui->tableWidget->setItem(count, 0, new QTableWidgetItem(vect[i].Get_Name()));
            ui->tableWidget->setItem(count, 1, new QTableWidgetItem(vect[i].Get_Release()));
            ui->tableWidget->setItem(count, 2, new QTableWidgetItem(vect[i].Get_Developer()));
            ui->tableWidget->setItem(count, 3, new QTableWidgetItem(tr("%1").arg(vect[i].Get_Memory())));
            ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
            count++;
        }
    }

}

void GridWindow::on_pushButton_memoryfind_clicked()
{
    if (ui->lineEdit_memory->text().toStdString() == "") return;
    int memory = std::stoi(ui->lineEdit_memory->text().toStdString().c_str());

    bool key=false;
    for (int i=0; i < vect.size(); i++)
    {
        if (vect[i].Get_Memory() <= memory)
        {
            key=true;
            break;
        }
    }

    if (!key)
    {
        QMessageBox::information(0, "Информация", "Элементы не найдены!"); return;
    }

    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Название продукта" << "Дата выпуска" << "Разработчик" << "Требуемая ОЗУ в Гб");
    ui->tableWidget->setRowCount(1);

    for (int i=0, count=0; i < vect.size(); i++)
    {
        if (vect[i].Get_Memory() <= memory)
        {
            ui->tableWidget->setItem(count, 0, new QTableWidgetItem(vect[i].Get_Name()));
            ui->tableWidget->setItem(count, 1, new QTableWidgetItem(vect[i].Get_Release()));
            ui->tableWidget->setItem(count, 2, new QTableWidgetItem(vect[i].Get_Developer()));
            ui->tableWidget->setItem(count, 3, new QTableWidgetItem(tr("%1").arg(vect[i].Get_Memory())));
            ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
            count++;
        }
    }
}
