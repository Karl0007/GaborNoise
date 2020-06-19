#pragma once

#include <QWidget>
#include <iostream>
#include <qfile.h>
#include <qfiledialog.h>
#include "ui_ParaTable.h"
#include "MathFun2d.h"
#include "qpainter.h"
#include "QtPainterWidget.h"
#include "Gabor.h"
#include "Image.h"
#include "GLPainter.h"
#include "GaborNoiseView.h"
#include "Color.h"
#include "ColorSetting.h"
using Karl07::KernelMaker;
using Karl07::Image;
using Karl07::KernelData;
using Karl07::Range;
using Karl07::GaborMaker;
using Karl07::Color;
using Karl07::ColorMap;
using namespace Karl07::Setting;

class ParaTable : public QWidget
{
	Q_OBJECT

public:
	ParaTable(QWidget *parent = Q_NULLPTR);
	~ParaTable();
	void paintEvent(QPaintEvent *e);

private slots:
	void AddNewRow();
	void DeleteRow();
	void TableClick(QModelIndex const& index);
	void Save();
	void Load();
	void OK();
	void Color();
	//void FminChange(int);
	//void FmaxChange(int);
	//void WminChange(int);
	//void WmaxChange(int);
	//void AChange(int);
	//void PChange(int);

private:
	double fmin, fmax, wmin, wmax,pnum,anum,frg,wrg;
	void setNew(int index,int from);
	void getNum(int index);
	ColorMap color_map;
	QtPainterWidget *painter;
	Ui::ParaTable ui;
};
