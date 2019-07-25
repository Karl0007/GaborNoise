#include "GLPainter.h"

GLPainter::GLPainter(QWidget *parent, Func &fun,QWidget *IMG)
	: QGLWidget(parent)
{
	this->setFixedSize(256, 256);
	rx = ry = 0;

	img = new Image(1 << size, 1 << size);
	t = new GLTexture<size>;
	img->Reset(fun);
	obj = gluNewQuadric();
	label = new QLabel(IMG);
	label->setPixmap(QPixmap::fromImage(QImage(img->m_data, img->W(), img->H(), QImage::Format::Format_RGBA8888)));
	label->show();

	//for (int i = 0; i < 6; i++) {
	//	img2[i] = new Image(1 << size, 1 << size);
	//	t2[i] = new GLTexture<size>;
	//	img2[i]->Reset(gmk.Cube(i+1));
	//}
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
	glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
	static GLfloat lightPosition[4] = { 5, 5, 5, 1.0 };
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


 
	glRotated(rx, 0, 1, 0);
	glRotated(ry, 1, 0, 0);
	t->Reset(*img);
	t->SetUse(true);
	gluQuadricTexture(obj, GL_TRUE);
	gluSphere(obj, 1, 30, 30);


	//t2[5]->Reset(*img2[5]);
	//t2[5]->SetUse(true);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0, 0);
	//glNormal3f(-1, -1, -1);
	//glVertex3f(-1, -1, -1);
	//glTexCoord2f(0, 1);
	//glNormal3f(-1, -1, 1);
	//glVertex3f(-1, -1, 1);
	//glTexCoord2f(1, 1);
	//glNormal3f(-1, 1, 1);
	//glVertex3f(-1, 1, 1);
	//glTexCoord2f(1, 0);
	//glNormal3f(-1, 1, -1);
	//glVertex3f(-1, 1, -1);
	//glEnd();

	//t2[0]->Reset(*img2[0]);
	//t2[0]->SetUse(true);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0, 0);
	//glNormal3f(1, 1, -1);
	//glVertex3f(1, 1, -1);
	//glTexCoord2f(0, 1);
	//glNormal3f(1, 1, 1);
	//glVertex3f(1, 1, 1);
	//glTexCoord2f(1, 1);
	//glNormal3f(1, -1, 1);
	//glVertex3f(1, -1, 1);
	//glTexCoord2f(1, 0);
	//glNormal3f(1, -1, -1);
	//glVertex3f(1, -1, -1);
	//glEnd();

	//t2[2]->Reset(*img2[2]);
	//t2[2]->SetUse(true);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0, 0);
	//glNormal3f(-1, 1, -1);
	//glVertex3f(-1, 1, -1);
	//glTexCoord2f(0, 1);
	//glNormal3f(-1, 1, 1);
	//glVertex3f(-1, 1, 1);
	//glTexCoord2f(1, 1);
	//glNormal3f(1, 1, 1);
	//glVertex3f(1, 1, 1);
	//glTexCoord2f(1, 0);
	//glNormal3f(1, 1, -1);
	//glVertex3f(1, 1, -1);
	//glEnd();

	//t2[1]->Reset(*img2[1]);
	//t2[1]->SetUse(true);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0, 0);
	//glNormal3f(1, -1, -1);
	//glVertex3f(1, -1, -1);
	//glTexCoord2f(0, 1);
	//glNormal3f(1, -1, 1);
	//glVertex3f(1, -1, 1);
	//glTexCoord2f(1, 1);
	//glNormal3f(-1, -1, 1);
	//glVertex3f(-1, -1, 1);
	//glTexCoord2f(1, 0);
	//glNormal3f(-1, -1, -1);
	//glVertex3f(-1, -1, -1);
	//glEnd();

	////t->Reset(*img);
	////t->SetUse(true);
	//t2[3]->Reset(*img2[3]);
	//t2[3]->SetUse(true);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0, 0);
	//glNormal3f(-1, -1, -1);
	//glVertex3f(-1, -1, -1);
	//glTexCoord2f(0, 1);
	//glNormal3f(-1, 1, -1);
	//glVertex3f(-1, 1, -1);
	//glTexCoord2f(1, 1);
	//glNormal3f(1, 1, -1);
	//glVertex3f(1, 1, -1);
	//glTexCoord2f(1, 0);
	//glNormal3f(1, -1, -1);
	//glVertex3f(1, -1, -1);
	//glEnd();

	//t2[4]->Reset(*img2[4]);
	//t2[4]->SetUse(true);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0, 0);
	//glNormal3f(1, -1, 1);
	//glVertex3f(1, -1, 1);
	//glTexCoord2f(0, 1);
	//glNormal3f(1, 1, 1);
	//glVertex3f(1, 1, 1);
	//glTexCoord2f(1, 1);
	//glNormal3f(-1, 1, 1);
	//glVertex3f(-1, 1, 1);
	//glTexCoord2f(1, 0);
	//glNormal3f(-1, -1, 1);
	//glVertex3f(-1, -1, 1);
	//glEnd();

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

void GLPainter::closeEvent(QCloseEvent * e)
{
	cout << "delete" << endl;
	delete img;
	delete t;
	delete label;
	delete this;
}


