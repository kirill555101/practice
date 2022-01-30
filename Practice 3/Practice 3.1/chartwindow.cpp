#include "chartwindow.h"
#include "ui_chartwindow.h"

ChartWindow::ChartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChartWindow)
{
    ui->setupUi(this);

    QChart *chart = new QChart();
    QSplineSeries *series = new QSplineSeries();
    pricelist pr;
    std::ifstream fis("file.dat", std::ios::binary);
    QVector<pricelist> vect;
    while (fis.read(reinterpret_cast<char*>(&pr), sizeof(pr)))
    {
        vect.push_back(pr);
    }
    fis.close();

    int min, max;
    min = max = vect[0].Get_Days();
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i].Get_Days() > max)
            max = vect[i].Get_Days();
        if (vect[i].Get_Days() < min)
            min = vect[i].Get_Days();
    }

    int TickCount = 0;
    for (int days = min; days <= max; days++)
    {
        int count = 0, sum = 0;
        bool key = false;
        for (int i = 0; i < vect.size(); i++)
            if (vect[i].Get_Days()  == days)
            {
                count++; sum += vect[i].Get_Price();
                key = true;
            }

        if (key)
            series->append(days, sum/count);
        else
            series->append(days, 0);
        TickCount++;
    }

    chart->addSeries(series);
    chart->setTitle("График зависимости средней стоимости услуг мастерской от срока выполнения");

    //Ось OX
    QValueAxis *axisX = new QValueAxis;
    axisX->setLabelFormat("%i");
    axisX->setTickCount(TickCount);
    axisX->setRange(min, max);
    axisX->setTitleText("Срок выполнения");
    chart->addAxis(axisX, Qt::AlignBottom);

    //Ось OY
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Средняя стоимость услуги");
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
