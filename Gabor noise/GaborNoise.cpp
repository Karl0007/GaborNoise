#include "GaborNoise.h"

GaborNoise::GaborNoise(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	TryGabor *tg = new TryGabor(this);
	//tg->show();
	GLPainter *P = new GLPainter(this);
	//P->show();
	ui.horizontalLayout->addWidget(tg);
	ui.horizontalLayout->addWidget(P);
	RandEngine.seed(time(0));
	setFixedSize(MainSizeW, MainSizeH);
}

void GaborNoise::showImg(Image & img, QLabel & lable)
{
	lable.setPixmap(QPixmap::fromImage(QImage(img.m_data, img.W(), img.H(), QImage::Format::Format_RGB888)));
}

void GaborNoise::saveImg(Image & img,const char *s)
{
	QImage(img.m_data, img.W(), img.H(), QImage::Format::Format_RGB888).save(s);
}

void GaborNoise::keyPressEvent(QKeyEvent * e)
{
	cout << 123 << endl;
}

