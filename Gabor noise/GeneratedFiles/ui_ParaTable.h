/********************************************************************************
** Form generated from reading UI file 'ParaTable.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARATABLE_H
#define UI_PARATABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParaTable
{
public:
    QTableWidget *tableWidget;
    QSpinBox *Seed;
    QLabel *label;
    QSpinBox *KernelNum;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *Contrast;
    QWidget *widget;
    QLabel *Image;
    QLabel *label_4;
    QSlider *Fnum;
    QSlider *Wnum;
    QSlider *Anum;
    QSlider *Pnum;
    QPushButton *New;
    QPushButton *Delete;
    QPushButton *Save;
    QPushButton *Load;
    QPushButton *OK;

    void setupUi(QWidget *ParaTable)
    {
        if (ParaTable->objectName().isEmpty())
            ParaTable->setObjectName(QString::fromUtf8("ParaTable"));
        ParaTable->resize(789, 487);
        tableWidget = new QTableWidget(ParaTable);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 60, 491, 291));
        tableWidget->setMouseTracking(false);
        tableWidget->setFocusPolicy(Qt::StrongFocus);
        tableWidget->setShowGrid(true);
        tableWidget->setRowCount(5);
        tableWidget->setColumnCount(4);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(120);
        tableWidget->horizontalHeader()->setMinimumSectionSize(120);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        Seed = new QSpinBox(ParaTable);
        Seed->setObjectName(QString::fromUtf8("Seed"));
        Seed->setGeometry(QRect(80, 20, 61, 22));
        label = new QLabel(ParaTable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 51, 20));
        KernelNum = new QSpinBox(ParaTable);
        KernelNum->setObjectName(QString::fromUtf8("KernelNum"));
        KernelNum->setGeometry(QRect(260, 20, 61, 22));
        KernelNum->setMinimum(5);
        KernelNum->setMaximum(100);
        KernelNum->setSingleStep(5);
        KernelNum->setValue(20);
        label_2 = new QLabel(ParaTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 20, 81, 20));
        label_3 = new QLabel(ParaTable);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(350, 20, 81, 20));
        Contrast = new QDoubleSpinBox(ParaTable);
        Contrast->setObjectName(QString::fromUtf8("Contrast"));
        Contrast->setGeometry(QRect(430, 20, 70, 22));
        Contrast->setDecimals(1);
        Contrast->setMaximum(3.000000000000000);
        Contrast->setSingleStep(0.200000000000000);
        Contrast->setValue(1.000000000000000);
        widget = new QWidget(ParaTable);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(560, 250, 200, 200));
        widget->setMinimumSize(QSize(200, 200));
        widget->setMaximumSize(QSize(200, 200));
        Image = new QLabel(ParaTable);
        Image->setObjectName(QString::fromUtf8("Image"));
        Image->setGeometry(QRect(560, 40, 200, 200));
        Image->setMinimumSize(QSize(200, 200));
        Image->setMaximumSize(QSize(200, 200));
        label_4 = new QLabel(ParaTable);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(650, 20, 72, 15));
        Fnum = new QSlider(ParaTable);
        Fnum->setObjectName(QString::fromUtf8("Fnum"));
        Fnum->setGeometry(QRect(20, 360, 101, 22));
        Fnum->setOrientation(Qt::Horizontal);
        Wnum = new QSlider(ParaTable);
        Wnum->setObjectName(QString::fromUtf8("Wnum"));
        Wnum->setGeometry(QRect(140, 360, 101, 22));
        Wnum->setOrientation(Qt::Horizontal);
        Anum = new QSlider(ParaTable);
        Anum->setObjectName(QString::fromUtf8("Anum"));
        Anum->setGeometry(QRect(270, 360, 101, 22));
        Anum->setOrientation(Qt::Horizontal);
        Pnum = new QSlider(ParaTable);
        Pnum->setObjectName(QString::fromUtf8("Pnum"));
        Pnum->setGeometry(QRect(390, 360, 101, 22));
        Pnum->setOrientation(Qt::Horizontal);
        New = new QPushButton(ParaTable);
        New->setObjectName(QString::fromUtf8("New"));
        New->setGeometry(QRect(20, 410, 93, 28));
        Delete = new QPushButton(ParaTable);
        Delete->setObjectName(QString::fromUtf8("Delete"));
        Delete->setGeometry(QRect(140, 410, 93, 28));
        Save = new QPushButton(ParaTable);
        Save->setObjectName(QString::fromUtf8("Save"));
        Save->setGeometry(QRect(260, 410, 93, 28));
        Load = new QPushButton(ParaTable);
        Load->setObjectName(QString::fromUtf8("Load"));
        Load->setGeometry(QRect(380, 410, 93, 28));
        OK = new QPushButton(ParaTable);
        OK->setObjectName(QString::fromUtf8("OK"));
        OK->setGeometry(QRect(190, 440, 101, 41));

        retranslateUi(ParaTable);

        QMetaObject::connectSlotsByName(ParaTable);
    } // setupUi

    void retranslateUi(QWidget *ParaTable)
    {
        ParaTable->setWindowTitle(QApplication::translate("ParaTable", "ParaTable", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ParaTable", "F", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ParaTable", "W", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ParaTable", "A", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ParaTable", "P", nullptr));
        label->setText(QApplication::translate("ParaTable", "Seed:", nullptr));
        KernelNum->setSuffix(QString());
        KernelNum->setPrefix(QString());
        label_2->setText(QApplication::translate("ParaTable", "KernelNum:", nullptr));
        label_3->setText(QApplication::translate("ParaTable", "Contrast:", nullptr));
        Image->setText(QString());
        label_4->setText(QApplication::translate("ParaTable", "\351\242\204\350\247\210", nullptr));
        New->setText(QApplication::translate("ParaTable", "New", nullptr));
        Delete->setText(QApplication::translate("ParaTable", "Delete", nullptr));
        Save->setText(QApplication::translate("ParaTable", "Save", nullptr));
        Load->setText(QApplication::translate("ParaTable", "Load", nullptr));
        OK->setText(QApplication::translate("ParaTable", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ParaTable: public Ui_ParaTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARATABLE_H
