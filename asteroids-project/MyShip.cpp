/*
 * MyShip.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: zaid
 */

#include "MyShip.h"
#include <iostream>
#include "Board.h"
using namespace std;

MyShip::MyShip() {
	// TODO Auto-generated constructor stub

}

MyShip::MyShip(int x1,int y1,int x2,int y2,int x3,int y3){
	x_1=x1;
	x_2=x2;
	x_3=x3;
	y_1=y1;
	y_2=y2;
	y_3=y3;

}

void MyShip::drawSpaceship(Board* b){

	DrawTriangle(x_1,y_1,x_2,y_2,x_3,y_3,colors[139]);

}

void MyShip::Rotate(int x1,int y1,int x2,int y2,int x3,int y3,float Angle)
{
	int a1,b1,a2,b2,a3,b3,p=x2,q=y2;

	Angle=(Angle*3.14)/180;
	a1=p+(x1-p)*cos(Angle)-(y1-q)*sin(Angle);
	b1=q+(x1-p)*sin(Angle)+(y1-q)*cos(Angle);
	a2=p+(x2-p)*cos(Angle)-(y2-q)*sin(Angle);
	b2=q+(x2-p)*sin(Angle)+(y2-q)*cos(Angle);
	a3=p+(x3-p)*cos(Angle)-(y3-q)*sin(Angle);
	b3=q+(x3-p)*sin(Angle)+(y3-q)*cos(Angle);


	x_1=a1;
	y_1=b1;
	x_2=a2;
	y_2=b2;
	x_3=a3;
	y_3=b3;
	DrawTriangle(x_1,y_1,x_2,y_2,x_3,y_3,colors[5]);
}

int MyShip::movement(){


	if(x_3>x_1 && x_3<x_2 && y_3>y_1 && y_1==y_2){
		cout<<"Ship is upward\n";
		return 1;
	}

	else if((x_1-2)==(x_2)){
		cout<<"Ship is toward right\n";
		return 2;
	}

	else if(x_1==(x_2-1)){
		cout<<"Ship is toward left\n";
		return 3;
	}

	else if((y_2-3)==(y_1)){
		cout<<"Ship is downward\n";
		return 4;
	}

	else if(x_3<x_1 && x_1<x_2 && y_3>y_2 &&y_2>y_1){
		cout<<"Ship is up left\n";
		return 5;
	}
	else if(x_3<x_2 && x_2<x_1 && y_2>y_1 && y_1>y_3){
		cout<<"Ship is down left\n";
		return 6;
	}
	else if(x_1<x_2 && x_2<x_3 && y_3>y_1 && y_1>y_2){
		cout<<"Ship is up right\n";
		return 7;
	}
	else if(x_2<x_1 && x_1<x_3 && y_1>y_2 && y_2>y_3){
		cout<<"Ship is down right\n";
		return 8;
	}
	return 0;
}


int MyShip::getX_1(){
	return x_1;
}
int MyShip::getX_2(){
	return x_2;
}
int MyShip::getX_3(){
	return x_3;
}
int MyShip::getY_1(){
	return y_1;
}
int MyShip::getY_2(){
	return y_2;
}
int MyShip::getY_3(){
	return y_3;
}

void MyShip::setX_1(int a){
	x_1=a;
}
void MyShip::setX_2(int a){
	x_2=a;
}
void MyShip::setX_3(int a){
	x_3=a;
}
void MyShip::setY_1(int a){
	y_1=a;
}

void MyShip::setY_2(int a){
	y_2=a;
}
void MyShip::setY_3(int a){
	y_3=a;
}

void MyShip::fireBombs(Bombs bs,int n,int k){
	//for(int i=0;i<100;++i){
		bs.DrawBomb(n,k);
	//}
}

MyShip::~MyShip() {
	// TODO Auto-generated destructor stub
}

