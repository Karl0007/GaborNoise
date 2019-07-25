/********************************************************************************
** Form generated from reading UI file 'GaborNoiseView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GABORNOISEVIEW_H
#define UI_GABORNOISEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GaborNoiseView
{
public:
    QWidget *W1;
    QWidget *W2;

    void setupUi(QWidget *GaborNoiseView)
    {
        if (GaborNoiseView->objectName().isEmpty())
            GaborNoiseView->setObjectName(QString::fromUtf8("GaborNoiseView"));
        GaborNoiseView->resize(573, 303);
        W1 = new QWidget(GaborNoiseView);
        W1->setObjectName(QString::fromUtf8("W1"));
        W1->setGeometry(QRect(20, 20, 256, 256));
        W1->setMinimumSize(QSize(256, 256));
        W1->setMaximumSize(QSize(256, 256));
        W2 = new QWidget(GaborNoiseView);
        W2->setObjectName(QString::fromUtf8("W2"));
        W2->setGeometry(QRect(290, 20, 256, 256));
        W2->setMinimumSize(QSize(256, 256));
        W2->setMaximumSize(QSize(256, 256));

        retranslateUi(GaborNoiseView);

        QMetaObject::connectSlotsByName(GaborNoiseView);
    } // setupUi

    void retranslateUi(QWidget *GaborNoiseView)
    {
        GaborNoiseView->setWindowTitle(QApplication::translate("GaborNoiseView", "GaborNoiseView", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GaborNoiseView: public Ui_GaborNoiseView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GABORNOISEVIEW_H
