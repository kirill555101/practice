/********************************************************************************
** Form generated from reading UI file 'gridwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRIDWINDOW_H
#define UI_GRIDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GridWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_10;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_entry;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_entryfind;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_mostproduction;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *lineEdit_production;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_productionfind;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_makechart;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_reset;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_back;

    void setupUi(QMainWindow *GridWindow)
    {
        if (GridWindow->objectName().isEmpty())
            GridWindow->setObjectName(QString::fromUtf8("GridWindow"));
        GridWindow->resize(1064, 650);
        centralwidget = new QWidget(GridWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_10 = new QHBoxLayout(centralwidget);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        horizontalLayout_10->addWidget(tableWidget);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_entry = new QLineEdit(centralwidget);
        lineEdit_entry->setObjectName(QString::fromUtf8("lineEdit_entry"));

        horizontalLayout->addWidget(lineEdit_entry);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        pushButton_entryfind = new QPushButton(centralwidget);
        pushButton_entryfind->setObjectName(QString::fromUtf8("pushButton_entryfind"));
        pushButton_entryfind->setMaximumSize(QSize(16777215, 70));

        horizontalLayout_9->addWidget(pushButton_entryfind);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_9);


        verticalLayout_5->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButton_mostproduction = new QPushButton(centralwidget);
        pushButton_mostproduction->setObjectName(QString::fromUtf8("pushButton_mostproduction"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_mostproduction->sizePolicy().hasHeightForWidth());
        pushButton_mostproduction->setSizePolicy(sizePolicy2);
        pushButton_mostproduction->setMinimumSize(QSize(0, 0));
        pushButton_mostproduction->setMaximumSize(QSize(250, 70));

        horizontalLayout_8->addWidget(pushButton_mostproduction);


        verticalLayout_5->addLayout(horizontalLayout_8);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEdit_production = new QLineEdit(centralwidget);
        lineEdit_production->setObjectName(QString::fromUtf8("lineEdit_production"));

        horizontalLayout_2->addWidget(lineEdit_production);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButton_productionfind = new QPushButton(centralwidget);
        pushButton_productionfind->setObjectName(QString::fromUtf8("pushButton_productionfind"));
        pushButton_productionfind->setMaximumSize(QSize(16777215, 70));

        horizontalLayout_4->addWidget(pushButton_productionfind);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(verticalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_4->addWidget(label_7);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        lineEdit_name = new QLineEdit(centralwidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        horizontalLayout_7->addWidget(lineEdit_name);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButton_makechart = new QPushButton(centralwidget);
        pushButton_makechart->setObjectName(QString::fromUtf8("pushButton_makechart"));
        sizePolicy2.setHeightForWidth(pushButton_makechart->sizePolicy().hasHeightForWidth());
        pushButton_makechart->setSizePolicy(sizePolicy2);
        pushButton_makechart->setMinimumSize(QSize(0, 0));
        pushButton_makechart->setMaximumSize(QSize(250, 70));

        horizontalLayout_3->addWidget(pushButton_makechart);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_reset = new QPushButton(centralwidget);
        pushButton_reset->setObjectName(QString::fromUtf8("pushButton_reset"));
        sizePolicy2.setHeightForWidth(pushButton_reset->sizePolicy().hasHeightForWidth());
        pushButton_reset->setSizePolicy(sizePolicy2);
        pushButton_reset->setMaximumSize(QSize(250, 70));

        horizontalLayout_6->addWidget(pushButton_reset);


        verticalLayout_5->addLayout(horizontalLayout_6);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_back = new QPushButton(centralwidget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        sizePolicy2.setHeightForWidth(pushButton_back->sizePolicy().hasHeightForWidth());
        pushButton_back->setSizePolicy(sizePolicy2);
        pushButton_back->setMaximumSize(QSize(250, 70));

        horizontalLayout_5->addWidget(pushButton_back);


        verticalLayout_5->addLayout(horizontalLayout_5);


        horizontalLayout_10->addLayout(verticalLayout_5);

        GridWindow->setCentralWidget(centralwidget);

        retranslateUi(GridWindow);

        QMetaObject::connectSlotsByName(GridWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GridWindow)
    {
        GridWindow->setWindowTitle(QCoreApplication::translate("GridWindow", "\320\237\320\276\320\272\320\260\320\267 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\276\320\262", nullptr));
        label->setText(QCoreApplication::translate("GridWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">\320\232\320\276\320\274\320\260\320\275\320\264\321\213</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("GridWindow", "<html><head/><body><p align=\"center\">\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\264\320\260\321\202\320\265</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("GridWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\321\202\321\203", nullptr));
        pushButton_entryfind->setText(QCoreApplication::translate("GridWindow", "\320\222\320\262\320\265\321\201\321\202\320\270", nullptr));
        pushButton_mostproduction->setText(QCoreApplication::translate("GridWindow", "\320\237\320\276\320\270\321\201\320\272 \320\275\320\260\320\270\320\261\320\276\320\273\321\214\321\210\320\265\320\271 \321\201\321\202\320\276\320\270\320\274\320\276\321\201\321\202\320\270 \320\277\320\260\321\200\321\202\320\270\320\270", nullptr));
        label_4->setText(QCoreApplication::translate("GridWindow", "<html><head/><body><p align=\"center\">\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\276\320\261\321\212\320\265\320\274\321\203 \320\277\320\260\321\200\321\202\320\270\320\270</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("GridWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\320\261\321\212\320\265\320\274 \320\277\320\260\321\200\321\202\320\270\320\270", nullptr));
        pushButton_productionfind->setText(QCoreApplication::translate("GridWindow", "\320\222\320\262\320\265\321\201\321\202\320\270", nullptr));
        label_7->setText(QCoreApplication::translate("GridWindow", "<html><head/><body><p align=\"center\">\320\237\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\320\265 \320\263\321\200\320\260\321\204\320\270\320\272\320\260</p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("GridWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\267\320\260\320\262\320\260\320\275\320\270\320\265 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\260", nullptr));
        pushButton_makechart->setText(QCoreApplication::translate("GridWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214", nullptr));
        pushButton_reset->setText(QCoreApplication::translate("GridWindow", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        pushButton_back->setText(QCoreApplication::translate("GridWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GridWindow: public Ui_GridWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRIDWINDOW_H
