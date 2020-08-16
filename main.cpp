#include <iostream>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1416

GLint i,a,b;
static GLfloat spin = 0.0;
static float	tx	=  0.0;
static float	ty	=  0.0;



void init(void)
{
	   glClearColor(201.0f/255.0f, 229.0f/255.0f, 235.0f/255.0f, 0.0);
	   glMatrixMode(GL_PROJECTION);
	   gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}



void animation(void)
{
      spin = spin + .02;
      if (spin > 30.0)
        spin = spin - 40.0;

      tx	+=  0.03;
      if (tx > 100.0)
         tx = tx - 110.0;

glutPostRedisplay();

}

//full circle with 3 perameters
void circle(GLdouble rad, GLdouble x, GLdouble y)

{
       GLint points = 360;
       GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
       GLdouble theta = 0.0;

      glBegin(GL_TRIANGLE_FAN);
      {
          for( i = 0; i <=360; i++, theta += delTheta )
          {
              glVertex2f(x+rad * cos(theta),y+rad * sin(theta));
          }
      }
      glEnd();
}

///full circle with 5 perameters
void DrawCircle(float cx, float cy, float rx,float ry )
{
      glBegin(GL_TRIANGLE_FAN);
      for(i = 0; i < 360; i++)
      {
          float theta = 2.0f * 3.1415926f * float(i) / float(360);

          float x = rx * cosf(theta);
          float y = ry * sinf(theta);
          glVertex2f(x + cx, y + cy);

      }
      glEnd();
}


void rock()
{
     glColor3ub(21, 14, 45);
     DrawCircle(425 , 0, 120 ,100);
     glBegin(GL_TRIANGLES);
     glVertex2f(350,70);
     glVertex2f(350,0);
     glVertex2f(250,0);
     glEnd();
     glColor3ub(45, 89, 216);
     glBegin(GL_POLYGON);
     glVertex2f(320,50);
     glVertex2f(250,0);
     glVertex2f(350,60);
     glVertex2f(320,50);
     glEnd();
     glBegin(GL_TRIANGLES);
     glVertex2f(350,10);
     glVertex2f(350,0);
     glVertex2f(250,0);
     glEnd();
     DrawCircle(400 , 0, 40 ,27);
     DrawCircle(360 , 0, 30 ,17);
     glColor3ub(21, 14, 45);
     DrawCircle(400 , 0, 40 ,25);
     DrawCircle(360 , 0, 30 ,15);

}
void sea()
{

     glBegin(GL_QUADS);// for gradient  color
     glColor3ub(19, 9, 34);
     glVertex2f(500,100);
     glVertex2f(0,100);
     glColor3ub(47, 42, 108);
     glVertex2f(0,0);
     glVertex2f(500,0);
     glEnd();

     glPushMatrix();
	 glTranslatef(tx,ty,0);
     glColor3ub(84, 169, 223);
     glRectf(100,50,130,53);
     glPopMatrix();

     glPushMatrix();
     glTranslatef(tx-.02,ty,0);
     glRectf(250,50,270,53);
     glPopMatrix();

     glPushMatrix();
     glTranslatef(tx,ty,0);
     glRectf(75,30,95,33);
     glRectf(25,75,35,78);
     glPopMatrix();
     glPushMatrix();
     glTranslatef(tx-.02,ty,0);
     glRectf(100,50,130,53);
     glRectf(150,20,180,23);
     glRectf(170,75,180,78);
     glRectf(270,83,280,86);
     glPopMatrix();

}

