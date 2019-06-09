#include "GaborNoise.h"

GaborNoise::GaborNoise(QWidget *parent)
	: QMainWindow(parent)
{
	TryGabor *tg = new TryGabor(this);
	tg->show();
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

