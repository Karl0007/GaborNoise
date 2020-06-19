/********************************************************************************
** Form generated from reading UI file 'ColorSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORSETTING_H
#define UI_COLORSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorSetting
{
public:
    QLabel *ColorView;
    QPushButton *Del;
    QPushButton *Load;
    QPushButton *Save;
    QPushButton *Edit;
    QTableWidget *TableView;
    QSpinBox *Pos;
    QLabel *label;

    void setupUi(QWidget *ColorSetting)
    {
        if (ColorSetting->objectName().isEmpty())
            ColorSetting->setObjectName(QString::fromUtf8("ColorSetting"));
        ColorSetting->resize(564, 500);
        ColorView = new QLabel(ColorSetting);
        ColorView->setObjectName(QString::fromUtf8("ColorView"));
        ColorView->setGeometry(QRect(30, 20, 70, 450));
        Del = new QPushButton(ColorSetting);
        Del->setObjectName(QString::fromUtf8("Del"));
        Del->setGeometry(QRect(300, 460, 61, 31));
        Load = new QPushButton(ColorSetting);
        Load->setObjectName(QString::fromUtf8("Load"));
        Load->setGeometry(QRect(220, 460, 61, 31));
        Save = new QPushButton(ColorSetting);
        Save->setObjectName(QString::fromUtf8("Save"));
        Save->setGeometry(QRect(140, 460, 61, 31));
        Edit = new QPushButton(ColorSetting);
        Edit->setObjectName(QString::fromUtf8("Edit"));
        Edit->setGeometry(QRect(380, 460, 61, 31));
        TableView = new QTableWidget(ColorSetting);
        if (TableView->columnCount() < 4)
            TableView->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TableView->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TableView->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TableView->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TableView->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        TableView->setObjectName(QString::fromUtf8("TableView"));
        TableView->setGeometry(QRect(130, 20, 421, 421));
        Pos = new QSpinBox(ColorSetting);
        Pos->setObjectName(QString::fromUtf8("Pos"));
        Pos->setGeometry(QRect(490, 460, 51, 31));
        Pos->setMaximum(255);
        Pos->setSingleStep(0);
        label = new QLabel(ColorSetting);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(460, 460, 31, 31));

        retranslateUi(ColorSetting);

        QMetaObject::connectSlotsByName(ColorSetting);
    } // setupUi

    void retranslateUi(QWidget *ColorSetting)
    {
        ColorSetting->setWindowTitle(QApplication::translate("ColorSetting", "ColorSetting", nullptr));
        ColorView->setText(QString());
        Del->setText(QApplication::translate("ColorSetting", "Del", nullptr));
        Load->setText(QApplication::translate("ColorSetting", "Load", nullptr));
        Save->setText(QApplication::translate("ColorSetting", "Save", nullptr));
        Edit->setText(QApplication::translate("ColorSetting", "Edit", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TableView->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ColorSetting", "Pos", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TableView->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ColorSetting", "R", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TableView->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ColorSetting", "G", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = TableView->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ColorSetting", "B", nullptr));
        label->setText(QApplication::translate("ColorSetting", "Pos\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ColorSetting: public Ui_ColorSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORSETTING_H
