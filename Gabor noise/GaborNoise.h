#pragma once
#include "ConstNum.h"
#include <QtWidgets/QMainWindow>
#include <qpainter.h>
#include <qimage.h>
#include <qlabel.h>
#include <iostream>
#include <random>
#include "Image.h"
#include "MathFun2d.h"
#include "TryGabor.h"
#include "ui_MainWindow.h"
#include <qkeyeventtransition.h>
using Karl07::Image;
using Karl07::Func;
using Karl07::Gaussian;
using Karl07::Harmonic;
using Karl07::ConstNum;
using Karl07::Range;
using Karl07::Delta;
using Karl07::KernelMaker;
using Karl07::Gabor;
using Karl07::RandEngine;
using Karl07::Merge;
using namespace Karl07::Setting;
using namespace Karl07::Const;

class GaborNoise : public QMainWindow
{
	Q_OBJECT

public:
	GaborNoise(QWidget *parent = Q_NULLPTR);
	using Fun = function<double(double, double)>const &;
private:
	void showImg(Image& img, QLabel &lable);
	void saveImg(Image & img, const char * s);
	void keyPressEvent(QKeyEvent *e);
	QPaintDevice * m_painterDevice;
	QPainter * m_painter;
	QImage *img1, *img2, *img3;
	QLabel *lable;

	Ui::MainWindow ui;
};
