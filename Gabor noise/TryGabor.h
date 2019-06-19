#pragma once

#include <QWidget>
#include <qmessagebox.h>
#include <qfiledialog.h>
#include "ui_TryGabor.h"
#include "MathFun2d.h"
#include "Image.h"
#include "Gabor.h"
#include "GLPainter.h"
#include "QtPainterWidget.h"
#include <qpaintdevice.h>
using Karl07::Range;
using Karl07::Image;
using Karl07::Gaussian;
using Karl07::Harmonic;
using Karl07::Gabor;
using Karl07::GaborMaker;
using Karl07::KernelData;
using Karl07::KernelMaker;

class TryGabor : public QWidget
{
	Q_OBJECT
public:
	TryGabor(QWidget *parent = Q_NULLPTR);
	~TryGabor();

private slots:
	void DrawOnLable0();
	void Save();
	void addToList();
	void GaborShow();

private:
	vector<KernelData> vec;
	void BindData(QSlider &slider, QDoubleSpinBox &spin);
	void DrawOnLable(QLabel & lable, double F, double W);
	Ui::TryGabor ui;
};
