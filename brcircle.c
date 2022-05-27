#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>

void plot_point(int x,int y)
{
   glBegin(GL_LINES);
   glColor3f(0.0f,1.0f,0.0f);
   glVertex2i(-320,0);
   glVertex2i(320,0);
   glVertex2i(0,-240);
   glVertex2i(0,240);
   glEnd();

   glBegin(GL_POINTS);
   glColor3f(1.0f,1.0f,1.0f);
   glVertex2i(x,y);
   glVertex2i(y,x);
   glVertex2i(x,-y);
   glVertex2i(y,-x);
   glVertex2i(-x,-y);
   glVertex2i(-y,-x);
   glVertex2i(-x,y);
   glVertex2i(-y,x);
   glEnd();
}

void bresenham_circle(int r)
{
   int x=0, y=r;
   float pk=3-2*r;
   plot_point(x,y);
   int k;
   while(x<y)
   {
     x=x+1;
     if(pk<0)
         pk=pk+4*x+6;
     else
     {
          y=y-1;
          pk=pk+4*(x-y)+10;
     }
    plot_point(x,y);
}
glFlush();
}
void concentric_circles(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  int radius1=50;
  bresenham_circle(radius1);
}
void Init()
{
glClearColor(0.0,0.0,0.0,0.0);
glColor3f(1.0,0.0,0.0);
gluOrtho2D(-320 ,320,-240,240);
}
void main(int argc, char ** argv)
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(640,480);
   glutInitWindowPosition(0,0);
   glutCreateWindow("Bresenham Circle");
   Init();
   glutDisplayFunc(concentric_circles);
   glutMainLoop();
}
