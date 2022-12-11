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

void Land()
{
	glColor3ub(0,130, 50);
	glBegin(GL_QUADS);
    glVertex2i(0, 170);///BottomLeft
    glVertex2i(1280, 150);///BottomRight
	glVertex2i(1280, 450);///TopRight
	glVertex2i(0, 450);///TopLeft
	glEnd();
}
void Sky(){
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

void Sun()
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

void HighWay()
{
    ///main road
    glColor3ub(66, 66, 49);
	glBegin(GL_QUADS);
	glVertex2i(0,250);
	glVertex2i(1280,250);
	glVertex2i(1280,200);
	glVertex2i(0,200);
	glEnd();

    ///sub road 1
	glColor3ub(66, 66, 49);
	glBegin(GL_QUADS);
	glVertex2i(300,250);
	glVertex2i(330-10,250);
	glVertex2i(300-10,450);
	glVertex2i(270,450);
	glEnd();

    ///sub road 2
    glColor3ub(66, 66, 49);
	glBegin(GL_QUADS);
	glVertex2i(940,450);
	glVertex2i(960,450);
	glVertex2i(960,250);
	glVertex2i(940,250);
	glEnd();

	///sub road 3
	glColor3ub(66, 66, 49);
	glBegin(GL_QUADS);
	glVertex2i(0,375);
	glVertex2i(0,365);
	glVertex2i(300,365);
	glVertex2i(300,375);
	glEnd();

    ///divider
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2i(0,222);
	glVertex2i(1280,222);
	glVertex2i(0,225);
	glVertex2i(1280,225);
	glEnd();

}

void RoadLights1()
{
    float a;
	for(a=0; a<=1280; a+=70)
    {
        float b=a+3;
        glColor3ub(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2i(a,200);
        glVertex2i(b,200);
        glVertex2i(b,218);
        glVertex2i(a,218);
        glEnd();
        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
        glVertex2i(a,218);
        glVertex2i(b,218);
        glVertex2i(b,223);
        glVertex2i(a,223);
        glEnd();
    }
}

void RoadLights2()
{
	float a;
	for(a=35; a<=1280; a+=70)
    {
        float b=a+3;
        glColor3ub(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2i(a,250);
        glVertex2i(b,250);
        glVertex2i(b,268);
        glVertex2i(a,268);
        glEnd();
        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
        glVertex2i(a,268);
        glVertex2i(b,268);
        glVertex2i(b,273);
        glVertex2i(a,273);
        glEnd();
    }
}
void Building1(int a, int b , int c , int d, int color[3])
{
        ///for x axis /// difference = 80
        ///for y axis /// difference = 40

        glColor3ub(color[0],color[1],color[2]);
        glBegin(GL_QUADS);
        glVertex2i(a,c);
        glVertex2i(b,c);
        glVertex2i(b,d);
        glVertex2i(a,d);
        glEnd();
        glColor3ub(225,225,225);
        glBegin(GL_QUADS);
        glVertex2i(a+20,c);
        glVertex2i(b-20,c);
        glVertex2i(b-20,d-20);
        glVertex2i(a+20,d-20);
        glEnd();
        ///second floor
        glColor3ub(22, 150, 219);
        glBegin(GL_QUADS);
        glVertex2i(a+5,c+40);
        glVertex2i(b-5,c+40);
        glVertex2i(b-5,d+40);
        glVertex2i(a+5,d+40);
        glEnd();
        ///third floor
        glColor3ub(color[0],color[1],color[2]);
        glBegin(GL_QUADS);
        glVertex2i(a+10,c+80);
        glVertex2i(b-10,c+80);
        glVertex2i(b-10,d+80);
        glVertex2i(a+10,d+80);
        glEnd();
        ///fourth floor
        glColor3ub(color[0],color[1],color[2]);
        glBegin(GL_QUADS);
        glVertex2i(a+15,c+120);
        glVertex2i(b-15,c+120);
        glVertex2i(b-15,d+120);
        glVertex2i(a+15,d+120);
        glEnd();
        glColor3ub(175, 179, 179);
        glBegin(GL_QUADS);
        glVertex2i(a+39,c+160);
        glVertex2i(b-39,c+160);
        glVertex2i(b-39,d+140);
        glVertex2i(a+39,d+140);
        glEnd();
}

void PlayGroud()
{
        glColor3ub(52, 186, 60);
        glBegin(GL_QUADS);
        glVertex2i(40,270);
        glVertex2i(200,270);
        glVertex2i(185,350);
        glVertex2i(30,350);
        glEnd();

        glLineWidth(1.5);
        glBegin(GL_LINES);///Bottom line
        glColor3ub(255,255,255);
        glVertex2i(40,270);
        glVertex2i(200,270);
        glEnd();

        glBegin(GL_LINES);///Top line
        glColor3ub(255,255,255);
        glVertex2i(185,350);
        glVertex2i(30,350);
        glEnd();

        glBegin(GL_LINES);///Left line
        glColor3ub(255,255,255);
        glVertex2i(40,270);
        glVertex2i(30,350);
        glEnd();

        glBegin(GL_LINES);///Right line
        glColor3ub(255,255,255);
        glVertex2i(200,270);
        glVertex2i(185,350);
        glEnd();

        glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2i(120,270);
        glVertex2i(105,350);
        glEnd();

        glColor3ub(78, 237, 88);
        glBegin(GL_QUADS);
        glVertex2i(40,280);
        glVertex2i(80,280);
        glVertex2i(70,340);
        glVertex2i(32,340);
        glEnd();

        glColor3ub(78, 237, 88);
        glBegin(GL_QUADS);
        glVertex2i(197,280);
        glVertex2i(157,280);
        glVertex2i(144,340);
        glVertex2i(186,340);
        glEnd();

        ///side road
        glColor3ub(66, 66, 49);
        glBegin(GL_QUADS);
        glVertex2i(202,345);
        glVertex2i(290,345);
        glVertex2i(290,358);
        glVertex2i(200,358);
        glEnd();
        ///parking
        glColor3ub(66, 66, 49);
        glBegin(GL_QUADS);
        glVertex2i(210,260);
        glVertex2i(255,260);
        glVertex2i(238,358);
        glVertex2i(193,358);
        glEnd();

        ///Facility Building
        glColor3ub(160, 201, 217);
        glBegin(GL_QUADS);
        glVertex2i(290,290);
        glVertex2i(260,290);
        glVertex2i(250,350);
        glVertex2i(281,350);
        glEnd();
        glColor3ub(250, 250, 250);
        glBegin(GL_QUADS);
        glVertex2i(256,280);
        glVertex2i(286,280);
        glVertex2i(290,290);
        glVertex2i(260,290);
        glEnd();
        glColor3ub(221, 221, 221);
        glBegin(GL_QUADS);
        glVertex2i(256,280);
        glVertex2i(260,290);///bottom right
        glVertex2i(250,350);///top right
        glVertex2i(247,337);
        glEnd();

        ///fences
        for(int a=0; a<=280; a+=3)
        {
            glLineWidth(1);
            glColor3ub(50, 51, 51);
            glBegin(GL_LINES);
            glVertex2i(a,360);
            glVertex2i(a,390);

            glVertex2i(a,255);
            glVertex2i(a,280);
            glEnd();
        }
        for(int a=283; a<=296; a+=3)
        {
            glLineWidth(1);
            glColor3ub(50, 51, 51);
            glBegin(GL_LINES);
            glVertex2i(a,255);
            glVertex2i(a,280);
            glEnd();
        }

}
void HillTree1(int y1, int y2)
{
    ///difference = 15
    for(int a=10;a<1280;a+=50)
    {
        int b=a+2;
        glColor3ub(77, 53, 12);
        glBegin(GL_QUADS);
        glVertex2i(a, y1);
        glVertex2i(b, y1);
        glVertex2i(b, y2);
        glVertex2i(a, y2);
        glEnd();
        glColor3ub(102, 204, 0);
        glBegin(GL_POLYGON);
        glVertex2i(a-5, y2);
        glVertex2i(b+5, y2);
        glVertex2i(a+1,y2+10);
        glEnd();
        glColor3ub(102, 204, 0);
        glBegin(GL_POLYGON);
        glVertex2i(a-5, y2+4);
        glVertex2i(b+5, y2+4);
        glVertex2i(a+1,y2+14);
        glEnd();
    }
}

void HillTree2(int y1, int y2)
{
    ///difference = 15
    for(int a=30;a<1280;a+=50)
    {
        int b=a+2;
        glColor3ub(77, 53, 12);
        glBegin(GL_QUADS);
        glVertex2i(a, y1);
        glVertex2i(b, y1);
        glVertex2i(b, y2);
        glVertex2i(a, y2);
        glEnd();
        glColor3ub(102, 204, 0);
        glBegin(GL_POLYGON);
        glVertex2i(a-5, y2);
        glVertex2i(b+5, y2);
        glVertex2i(a+1,y2+10);
        glEnd();
        glColor3ub(102, 204, 0);
        glBegin(GL_POLYGON);
        glVertex2i(a-5, y2+4);
        glVertex2i(b+5, y2+4);
        glVertex2i(a+1,y2+14);
        glEnd();
    }
}

void Hospital(int a, int b , int c , int d, int color[3])
{
        ///for x axis /// difference = 80
        ///for y axis /// difference = 40

        glColor3ub(color[0],color[1],color[2]);
        glBegin(GL_QUADS);
        glVertex2i(a,c);
        glVertex2i(b,c);
        glVertex2i(b,d);
        glVertex2i(a,d);
        glEnd();
        glColor3ub(200,200,200);
        glBegin(GL_QUADS);
        glVertex2i(a+20,c);
        glVertex2i(b-20,c);
        glVertex2i(b-20,c+20);
        glVertex2i(a+20,c+20);
        glEnd();

        for(int i=c+25;  i<d;  i+=5){
        glBegin(GL_LINES);
        glColor3ub(69, 69, 69);
        glVertex2i(a,i);
        glVertex2i(b,i);
        glEnd();
        }

}

void Building2(int a, int b , int c , int d, int color[3])
{
        ///for x axis /// difference = 50

        glColor3ub(color[0],color[1],color[2]);
        glBegin(GL_QUADS);
        glVertex2i(a,c);
        glVertex2i(a+50,c);
        glVertex2i(a+50,d);
        glVertex2i(a,d);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2i(a+60,c);
        glVertex2i(b,c);
        glVertex2i(b,d);
        glVertex2i(a+60,d);
        glEnd();

        for(int i=c;  i<d;  i+=3){
        glBegin(GL_LINES);
        glColor3ub(69, 69, 69);
        glVertex2i(a,i);
        glVertex2i(a+50,i);
        glEnd();
        glBegin(GL_LINES);
        glColor3ub(69, 69, 69);
        glVertex2i(a+60,i);
        glVertex2i(b,i);
        glEnd();
        }
        glBegin(GL_LINES);
        glColor3ub(0,0,0);
        glVertex2i(a+25,d);
        glVertex2i(a+25,d+20);
        glEnd();

        glBegin(GL_LINES);
        glColor3ub(0,0,0);
        glVertex2i(a+60+25,d);
        glVertex2i(a+60+25,d+20);
        glEnd();

}

void Building3(int a, int b , int c , int d, int color[3])
{
        ///for x axis /// difference = 70

        glColor3ub(color[0],color[1],color[2]);
        glBegin(GL_QUADS);
        glVertex2i(a,c);
        glVertex2i(b,c);
        glVertex2i(a,d);
        glVertex2i(a,d);
        glEnd();
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3ub(200,200,200);
        glVertex2i(a,d-3);
        glVertex2i(a,d+20);
        glEnd();
        float counter=1;
        for (int i=a+2;i<b;i+=2){
            glLineWidth(1);
            glBegin(GL_LINES);
            glColor3ub(80,80,80);
            glVertex2f(i,d-counter);
            glVertex2f(i,c);
            glEnd();
            counter+=6.7;
        }

}

void Building4(int a, int b , int c , int d, int color[3])
{
        ///for x axis /// difference = 70

        glColor3ub(190,190,190);
        glBegin(GL_QUADS);
        glVertex2i(a,c);///bottom left
        glVertex2i(a,d);///top left
        glVertex2i(b,d);///top right
        glVertex2i(b,c);///bottom right
        glEnd();
        glColor3ub(color[0],color[1],color[2]);
        glBegin(GL_QUADS);
        glVertex2i(a,c);///bottom left
        glVertex2i(a,d);///top left
        glVertex2i(b,d);///top right
        glVertex2i(b-40,c);///bottom right
        glEnd();
        for (int i=a;i<b;i+=4){
            glLineWidth(1);
            glBegin(GL_LINES);
            glColor3ub(80,80,80);
            glVertex2f(i,d);
            glVertex2f(i,c);
            glEnd();
        }

}

void Stadium(){

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2i(980,440);
    glVertex2i(1000,460);
    glVertex2i(987,440);
    glVertex2i(1007,460);
    ///
    glVertex2i(1253,440);
    glVertex2i(1233,460);
    glVertex2i(1260,440);
    glVertex2i(1240,460);
    glEnd();

    for(int i=1040;i<1200;i+=20)
    {
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3ub(0,0,0);
        glVertex2i(1007,460);
        glVertex2i(i,420);
        glEnd();
    }
    for(int i=1200;i>1040;i-=20)
    {
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3ub(0,0,0);
        glVertex2i(1233,460);
        glVertex2i(i,420);
        glEnd();
    }

    glColor3ub(190, 190, 190);
    glBegin(GL_QUADS);
    glVertex2i(980,320);///bottom left
    glVertex2i(980,440);///top left
    glVertex2i(987,440);///top right
    glVertex2i(987,320);///bottom right
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(1000,320);///bottom left
    glVertex2i(1000,460);///top left
    glVertex2i(1007,460);///top right
    glVertex2i(1007,320);///bottom right
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(1253,320);///bottom left
    glVertex2i(1253,440);///top left
    glVertex2i(1260,440);///top right
    glVertex2i(1260,320);///bottom right
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(1233,320);///bottom left
    glVertex2i(1233,460);///top left
    glVertex2i(1240,460);///top right
    glVertex2i(1240,320);///bottom right
    glEnd();

    glColor3ub(215, 218, 219);
    glBegin(GL_QUADS);
    glVertex2i(1030,320);///bottom left
    glVertex2i(970,400);///top left
    glVertex2i(1270,400);///top right
    glVertex2i(1210,320);///bottom right
    glEnd();
    glColor3ub(190, 190, 190);
    glBegin(GL_QUADS);
    glVertex2i(970,400);///bottom left
    glVertex2i(990,420);///top left
    glVertex2i(1250,420);///top right
    glVertex2i(1270,400);///bottom right
    glEnd();
    ///roads
    glColor3ub(66, 66, 49);
	glBegin(GL_QUADS);
	glVertex2i(1030,310);///bottom left
    glVertex2i(970,320);///top left
    glVertex2i(1270,320);///top right
    glVertex2i(1210,310);///bottom right
	glEnd();
	glBegin(GL_QUADS);
	glVertex2i(960,260);///bottom left
    glVertex2i(960,300);///top left
    glVertex2i(1280,300);///top right
    glVertex2i(1280,260);///bottom right
	glEnd();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	Sky();
    Land();
    Sun();
    Hill();
    HillTree1(440,465);
    HighWay();
    River();

    int color[3]={45, 93, 168};
    Building1(10,90,380,420,color); ///a //b //c //d //color

    int color1[3]={30, 103, 217};
    Building1(100,180,380,420,color1);

    int color2[3]={45, 93, 168};
    Building1(190,270,380,420,color2);

    ///
    int color3[3]={99, 122, 194};
    Hospital(320,430,310,500,color3);

    int color4[3]={70, 160, 179};
    Hospital(440,550,310,500,color4);

    int color5[3]={99, 122, 194};
    Hospital(680,790,310,500,color5);

    int color6[3]={70, 160, 179};
    Hospital(800,910,310,500,color6);

    Building1(560,640,370,410,color2);
    ///

    int color7[3]={31, 147, 219};
    Building4(320,390,270,530,color7);///for x axis /// difference = 70

    int color8[3]={169, 174, 176};
    Building3(400,500,270,600,color8);///for x axis /// difference = 50

    int color9[3]={74, 95, 135};
    Building4(520,590,270,530,color9);///for x axis /// difference = 70

    int color10[3]={91, 172, 199};
    Building3(820,920,270,600,color10);///for x axis /// difference = 70

    int color11[3]={169, 174, 176};
    Building2(600,710,270,600,color11);///for x axis /// difference = 50

    Building4(720,790,270,530,color7);///for x axis /// difference = 70
    Stadium();

    PlayGroud();
    RoadLights1();
    HillTree2(253,270);
    HillTree1(180,205);
    HillTree2(170,195);
    RoadLights2();

    glFlush();
}


int main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Urban Landscape");
	glutDisplayFunc(Display);
    init();

	glutMainLoop();
	return 0;
}

