#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>     
int x1,x2,y1,y2;
 
void display(void)
{
float dy,dx,length,x,y,k,Xin,Yin;

dx=x2-x1;
dy=y2-y1;
 
if(abs(dx)>= abs(dy))
{
length = abs(dx);
}
else
length = abs(dy);
 
Xin = dx/length;
Yin = dy/length;
 
x= x1;
y= y1;
 glBegin(GL_LINES);           
     // glColor3f(0.0f, 1.0f, 0.0f);     

	
      glVertex2f(-100.0f, 0.0f);
 glVertex2f(100.0f, 0.0f);

glVertex2f(0.0f, -100.0f);
 glVertex2f(0.0f, 100.0f);
   glEnd();

glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
// glColor3f(0.0f, 1.0f, 0.0f);
for (k=1;k<=length;k++)
{
x= x + Xin;
y= y + Yin;
 
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
 
 
glFlush();
}
 
void init(void)
{
glClearColor(0.0,0.0,0.0,1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100,100,-100,100);
}
 
int main(int argc, char** argv) 
{

printf("Enter the value of x1 : ");
scanf("%d",&x1);
printf("Enter the value of y1 : ");
scanf("%d",&y1);
printf("Enter the value of x2 : ");
scanf("%d",&x2);
printf("Enter the value of y2 : ");
scanf("%d",&y2);
 
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (50, 50);
glutCreateWindow ("DDA Line Algorithm");
init();
glutDisplayFunc(display);
glutMainLoop();
 
return 0;
}
