#pragma once

#include <QGLWidget>
#include <iostream>
#include "GLTexture.h"
#include "Image.h"
#include "Gabor.h"
#include <qevent.h>
using namespace std;
using Karl07::GaborMaker;
using Karl07::Image;
using Karl07::GLTexture;
class GLPainter : public QGLWidget
{
	Q_OBJECT

public:
	float rx, ry,lx,ly;
	GLPainter(QWidget *parent = nullptr);
	~GLPainter();
	void initializeGL();
	void resizeGL(int x, int y);
	void paintGL();
	void mouseMoveEvent(QMouseEvent *e);
	void mousePressEvent(QMouseEvent *e);
};
