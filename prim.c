/*
 * GL02Primitive.cpp: Vertex, Primitive and Color
 * Draw Simple 2D colored Shapes: quad, triangle and polygon.
 */

#include <GL/glut.h>  // GLUT, include glu.h and gl.h
 
/* Initialize OpenGL Graphics */
void init(void)
{
glClearColor(0.0,0.0,0.0,1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100,100,-100,100);
}
 
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClear(GL_COLOR_BUFFER_BIT);   
glPointSize(4.0f);
 glBegin(GL_LINES);           
     
    glVertex2f(-100.0f, 0.0f);
    glVertex2f(100.0f, 0.0f);
      
    glVertex2f(0.0f, 100.0f);
    glVertex2f(0.0f, -100.0f);
     
   glEnd();
glBegin(GL_LINE_LOOP);           
     	  glColor3f(1.0f, 0.0f, 5.0f);   
    glVertex2f(10.0f, 10.0f);
    glVertex2f(40.0f, 10.0f);
      
    glVertex2f(40.0f, 40.0f);
   glVertex2f(10.0f, 40.0f);
    
   glEnd();

glBegin(GL_LINE_LOOP);           
     	  glColor3f(1.0f, 0.0f, 5.0f);   
    glVertex2f(25.0f, 25.0f);
    glVertex2f(55.0f, 25.0f);
      glVertex2f(55.0f, 55.0f);
    glVertex2f(25.0f, 55.0f);
    
   glEnd();

glBegin(GL_LINES);           
     	  glColor3f(1.0f, 0.0f, 5.0f);   
    glVertex2f(10.0f, 10.0f);
glVertex2f(25.0f, 25.0f);
    glVertex2f(40.0f, 10.0f);
      glVertex2f(55.0f, 25.0f);
    glVertex2f(40.0f, 40.0f);
 glVertex2f(55.0f, 55.0f);
   glVertex2f(10.0f, 40.0f);
 glVertex2f(25.0f, 55.0f);
    
   glEnd();



   glFlush();  // Render now
}
 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
  glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (50, 50);
glutCreateWindow ("Cube");
init();
glutDisplayFunc(display);
glutMainLoop();                // Enter the event-processing loop
   return 0;
}
