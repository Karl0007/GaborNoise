#include "TryGabor.h"

TryGabor::TryGabor(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	BindData(*ui.DSlider, *ui.DSpinBox);
	BindData(*ui.SSlider, *ui.SSpinBox);
	BindData(*ui.FSlider,*ui.FSpinBox);
	QObject::connect(ui.Save, &QPushButton::clicked, this, &TryGabor::Save);
	QObject::connect(ui.Add, &QPushButton::clicked, this, &TryGabor::addToList);
	QObject::connect(ui.Gabor, &QPushButton::clicked, this, &TryGabor::GaborShow);
	DrawOnLable0();

	auto mpaint = new QtPainterWidget(nullptr);
	mpaint->show();


	//auto x = new GLPainter(ui.widget);
	//x->show();
	//x->paintGL();
	//x->initializeGL();
	//x->show();
}

TryGabor::~TryGabor()
{
}

void TryGabor::BindData(QSlider& slider, QDoubleSpinBox & spin)
{
	void (QDoubleSpinBox::*px)(double) = &QDoubleSpinBox::valueChanged;
	QObject::connect(&slider, &QSlider::sliderMoved, [&](int val) {spin.setValue(Range(spin.minimum(), spin.maximum()).Reflect(Range(slider.minimum(), slider.maximum()).Normalize(val))); });
	QObject::connect(&spin, px, [&](double val) {slider.setValue(Range(slider.minimum(),slider.maximum()).Reflect(Range(spin.minimum(), spin.maximum()).Normalize(val)));});
	QObject::connect(&slider, &QSlider::sliderMoved, this, &TryGabor::DrawOnLable0);
	QObject::connect(&spin, px, this, &TryGabor::DrawOnLable0);
}

void TryGabor::DrawOnLable(QLabel & lable, double F, double W)
{
	static Image img(lable.size().width(), lable.size().height());
	img.Reset(KernelMaker(KernelData(Range(F, F), Range(W, W))).Make());
	lable.setPixmap(QPixmap::fromImage(QImage(img.m_data, img.W(), img.H(), QImage::Format::Format_RGBA8888)));
}


void TryGabor::Save() {
	auto file = QFileDialog::getSaveFileName();
	ui.Picture->pixmap()->save(file);
}

void TryGabor::addToList()
{
	vec.push_back(KernelData(
		Range(ui.FSpinBox->value(), ui.FSpinBox->value()),
		Range(ui.DSpinBox->value(), ui.DSpinBox->value())
	));
}

void TryGabor::GaborShow()
{
	if (vec.empty()) return;
	static Image img(ui.Picture->size().width(), ui.Picture->size().height());
	img.Reset(GaborMaker(vec,3)(1));
	vec.clear();
	ui.Picture->setPixmap(QPixmap::fromImage(QImage(img.m_data, img.W(), img.H(), QImage::Format::Format_RGBA8888)));
}

void TryGabor::DrawOnLable0()
{
	DrawOnLable(*ui.Picture,ui.FSpinBox->value(),ui.DSpinBox->value());
}
