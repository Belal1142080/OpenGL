#include<windows.h>
#include <GL/glut.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
#include <stdio.h>
#include <stdarg.h>
#define PI 3.1416

int m=-200;
int n=-50;
int wrongTry = 6;
char hangmanWord[100] ="hangman";
char tempWord[100]    ="-------" ;
void showHangman(int);
static bool win=false;
static float fx=5,fy=95;
static float tx=5,ty=85;
GLfloat spin = 0.0;
GLint z;
static float cloud1 = 20;
static float cloud2 = 60;
void clouds_mov();
void MyMusic();


void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
}


void drawstring(float x,float y, float z ,char *string)
{
    char *c;
	glRasterPos3i(x,y,z);

	for(c=string;*c!='\0';c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
	}
}


void circle(GLdouble rad)
{
    GLint points = 10;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( z = 0; z <=10; z++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}


void drawstring(float x,float y, float z ,char str)
{
	glRasterPos3i(x,y,z);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str);
}


void update(unsigned char key){
    for (int i=0;tempWord[i]!='\0';i++){
        if(hangmanWord[i] == key)
            tempWord[i] = key;
            printf("%c",tempWord[i]);
    }
    win=true;
    for (int i=0;tempWord[i]!='\0';i++){
        if (hangmanWord[i]!=tempWord[i]){
            win=false;
        }
    }
}


void enter(unsigned char key,int x, int y){
    glutIdleFunc(clouds_mov);

    int f = 0;
    if(wrongTry == 0)
        exit(0);
    if(strchr(hangmanWord, key)){
        f=1;
        update(key);
    }
    if(f==0)
        wrongTry--;

}


void circle(float radius_x, float radius_y)
{
    glColor3f(1.0f, 1.f, 1.0f);
	int i=0;
	float angle = 0.0;
	glBegin(GL_POLYGON);
		for(i = 0; i < 200; i++)
		{
			angle = 2 * PI * i / 200;
			glVertex2f (cos(angle) * radius_x, sin(angle) * radius_y);
		}
	glEnd();
}


void bgdown(float len_X, float len_Y)
{
    glColor3f(.6f, .6f, 0.0f);
	glBegin(GL_POLYGON);
			glVertex2f (len_X, len_Y);
			glVertex2f (len_X, len_Y);
			glVertex2f (-len_X, len_Y);
            glVertex2f (len_X, -len_Y);
    glEnd();
}


void bgmiddle(float len_X, float len_Y)
{
    glColor3f(.3f, 0.3f, 1.0f);

	glBegin(GL_POLYGON);
			glVertex2f (0,26.5);
			glVertex2f (100,26.5 );
			glVertex2f (100, 80);
            glVertex2f (0, 80);
    glEnd();
}


void bgup(float len_X, float len_Y)
{
     glColor3f(.3f, 0.3f, 1.0f);

	glBegin(GL_POLYGON);
			glVertex2f (0,80);
			glVertex2f (100,80 );
			glVertex2f (100, 100);
            glVertex2f (0, 100);
    glEnd();
}


void letter()
{
        glColor3f(1.0,0.0,0.0);
        drawstring(fx+2,fy-3,0.0,"A");
        drawstring(fx+9,fy-3,0.0,"B");
        drawstring(fx+16,fy-3,0.0,"C");
        drawstring(fx+23,fy-3,0.0,"D");
        drawstring(fx+30,fy-3,0.0,"E");
        drawstring(fx+37,fy-3,0.0,"F");
        drawstring(fx+44,fy-3,0.0,"G");
        drawstring(fx+51,fy-3,0.0,"H");
        drawstring(fx+58,fy-3,0.0,"I");
        drawstring(fx+65,fy-3,0.0,"J");
        drawstring(fx+72,fy-3,0.0,"K");
        drawstring(fx+79,fy-3,0.0,"L");
        drawstring(fx+86,fy-3,0.0,"M");
        drawstring(tx+2,ty-3,0.0,"N");
        drawstring(tx+9,ty-3,0.0,"O");
        drawstring(tx+16,ty-3,0.0,"P");
        drawstring(tx+23,ty-3,0.0,"Q");
        drawstring(tx+30,ty-3,0.0,"R");
        drawstring(tx+37,ty-3,0.0,"S");
        drawstring(tx+44,ty-3,0.0,"T");
        drawstring(tx+51,ty-3,0.0,"U");
        drawstring(tx+58,ty-3,0.0,"V");
        drawstring(tx+65,ty-3,0.0,"W");
        drawstring(tx+72,ty-3,0.0,"X");
        drawstring(tx+79,ty-3,0.0,"Y");
        drawstring(tx+86,ty-3,0.0,"Z");

}


