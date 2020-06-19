#include "ColorSetting.h"

ColorSetting::ColorSetting(ColorMap &map,QWidget *parent)
	: QWidget(parent),map(map)
{
	ui.setupUi(this);

	setFixedSize(size());

	painter = new ColorPainter(ui.ColorView, map,*ui.Pos);

	ui.TableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.TableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.TableView->setSelectionMode(QAbstractItemView::SingleSelection);
	TableUpdate();

	QObject::connect(ui.Edit, &QPushButton::clicked, this, &ColorSetting::Edit);
	QObject::connect(ui.Del, &QPushButton::clicked, this, &ColorSetting::Del);
	QObject::connect(ui.Save, &QPushButton::clicked, this, &ColorSetting::Save);
	QObject::connect(ui.Load, &QPushButton::clicked, this, &ColorSetting::Load);
	QObject::connect(ui.TableView, &QTableWidget::clicked, this, &ColorSetting::TableClick);
	QObject::connect(painter, &ColorPainter::mouseMoveEvent, this, &ColorSetting::SetPos);
}

ColorSetting::~ColorSetting()
{
}

void ColorSetting::TableUpdate()
{
	ui.TableView->setRowCount(map.color_map.size());
	int row = 0;
	for (auto const&i : map.color_map) {
		ui.TableView->setItem(row, 0, new QTableWidgetItem(QString::number(i.first)));
		ui.TableView->setItem(row, 1, new QTableWidgetItem(QString::number(i.second.r)));
		ui.TableView->setItem(row, 2, new QTableWidgetItem(QString::number(i.second.g)));
		ui.TableView->setItem(row, 3, new QTableWidgetItem(QString::number(i.second.b)));
		row++;
	}
	ui.TableView->setCurrentCell(0, 0);
	painter->update();
}

void ColorSetting::Edit()
{
	QColor color = QColorDialog::getColor();
	int r, g, b;
	if (color.isValid()) {
		color.getRgb(&r, &g, &b);
		map.color_map[ui.Pos->value()] = Karl07::Color(r, g, b);
	}
	TableUpdate();
}

void ColorSetting::Del()
{
	int key = ui.TableView->item(ui.TableView->currentRow(), 0)->text().toInt();
	if (key != 0 && key != 255) {
		map.color_map.erase(key);
	}
	TableUpdate();
}

void ColorSetting::TableClick(QModelIndex const & index)
{
	int row = index.row();
	ui.Pos->setValue(ui.TableView->item(row, 0)->text().toInt());
	painter->update();
}

void ColorSetting::SetPos(QMouseEvent * e)
{
	ui.Pos->setValue(1.0*e->pos().y() / 450 * 255);
	painter->update();
}

void ColorSetting::Save()
{
	auto filename = QFileDialog::getSaveFileName(nullptr, QString(), QString(), "ColorData (*.col)");
	QFile file(filename);
	QString Data;
	for (auto &i : map.color_map) {
		Data += QString::number(i.first) + " " + QString::number(i.second.r) +" " + QString::number(i.second.g) + " " + QString::number(i.second.b);
		Data += "\n";
	}
	file.open(QIODevice::WriteOnly | QIODevice::Text);
	file.write(Data.toUtf8());
	file.close();
}

void ColorSetting::Load()
{
	auto filename = QFileDialog::getOpenFileName(nullptr, QString(), QString(), "ColorData (*.col)");
	QFile file(filename);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
	map.color_map.clear();
	while (!file.atEnd())
	{
		auto list = QString(file.readLine()).split(" ");
		map.color_map[list[0].toInt()] = Karl07::Color(list[1].toInt(), list[2].toInt(), list[3].toInt());
	}
	file.close();
	TableUpdate();
}