/********************************************************************************
** Form generated from reading UI file 'deletewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEWINDOW_H
#define UI_DELETEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeleteWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_entry;
    QLineEdit *lineEdit_price;
    QLineEdit *lineEdit_production;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_deleteall;
    QPushButton *pushButton_back;

    void setupUi(QMainWindow *DeleteWindow)
    {
        if (DeleteWindow->objectName().isEmpty())
            DeleteWindow->setObjectName(QString::fromUtf8("DeleteWindow"));
        DeleteWindow->resize(382, 176);
        centralwidget = new QWidget(DeleteWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEdit_name = new QLineEdit(centralwidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_name);

        lineEdit_entry = new QLineEdit(centralwidget);
        lineEdit_entry->setObjectName(QString::fromUtf8("lineEdit_entry"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_entry);

        lineEdit_price = new QLineEdit(centralwidget);
        lineEdit_price->setObjectName(QString::fromUtf8("lineEdit_price"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_price);

        lineEdit_production = new QLineEdit(centralwidget);
        lineEdit_production->setObjectName(QString::fromUtf8("lineEdit_production"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_production);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_delete = new QPushButton(centralwidget);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setMaximumSize(QSize(16777215, 50));

        horizontalLayout->addWidget(pushButton_delete);

        pushButton_deleteall = new QPushButton(centralwidget);
        pushButton_deleteall->setObjectName(QString::fromUtf8("pushButton_deleteall"));
        pushButton_deleteall->setMaximumSize(QSize(16777215, 50));

        horizontalLayout->addWidget(pushButton_deleteall);

        pushButton_back = new QPushButton(centralwidget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setMaximumSize(QSize(16777215, 50));

        horizontalLayout->addWidget(pushButton_back);


        verticalLayout->addLayout(horizontalLayout);

        DeleteWindow->setCentralWidget(centralwidget);

        retranslateUi(DeleteWindow);

        QMetaObject::connectSlotsByName(DeleteWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DeleteWindow)
    {
        DeleteWindow->setWindowTitle(QCoreApplication::translate("DeleteWindow", "\320\243\320\264\320\260\320\273\320\260\320\275\320\270\320\265 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\260", nullptr));
        label->setText(QCoreApplication::translate("DeleteWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("DeleteWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\321\202\321\203 \320\262\321\213\320\277\321\203\321\201\320\272\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("DeleteWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\206\320\265\320\275\321\203", nullptr));
        label_4->setText(QCoreApplication::translate("DeleteWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\320\261\321\212\320\265\320\274 \320\277\320\260\321\200\321\202\320\270\320\270", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("DeleteWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_deleteall->setText(QCoreApplication::translate("DeleteWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265", nullptr));
        pushButton_back->setText(QCoreApplication::translate("DeleteWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteWindow: public Ui_DeleteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEWINDOW_H
