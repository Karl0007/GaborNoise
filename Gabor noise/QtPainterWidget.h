#pragma once

#include <QWidget>
#include <qpainter.h>
#include <qtablewidget.h>
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
	void PaintCircle(QPainter &,double f, double w, double a = 50);
	void paintEvent(QPaintEvent *);
};
