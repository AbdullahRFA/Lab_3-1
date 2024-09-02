#include<stdlib.h>
#include<stdio.h>
#include <iostream>
using namespace std;
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;

GLint xc,yc,r,sizes = 1000;
void draw_pixel(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

void myInit(void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void readInput() {
  printf("Enter xc, yc, radius(resp): ");
  scanf("%i %i %i",&xc, &yc, &r);
}

void setPixel(GLint xcoordinate, GLint ycoordinate) {
  glBegin(GL_POINTS);
  glVertex2i(xcoordinate, ycoordinate);
  glEnd();
  glFlush();
}

void draw_axis() {
  GLint i = (-sizes) / 2;
  for(;i< (sizes / 2); i++) {
    setPixel(i, 0);
    setPixel(0, i);
  }
}

void draw_in_each_oct(GLint xk,GLint yk, GLint xc,GLint yc) {
  setPixel(xc + xk, yc + yk);
  setPixel(xc + yk, yc + xk);
  setPixel(xc - yk, yc + xk);
  setPixel(xc - xk, yc + yk);
  setPixel(xc - xk, yc - yk);
  setPixel(xc - yk, yc - xk);
  setPixel(xc + yk, yc - xk);
  setPixel(xc + xk, yc - yk);
}

void midPtCircle(GLint xc,GLint yc,GLint r) {
  GLint pk, xk, yk;
  pk = 1 - r;
  xk = 0;
  yk = r;
  draw_in_each_oct(xk, yk, xc, yc);
  while (xk <= yk) {
    if (pk < 0) {
      xk = xk + 1;
      pk = pk + (2 * xk) + 1;
    } else {
      xk = xk + 1;
      yk = yk - 1;
      pk = pk + (2 * xk) + 1 - (2 * yk);
    }
    draw_in_each_oct(xk, yk, xc, yc);
  }
}

void Display() {
  glClear(GL_COLOR_BUFFER_BIT);
  draw_axis();
  midPtCircle(xc, yc, r);
}

int main(int argc,char *argv[]) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600,600);
  glutInitWindowPosition(50,50);
  glutCreateWindow("Exp2: Mid Point Circle");
  readInput();
  glutDisplayFunc(Display);
  myInit();
  glutMainLoop();
  return 0;
}