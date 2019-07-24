#pragma once

#include <QWidget>
#include <qpainter.h>
#include <qtablewidget.h>
#include "ConstNum.h"
#include <iostream>
using namespace Karl07::Setting;

class QtPainterWidget : public QWidget
{
	Q_OBJECT

private:
	QTableWidget const*table;
	int row;
public:
	QtPainterWidget(QWidget *parent, QTableWidget const & w);
	~QtPainterWidget();
	void PaintTable(int row = -1);
	void PaintCircle(QPainter &, double f, double w, double a, double p, double fr, double wr);
	void PaintCircle(QPainter &,double f, double w, double a,double p);
	void paintEvent(QPaintEvent *);
};
