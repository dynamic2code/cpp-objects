//This programm was written on a linux machine on a windows machine the include statments should be un commented

// for windows users un comment the first line
//#include <GL/wglext.h>
//#include <Gl/glu.h>

#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
//the programms defination
//declarations
void display();
void reshape(int,int);
float x_position = -10;
void timer(int);
int state = 1;

//the main method
int  main(int argc,char **argv){
	glutInit(&argc,argv);
	//GLUT_DOUBLE  adds another frame buffer to reduce destotion and loss of quality for low power devices
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(200,100);
	glutInitWindowSize(1000,500);
	glutCreateWindow("Our Group Assingnment");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(1000, timer, 0);
	glutMainLoop();
	return 0;
} 

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	//the drawing comes here

	glBegin(GL_POLYGON);
	//2 for 2D f for the float datatype we'll use
	glVertex2f(x_position, 1);
	glVertex2f(x_position, -1);
	glVertex2f(x_position + 2,- 1);
	glVertex2f(x_position + 2, 1);

	glEnd();
        glBegin(GL_POLYGON);
        //2 for 2D f for the float datatype we'll use
        glVertex2f(x_position, -2);
        glVertex2f(x_position, -4);
        glVertex2f(x_position + 2,- 4);
        glVertex2f(x_position + 2, -2);

        glEnd();
        glBegin(GL_POLYGON);
        //2 for 2D f for the float datatype we'll use
        glVertex2f(x_position, 4);
        glVertex2f(x_position, 2);
        glVertex2f(x_position + 2, 2);
        glVertex2f(x_position + 2, 4);

        glEnd();

        glBegin(GL_POLYGON);
        //2 for 2D f for the float datatype we'll use
        glVertex2f(x_position, 8);
        glVertex2f(x_position, 6);
        glVertex2f(x_position + 2,6);
        glVertex2f(x_position + 2, 8);

        glEnd();
        glBegin(GL_POLYGON);
        //2 for 2D f for the float datatype we'll use
        glVertex2f(x_position, -6);
        glVertex2f(x_position, -8);
        glVertex2f(x_position + 2,-8);
        glVertex2f(x_position + 2, -6);

        glEnd();

	//glFlush();
	glutSwapBuffers();
}

void reshape(int x,int y){
	//view port where the drawings will be visible
	glViewport(0, 0, x, y);
	// projection matrix used for prjections and rotations
	// only chang to the projection matrix when you need to change the projection
	//always use the anticlock wise direction. Points should follow  an aticlockwise  direction
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	//change to the default mode always
	glMatrixMode(GL_MODELVIEW);
}

void timer(int){
	//creating the  displaying loop
	glutPostRedisplay();
	glutTimerFunc(1000/60, timer, 0);
	// changing the coordinates
	switch(state){
	case 1:
        	if(x_position < 8){
        		x_position += 0.20;
        	}
		else{
			state = -1;
		}
		break;
	case -1:
                if(x_position > -10){
                        x_position -= 0.20;
                }
                else{ 
                        state = 1;
                }
                break;
	}
}
