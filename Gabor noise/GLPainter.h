#pragma once

#include <QGLWidget>
#include <iostream>
using namespace std;
class GLPainter : public QGLWidget
{
	Q_OBJECT

public:
	GLPainter(QWidget *parent = nullptr);
	~GLPainter();
	void initializeGL();
	void resizeGL(int x, int y);
	void paintGL();
};
