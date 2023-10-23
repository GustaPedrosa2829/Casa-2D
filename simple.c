
/* Copyright (c) Mark J. Kilgard, 1996. */

/* This program is freely distributable without licensing fees 
   and is provided without guarantee or warrantee expressed or 
   implied. This program is -not- in the public domain. */

/* This program is a response to a question posed by Gil Colgate
   <gcolgate@sirius.com> about how lengthy a program is required using
   OpenGL compared to using  Direct3D immediate mode to "draw a
   triangle at screen coordinates 0,0, to 200,200 to 20,200, and I
   want it to be blue at the top vertex, red at the left vertex, and
   green at the right vertex".  I'm not sure how long the Direct3D
   program is; Gil has used Direct3D and his guess is "about 3000
   lines of code". */

/* X compile line: cc -o simple simple.c -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm */

#include <GL/glut.h>
#include <math.h>


void
reshape(int w, int h)
{
  /* Because Gil specified "screen coordinates" (presumably with an
     upper-left origin), this short bit of code sets up the coordinate
     system to correspond to actual window coodrinates.  This code
     wouldn't be required if you chose a (more typical in 3D) abstract
     coordinate system. */

  glViewport(0, 0, w, h);       /* Establish viewing area to cover entire window. */
  glMatrixMode(GL_PROJECTION);  /* Start modifying the projection matrix. */
  glLoadIdentity();             /* Reset project matrix. */
  glOrtho(0, w, 0, h, -1, 1);   /* Map abstract coords directly to window coords. */
  //glScalef(1, -1, 1);           /* Invert Y axis so increasing Y goes down. */
  //glTranslatef(0, -h, 0);       /* Shift origin up to upper-left corner. */
}
//glColor3f(0.0, 1.0, 0.0);  /* green */
//glColor3f(1.0, 0.0, 0.0);  /* red */
void
display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_QUADS);

    glColor3f(0.0, 0.5, 1.0);  /* green */
    glVertex2i(0, 0);  
    glColor3f(0.0, 0.5, 1.0);  /* green */
    glVertex2i(200, 0);
    glColor3f(0.0, 0.5, 1.0);  /* red */
    glVertex2i(200, 200);
    glColor3f(0.0, 0.5, 1.0);  /* red */
    glVertex2i(0, 200);
  glEnd();
  glBegin(GL_QUADS);
  //porta
    glColor3f(0.55, 0.34, 0.26);  /* blue */
    glVertex2i(50, 0);
    glColor3f(0.55, 0.34, 0.26);  /* green */
    glVertex2i(125, 0);
    glColor3f(0.55, 0.34, 0.26);  /* red */
    glVertex2i(125, 100);
    glColor3f(0.55, 0.34, 0.26);  /* red */
    glVertex2i(50, 100);
  glEnd();
  //macaneta
  glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 0.0, 0.0);  
    glVertex2f(110, 50); // Centro do círculo
    float numSegments = 100;
    float radius = 5.0;
    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * 3.1415926f * i / numSegments;
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + 110, y + 50);
    }
  glEnd();
   glBegin(GL_QUADS);
   //retangulo verde
    glColor3f(0.0, 0.75, 1.0);  /* blue */
    glVertex2i(200, 0);
    glColor3f(0.0, 0.75, 1.0);  /* green */
    glVertex2i(500, 0);
    glColor3f(0.0, 0.75, 1.0);  /* red */
    glVertex2i(500, 200);
    glColor3f(0.0, 0.75, 1.0);  /* red */
    glVertex2i(200, 200);
  glEnd();
   glBegin(GL_QUADS);
   //janela branca 1
    glColor3f(0.44, 0.5, 0.56);  /* blue */
    glVertex2i(250, 75);
    glColor3f(0.44, 0.5, 0.56);  /* green */
    glVertex2i(300, 75);
    glColor3f(0.44, 0.5, 0.56);  /* red */
    glVertex2i(300, 125);
    glColor3f(0.44, 0.5, 0.56);  /* red */
    glVertex2i(250, 125);
  glEnd();
  //linha horizontal da janela1
  glBegin(GL_LINES);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2i(250,100);
  glVertex2i(300,100);
  glEnd();
  //linha vertical da janela1
  glBegin(GL_LINES);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2i(275,125);
  glVertex2i(275,75);
  glEnd();
  glBegin(GL_QUADS);
   //janela branca 2
    glColor3f(0.44, 0.5, 0.56);  /* blue */
    glVertex2i(350, 75);
    glColor3f(0.44, 0.5, 0.56);  /* green */
    glVertex2i(400, 75);
    glColor3f(0.44, 0.5, 0.56);  /* red */
    glVertex2i(400, 125);
    glColor3f(0.44, 0.5, 0.56);  /* red */
    glVertex2i(350, 125);
  glEnd();
  //linha horizontal da janela2
  glBegin(GL_LINES);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2i(350,100);
  glVertex2i(400,100);
  glEnd();
  //linha vertical da janela2
  glBegin(GL_LINES);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2i(375,125);
  glVertex2i(375,75);
  glEnd();
  glBegin(GL_TRIANGLES);
  //telhado vermelho
    glColor3f(1.0, 0.92, 0.8);  /* blue */
    glVertex2i(0, 200);
    glColor3f(1.0, 0.92, 0.8);  /* green */
    glVertex2i(200, 200);
    glColor3f(1.0, 0.92, 0.8);  /* red */
    glVertex2i(100, 300);
  glEnd();
  // circulo janela
  glBegin(GL_TRIANGLE_FAN);
  glColor3f(0.44, 0.5, 0.56);  // Verde
  glVertex2f(100, 240); // Centro do círculo
  numSegments = 100;
  radius = 25.0;
  for (int i = 0; i <= numSegments; i++) {
      float theta = 2.0f * 3.1415926f * i / numSegments;
      float x = radius * cosf(theta);
      float y = radius * sinf(theta);
      glVertex2f(x + 100, y + 240);
  }
  glEnd();
  //linha horizontal da janela circular
  glBegin(GL_LINES);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2i(125,240);
  glVertex2i(75,240);
  glEnd();
  //linha vertical da janela circular
  glBegin(GL_LINES);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2i(100,265);
  glVertex2i(100,215);
  glEnd();
  glBegin(GL_QUADS);
  //telhado amarelo
    glColor3f(1.0, 0.27, 0.0);  
    glVertex2i(200, 200);
    glColor3f(1.0, 0.27, 0.0);  
    glVertex2i(500, 200);
    glColor3f(1.0, 0.27, 0.0);  
    glVertex2i(400, 300);
    glColor3f(1.0, 0.27, 0.0);  
    glVertex2i(100, 300);
  glEnd();
  //bloquinho da chamine
  glBegin(GL_QUADS);
    glColor3f(0.8, 0.36, 0.36);  /* blue */
    glVertex2i(280, 300);
    glColor3f(0.8, 0.36, 0.36);  /* green */
    glVertex2i(310, 300);
    glColor3f(0.8, 0.36, 0.36);  /* red */
    glVertex2i(310, 310);
    glColor3f(0.8, 0.36, 0.36);  /* red */
    glVertex2i(280, 310);
  glEnd();
  //chamine
  glBegin(GL_QUADS);
    glColor3f(0.8, 0.36, 0.36);  /* blue */
    glVertex2i(275, 310);
    glColor3f(0.8, 0.36, 0.36);  /* green */
    glVertex2i(315, 310);
    glColor3f(0.8, 0.36, 0.36);  /* red */
    glVertex2i(315, 325);
    glColor3f(0.8, 0.36, 0.36);  /* red */
    glVertex2i(275, 325);
  glEnd();
  //fumaca1
  glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0);  
    glVertex2f(300, 340); // Centro do círculo
     numSegments = 100;
     radius = 10.0;
    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * 3.1415926f * i / numSegments;
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + 300, y + 340);
    }
  glEnd();
  //fumaca2
  glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0);  
    glVertex2f(310, 350); // Centro do círculo
     numSegments = 100;
     radius = 10.0;
    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * 3.1415926f * i / numSegments;
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + 310, y + 350);
    }
  glEnd();
  //fumaca3
  glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0);  
    glVertex2f(305, 363); // Centro do círculo
     numSegments = 100;
     radius = 10.0;
    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * 3.1415926f * i / numSegments;
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + 305, y + 363);
    }
  glEnd();
  glFlush();  /* Single buffered, so needs a flush. */
}
int
main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(640,500);
  glutCreateWindow("Casa bonita");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}
