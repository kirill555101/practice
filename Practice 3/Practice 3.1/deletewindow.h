#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QMainWindow>

namespace Ui {
class DeleteWindow;
}

class DeleteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteWindow(QWidget *parent = nullptr);
    ~DeleteWindow();

signals:
    void firstWindow();

private slots:
    void on_pushButton_delete_clicked();

    void on_pushButton_deleteall_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::DeleteWindow *ui;
};

#endif // DELETEWINDOW_H
