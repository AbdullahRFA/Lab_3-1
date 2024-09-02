#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
// (x1, y2) and (x2, y3)
int x1, x2, y2, y3;

void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void display(void)
{
    int dy, dx, x, y;

    // step one find dx and dy;
    dx = x2 - x1;
    dy = y3 - y2;

    // increment in x and y and decision perameter.
    int increment_x, increment_y, Pk;

    // check if we need to increment or decrement.
    increment_x = 1, increment_y = 1;
    if (x2 < x1)
        increment_x = -1;
    if (y3 < y2)
        increment_y = -1;

    int inc1, inc2;

    x = x1, y = y2;

    if (dx > dy)
    {
        draw_pixel(x, y);
        Pk = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        for (int i = 0; i < dx; i++)
        {
            if (Pk >= 0)
            {
                y += increment_y;
                Pk += inc1;
            }
            else
            {
                Pk += inc2;
            }
            x += increment_x;
            draw_pixel(x, y);
        }
    }
    else
    {
        draw_pixel(x, y);
        Pk = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;
        for (int i = 0; i < dy; i++)
        {
            if (Pk >= 0)
            {
                x += increment_x;
                Pk += inc1;
            }
            else
            {
                Pk += inc2;
            }
            y += increment_y;
            draw_pixel(x, y);
        }
    }
    glFlush();
}

void myInit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char **argv)
{
    cout << "Enter the value of x1: ";
    cin >> x1;
    cout << "Enter the value of y1: ";
    p -
            cin >>
        y2;
    cout << "Enter the value of x2: ";
    cin >> x2;
    cout << "Enter the value of y2: ";
    cin >> y3;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Exp1 : Bresenham Line drawing");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}