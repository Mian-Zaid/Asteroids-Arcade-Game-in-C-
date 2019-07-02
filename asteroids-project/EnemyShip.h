/*
 * EnemyShip.h
 *
 *  Created on: Apr 30, 2018
 *      Author: zaid
 */

#ifndef ENEMYSHIP_H_
#define ENEMYSHIP_H_
#include "iostream"
using namespace std;
#include "SpaceShip.h"

class EnemyShip:public SpaceShip {
private:
	int x_4;
	int y_4;
	int x_5;
	int y_5;
	int x_6;
	int y_6;
	int x_7;
	int y_7;
	int x_8;
	int y_8;
public:
	EnemyShip();
	void drawSpaceship(Board *b,int x,int y);
	virtual ~EnemyShip();
};

#endif /* ENEMYSHIP_H_ */
