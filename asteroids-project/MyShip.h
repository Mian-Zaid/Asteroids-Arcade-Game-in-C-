/*
 * MyShip.h
 *
 *  Created on: Apr 30, 2018
 *      Author: zaid
 */

#ifndef MYSHIP_H_
#define MYSHIP_H_
#include <iostream>
using namespace std;
#include "Board.h"
#include "Bombs.h"
#include "SpaceShip.h"
class MyShip:public SpaceShip {
public:
	MyShip();
	MyShip(int,int,int,int,int,int);

	int getX_1();
	int getX_2();
	int getX_3();
	int getY_1();
	int getY_2();
	int getY_3();


	void setX_1(int);
	void setX_2(int);
	void setX_3(int);
	void setY_1(int);
	void setY_2(int);
	void setY_3(int);

	void drawSpaceship(Board *b);
	void Rotate(int,int,int,int,int,int,float);
	int movement();
	void fireBombs(Bombs bs,int n,int k);
	virtual ~MyShip();
};

#endif /* MYSHIP_H_ */
