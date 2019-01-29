#include "point2.h"
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

Point2::Point2 (float x_in, float y_in){
	x = x_in;
	y = y_in;
}

Point2::Point2(){
	x = 0;
	y = 0;
}

float Point2::DistanceBetween(Point2 other){
	//pythagorean theorem
	return sqrt(pow(other.x - this->x,2) + pow(other.y - this->y,2));
}

void Point2::Print(){
	cout << "(" << x << "," << y << ")" << endl;
}

int Point2::Quadrant(){
	if(x > 0){
		if(y < 0) {
			return 4;
		}
		else if( y > 0){
			return 1;
		}
		else{ // y > 0 or on border
			return 1;
		}
	}
	else if (x < 0) {
		if(y > 0) {
			return 2;
		}
		else if(y < 0){
			return 3;
		}
		else{ // y < 0
			return 3;
		}
	}
	else{ // x = 0
		if(y > 0){
			return 2;
		}
		else if(y < 0){
			return 4;
		}
		else{ //both are 0
			return 0;
		}
	}
}

