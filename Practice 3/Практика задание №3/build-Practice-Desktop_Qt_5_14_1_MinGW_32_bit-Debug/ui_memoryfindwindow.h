/********************************************************************************
** Form generated from reading UI file 'memoryfindwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMORYFINDWINDOW_H
#define UI_MEMORYFINDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MemoryFindWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MemoryFindWindow)
    {
        if (MemoryFindWindow->objectName().isEmpty())
            MemoryFindWindow->setObjectName(QString::fromUtf8("MemoryFindWindow"));
        MemoryFindWindow->resize(286, 153);
        centralwidget = new QWidget(MemoryFindWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(pushButton);

        MemoryFindWindow->setCentralWidget(centralwidget);

        retranslateUi(MemoryFindWindow);

        QMetaObject::connectSlotsByName(MemoryFindWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MemoryFindWindow)
    {
        MemoryFindWindow->setWindowTitle(QCoreApplication::translate("MemoryFindWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\236\320\227\320\243", nullptr));
        label->setText(QCoreApplication::translate("MemoryFindWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\236\320\227\320\243 \320\262 \320\223\320\261", nullptr));
        pushButton->setText(QCoreApplication::translate("MemoryFindWindow", "\320\222\320\262\320\265\321\201\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MemoryFindWindow: public Ui_MemoryFindWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMORYFINDWINDOW_H
