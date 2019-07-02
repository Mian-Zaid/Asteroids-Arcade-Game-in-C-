//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Brick Slayer...
//============================================================================

#ifndef GAME_CPP_
#define GAME_CPP_
#include "Board.h"
#include "Bombs.h"
#include "util.h"
#include "Asteroid.h"
#include "SpaceShip.h"
#include "MyShip.h"
#include "EnemyShip.h"
#include "ComplexAsteroid.h"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

#include <cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


void DrawAsteroid(int x/*starting x*/, int y/*starting y*/,
		ColorNames color/*color*/, float radius = 6/*Asteroid radius in Units*/,
		const int corners = 7/*Asteroid corners*/) {
	int ogr = 6, ogh = 7;

	glPushMatrix();
	float sx = (float) radius / ogr;
	//glTranslatef(x, y, 1);
	//glScalef(sx, 1, 1);

	// Draw Asteroid here
	const int nvertices = 722;
	GLfloat vertices[nvertices][2];
	float hdegree = M_PI / (corners/2);
	float angle = 0;
	for (int i = 0; i < nvertices ; ++i) {
		vertices[i][0] = radius * cos(angle);
		vertices[i][1] = radius * sin(angle);
		angle += hdegree;
	}

	glColor3fv(colors[color]); // set the circle color
	glBegin(GL_TRIANGLE_FAN);
	glVertex4f(x, y, 0, 1);
	for (int i = 0; i < nvertices; ++i)
		glVertex4f(x + vertices[i][0], y + vertices[i][1], 0, 1);
	glEnd();

	glPopMatrix();
}

//Number of Vertices used to draw Bomberman Circle...
// x= r cos (theta), y= r sin(theta)
const int npmvertices = 1220;
GLfloat pmvertices[npmvertices][2];
void InitPMVertices(float radius) {

	float hdegree = (M_PI - M_PI / 2.0) / 360.0;
	float angle = M_PI + M_PI / 6.0;
	for (int i = 0; i < npmvertices; ++i) {
		pmvertices[i][0] = radius * cos(angle);
		pmvertices[i][1] = radius * sin(angle);
		angle += hdegree;
	}
}

void DrawBomberman(float sx/*center x*/, float sy/*center y*/,
		float radius/*Radius*/,
		const ColorNames &colorname/*Bomberman Colour*/) {

	glColor3fv(colors[colorname]); // set the circle color
	InitPMVertices(radius);
	glBegin (GL_TRIANGLE_FAN);
	glVertex4f(sx, sy, 0, 1);
	for (int i = 0; i < npmvertices; ++i)
		glVertex4f(sx + pmvertices[i][0], sy + pmvertices[i][1], 0, 1);
	glEnd();
	DrawCircle(sx - radius + radius / 2, sy + (radius - radius / 2),
			radius / 10, colors[BLACK]);
}




/*
 * Main Canvas drawing function.
 * */
Board *b;
Asteroid a(b);
int size=20;
Asteroid *array=new Asteroid[20];
ComplexAsteroid ca;
MyShip ms;
EnemyShip es;
SpaceShip *s=&ms;
Bombs bs;
float angle=45;
bool var=false;
int n=0;
int timee=1;
bool end_check=false;
int lives=3;

int score=0;
string str_1="";
int currentScore=0;
int initialScore=score;
int X=6;
int Y=2;
int k=10;
int g=0;


float dt =200.0 , lastframe = 0.0,myTime=0.0;
bool mov=false;
float start_time=dt,current_time=dt;

void intToStirng(int score){

	ostringstream str1;

	str1 << score;

	str_1 = str1.str();
}

void colissionDetection(){

}

void DrawLives(){
	DrawString(60, 770, "Lives ", colors[7]);
	int x1=120;
	int y1=770;
	int x2=150;
	int y2=770;
	int x3=135;
	int y3=800;
	for(int i=0;i<lives;++i){
		DrawTriangle(x1,y1,x2,y2,x3,y3,colors[WHITE]);
		x1+=30;
		x2+=30;
		x3+=30;
	}
}

void DrawTime(){

	int sec=myTime/1000;
	intToStirng(sec);
	DrawString(60,770-40, "Time "+str_1+" Seconds", colors[7]);
}
void DrawScore(int x, int y){
	b->GetInitTextPosition(x, y);
	intToStirng(score);
	DrawString(x, y, "Score "+str_1, colors[7]);
}


