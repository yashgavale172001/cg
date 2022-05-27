#include<GL/glut.h>
void init(void)
{
glClearColor(0.0,0.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100,100,-100,100);
}
void display()
{
int tx=10, ty=10;
glClear(GL_COLOR_BUFFER_BIT);
glPointSize(4.0f);
glBegin(GL_LINES);

glVertex2i(-100.0f,0.0f);
glVertex2i(100.0f,0.0f);
glVertex2i(0.0f,100.0f);
glVertex2i(0.0f,-100.0f);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0f,1.0f,0.0f);
glVertex2i(10,10);
glVertex2i(40,40);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0f,0.0f,1.0f);
glVertex2i(40+tx, 40+ty);
glEnd();
glFlush();
}

int main(int argc, char**argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(50,50);
glutCreateWindow("translation");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
