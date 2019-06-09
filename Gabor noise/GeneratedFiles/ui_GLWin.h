/********************************************************************************
** Form generated from reading UI file 'GLWin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLWIN_H
#define UI_GLWIN_H

#include <QtCore/QVariant>
#include <QtOpenGL/QGLWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QOpenGLWidget>

QT_BEGIN_NAMESPACE

class Ui_GLWin
{
public:
    QOpenGLWidget *openGLWidget;

    void setupUi(QGLWidget *GLWin)
    {
        if (GLWin->objectName().isEmpty())
            GLWin->setObjectName(QString::fromUtf8("GLWin"));
        GLWin->resize(400, 300);
        openGLWidget = new QOpenGLWidget(GLWin);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(20, 20, 331, 241));

        retranslateUi(GLWin);

        QMetaObject::connectSlotsByName(GLWin);
    } // setupUi

    void retranslateUi(QGLWidget *GLWin)
    {
        GLWin->setWindowTitle(QApplication::translate("GLWin", "GLWin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GLWin: public Ui_GLWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLWIN_H