void lighthouse()
{


     glColor3ub(82, 70, 168);//body
     glBegin(GL_POLYGON);
     glVertex2f(380,50);
     glVertex2f(450,50);
     glVertex2f(435,315);
     glVertex2f(390,315);
     glEnd();

     glBegin(GL_POLYGON);//upper body
     glVertex2f(435,315);
     glVertex2f(390,315);
     glVertex2f(375,330);
     glVertex2f(450,330);
     glEnd();

     glBegin(GL_POLYGON);
     glVertex2f(392,330);
     glVertex2f(432,330);
     glVertex2f(438,370);
     glVertex2f(386,370);
     glEnd();

     glColor3ub(159, 249, 253);// light into the light house
     glRectf(402,330,422,370);
     glColor3ub(65, 143, 166);
     glRectf(408,330,406,370);
     glRectf(414,330,416,370);
     glRectf(402,346,422,348);
     glRectf(402,357,422,359);


     glColor3ub(11, 74, 127);// bar
     glRectf(375,340,450,343);

       a= 375 ;
       b= 377;
        for( i = 0; i <=12; i++)
        {
           glRectf(a,340,b,330);
           a=a+6;
           b=a+2;
        }

     glBegin(GL_TRIANGLES);//head
     glVertex2f(377,370);
     glVertex2f(448,370);
     glVertex2f(412.5,410);
     glEnd();


///// reflect
     glColor3ub(21, 14, 45);
     glBegin(GL_POLYGON);
     glVertex2f(390,275);
     glVertex2f(438,275);
     glVertex2f(440,230);
     glVertex2f(387,230);
     glEnd();

     glBegin(GL_POLYGON);
     glVertex2f(390,175);
     glVertex2f(443,175);
     glVertex2f(446,130);
     glVertex2f(387,130);
     glEnd();


     glColor3ub(24, 99, 230);
     glBegin(GL_TRIANGLES);
     glVertex2f(377,370);
     glVertex2f(390,370);
     glVertex2f(412.5,410);
     glEnd();


     glColor3ub(24, 99, 230);
     glBegin(GL_POLYGON);;
     glVertex2f(392,330);
     glVertex2f(386,370);
     glVertex2f(395,370);
     glVertex2f(395,330);
     glEnd();

     glBegin(GL_POLYGON);;
     glVertex2f(400,315);
     glVertex2f(390,315);
     glVertex2f(375,330);
     glVertex2f(395,330);
     glEnd();

     glBegin(GL_POLYGON);
     glVertex2f(380,50);
     glVertex2f(400,50);
     glVertex2f(400,315);
     glVertex2f(390,315);
     glEnd();

     glColor3ub(30, 38, 100);
     glBegin(GL_POLYGON);
     glVertex2f(388,275);
     glVertex2f(400,275);
     glVertex2f(400,230);
     glVertex2f(386,230);
     glEnd();

     glBegin(GL_POLYGON);
     glVertex2f(384,175);
     glVertex2f(400,175);
     glVertex2f(400,130);
     glVertex2f(383,130);
     glEnd();

     glColor3ub(24, 99, 230);
     glRectf(375,340,395,343);
       a= 375 ;
       b= 377;

        for( i = 0; i <=3; i++)
        {
           glRectf(a,340,b,330);
           a=a+6;
           b=a+2;
        }

}


void sky ()
{

     glColor3ub(37, 22, 61);
     glBegin(GL_POLYGON);;
     glVertex2f(0,330);
     glVertex2f(0,370);
     glVertex2f(500,340);
     glVertex2f(500,300);
     glEnd();

     glColor3ub(86, 51, 121);
     glBegin(GL_TRIANGLES);
     glVertex2f(0,250);
     glVertex2f(0,235);
     glVertex2f(150,250);
     glEnd();

     glBegin(GL_TRIANGLES);
     glVertex2f(0,240);
     glVertex2f(0,225);
     glVertex2f(110,235);
     glEnd();

     glBegin(GL_TRIANGLES);
     glVertex2f(500,240);
     glVertex2f(500,220);
     glVertex2f(400,230);
     glEnd();

     glBegin(GL_TRIANGLES);
     glVertex2f(500,150);
     glVertex2f(500,165);
     glVertex2f(275,150);
     glEnd();

     glBegin(GL_TRIANGLES);
     glVertex2f(500,160);
     glVertex2f(500,180);
     glVertex2f(400,170);
     glEnd();

     glBegin(GL_TRIANGLES);
     glVertex2f(500,178);
     glVertex2f(500,190);
     glVertex2f(320,175);
     glEnd();

    DrawCircle(500 , 200, 50 ,15);

}


