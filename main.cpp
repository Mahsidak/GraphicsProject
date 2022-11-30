#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>


using namespace std;


void init()
{
    glClearColor(0.0,0.5,0.8,1.0);
	gluOrtho2D(0.0,1280,0.0,720);
}

void land()
{
	glColor3ub(0,130, 50);
	glBegin(GL_QUADS);
    glVertex2i(0, 170);///BottomLeft
    glVertex2i(1280, 150);///BottomRight
	glVertex2i(1280, 450);///TopRight
	glVertex2i(0, 450);///TopLeft
	glEnd();
}
void sky(){
    glColor3ub(45, 139, 237);
	glBegin(GL_QUADS);
    glVertex2i(0, 720);
    glVertex2i(1280, 720);
	glVertex2i(1280, 100);
	glVertex2i(0, 100);
	glEnd();
}
void River()
{
    glColor3ub(0,180,250);///color
    glBegin(GL_QUADS);
    glVertex2i(0, 170);///TopLeft
    glVertex2i(1280, 150);///TopRight
	glVertex2i(1280, 0);///BottomRight
	glVertex2i(0, 0);///BottomLeft
	glEnd();
}

void Hill()
{
    glColor3ub(112,77, 12);
    glBegin(GL_QUADS);
    glVertex2i(0,450);
    glVertex2i(0,500);
    glVertex2i(100,550);
    glVertex2i(200,450);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(100,450);
    glVertex2i(300,650);
    glVertex2i(500,450);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(260,450);
    glVertex2i(500,630);
    glVertex2i(700,450);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(480,450);
    glVertex2i(750,630);
    glVertex2i(1100,450);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(800,450);
    glVertex2i(1000,650);
    glVertex2i(1200,450);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(1000,500);
    glVertex2i(1200,650);
    glVertex2i(1270,450);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(1100,450);
    glVertex2i(1280,580);
    glVertex2i(1280,450);
    glEnd();
}

void sun()
{
    glPushMatrix();
    glTranslatef(600,660, 0);
    glBegin(GL_POLYGON);
    glColor3ub(249,215,28);
for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
   glEnd();
   glPopMatrix();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	sky();
    land();
    sun();
    Hill();
    River();

    glFlush();
}

int main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Urban Landscape");
	glutDisplayFunc(display);
    init();

	glutMainLoop();
	return 0;
}

