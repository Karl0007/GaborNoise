#include "QtPainterWidget.h"

QtPainterWidget::QtPainterWidget(QWidget *parent)
	: QWidget(parent)
{
	setFixedSize(600, 600);
}

QtPainterWidget::~QtPainterWidget()
{
}

void QtPainterWidget::paintEvent(QPaintEvent * e)
{
	QPainter painter(this);
	QRadialGradient rgbrush(QPointF(50, 50), 50, QPointF(50, 50));
	//rgbrush.setCenter(0, 0);
	rgbrush.setColorAt(0, Qt::green);
	rgbrush.setColorAt(1, Qt::red);
	painter.setBrush(rgbrush);
	painter.drawEllipse(QPointF(50, 50), 50, 50);
	painter.drawEllipse(QPointF(60, 60), 50, 50);
	//painter.setBrush(QBrush(QColor("black"),Qt::RadialGradientPattern));
	painter.setBackground(QBrush(QColor("black")));
	painter.drawPoint(100, 100);
}
