#include<GL/glut.h>
void init(void)
{
glClearColor(0.0,0.0,0.0,1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100,100,-100,100);
}
void display()
{
float sx=1.0, sy=2;
glClear(GL_COLOR_BUFFER_BIT);
glPointSize(4.0f);
glBegin(GL_LINE);

glVertex2i(-100.0f,0.0f);
glVertex2i(100.0f,0.0f);
glVertex2i(0.0f,100.0f);
glVertex2i(0.0f,-100.0f);
glEnd();

glBegin(GL_LINE_LOOP);
glColor3f(0.0f,1.0f,0.0f);
glVertex2i(10,10);
glVertex2i(40,10);
glVertex2i(20,40);
glEnd();

glBegin(GL_LINE_LOOP);
glColor3f(1.0f,0.0f,1.0f);
glVertex2i(10*sx, 10*sy);
glVertex2i(40*sx, 10*sy);
glVertex2i(20*sx, 40*sy);
glEnd();
glFlush();
}

int main(int argc, char**argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(50,50);
glutCreateWindow("Cube");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

