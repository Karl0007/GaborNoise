#include "TryGabor.h"

TryGabor::TryGabor(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	BindData(*ui.DSlider, *ui.DSpinBox);
	BindData(*ui.SSlider, *ui.SSpinBox);
	BindData(*ui.FSlider,*ui.FSpinBox);
	QObject::connect(ui.Save, &QPushButton::clicked, this, &TryGabor::Save);
	DrawOnLable0();
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

	//QObject::connect(&spin, px, [&](double val) {slider.setValue(Range(spin.minimum(), spin.maximum()).Normalize(val)); });
}

void TryGabor::DrawOnLable(QLabel & lable, double A, double F, double W)
{
	//for (auto &i : c) i = 255;
	//Image img(lable.size().width(), lable.size().height(), KernelMaker(Range(W, W), Range(F, F), Range(A, A)).Make());
	//cout << (int)img.m_data[201 * 201 * 3+100] << endl;
	static Image img(lable.size().width(), lable.size().height());
	img.Reset(KernelMaker(Range(W, W), Range(F, F), Range(A, A)).Make());
	lable.setPixmap(QPixmap::fromImage(QImage(img.m_data, img.W(), img.H(), QImage::Format::Format_RGBA8888)));
}

void TryGabor::Save() {
	auto file = QFileDialog::getSaveFileName();
	ui.Picture->pixmap()->save(file);
}

void TryGabor::DrawOnLable0()
{
	DrawOnLable(*ui.Picture,ui.SSpinBox->value(),ui.FSpinBox->value(),ui.DSpinBox->value());
}
