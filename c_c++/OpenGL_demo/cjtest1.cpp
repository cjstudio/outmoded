#include "cjtest1.h"

CJTest1::CJTest1()
{
    const GLfloat PI = 3.1415926536f;
    short angle = 18;
    for(short i=0;i<5;++i)
    {
        Point[i][0] = cos(angle * PI/180);
        Point[i][1] = sin(angle * PI/180);
        Point[i][2] = 0.0;      // Z值
        angle += 72;
    }
}

CJTest1::~CJTest1()
{
    makeCurrent();
}

void CJTest1::initializeGL()
{
    glShadeModel(GL_SMOOTH);

    glClearColor(0.0,0.0,0.0,0.0);
    glClearDepth(1.0);

    glEnable(GL_DEPTH_TEST);

    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,Point);
}

void CJTest1::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(-1.5,0.0,-6.0);

    glBegin(GL_TRIANGLES);
        glVertex3f(0.0,1.0,0.0);
        glVertex3f(-1.0,-1.0,0.0);
        glVertex3f(1.0,-1.0,0.0);
    glEnd();

    glTranslatef(3.0,0.0,0.0);

    glBegin(GL_LINE_LOOP);
        glArrayElement(1);
        glArrayElement(4);
        glArrayElement(2);
        glArrayElement(0);
        glArrayElement(3);
    glEnd();
}

void CJTest1::resizeGL(int width, int height)
{
    int side = qMin(width, height);
//    glViewport((width - side) / 2 , (height - side) / 2, side, side);
    glViewport(0,0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-2.5, +2.5, -1.2, 1.3, 5.0, 6.0);
//    glFrustum(-2.5, +2.5, -2.5, 2.5, 5.0, 6.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(40.0, 0.0, -40.0);
}
