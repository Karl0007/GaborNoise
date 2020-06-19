#pragma once

#include <QWidget>
#include "ui_ColorSetting.h"
#include "Color.h"
#include "ColorPainter.h"
#include <qcolordialog.h>
#include <qdialog.h>
#include <qpainter.h>
#include "qfiledialog.h"
using Karl07::ColorMap;

class ColorSetting : public QWidget
{
	Q_OBJECT

public:
	ColorSetting(ColorMap &map,QWidget *parent = Q_NULLPTR);
	~ColorSetting();
private slots:
	void TableUpdate();
	void Save();
	void Load();
	void Edit();
	void Del();
	void TableClick(QModelIndex const& index);
	void SetPos(QMouseEvent * e);

private:
	ColorMap &map;
	ColorPainter *painter;
	Ui::ColorSetting ui;
};
