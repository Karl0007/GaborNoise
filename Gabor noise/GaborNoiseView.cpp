#include "GaborNoiseView.h"

GaborNoiseView::GaborNoiseView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setFixedSize(size());
}

GaborNoiseView::~GaborNoiseView()
{
}

void GaborNoiseView::closeEvent(QCloseEvent * e)
{
	delete this;
}
