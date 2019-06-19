#pragma once

#include <QWidget>
#include <qpainter.h>

class QtPainterWidget : public QWidget
{
	Q_OBJECT

public:
	QtPainterWidget(QWidget *parent);
	~QtPainterWidget();
	void paintEvent(QPaintEvent *);
};
