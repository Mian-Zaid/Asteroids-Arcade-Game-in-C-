/*
 * Bombs.h
 *
 *  Created on: May 3, 2018
 *      Author: zaid
 */

#ifndef BOMBS_H_
#define BOMBS_H_
#include <iostream>
#include "util.h"
using namespace std;

class Bombs{
	int bomb_x;
	int bomb_y;
public:
	Bombs();
	int getBomb_x();
	int getBomb_y();
	void setBomb_x(int);
	void setBomb_y(int);
	void DrawBomb(int n,int k);
	virtual ~Bombs();
};

#endif /* BOMBS_H_ */