void light()
{
	 glPushMatrix();
	 glTranslatef(410, 350, 0 );
	 glRotatef(spin, 0.0, 0.0, 1.0);
     glTranslatef(-410, -350, 0 );
	 glBegin(GL_QUADS);
     glColor3ub(159, 249, 253);
     glVertex2f(410,330);
     glVertex2f(410,370);
     glColor3ub(48, 85, 86);
     glVertex2f(-20,400);
     glVertex2f(-20,300);
     glEnd();
     glPopMatrix();

}


void stars()
{

     glColor3ub(158, 249, 254);
     circle(1,50,450);
     circle(1,50,450);
     circle(1,200,400);
     circle(1,150,275);

     circle(1,250,350);
     circle(1,390,440);
     circle(1,300,250);
     circle(1,25,275);

     circle(1,450,350);
     circle(1,125,375);
     circle(1,175,475);
     circle(1,250,150);

     circle(1,50,470);
     circle(1,60,460);
     circle(1,80,485);
     circle(1,95,460);
     circle(1,102,470);

     circle(1,120,450);
     circle(1,150,420);
     circle(1,160,445);
     circle(1,200,430);
     circle(1,250,400);

     circle(1,350,470);
     circle(1,360,440);
     circle(1,390,485);
     circle(1,425,490);
     circle(1,450,470);

     circle(1,220,450);
     circle(1,280,410);
     circle(1,320,445);
     circle(1,270,480);
     circle(1,300,400);

     ////
     circle(1,10,370);
     circle(1,60,360);
     circle(1,30,385);
     circle(1,95,360);
     circle(1,102,370);

     circle(1,120,350);
     circle(1,150,320);
     circle(1,160,345);
     circle(1,200,330);
     circle(1,250,300);

     circle(1,350,370);
     circle(1,360,340);
     circle(1,390,385);
     circle(1,425,390);
     circle(1,450,370);

     circle(1,220,350);
     circle(1,280,310);
     circle(1,320,345);
     circle(1,270,380);
     circle(1,300,300);

     ///
     circle(1,10,270);
     circle(1,60,260);
     circle(1,30,285);
     circle(1,95,260);
     circle(1,102,270);

     circle(1,120,250);
     circle(1,150,220);
     circle(1,160,245);
     circle(1,200,230);
     circle(1,250,200);

     circle(1,350,270);
     circle(1,360,240);
     circle(1,390,285);
     circle(1,425,290);
     circle(1,450,270);

     circle(1,220,250);
     circle(1,280,210);
     circle(1,320,245);
     circle(1,270,280);
     circle(1,300,200);


     ////
     circle(1,10,170);
     circle(1,60,160);
     circle(1,30,185);
     circle(1,95,160);
     circle(1,102,170);

     circle(1,120,150);
     circle(1,150,120);
     circle(1,160,145);
     circle(1,200,130);
     circle(1,250,100);

     circle(1,350,170);
     circle(1,360,140);
     circle(1,390,185);
     circle(1,425,190);
     circle(1,450,170);

     circle(1,220,150);
     circle(1,280,110);
     circle(1,320,145);
     circle(1,270,180);
     circle(1,300,100);

///


    circle(1,470,450);
    circle(1,495,400);
    circle(1,480,340);
    circle(1,460,210);
    circle(1,490,150);

}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);//background gradient
    glColor3ub(69, 40, 98);
    glVertex2f(0,0);
    glVertex2f(500,0);
    glColor3ub(19, 9, 34);
    glVertex2f(500, 500);
    glVertex2f(0, 500);


    glEnd();
    sky();
    stars();
    sea();
    light();
    lighthouse();
    rock();
    glFlush();

}





void mouse(int button, int state, int x, int y)
{
   switch (button) {
        case GLUT_LEFT_BUTTON:
           if (state == GLUT_DOWN)
           {

             glutIdleFunc(animation);
           }

         break;
        case GLUT_MIDDLE_BUTTON:
        case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
          glutIdleFunc(NULL);
         break;
        default:
         break;
   }
}





int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 50);
	glutInitWindowSize(800, 1900);
	glutCreateWindow("LightHouse");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
}
