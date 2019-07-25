#pragma once

#include <QGLWidget>
#include <iostream>
#include "GLTexture.h"
#include "Image.h"
#include "Gabor.h"
#include <gl/GLU.h>
#include <qopengl.h>
#include <qevent.h>
#include <qlabel.h>
using namespace std;
using Karl07::GaborMaker;
using Karl07::Image;
using Karl07::GLTexture;
using Karl07::Func;
class GLPainter : public QGLWidget
{
	Q_OBJECT

private:
	static const int size = 8;
	GLUquadric *obj;
	Image *img;
	QLabel *label;
	GLTexture<size> *t;

	Image * img2[6];
	GLTexture<size> * t2[6];

public:
	float rx, ry,lx,ly;
	GLPainter(QWidget *parent,Func &fun,QWidget *IMG);
	~GLPainter();
	void initializeGL();
	void resizeGL(int x, int y);
	void paintGL();
	void mouseMoveEvent(QMouseEvent *e);
	void mousePressEvent(QMouseEvent *e);
	void closeEvent(QCloseEvent *e);
};
