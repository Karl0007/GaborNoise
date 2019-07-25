#pragma once

#include <QWidget>
#include "ui_GaborNoiseView.h"

class GaborNoiseView : public QWidget
{
	Q_OBJECT

public:
	GaborNoiseView(QWidget *parent = Q_NULLPTR);
	~GaborNoiseView();

	void closeEvent(QCloseEvent *e);

public:
	Ui::GaborNoiseView ui;
private:
};
