#include "chartwindow.h"
#include "ui_chartwindow.h"

ChartWindow::ChartWindow(QWidget *parent) :
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

    int min,max;
    min = max = atoi(vect[0].Get_Release()+6);
    for (int i=0; i < vect.size(); i++)
    {
        if (atoi(vect[i].Get_Release()+6) > max)
            max = atoi(vect[i].Get_Release()+6);
        if (atoi(vect[i].Get_Release()+6) < min)
            min = atoi(vect[i].Get_Release()+6);
    }

    int k=0;
    for (int i = min; i <= max; i++)
    {
        int count=0;
        for (int j=0; j < vect.size(); j++)
            if (atoi(vect[j].Get_Release()+6) == i)
                count++;

        series->append(i, count);
        k++;
    }
    //series->setName("Линия");
    chart->addSeries(series);
    chart->setTitle("График изменения количества выпущенных программ по годам");

    //Ось OX
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(k);
    axisX->setFormat("yyyy");

    // Установка времени
    QDateTime minDate;
    minDate.setDate(QDate(min, 1 , 1));
    minDate.setTime(QTime(0, 00));
    QDateTime maxDate;
    maxDate.setDate(QDate(max, 12 , 31));
    maxDate.setTime(QTime(23, 59));

    axisX->setRange(minDate, maxDate);
    axisX->setTitleText("Год");
    chart->addAxis(axisX, Qt::AlignBottom);

    //Ось OY
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Количество выпущенных программ");
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
