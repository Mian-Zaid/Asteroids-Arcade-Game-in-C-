/*
 * Bombs.cpp
 *
 *  Created on: May 3, 2018
 *      Author: zaid
 */

#include "Bombs.h"
#include <iostream>
using namespace std;

Bombs::Bombs() {
	// TODO Auto-generated constructor stub
	bomb_x=0;
	bomb_y=0;
}
void Bombs::DrawBomb(int n,int k){
	if(n==1){//up
		DrawCircle(bomb_x,bomb_y+k,2,colors[5]);
	}
	else if(n==2){//right
		DrawCircle(bomb_x+k,bomb_y,2,colors[5]);
	}
	else if(n==3){//left
		DrawCircle(bomb_x-k,bomb_y,2,colors[5]);
	}
	else if(n==4){//down
		DrawCircle(bomb_x,bomb_y-k,2,colors[5]);
	}
	else if(n==5){
		DrawCircle(bomb_x-k,bomb_y+k,2,colors[5]);
	}
	else if(n==6){
		DrawCircle(bomb_x-k,bomb_y-k,2,colors[5]);
	}
	else if(n==7){
		DrawCircle(bomb_x+k,bomb_y+k,2,colors[5]);
	}
	else if(n==8){
		DrawCircle(bomb_x+k,bomb_y-k,2,colors[5]);
	}

}

int Bombs::getBomb_x(){
	return bomb_x;
}
int Bombs::getBomb_y(){
	return bomb_y;
}
void Bombs::setBomb_x(int x){
	bomb_x=x;
}
void Bombs::setBomb_y(int y){
	bomb_y=y;
}

Bombs::~Bombs() {
	// TODO Auto-generated destructor stub
}