void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// draw asteroids

	int x, y;

	if(timee==2){

		if(lives>0){
			//score and lives...

			DrawScore(x,y); //score
			DrawLives();  //lives
			DrawTime();   //time

			currentScore=score;
			if(currentScore-initialScore==1000){
				lives++;
				initialScore=currentScore;
			}
			//start game..
			for(int i=0;i<size/2;++i){

				//large asteroids
				array[i].drawAsteroid(a.getRad());

			}
			for(int i=size/2;i<size;++i){
				//small asteroids
				array[i].drawAsteroid(ca.getRad_2());
			}
			ms.drawSpaceship(b);
			if(mov==true){
				es.drawSpaceship(b,X,Y);
				X-=6;
				Y-=2;
			}

		}
		else {
			timee=-1;
		}
	}
	else if(timee==1){
		//before starting game..
		var=false; //stop firing bombs..

		DrawString(static_cast<float>(b->GetWidth()/2-200),static_cast<float>(b->GetHeight()-250),"WELCOME TO ASTEROIDS ", colors[LIGHT_CYAN]);
		DrawString(static_cast<float>(b->GetWidth()/2-200),static_cast<float>(b->GetHeight()-350),"Wanna PLAY GAME ! Press ENTER ", colors[LIGHT_CYAN]);
		DrawString(static_cast<float>(b->GetWidth()/2-200),static_cast<float>(b->GetHeight()-550),"Press ESC to Exit... ", colors[LIGHT_CYAN]);
		DrawString(static_cast<float>(b->GetWidth()/2-200),static_cast<float>(b->GetHeight()-400),"Press BACKSPACE Pause GAME ", colors[LIGHT_CYAN]);
		DrawString(static_cast<float>(b->GetWidth()/2-200),static_cast<float>(b->GetHeight()-450),"Press 'E' to END GAME ", colors[LIGHT_CYAN]);

	}
	else if(timee==0){
		//after ending game..
		var=false; //stop firing bombs..


		DrawScore(x,y); //score
		DrawLives();  //lives
		DrawTime();   //time

		DrawString(static_cast<float>(b->GetWidth()/2-200),static_cast<float>(b->GetHeight()-400),"Press 'E' to END GAME ", colors[LIGHT_CYAN]);
		DrawString(static_cast<float>(b->GetWidth()/2-200),static_cast<float>(b->GetHeight()-350),"Press ENTER to RESUME ", colors[LIGHT_CYAN]);
		DrawString(static_cast<float>(b->GetWidth()/2-200),static_cast<float>(b->GetHeight()-500),"Press ESC to Exit... ", colors[LIGHT_CYAN]);
	}
	else if(timee==-1){
		//game over
		var=false;
		DrawString(static_cast<float>(b->GetWidth()/2-200),static_cast<float>(b->GetHeight()-250),"GAME OVER ", colors[LIGHT_CYAN]);
		DrawString(static_cast<float>(b->GetWidth()/2-200),static_cast<float>(b->GetHeight()-300),"FINAL SCORE  : "+str_1  , colors[LIGHT_CYAN]);
		DrawString(static_cast<float>(b->GetWidth()/2-200),static_cast<float>(b->GetHeight()-400),"Press ESC to Exit... ", colors[LIGHT_CYAN]);

	}
	//draw bombs

	if(var==true){

		if(g<10){
			//for(int i=0;i<10;++i){
			if(current_time-start_time>=200){
				start_time=current_time;
				ms.fireBombs(bs,n,k);
				k+=10;
			}
			//}
			g++;
		}
	}

	glutSwapBuffers(); // do not modify this line..

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	int x_cord=6;
	int y_cord=6;
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

		ms.Rotate(ms.getX_1(),ms.getY_1(),ms.getX_2(),ms.getY_2(),ms.getX_3(),ms.getY_3(),angle);

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {


		ms.Rotate(ms.getX_1(),ms.getY_1(),ms.getX_2(),ms.getY_2(),ms.getX_3(),ms.getY_3(),-angle);

	}
	else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		cout<<"Up key pressed\n";

		int n=ms.movement();

		if(n==1){
			ms.setY_1(ms.getY_1()+y_cord);
			ms.setY_2(ms.getY_2()+y_cord);
			ms.setY_3(ms.getY_3()+y_cord);
		}
		else if(n==2){
			ms.setX_1(ms.getX_1()+x_cord);
			ms.setX_2(ms.getX_2()+x_cord);
			ms.setX_3(ms.getX_3()+x_cord);
		}
		else if(n==3){
			ms.setX_1(ms.getX_1()-x_cord);
			ms.setX_2(ms.getX_2()-x_cord);
			ms.setX_3(ms.getX_3()-x_cord);
		}
		else if(n==4){
			ms.setY_1(ms.getY_1()-y_cord);
			ms.setY_2(ms.getY_2()-y_cord);
			ms.setY_3(ms.getY_3()-y_cord);
		}
		else if(n==5){
			ms.setX_1(ms.getX_1()-x_cord);
			ms.setX_2(ms.getX_2()-x_cord);
			ms.setX_3(ms.getX_3()-x_cord);

			ms.setY_1(ms.getY_1()+y_cord);
			ms.setY_2(ms.getY_2()+y_cord);
			ms.setY_3(ms.getY_3()+y_cord);
		}
		else if(n==6){
			ms.setX_1(ms.getX_1()-x_cord);
			ms.setX_2(ms.getX_2()-x_cord);
			ms.setX_3(ms.getX_3()-x_cord);

			ms.setY_1(ms.getY_1()-y_cord);
			ms.setY_2(ms.getY_2()-y_cord);
			ms.setY_3(ms.getY_3()-y_cord);

		}
		else if(n==7){
			ms.setX_1(ms.getX_1()+x_cord);
			ms.setX_2(ms.getX_2()+x_cord);
			ms.setX_3(ms.getX_3()+x_cord);

			ms.setY_1(ms.getY_1()+y_cord);
			ms.setY_2(ms.getY_2()+y_cord);
			ms.setY_3(ms.getY_3()+y_cord);
		}
		else if(n==8){
			ms.setX_1(ms.getX_1()+x_cord);
			ms.setX_2(ms.getX_2()+x_cord);
			ms.setX_3(ms.getX_3()+x_cord);

			ms.setY_1(ms.getY_1()-y_cord);
			ms.setY_2(ms.getY_2()-y_cord);
			ms.setY_3(ms.getY_3()-y_cord);
		}

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {


		int n=ms.movement();

		if(n==1){
			ms.setY_1(ms.getY_1()-y_cord);
			ms.setY_2(ms.getY_2()-y_cord);
			ms.setY_3(ms.getY_3()-y_cord);
		}
		else if(n==2){
			ms.setX_1(ms.getX_1()-x_cord);
			ms.setX_2(ms.getX_2()-x_cord);
			ms.setX_3(ms.getX_3()-x_cord);
		}
		else if(n==3){
			ms.setX_1(ms.getX_1()+x_cord);
			ms.setX_2(ms.getX_2()+x_cord);
			ms.setX_3(ms.getX_3()+x_cord);
		}
		else if(n==4){
			ms.setY_1(ms.getY_1()+y_cord);
			ms.setY_2(ms.getY_2()+y_cord);
			ms.setY_3(ms.getY_3()+y_cord);
		}
		else if(n==5){
			ms.setX_1(ms.getX_1()+x_cord);
			ms.setX_2(ms.getX_2()+x_cord);
			ms.setX_3(ms.getX_3()+x_cord);

			ms.setY_1(ms.getY_1()-y_cord);
			ms.setY_2(ms.getY_2()-y_cord);
			ms.setY_3(ms.getY_3()-y_cord);
		}
		else if(n==6){
			ms.setX_1(ms.getX_1()+x_cord);
			ms.setX_2(ms.getX_2()+x_cord);
			ms.setX_3(ms.getX_3()+x_cord);

			ms.setY_1(ms.getY_1()+y_cord);
			ms.setY_2(ms.getY_2()+y_cord);
			ms.setY_3(ms.getY_3()+y_cord);

		}
		else if(n==7){
			ms.setX_1(ms.getX_1()-x_cord);
			ms.setX_2(ms.getX_2()-x_cord);
			ms.setX_3(ms.getX_3()-x_cord);

			ms.setY_1(ms.getY_1()-y_cord);
			ms.setY_2(ms.getY_2()-y_cord);
			ms.setY_3(ms.getY_3()-y_cord);
		}
		else if(n==8){
			ms.setX_1(ms.getX_1()-x_cord);
			ms.setX_2(ms.getX_2()-x_cord);
			ms.setX_3(ms.getX_3()-x_cord);

			ms.setY_1(ms.getY_1()+y_cord);
			ms.setY_2(ms.getY_2()+y_cord);
			ms.setY_3(ms.getY_3()+y_cord);
		}

	}


	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	/*
	 glutPostRedisplay();
	 */
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		delete []array;
		exit(1); // exit the program when escape key is pressed.
	}

	if(end_check==false){
		if(key==32){  //space key
			//fire bombs
			bs.setBomb_x(ms.getX_3());
			bs.setBomb_y(ms.getY_3());

			n=ms.movement();

			var=true;
			k=10;
			g=0;

			score+=20;

		}
		if(key==13){  //enter key
			//start game or resume game
			timee=2;
		}
		if(key==8){  //backspace key
			//pause game
			timee=0;
		}
	}

	if(key==69 || key==101){  //E and e key
		//game over
		timee=-1;
		end_check=true;
	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */





void Timer(int m) {

	// implement your functionality here

	lastframe+=dt;
	current_time+=dt;
	myTime+=dt;
	//mov=false;
	if(lastframe>=30000){
		lastframe=0.0;
		mov=true;
	}

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutPostRedisplay();

	glutTimerFunc(dt, Timer, 0);
}

/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	b->InitalizeBoard(width, height);

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("CP's Asteroids"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
#ifdef WITH_TEXTURES
	RegisterTextures();
#endif
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	cout<<"Main Ended"<<endl;
	return 1;

}
#endif /* AsteroidS_CPP_ */
