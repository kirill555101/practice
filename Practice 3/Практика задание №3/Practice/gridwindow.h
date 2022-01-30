#ifndef GRIDWINDOW_H
#define GRIDWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include "chartwindow.h"

namespace Ui {
class GridWindow;
}

class GridWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GridWindow(QWidget *parent = nullptr);
    ~GridWindow();

signals:
    void firstWindow();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_makechart_clicked();

    void on_pushButton_mostproduction_clicked();

    void on_pushButton_productionfind_clicked();

    void on_pushButton_entryfind_clicked();

private:
    Ui::GridWindow *ui;
    ChartWindow *ch;
};

#endif // GRIDWINDOW_H