void letterbox(void){
    int i=0;
    int j=0;
    for(i = 0; i < 90; i=i+7){

            glColor3f(0.0f, 0.8f, 0.0f);   //1st line
            glBegin(GL_QUADS);
            glVertex3f(fx+i, fy, 0.0);
            glVertex3f(fx+i, fy-5, 0.0);
            glVertex3f(fx+5+i, fy-5, 0.0);
            glVertex3f(fx+5+i, fy, 0.0);
            glEnd();
    };
    for(j = 0; j < 90; j=j+7){
            glColor3f(0.0f, 0.8f, 0.0f);   //2nd line
            glBegin(GL_QUADS);
            glVertex3f(tx+j, ty, 0.0);
            glVertex3f(tx+j, ty-5, 0.0);
            glVertex3f(tx+5+j, ty-5, 0.0);
            glVertex3f(tx+5+j, ty, 0.0);
            glEnd();
            letter();
		};
}



///    if (wrongTry ==5){
 void head(){
        glPushMatrix();
        glColor3f(1.0f, .5f, 0.0f);          //head
        glTranslatef(47.5,52.5,0);
        circle(2.5);
        glPopMatrix();
    }


///    else if (wrongTry ==4){
void body(){
        glColor3f(0.5,0,0.5);   //body
        glBegin(GL_QUADS);
        glVertex3f(50, 50, 0.0);
        glVertex3f(45, 50, 0.0);
        glVertex3f(45, 40, 0.0);
        glVertex3f(50, 40, 0.0);
        glEnd();
    }


 ///   else if (wrongTry ==3){
void lt_hand(){
        glColor3f(1.0f, 0.5f, 0.0f);  //left hand
        glBegin(GL_QUADS);
        glVertex3f(50.0, 50.0, 0.0);
        glVertex3f(50.0, 48.0, 0.0);
        glVertex3f(53.0, 48, 0.0);
        glVertex3f(53.0, 50, 0.0);
        glEnd();
    }


///    else if (wrongTry ==2){
void rt_hand(){
        glColor3f(1.0f, 0.5f, 0.0f); //right hand
        glBegin(GL_QUADS);
        glVertex3f(45.0, 50, 0.0);
        glVertex3f(42.0, 50, 0.0);
        glVertex3f(42.0, 48, 0.0);
        glVertex3f(45.0, 48.0, 0.0);
        glEnd();
        }


///    else if (wrongTry ==1){
void lt_leg(){
        glColor3f(0.1f, 0.2f, 0.1f); //right leg
        glBegin(GL_QUADS);
        glVertex3f(45, 40, 0.0);
        glVertex3f(45, 36, 0.0);
        glVertex3f(47, 36, 0.0);
        glVertex3f(47, 40, 0.0);
        glEnd();
    }


///    else if (wrongTry ==0){
void rt_leg(){
        glColor3f(0.1f, 0.2f, 0.1f); // left leg
        glBegin(GL_QUADS);
        glVertex3f(50, 40, 0.0);
        glVertex3f(48, 40, 0.0);
        glVertex3f(48, 36, 0.0);
        glVertex3f(50, 36, 0.0);
        glEnd();
        glColor3f(1.0f, 0.0f, 0.0f);
        drawstring(35,68,0.0,"LOSER!! LOSER!!");
}


///*** Tree_Model ***///
void Tree_Model_One(){
    glPushMatrix();
    glTranslatef(16,40,0);
    glColor3f(0.0f, 0.8f, 0.0f);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(16,48,0);
    circle(8);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(15, 35);
	glVertex2f(15, 17);
	glVertex2f(17, 17);
	glVertex2f(17, 35);

    glEnd();

}


void Tree_Model_two(){
    glPushMatrix();
    glTranslatef(6,60,0);
     glColor3f(0.0f, 0.80f, 0.0f);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6,68,0);
    circle(8);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(5, 55);
	glVertex2f(5, 21);
	glVertex2f(7, 21);
	glVertex2f(7, 55);

    glEnd();

}


void Tree_Model_three(){
    glPushMatrix();
    glTranslatef(90,60,0);
    glColor3f(0.0f, 0.8f, 0.0f);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(90,68,0);
    circle(8);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(89, 55);
	glVertex2f(89, 21);
	glVertex2f(91, 21);
	glVertex2f(91, 55);

    glEnd();

}


