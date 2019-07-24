#include "ParaTable.h"

ParaTable::ParaTable(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	painter = new QtPainterWidget(ui.widget, *ui.tableWidget);

	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableWidget->setRowCount(1);
	ui.tableWidget->setCurrentCell(0, 0);
	ui.tableWidget->setItem(0, 0, new QTableWidgetItem(QString::number(1)));
	ui.tableWidget->setItem(0, 1, new QTableWidgetItem(QString::number(0)));
	ui.tableWidget->setItem(0, 2, new QTableWidgetItem(QString::number(0)));
	ui.tableWidget->setItem(0, 3, new QTableWidgetItem(QString::number(0)));

	getNum(0);
	ui.Fnum->setValue(Range::FromTo(FMIN, FMAX, 0, 99, fmin));
	ui.Wnum->setValue(Range::FromTo(WMIN, WMAX, 0, 99, wmin));

	QObject::connect(ui.New, &QPushButton::clicked, this, &ParaTable::AddNewRow);
	QObject::connect(ui.Delete, &QPushButton::clicked, this, &ParaTable::DeleteRow);
	QObject::connect(ui.tableWidget, &QTableWidget::clicked, this, &ParaTable::TableClick);
	QObject::connect(ui.Fnum, &QSlider::valueChanged, [&](int val) { ui.tableWidget->setItem(ui.tableWidget->currentRow(), 0, new QTableWidgetItem(QString::number( Range::FromTo(0, 99, FMIN, FMAX, val)))); getNum(ui.tableWidget->currentRow()); });
	QObject::connect(ui.Wnum, &QSlider::valueChanged, [&](int val) { ui.tableWidget->setItem(ui.tableWidget->currentRow(), 1, new QTableWidgetItem(QString::number( Range::FromTo(0, 99, WMIN, WMAX, val)))); getNum(ui.tableWidget->currentRow()); });

}

ParaTable::~ParaTable()
{
}

void ParaTable::paintEvent(QPaintEvent * e)
{
}

void ParaTable::AddNewRow()
{
	ui.tableWidget->insertRow(ui.tableWidget->rowCount());
	setNew(ui.tableWidget->rowCount()-1,ui.tableWidget->currentRow());
	getNum(ui.tableWidget->currentRow());
}

void ParaTable::DeleteRow()
{
	if (ui.tableWidget->rowCount() > 1) {
		ui.tableWidget->removeRow(ui.tableWidget->currentRow());
		getNum(ui.tableWidget->currentRow());
	}
}

void ParaTable::TableClick(QModelIndex const& index)
{
	getNum(index.row());
	ui.Fnum->setValue(Range::FromTo(FMIN, FMAX, 0, 99, fmin));
	ui.Wnum->setValue(Range::FromTo(WMIN, WMAX, 0, 99, wmin));

}

void ParaTable::setNew(int index,int from)
{
	for (int i = 0; i < 4; i++)
		ui.tableWidget->setItem(index, i, new QTableWidgetItem(*ui.tableWidget->item(from, i)));
}

void ParaTable::getNum(int index)
{
	fmin = fmax = ui.tableWidget->item(index, 0)->text().toDouble();
	wmin = wmax = ui.tableWidget->item(index, 1)->text().toDouble();
	painter->update();
	static Image img(ui.Image->size().width(), ui.Image->size().height());
	img.Reset(KernelMaker(KernelData(Range(fmin, fmax), Range(wmin, wmax))).Make());
	ui.Image->setPixmap(QPixmap::fromImage(QImage(img.m_data, img.W(), img.H(), QImage::Format::Format_RGBA8888)));

}
