#pragma once

#include <QWidget>
#include <iostream>
#include "ui_ParaTable.h"
#include "MathFun2d.h"
#include "qpainter.h"
#include "QtPainterWidget.h"
#include "Gabor.h"
#include "Image.h"
using Karl07::KernelMaker;
using Karl07::Image;
using Karl07::KernelData;
using Karl07::Range;
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
	//void FminChange(int);
	//void FmaxChange(int);
	//void WminChange(int);
	//void WmaxChange(int);
	//void AChange(int);
	//void PChange(int);

private:
	double fmin, fmax, wmin, wmax,pnum,anum;
	void setNew(int index,int from);
	void getNum(int index);
	QtPainterWidget *painter;
	Ui::ParaTable ui;
};
