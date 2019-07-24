#include "QtPainterWidget.h"

QtPainterWidget::QtPainterWidget(QWidget *parent, QTableWidget const & w)
	: QWidget(parent)
{
	setFixedSize(200, 200);
	table = &w;
	row = -1;

}

QtPainterWidget::~QtPainterWidget()
{
}

void QtPainterWidget::PaintTable(int r)
{
	row = r;
}

void QtPainterWidget::PaintCircle(QPainter &painter,double f, double w, double a)
{
	QPointF center(100 + cos(w)*f*50, 100 + sin(w)*f*50);
	QRadialGradient brush(center, a);
	////rgbrush.setCenter(0, 0);
	brush.setColorAt(1, QColor(0, 0, 0, 0));
	brush.setColorAt(0, QColor(255, 255, 255, 100));
	painter.setBrush(brush);
	painter.setPen(QColor(0, 0, 0, 0));
	painter.drawEllipse(center, a, a);
}

void QtPainterWidget::paintEvent(QPaintEvent * e)
{
	QPainter painter(this);
	static QPoint center(100, 100);
	painter.setBrush(QBrush(Qt::black));
	painter.drawRect(0, 0, 200, 200);
	if (row == -1) {
		for (int i = 0; i < table->rowCount(); i++) {
			PaintCircle(painter, table->item(i, 0)->text().toDouble(), table->item(i, 1)->text().toDouble(), 25);
			PaintCircle(painter, -table->item(i, 0)->text().toDouble(), table->item(i, 1)->text().toDouble(), 25);
		}
	}
	else {
		PaintCircle(painter, table->item(row, 0)->text().toDouble(), table->item(row, 1)->text().toDouble(), 25);
		PaintCircle(painter, -table->item(row, 0)->text().toDouble(), table->item(row, 1)->text().toDouble(), 25);
	}
	//painter.setBrush(rgbrush);
	//painter.drawEllipse(QPointF(50, 50), 50, 50);
	//painter.drawEllipse(QPointF(60, 60), 50, 50);
	////painter.setBrush(QBrush(QColor("black"),Qt::RadialGradientPattern));
	//painter.setBackground(QBrush(QColor("black")));
	//painter.drawPoint(100, 100);
}