void Tree_Model_four(){
    glPushMatrix();
    glTranslatef(80,40,0);
      glColor3f(0.0f, 0.8f, 0.0f);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(80,48,0);
    circle(8);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2f(79, 35);
	glVertex2f(79, 17);
	glVertex2f(81, 17);
	glVertex2f(81, 35);

    glEnd();

}


void clouds_mov()
{
    cloud1+=0.01;
    cloud2+=0.01;

    glutPostRedisplay();
}


void hangman(void)
{
    char c;
    bgdown(100,26.5);
    bgmiddle(100,60);
    bgup(100,80);
    Tree_Model_One();
    Tree_Model_two();
    Tree_Model_three();
    Tree_Model_four();
    //glClear(GL_COLOR_BUFFER_BIT);
    //letterbox();
    //letter();
    glColor3f(0.1f, 0.1f, 0.1f);
    drawstring(38,15,0.0,"A 2D PROJECT ON");
	glColor3f(0.1f, 0.1f, 0.1f);
	drawstring(41,10,0.0,"HANGMAN");
	glColor3f(1,0.5,0);

        glColor3f(0.1f, 0.1f, 0.1f);  //ground
        glBegin(GL_QUADS);
        glVertex3f(32, 30, 0.0);
        glVertex3f(32, 26, 0.0);
        glVertex3f(65, 26, 0.0);
        glVertex3f(65, 30, 0.0);
        glEnd();

        glColor3f(0.1f, 0.1f, 0.1f);  //vertical
        glBegin(GL_QUADS);
        glVertex3f(34, 30, 0.0);
        glVertex3f(36, 30, 0.0);
        glVertex3f(36, 64, 0.0);
        glVertex3f(34, 64, 0.0);
        glEnd();

        glColor3f(0.1f, 0.1f, 0.1f);  //horizontal
        glBegin(GL_QUADS);
        glVertex3f(36, 60, 0.0);
        glVertex3f(36, 59, 0.0);
        glVertex3f(58, 59, 0.0);
        glVertex3f(58, 60, 0.0);
        glEnd();

        glColor3f(0.1f, 0.1f, 0.1f);  //vertical to head
        glBegin(GL_QUADS);
        glVertex3f(47.5, 60,0);
        glVertex3f(47.5, 55, 0.0);
        glVertex3f(48.5, 56,0);
        glVertex3f(48.5, 60, 0.0);
        glEnd();

    if (wrongTry ==5){
        head();
        //glutPostRedisplay();
    }
    else if (wrongTry ==4){
        head();
        body();
    }
    else if (wrongTry ==3){
        head();
        body();
        lt_hand();
    }
    else if (wrongTry ==2){
        head();
        body();
        lt_hand();
        rt_hand();
    }
    else if (wrongTry ==1){
        head();
        body();
        lt_hand();
        rt_hand();
        lt_leg();
    }
    else if (wrongTry ==0){
        head();
        body();
        lt_hand();
        rt_hand();
        lt_leg();
        rt_leg();
    }
    if (win){
        glColor3f(1.0f, 0.0f, 0.0f);
        drawstring(35,68,0.0,"WINNER!! WINNER!!");
    }

    glColor3f(0,0,0);
    drawstring(40,77,0.0,tempWord);

    //cloud
    glPushMatrix();
    glTranslatef(cloud1,90,0);
    glColor3f(.949f, .949f, .949f);
    circle(7,3);
    circle(5,5);
    glTranslatef(-20,-92,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloud2,92,0);
    glColor3f(.949f, .949f, .949f);
    circle(7,3);
    circle(5,5);
    glTranslatef(-60,-90,0);
    glPopMatrix();
    if (cloud1>=102)
        cloud1=-2;
    if (cloud2>=102)
        cloud2=-2;
    glFlush();
    glutPostRedisplay();
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    hangman();
}


void MyMusic() {
    if (win==TRUE){
        PlaySound("applause3.wav",NULL,ASYNC_MODE_COMPATIBILITY);
        glutPostRedisplay();
    }
    if (win==FALSE){
        PlaySound("sad.wav",NULL,ASYNC_MODE_COMPATIBILITY);
        glutPostRedisplay();
    }
}


int main(int argc, char *argv[])
{
    char hangmanOutput[100];
    int matchFound = 0;
    int counter = 0 , position = 0, winner, length , i;
    char alphabetFromUser;

    glutInit( & argc, argv );
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (1024, 768);
	glutInitWindowPosition (50, 10);
	glutCreateWindow ("Hangman");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(enter);
	glutMainLoop();
	return 0;
}
