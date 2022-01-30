#include "gridwindow.h"
#include "ui_gridwindow.h"
#include "pricelist.h"

QVector<pricelist> vect;

GridWindow::GridWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GridWindow)
{
    ui->setupUi(this);
    ch = new ChartWindow();
    pricelist pr;
    std::ifstream fis("file.dat", std::ios::binary);

    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Название услуги" << "Фамилия мастера" << "Срок выполнения" << "Стоимость");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(0);

    int i=0;
    vect.clear();
    while (fis.read(reinterpret_cast<char*>(&pr), sizeof(pr)))
    {
        vect.push_back(pr);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(pr.Get_Service()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(pr.Get_Surname()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(tr("%1").arg(pr.Get_Days())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(tr("%1").arg(pr.Get_Price())));
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        i++;
    }
    fis.close();

    ui->lineEdit_surname->clear();
    ui->lineEdit_service->clear();

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
    ui->lineEdit_surname->clear();
    ui->lineEdit_service->clear();
    ui->tableWidget->clear();

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Название услуги" << "Фамилия мастера" << "Срок выполнения" << "Стоимость");
    ui->tableWidget->setRowCount(1);

    pricelist pr;
    std::ifstream fis("file.dat", std::ios::binary);
    int i=0;
    vect.clear();
    while (fis.read(reinterpret_cast<char*>(&pr), sizeof(pr)))
    {
        vect.push_back(pr);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(pr.Get_Service()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(pr.Get_Surname()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(tr("%1").arg(pr.Get_Days())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(tr("%1").arg(pr.Get_Price())));
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        i++;
    }
    fis.close();

}

void GridWindow::on_pushButton_makechart_clicked()
{
    ch->show();
}

void GridWindow::on_pushButton_servicesfind_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Название услуги" << "Количество");
    ui->tableWidget->setRowCount(1);

    int count = 0, k=0;
    char *service=new char[1];

    while (vect.size())
    {
        strcpy(service, vect[0].Get_Service());
        pricelist *pr = &vect[0];

        for (QVector<pricelist>::iterator it = vect.begin(); it!=vect.end(); it++)
              if (!strcmp(service, it->Get_Service()))
              {
                pr = it;
                k++;
              }

        ui->tableWidget->setItem(count, 0, new QTableWidgetItem(pr->Get_Service()));
        ui->tableWidget->setItem(count, 1, new QTableWidgetItem(tr("%1").arg(k)));
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        count++;
        k = 0;

        QVector<pricelist>::iterator it = vect.begin();
        while (it!=vect.end())
        {
            if (!strcmp(service, it->Get_Service()))
                it = vect.erase(it);
            else ++it;
        }

    }

    pricelist pr;
    std::ifstream fis("file.dat", std::ios::binary);
    vect.clear();
    while (fis.read(reinterpret_cast<char*>(&pr), sizeof(pr)))
    {
        vect.push_back(pr);
    }
    fis.close();

}

void GridWindow::on_pushButton_pricefind_clicked()
{
    if (ui->lineEdit_service->text().toStdString() == "") return;
    std::string service = ui->lineEdit_service->text().toStdString();

    bool key=false;
    pricelist pr = vect[0];

    for (int i=0; i < vect.size(); i++)
    {
        if (vect[i].Get_Service() == service && pr.Get_Price() > vect[i].Get_Price())
        {
            key = true;
            pr = vect[i];
        }
    }

    if (!key)
    {
        QMessageBox::information(0, "Ошибка", "Услуга не найдена!");
    }
    else
    {
        std::string res = "Услуга " + std::string(pr.Get_Service()) + " дешевле всего обойдется у мастера с фамилией " + std::string(pr.Get_Surname());
        QMessageBox::information(0, "Информация", res.c_str());
    }

}

void GridWindow::on_pushButton_surnamefind_clicked()
{
    if (ui->lineEdit_surname->text().toStdString() == "") return;
    std::string surname = ui->lineEdit_surname->text().toStdString();

    bool key=false;
    for (int i=0; i < vect.size(); i++)
    {
        if (vect[i].Get_Surname() == surname)
        {
            key=true;
            break;
        }
    }

    if (!key)
    {
        QMessageBox::information(0, "Информация", "Данные не найдены!"); return;
    }

    pricelist pr;
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Название продукта" << "Дата выпуска" << "Разработчик" << "Требуемая ОЗУ в Гб");
    ui->tableWidget->setRowCount(1);

    for (int i=0, count=0; i < vect.size(); i++)
    {
        if (vect[i].Get_Surname() == surname)
        {
            ui->tableWidget->setItem(count, 0, new QTableWidgetItem(vect[i].Get_Service()));
            ui->tableWidget->setItem(count, 1, new QTableWidgetItem(vect[i].Get_Surname()));
            ui->tableWidget->setItem(count, 2, new QTableWidgetItem(tr("%1").arg(vect[i].Get_Days())));
            ui->tableWidget->setItem(count, 3, new QTableWidgetItem(tr("%1").arg(vect[i].Get_Price())));
            ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
            count++;
        }
    }
}
