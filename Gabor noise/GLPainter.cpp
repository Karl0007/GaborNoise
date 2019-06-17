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
	//glRotatef(100 / 16.0, 1.0, 0.0, 0.0);
	//glRotatef(100 / 16.0, 0.0, 1.0, 0.0);
	//glRotatef(100 / 16.0, 0.0, 0.0, 1.0);
	//qglColor(Qt::red);

	static const int size = 8;
	static Image img(1<<size,1<<size);
	static GLTexture<size> t;
	static bool reset = 0;
	if (!reset) {
		reset = 1;
		img.Reset(GaborMaker(vector<Karl07::KernelData>{ Karl07::KernelData{ Karl07::Range(1,5),Karl07::Range(3.14/2,3.14/2) } }, 3)());
		t.Reset(img);
		t.SetUse(true);
	}
 
	/*// Œ∆¿Ì∞Û∂®
	{
		static unsigned int m_id = 0;
		int size = 64;
		unsigned char data[64][64][4];
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				data[i][j][0] = (j/4) & 1 ? 255 : 0;
				data[i][j][1] = (j/4) & 1 ? 0 : 255;
				data[i][j][2] = 0;
				data[i][j][3] = 255;
			}
		if (!m_id) {
			glGenTextures(1, &m_id);
			glBindTexture(GL_TEXTURE_2D, m_id);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, size, size, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
			glBindTexture(GL_TEXTURE_2D, m_id);
		}
		//glBindTexture(GL_TEXTURE_2D, 0);
	}
	*/ // Œ∆¿Ì∞Û∂®

	// ª≠«Ú
	{
		int step = 20;
		int R = 1;
		const float pi = 3.14159;
		float phi = -pi / 2;
		float theta = 0;
		float posx = 0, posy = 0, posz = 0;
		float rotx = 0, roty = 0, rotz = 0;
		auto X = [&](int i, int j) {return R * sin(i * pi / step)*sin(j * 2 * pi / step); };
		auto Y = [&](int i, int j) {return R * sin(i * pi / step)*cos(j * 2 * pi / step); };
		auto Z = [&](int i, int j) {return R * cos(i * pi / step); };

		//cout << endl;
		//glColor3f(1, 0, 0);
		//glTranslatef(-0.5, -0.5, 0);
		glRotated(rx, 0, 1, 0);
		glRotated(ry, 1, 0, 0);
		glBegin(GL_QUADS);
		for (int i = 0; i < step; i++) {
			for (int j = 0; j < step; j++) {
				//glTexCoord2f(j*1.0 / step, cos(-pi / 2 + i * pi / step));
				glTexCoord2f(j*1.0 / step, i*1.0 / step);
				glNormal3f(X(i, j), Y(i, j), Z(i, j));
				glVertex3f(X(i, j), Y(i, j), Z(i, j));

				//glTexCoord2f((j + 1)*1.0 / step, cos(-pi / 2 + i * pi / step));
				glTexCoord2f((j+1)*1.0 / step, i*1.0 / step);
				glNormal3f(X(i, j + 1), Y(i, j + 1), Z(i, j + 1));
				glVertex3f(X(i, j + 1), Y(i, j + 1), Z(i, j + 1));
				
				//glTexCoord2f((j + 1)*1.0 / step, cos(-pi / 2 + (i+1) * pi / step));
				glTexCoord2f((j + 1)*1.0 / step, (i + 1)*1.0 / step);
				glNormal3f(X(i + 1, j + 1), Y(i + 1, j + 1), Z(i + 1, j + 1));
				glVertex3f(X(i + 1, j + 1), Y(i + 1, j + 1), Z(i + 1, j + 1));

				//glTexCoord2f((j)*1.0 / step, cos(-pi / 2 + (i+1) * pi / step));
				glTexCoord2f((j)*1.0 / step, (i + 1)*1.0 / step);
				glNormal3f(X(i + 1, j), Y(i + 1, j), Z(i + 1, j));
				glVertex3f(X(i + 1, j), Y(i + 1, j), Z(i + 1, j));
			}
		}
		glEnd();

	}

	// ª≠«Ú

	//glBegin(GL_QUADS);
	//glNormal3f(0, 0, -1);
	//glVertex3f(-1, -1, 0);
	//glVertex3f(-1, 1, 0);
	//glVertex3f(1, 1, 0);
	//glVertex3f(1, -1, 0);
	//glEnd();


	//glBegin(GL_QUADS);
	//glNormal3f(0, 1,1);
	//glTexCoord2f(0, 0);
	//glVertex3f(-1, -1, 0);
	//glTexCoord2f(0, 1);
	//glVertex3f(1, -1, 0);
	//glTexCoord2f(1, 1);
	//glVertex3f(1, 1, 0);
	//glTexCoord2f(1, 0);
	//glVertex3f(-1, 1, 0);
	//glEnd();

	//glBegin(GL_TRIANGLES);
	//glNormal3f(0, -1,0.707);
	//glTexCoord2f(0, 0); 
	//glVertex3f(-1, -1, 0);
	//glTexCoord2f(1, 0); 
	//glVertex3f(1, -1, 0);
	//glTexCoord2f(1, 1); 
	//glVertex3f(1, 1, 0);
	//glEnd();
	//glBegin(GL_TRIANGLES);
	//glNormal3f(1, 0, 0.707);
	//glVertex3f(1, -1, 0);
	//glVertex3f(1, 1, 0);
	//glVertex3f(0, 0, 1.2);
	//glEnd();
	//glBegin(GL_TRIANGLES);
	//glNormal3f(0, 1, 0.707);
	//glVertex3f(1, 1, 0);
	//glVertex3f(-1, 1, 0);
	//glVertex3f(0, 0, 1.2);
	//glEnd();
	//glBegin(GL_TRIANGLES);
	//glNormal3f(-1, 0, 0.707);
	//glVertex3f(-1, 1, 0);
	//glVertex3f(-1, -1, 0);
	//glVertex3f(0, 0, 1.2);
	//glEnd();
	//update();
}

void GLPainter::mouseMoveEvent(QMouseEvent * e)
{
	//paintGL();
	cout << ry << " " << rx << endl;
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


