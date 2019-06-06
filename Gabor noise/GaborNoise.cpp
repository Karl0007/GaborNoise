#include "GaborNoise.h"

GaborNoise::GaborNoise(QWidget *parent)
	: QMainWindow(parent)
{
	TryGabor *tg = new TryGabor(this);
	//TryGabor *tg2 = new TryGabor();
	//tg2->show();
	tg->show();
	RandEngine.seed(time(0));
	setFixedSize(MainSizeW, MainSizeH);
	//lable = new QLabel(this);
	//lable->setFixedSize(PictrueW, PictrueH);
	//KernelMaker maker1(Range(0,1),Range(30,30),Range(1,1));
	//map<double, KernelMaker> mp;
	//mp[0] = maker1;
	////cout << mp.upper_bound(0.99)->first << endl;
	//Gabor g(mp);
	//uniform_real_distribution<double> d(-0.5,0.5);
	//for (int i = 0; i < 1000; i++) {
	//	g.AddPoint(d(RandEngine), d(RandEngine));
	//}
	//Image img2(PictrueW,PictrueH,g);
	//showImg(img2, *lable);
	//lable->show();


	//uniform_real_distribution<double> d(-0.5,0.5);
	//Delta fun(Range(0,PictrueW).step(),Range(0,PictrueH).step());
	//for (int i = 0; i < 1000; i++) {
	//	//fun.AddPoint(0, 0);
	//	fun.AddPoint(d(RandEngine),d(RandEngine));
	//}
	//Image img2(PictrueW,PictrueH, fun);// Harmonic(6, 3.14 / 4));
	//auto fu = Gaussian(7) *  Harmonic(7, 3.14 / 4);
	//Image img(50, 50, fu);// Harmonic(6, 3.14 / 4));
	//auto tmp = img2.Mul(img);
	//saveImg(tmp,"1.png");

}

void GaborNoise::showImg(Image & img, QLabel & lable)
{
	lable.setPixmap(QPixmap::fromImage(QImage(img.m_data, img.W(), img.H(), QImage::Format::Format_RGB888)));
}

void GaborNoise::saveImg(Image & img,const char *s)
{
	QImage(img.m_data, img.W(), img.H(), QImage::Format::Format_RGB888).save(s);
}

