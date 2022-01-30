#include "gridwindow.h"
#include "ui_gridwindow.h"
#include "product.h"

QVector<product> vect;

GridWindow::GridWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GridWindow)
{
    ui->setupUi(this);
    product pr;
    std::ifstream fis("file.dat", std::ios::binary);

    ch = nullptr;
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Название продукта" << "Дата поступления" << "Цена" << "Объем партии");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(0);

    int i=0;
    vect.clear();
    while (fis.read(reinterpret_cast<char*>(&pr), sizeof(pr)))
    {
        vect.push_back(pr);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(pr.Get_Name()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(pr.Get_Entry()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(tr("%1").arg(pr.Get_Price())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(tr("%1").arg(pr.Get_Production())));
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        i++;
    }
    fis.close();

    ui->lineEdit_name->setMaxLength(30);
    ui->lineEdit_entry->setInputMask("00.00.0000");
    ui->lineEdit_production->setInputMask("00000");
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
    ui->lineEdit_entry->clear();
    ui->lineEdit_production->clear();
    ui->tableWidget->clear();

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Название продукта" << "Дата поступления" << "Цена" << "Объем партии");
    ui->tableWidget->setRowCount(1);

    product pr;
    std::ifstream fis("file.dat", std::ios::binary);
    int i=0;
    vect.clear();
    while (fis.read(reinterpret_cast<char*>(&pr), sizeof(pr)))
    {
        vect.push_back(pr);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(pr.Get_Name()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(pr.Get_Entry()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(tr("%1").arg(pr.Get_Price())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(tr("%1").arg(pr.Get_Production())));
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        i++;
    }
    fis.close();

}

void GridWindow::on_pushButton_makechart_clicked()
{
    if (ui->lineEdit_name->text().toStdString() == "")
        return;

    std::string name = ui->lineEdit_name->text().toStdString();

    bool key=false;
    for (int i=0; i < vect.size(); i++)
    {
        if (name == vect[i].Get_Name())
        {
            key=true;
            break;
        }
    }

    if (!key)
    {
        QMessageBox::information(0, "Информация", "Товар не найден!"); return;
    }

    if (!ch)
        ch = new ChartWindow(nullptr, name);

    ch->show();
}

void GridWindow::on_pushButton_mostproduction_clicked()
{
  product maxpr = vect[0];

  for (int i = 0; i < vect.size(); i++)
    if (vect[i].Get_Production() > maxpr.Get_Production())
      maxpr = vect[i];

  std::string res = "Продукт: " + std::string(maxpr.Get_Name()) + ", выпущенный " + std::string(maxpr.Get_Entry()) + " имеет наибольшую стоимость партии: " + std::to_string(maxpr.Get_Production());
  QMessageBox::information(0, "Информация", res.c_str());
}

void GridWindow::on_pushButton_productionfind_clicked()
{
    if (ui->lineEdit_production->text().toStdString() == "") return;
    int production = std::atoi(ui->lineEdit_production->text().toStdString().c_str());

    bool key=false;
    for (int i=0; i < vect.size(); i++)
    {
        if (vect[i].Get_Production() >= production)
        {
            key=true;
            break;
        }
    }

    if (!key)
    {
        QMessageBox::information(0, "Информация", "Товары не найдены!"); return;
    }

    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Название продукта" << "Дата поступления" << "Цена" << "Объем партии");
    ui->tableWidget->setRowCount(1);

    int sum = 0;
    for (int i = 0, count = 0; i < vect.size(); i++)
    {
        if (vect[i].Get_Production() >= production)
        {
            ui->tableWidget->setItem(count, 0, new QTableWidgetItem(vect[i].Get_Name()));
            ui->tableWidget->setItem(count, 1, new QTableWidgetItem(vect[i].Get_Entry()));
            ui->tableWidget->setItem(count, 2, new QTableWidgetItem(tr("%1").arg(vect[i].Get_Price())));
            ui->tableWidget->setItem(count, 3, new QTableWidgetItem(tr("%1").arg(vect[i].Get_Production())));
            ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
            sum += vect[i].Get_Production();
            count++;
        }
    }

    std::string res = "Общая стоимость партий равна " + std::to_string(sum);
    QMessageBox::information(0, "Информация", res.c_str());
}

void GridWindow::on_pushButton_entryfind_clicked()
{
    if (ui->lineEdit_entry->text().toStdString() == "") return;
    std::string entry = ui->lineEdit_entry->text().toStdString();

    if (entry.size() < 10)
    {
        QMessageBox::warning(0,"Предупреждение", "Неправильный формат даты");
        return;
    }

    QDateTime entryDate = QDateTime::fromString(QString::fromStdString(entry),"dd.MM.yyyy");

    bool key=false;
    for (int i=0; i < vect.size(); i++)
    {
        QDateTime enDate = QDateTime::fromString(QString::fromStdString(std::string(vect[i].Get_Entry())),"dd.MM.yyyy");

        if (enDate >= entryDate)
        {
            key=true;
            break;
        }
    }

    if (!key)
    {
        QMessageBox::information(0, "Информация", "Товары не найдены!"); return;
    }

    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Название продукта" << "Дата выпуска" << "Разработчик" << "Требуемая ОЗУ в Гб");
    ui->tableWidget->setRowCount(1);

    for (int i=0, count=0; i < vect.size(); i++)
    {
        QDateTime enDate = QDateTime::fromString(QString::fromStdString(std::string(vect[i].Get_Entry())),"dd.MM.yyyy");

        if (enDate >= entryDate)
        {
            ui->tableWidget->setItem(count, 0, new QTableWidgetItem(vect[i].Get_Name()));
            ui->tableWidget->setItem(count, 1, new QTableWidgetItem(vect[i].Get_Entry()));
            ui->tableWidget->setItem(count, 2, new QTableWidgetItem(tr("%1").arg(vect[i].Get_Price())));
            ui->tableWidget->setItem(count, 3, new QTableWidgetItem(tr("%1").arg(vect[i].Get_Production())));
            ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
            count++;
        }
    }
}
