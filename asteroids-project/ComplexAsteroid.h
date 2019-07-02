/*
 * ComplexAsteroid.h
 *
 *  Created on: May 3, 2018
 *      Author: zaid
 */

#ifndef COMPLEXASTEROID_H_
#define COMPLEXASTEROID_H_
#include <iostream>
#include "Asteroid.h"
using namespace std;

class ComplexAsteroid:public Asteroid {
private:
	int rad_2;
public:
	ComplexAsteroid();
	int getRad_2();
	void drawAsteroid(int rad);
	virtual ~ComplexAsteroid();
};

#endif /* COMPLEXASTEROID_H_ */
