#include "chartwindow.h"
#include "ui_chartwindow.h"

ChartWindow::ChartWindow(QWidget *parent, std::string name) :
    QMainWindow(parent),
    ui(new Ui::ChartWindow)
{
    ui->setupUi(this);

    QChart *chart = new QChart();
    QSplineSeries *series = new QSplineSeries();
    product pr;
    std::ifstream fis("file.dat", std::ios::binary);
    QVector<product> vect;
    while (fis.read(reinterpret_cast<char*>(&pr), sizeof(pr)))
    {
        vect.push_back(pr);
    }
    fis.close();

    QDateTime min,max;

    min = max = QDateTime::fromString(QString::fromStdString(vect[0].Get_Entry()),"dd.MM.yyyy");
    for (int i=0; i < vect.size(); i++)
    {
        QDateTime enDate = QDateTime::fromString(QString::fromStdString(std::string(vect[i].Get_Entry())),"dd.MM.yyyy");

        if (enDate > max && name == vect[i].Get_Name())
            max = enDate;
        if (enDate < min && name == vect[i].Get_Name())
            min = enDate;
    }

    int k = 0;
    for (int i = min.date().year(); i <= max.date().year(); i++)
    {
        int production = 0;

        for (int j = 0; j < vect.size(); j++)
        {
            QDateTime enDate = QDateTime::fromString(QString::fromStdString(std::string(vect[j].Get_Entry())),"dd.MM.yyyy");
            if (enDate.date().year() == i && name == vect[j].Get_Name())
            {
                production = vect[j].Get_Production();
                break;
            }
        }

        series->append(i, production);
        k++;
    }

    //series->setName("Линия");
    chart->addSeries(series);
    std::string res = "График поступления товара " + name + " по годам";
    chart->setTitle(QString::fromStdString(res));

    //Ось OX
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(k);
    axisX->setFormat("yyyy");

    // Установка времени
    QDateTime minDate;
    minDate.setDate(min.date());
    minDate.setTime(QTime(0, 00));
    QDateTime maxDate;
    maxDate.setDate(max.date());
    maxDate.setTime(QTime(23, 59));

    axisX->setRange(minDate, maxDate);
    axisX->setTitleText("Год");
    chart->addAxis(axisX, Qt::AlignBottom);

    //Ось OY
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Количество выпущенного товара");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->chart()->legend()->hide();
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
}

ChartWindow::~ChartWindow()
{
    delete ui;
}
