/*
 * EnemyShip.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: zaid
 */

#include "EnemyShip.h"

EnemyShip::EnemyShip() {
	// TODO Auto-generated constructor stub

x_1=920; y_1=720;
x_2=935; y_2=720;
x_3=943; y_3=710;
x_4=958; y_4=700;
x_5=943; y_5=680;
x_6=912; y_6=680;
x_7=897; y_7=700;
x_8=912; y_8=710;


}

void EnemyShip::drawSpaceship(Board *b,int x,int y){

	DrawLine(x_1+x,y_1+y,x_2+x,y_2+y,2,colors[5]);
	DrawLine(x_2+x,y_2+y,x_3+x,y_3+y,2,colors[5]);
	DrawLine(x_3+x,y_3+y,x_4+x,y_4+y,2,colors[5]);
	DrawLine(x_4+x,y_4+y,x_5+x,y_5+y,2,colors[5]);
	DrawLine(x_5+x,y_5+y,x_6+x,y_6+y,2,colors[5]);
	DrawLine(x_6+x,y_6+y,x_7+x,y_7+y,2,colors[5]);
	DrawLine(x_7+x,y_7+y,x_8+x,y_8+y,2,colors[5]);
	DrawLine(x_8+x,y_8+y,x_1+x,y_1+y,2,colors[5]);

	DrawLine(x_8+x,y_8+y,x_3+x,y_3+y,2,colors[5]);
	DrawLine(x_7+x,y_7+y,x_4+x,y_4+y,2,colors[5]);


}

EnemyShip::~EnemyShip() {
	// TODO Auto-generated destructor stub
}

