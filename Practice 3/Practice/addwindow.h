#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QMainWindow>

namespace Ui {
class AddWindow;
}

class AddWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = nullptr);
    ~AddWindow();

signals:
    void firstWindow();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::AddWindow *ui;
};

#endif // ADDWINDOW_H
