/*
 * Asteroid.cpp
 *
 *  Created on: Apr 28, 2018
 *      Author: zaid
 */

#include "Asteroid.h"
#include "Board.h"
#include <cmath>
#include <iostream>
using namespace std;
Asteroid::Asteroid() {
	// TODO Auto-generated constructor stub
	//b->GetInitRandomPosition(x, y);
	x=GetRandInRange(50,1020-50);
	y=GetRandInRange(50,840-50);
	//rad2=GetRandInRange(10,30);
	rad=GetRandInRange(40,70);
	randomPoints();
	x_arr=new int[360];
	y_arr=new int [360];
	rand_mov=GetRandInRange(0,8);

}


Asteroid::Asteroid(Board *b) {
	// TODO Auto-generated constructor stub
	//b->GetInitRandomPosition(x, y);
	x=GetRandInRange(50,1020-50);
	y=GetRandInRange(50,840-50);
	rad=GetRandInRange(40,70);
	//rad2=GetRandInRange(10,30);
	randomPoints();
	x_arr=new int[360];
	y_arr=new int [360];
	rand_mov=GetRandInRange(0,8);

}
void Asteroid::setX(int j){
	x+=j;
}
void Asteroid::setY(int j){
	y+=j;
}
void Asteroid::setRand_mov(){
	rand_mov=GetRandInRange(0,7);
}

//int Asteroid::distenceBtwTwoPoints(int x1,int y1,int x2,int y2){
//	return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
//}

void Asteroid::randomPoints()
{
	//generate random points on circle ...

	rand_points=GetRandInRange(4,8);
	num_arr=new int[getrand_points()];
	int min=0;
	int max=45;
	for(int i=0;i<rand_points;++i){
		num_arr[i]=GetRandInRange(min,max);
		min+=45;
		max+=45;
	}

}
int Asteroid::getrand_points(){
	return rand_points;
}
int Asteroid::getX(){
	return x;
}
int Asteroid::getY(){
	return y;
}
int Asteroid::getRad(){
	return rad;
}
int* Asteroid::getNum_arr(){
	return num_arr;
}
int* Asteroid::getX_arr(){
	return x_arr;
}
int *Asteroid::getY_arr(){
	return y_arr;
}
void Asteroid::setX_arr(int j,int k){
	this->x_arr[j]+=k;
}
void Asteroid::setY_arr(int j,int k){
	this->y_arr[j]+=k;
}
void Asteroid::movement(int xCord,int yCord){

	setX(xCord);
	setY(yCord);
	for (int i=0;i<getrand_points();++i){
		for(int j=0;j<360;++j){
			//if(a.getNum_arr()[i]==j){
			setX_arr(j,xCord);
			setY_arr(j,yCord);
			//}
		}
	}
}
void Asteroid::drawAsteroid(int rad){


	cout<<"Radius = "<<rad<<endl;

	int temp_x;
	int temp_y;

	int t=0;
	for(int i=0;i<=360;++i){
		float x_t = static_cast<float>(rad)*cos(t*0.0174533) + x;
		float y_t = static_cast<float>(rad)*sin(t*0.0174533) + y;

		//		cout<<"angle = "<<t<<endl;
		//		cout<<"x = "<<x_t<<endl;
		//		cout<<"y = "<<y_t<<endl<<endl;
		if(i>0){
			//DrawLine(temp_x,temp_y,x_t,y_t,0,colors[5]);
		}
		x_arr[i]=x_t;
		y_arr[i]=y_t;
		temp_x=x_t;
		temp_y=y_t;

		t++;
	}




	//join those points by getting their coordinates values and make an asteroid..

	int start_x=0;
	int start_y=0;
	int find=0;

	for(int i=0;i<rand_points;++i){
		for(int j=0;j<=360;++j){
			if(num_arr[i]==j){
				find++;
				if(find==1){
					start_x=x_arr[j];
					start_y=y_arr[j];
				}
				if(i>0){
					if(i+1==rand_points){

						cout<<"temp x = "<<temp_x<<endl;
						cout<<"temp y = "<<temp_y<<endl;

						cout<<"stsrt x = "<<start_x<<endl;
						cout<<"stsrt y = "<<start_y<<endl<<endl;

						DrawLine(temp_x,temp_y,start_x,start_y,2,colors[11]);

					}
					else{
						cout<<"temp x = "<<temp_x<<endl;
						cout<<"temp y = "<<temp_y<<endl;
						cout<<"x_arr[j] = "<<x_arr[j]<<endl;
						cout<<"y arr[j] = "<<y_arr[j]<<endl<<endl;

						DrawLine(temp_x,temp_y,x_arr[j],y_arr[j],2,colors[11]);
					}
				}
				temp_x=x_arr[j];
				temp_y=y_arr[j];
			}
		}
	}


	cout<<"Random points = "<<rand_points<<endl;


	if(rand_mov==0){
		movement(6,6);
	}
	else if(rand_mov==1){
		movement(0,6);
	}
	else if(rand_mov==2){
		movement(6,0);
	}
	else if(rand_mov==3){
		movement(6,-6);
	}
	else if(rand_mov==4){
		movement(-6,6);
	}
	else if(rand_mov==5){
		movement(-6,-6);
	}
	else if(rand_mov==6){
		movement(0,-6);
	}
	else if(rand_mov==7){
		movement(-6,0);
	}
}

Asteroid::~Asteroid() {
	// TODO Auto-generated destructor stub
	delete []num_arr;
	delete []x_arr;
	delete []y_arr;
}

