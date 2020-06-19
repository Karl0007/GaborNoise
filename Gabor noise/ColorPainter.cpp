#include "ColorPainter.h"

ColorPainter::ColorPainter(QWidget *parent,ColorMap &map,QSpinBox &pos)
	: QWidget(parent),map(map),posBox(pos)
{
	setFixedSize(70, 450);
}

ColorPainter::~ColorPainter()
{
}

void ColorPainter::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);

	QLinearGradient linear(QPointF(0, 0), QPointF(0, 450));
	for (auto &i : map.color_map) {
		linear.setColorAt(i.first*1.0 / 255, QColor(i.second.r, i.second.g, i.second.b));
	}
	linear.setSpread(QGradient::PadSpread);
	painter.setBrush(linear);
	painter.drawRect(QRect(0, 0, 50, 450));
	drawPos(painter);
}

void ColorPainter::drawPos(QPainter &painter)
{
	int pos = posBox.value()*1.0/255*450;
	painter.setPen(QPen(QColor(0, 0, 0), 3));
	QPoint points[3];
	points[0].setX(50);
	points[0].setY(pos);
	points[1].setX(60);
	points[1].setY(pos+5);
	points[2].setX(60);
	points[2].setY(pos-5);
	painter.drawPolygon(points, 3);
}
