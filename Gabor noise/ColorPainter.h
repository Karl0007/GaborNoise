#pragma once

#include <QWidget>
#include "Color.h"
#include "qpainter.h"
#include "qevent.h"
#include "qspinbox.h"
using Karl07::ColorMap;
class ColorSetting;
class ColorPainter : public QWidget
{
	Q_OBJECT
	friend ColorSetting;
public:
	ColorPainter(QWidget *parent,ColorMap &map, QSpinBox &pos);
	~ColorPainter();
	void paintEvent(QPaintEvent *);
	void drawPos(QPainter &painter);
signals:
	void mouseMoveEvent(QMouseEvent *e);
private:
	QSpinBox &posBox;
	ColorMap &map;
};
