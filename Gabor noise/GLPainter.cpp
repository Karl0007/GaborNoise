#include "GLPainter.h"

GLPainter::GLPainter(QWidget *parent)
	: QGLWidget(parent)
{
	this->setFixedSize(500, 500);
	rx = ry = 0;
}

GLPainter::~GLPainter()
{
}

void GLPainter::initializeGL()
{
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE_2D);
	static GLfloat lightPosition[4] = { 10, 10, 10, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void GLPainter::resizeGL(int w, int h)
{
	glViewport(0, 0, (GLint)w, (GLint)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, +2, -2, +2, 1.0, 15.0);
	glMatrixMode(GL_MODELVIEW);
}

void GLPainter::paintGL()
{



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.0);

	static const int size = 8;
	static Image img(1<<size,1<<size);
	static GLTexture<size> t;
	static bool reset = 0;
	if (!reset) {
		reset = 1;
		img.Reset(GaborMaker(vector<Karl07::KernelData>{ Karl07::KernelData{ Karl07::Range(1,5),Karl07::Range(3.14/4,3.14/4) } }, 3)());
		t.Reset(img);
		t.SetUse(true);
	}
 
	glRotated(rx, 0, 1, 0);
	glRotated(ry, 1, 0, 0);
	static auto obj = gluNewQuadric();
	gluQuadricTexture(obj, GL_TRUE);
	gluSphere(obj, 1, 30, 30);

}

void GLPainter::mouseMoveEvent(QMouseEvent * e)
{
	rx -= (lx - e->x());
	ry -= (ly - e->y());
	lx = e->x();
	ly = e->y();
	update();
}

void GLPainter::mousePressEvent(QMouseEvent * e)
{
	lx = e->x(),ly = e->y();
}


