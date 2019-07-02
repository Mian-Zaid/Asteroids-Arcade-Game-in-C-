/*
 * SpaceShip.h
 *
 *  Created on: Apr 28, 2018
 *      Author: zaid
 */

#ifndef SPACESHIP_H_
#define SPACESHIP_H_
#include <iostream>
#include "Board.h"
using namespace std;

class SpaceShip {
protected:
	int x_1;
	int y_1;
	int x_2;
	int y_2;
	int x_3;
	int y_3;
public:
	virtual void drawSpaceship(Board *b);
	virtual void movement(int,int,int,Board *b);
	//virtual void Rotate(int,int,int,int,int,int,float);
	SpaceShip();
	virtual ~SpaceShip();
};

#endif /* SPACESHIP_H_ */
