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


void QtPainterWidget::PaintCircle(QPainter &painter, double fi, double wi, double a, double p)
{
	a *= 20;
	QPointF center(100 + cos(wi)*fi * 20, 100 + sin(wi)*fi * 20);
	QRadialGradient brush(center, a);
	brush.setColorAt(1, QColor(0, 0, 0, 0));
	brush.setColorAt(0, QColor(255, 255, 255, std::max(40.0,200 * p)));
	painter.setBrush(brush);
	painter.setPen(QColor(0, 0, 0, 0));
	painter.drawEllipse(center, a, a);
}

void QtPainterWidget::PaintCircle(QPainter &painter,double f, double w, double a,double p,double fr,double wr)
{
	static const double step = 0.5;
	double ap = std::max(1.0,(-std::max(FMIN, f - fr)+std::min(FMAX, f + fr)) / step)*std::max( 1.0, (-std::max(WMIN, w - wr) + std::min(WMAX, w + wr)) / step);
	for (auto fi = std::max(FMIN, f - fr); fi <= std::min(FMAX, f + fr); fi += step) {
		for (auto wi = std::max(WMIN, w - wr); wi <= std::min(WMAX, w + wr); wi += step) {
			PaintCircle(painter, fi, wi, a, p/ap);
			PaintCircle(painter, -fi, wi, a, p/ap);

		}
	}

}

void QtPainterWidget::paintEvent(QPaintEvent * e)
{
	QPainter painter(this);
	static QPoint center(100, 100);
	painter.setBrush(QBrush(Qt::black));
	painter.drawRect(0, 0, 200, 200);
	double ap = 0;
	for (int i = 0; i < table->rowCount(); i++) {
		ap += table->item(i, 3)->text().toDouble();
	}
	for (int i = 0; i < table->rowCount(); i++) {
		PaintCircle(painter, table->item(i, 0)->text().toDouble(), table->item(i, 1)->text().toDouble(), table->item(i, 2)->text().toDouble(), table->item(i, 3)->text().toDouble() / ap);
		PaintCircle(painter, -table->item(i, 0)->text().toDouble(), table->item(i, 1)->text().toDouble(), table->item(i, 2)->text().toDouble(), table->item(i, 3)->text().toDouble() / ap);
	}


	//painter.setBrush(rgbrush);
	//painter.drawEllipse(QPointF(50, 50), 50, 50);
	//painter.drawEllipse(QPointF(60, 60), 50, 50);
	////painter.setBrush(QBrush(QColor("black"),Qt::RadialGradientPattern));
	//painter.setBackground(QBrush(QColor("black")));
	//painter.drawPoint(100, 100);
}
