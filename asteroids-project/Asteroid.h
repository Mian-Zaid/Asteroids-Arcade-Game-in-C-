/*
 * Asteroid.h
 *
 *  Created on: Apr 28, 2018
 *      Author: zaid
 */

#ifndef ASTEROID_H_
#define ASTEROID_H_
#include <iostream>
#include "Board.h"
using namespace std;

class Asteroid:public Board {
protected:
	int rand_points;
	int *num_arr;
	int *x_arr;
	int *y_arr;
	int x,y;
	int rad;
	//int rad2;
	int rand_mov;


public:
	//int distenceBtwTwoPoints(int x1,int y1,int x2,int y2);
	void randomPoints();
	virtual void drawAsteroid(int rad);
	int getrand_points();
	void setRand_mov();
	void setX(int);
	void setY(int);
	int getX();
	int getY();
	int getRad();
	int* getNum_arr();
	int *getX_arr();
	int *getY_arr();
	void setX_arr(int,int  );
	void setY_arr(int,int );
	void movement(int,int);
	Asteroid(Board *b);
	Asteroid();
	virtual ~Asteroid();
};

#endif /* ASTEROID_H_ */
