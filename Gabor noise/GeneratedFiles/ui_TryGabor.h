/********************************************************************************
** Form generated from reading UI file 'TryGabor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRYGABOR_H
#define UI_TRYGABOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TryGabor
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLabel *Picture;
    QVBoxLayout *Settings;
    QHBoxLayout *Size;
    QLabel *label_3;
    QSlider *SSlider;
    QDoubleSpinBox *SSpinBox;
    QHBoxLayout *Deg;
    QLabel *label;
    QSlider *DSlider;
    QDoubleSpinBox *DSpinBox;
    QHBoxLayout *Fre;
    QLabel *label_2;
    QSlider *FSlider;
    QDoubleSpinBox *FSpinBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *Kernel;
    QPushButton *Save;
    QPushButton *Texture;

    void setupUi(QWidget *TryGabor)
    {
        if (TryGabor->objectName().isEmpty())
            TryGabor->setObjectName(QString::fromUtf8("TryGabor"));
        TryGabor->setEnabled(true);
        TryGabor->resize(200, 350);
        TryGabor->setMinimumSize(QSize(200, 350));
        verticalLayoutWidget_2 = new QWidget(TryGabor);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 201, 341));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Picture = new QLabel(verticalLayoutWidget_2);
        Picture->setObjectName(QString::fromUtf8("Picture"));
        Picture->setMinimumSize(QSize(200, 200));
        Picture->setMaximumSize(QSize(200, 200));

        verticalLayout->addWidget(Picture);

        Settings = new QVBoxLayout();
        Settings->setSpacing(6);
        Settings->setObjectName(QString::fromUtf8("Settings"));
        Size = new QHBoxLayout();
        Size->setSpacing(6);
        Size->setObjectName(QString::fromUtf8("Size"));
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        Size->addWidget(label_3);

        SSlider = new QSlider(verticalLayoutWidget_2);
        SSlider->setObjectName(QString::fromUtf8("SSlider"));
        SSlider->setEnabled(true);
        SSlider->setMinimum(0);
        SSlider->setMaximum(10000);
        SSlider->setSingleStep(0);
        SSlider->setOrientation(Qt::Horizontal);

        Size->addWidget(SSlider);

        SSpinBox = new QDoubleSpinBox(verticalLayoutWidget_2);
        SSpinBox->setObjectName(QString::fromUtf8("SSpinBox"));
        SSpinBox->setReadOnly(false);
        SSpinBox->setDecimals(1);
        SSpinBox->setMinimum(0.500000000000000);
        SSpinBox->setMaximum(100.000000000000000);
        SSpinBox->setSingleStep(1.000000000000000);
        SSpinBox->setValue(3.000000000000000);

        Size->addWidget(SSpinBox);


        Settings->addLayout(Size);

        Deg = new QHBoxLayout();
        Deg->setSpacing(6);
        Deg->setObjectName(QString::fromUtf8("Deg"));
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        Deg->addWidget(label);

        DSlider = new QSlider(verticalLayoutWidget_2);
        DSlider->setObjectName(QString::fromUtf8("DSlider"));
        DSlider->setEnabled(true);
        DSlider->setMaximum(10000);
        DSlider->setSingleStep(0);
        DSlider->setOrientation(Qt::Horizontal);

        Deg->addWidget(DSlider);

        DSpinBox = new QDoubleSpinBox(verticalLayoutWidget_2);
        DSpinBox->setObjectName(QString::fromUtf8("DSpinBox"));
        DSpinBox->setReadOnly(false);
        DSpinBox->setDecimals(2);
        DSpinBox->setMaximum(1.000000000000000);
        DSpinBox->setSingleStep(0.100000000000000);

        Deg->addWidget(DSpinBox);


        Settings->addLayout(Deg);

        Fre = new QHBoxLayout();
        Fre->setSpacing(6);
        Fre->setObjectName(QString::fromUtf8("Fre"));
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        Fre->addWidget(label_2);

        FSlider = new QSlider(verticalLayoutWidget_2);
        FSlider->setObjectName(QString::fromUtf8("FSlider"));
        FSlider->setEnabled(true);
        FSlider->setMaximum(10000);
        FSlider->setSingleStep(0);
        FSlider->setOrientation(Qt::Horizontal);

        Fre->addWidget(FSlider);

        FSpinBox = new QDoubleSpinBox(verticalLayoutWidget_2);
        FSpinBox->setObjectName(QString::fromUtf8("FSpinBox"));
        FSpinBox->setReadOnly(false);
        FSpinBox->setDecimals(1);
        FSpinBox->setMinimum(0.500000000000000);
        FSpinBox->setMaximum(100.000000000000000);
        FSpinBox->setSingleStep(1.000000000000000);
        FSpinBox->setValue(3.000000000000000);

        Fre->addWidget(FSpinBox);


        Settings->addLayout(Fre);


        verticalLayout->addLayout(Settings);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Kernel = new QPushButton(verticalLayoutWidget_2);
        Kernel->setObjectName(QString::fromUtf8("Kernel"));

        horizontalLayout->addWidget(Kernel);

        Save = new QPushButton(verticalLayoutWidget_2);
        Save->setObjectName(QString::fromUtf8("Save"));

        horizontalLayout->addWidget(Save);

        Texture = new QPushButton(verticalLayoutWidget_2);
        Texture->setObjectName(QString::fromUtf8("Texture"));

        horizontalLayout->addWidget(Texture);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(TryGabor);

        QMetaObject::connectSlotsByName(TryGabor);
    } // setupUi

    void retranslateUi(QWidget *TryGabor)
    {
        TryGabor->setWindowTitle(QApplication::translate("TryGabor", "TryGabor", nullptr));
        Picture->setText(QString());
        label_3->setText(QApplication::translate("TryGabor", "Size:", nullptr));
        label->setText(QApplication::translate("TryGabor", "Deg:", nullptr));
        label_2->setText(QApplication::translate("TryGabor", "Fre:", nullptr));
        Kernel->setText(QApplication::translate("TryGabor", "Kernel", nullptr));
        Save->setText(QApplication::translate("TryGabor", "Save", nullptr));
        Texture->setText(QApplication::translate("TryGabor", "Texture", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TryGabor: public Ui_TryGabor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRYGABOR_H
