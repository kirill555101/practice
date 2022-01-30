#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    add = new AddWindow();
    connect(add, &AddWindow::firstWindow, this, &MainWindow::show);

    del = new DeleteWindow();
    connect(del, &DeleteWindow::firstWindow, this, &MainWindow::show);

    grid = new GridWindow();
    connect(grid, &GridWindow::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete add;
    delete del;
    delete grid;
    delete ui;
}


void MainWindow::on_pushButton_add_clicked()
{
    add->show();
    this->close();
}

void MainWindow::on_pushButton_delete_clicked()
{
    del->show();
    this->close();
}

void MainWindow::on_pushButton_show_clicked()
{
    delete grid;
    grid = new GridWindow();
    connect(grid, &GridWindow::firstWindow, this, &MainWindow::show);
    grid->show();
    this->close();
}

void MainWindow::on_pushButton_exit_clicked()
{
    qApp->exit();
}
