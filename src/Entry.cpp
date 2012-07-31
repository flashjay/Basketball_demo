//  main.cpp
//  BasketBall
//
//  Created by FarYang on 7/31/12.
//  Copyright (c) 2012 FarYang. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GLUT/glut.h>
#include "Game.h"

using namespace std;

const int tick = 50;/*ms*/

int main_window, bottom_window, right_window;

float obj_pos[] = { 2.0, 0.0, -50.0 };
int last_x,last_y;


void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(-obj_pos[0],-obj_pos[1],-obj_pos[2] );
    GAME->Render();
    //draw the secen
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f,0.0f,70.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
    glutPostRedisplay();
}

void update()
{
    if ( glutGetWindow() != main_window )
        glutSetWindow(main_window);
    usleep(tick * 1000);
    GAME->Update();
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH );
    glutInitWindowSize( 800, 600 );
    glutInitWindowPosition(800, 500);
    main_window = glutCreateWindow( "BasketBall - keywords: AI, FSM, Steering Behaviors" );
    glClearColor(0.0, 00.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    srand((unsigned)time(NULL));
    glutDisplayFunc( display );
    glutReshapeFunc(reshape);
    
    glutIdleFunc(update);
    
    glutMainLoop();
    return 0;
}

