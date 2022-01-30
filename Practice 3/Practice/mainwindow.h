#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "addwindow.h"
#include "deletewindow.h"
#include "gridwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_show_clicked();

    void on_pushButton_exit_clicked();

private:
    Ui::MainWindow *ui;
    AddWindow *add;
    DeleteWindow *del;
    GridWindow *grid;
};
#endif // MAINWINDOW_H
