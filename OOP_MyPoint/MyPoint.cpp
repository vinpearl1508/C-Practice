#include "MyPoint.h"
#include <iostream>
#include <math.h>

using namespace std;

MyPoint::MyPoint() {
	mPosX = 0;
	mPosY = 0;
}

MyPoint::MyPoint(int mPosX, int mPosY) {
	this->mPosX = mPosX;
	this->mPosY = mPosY;
}

void MyPoint::display() {
	cout << mPosX << " " << mPosY << endl;
}

void MyPoint::setX(int mPosX) {
	this->mPosX = mPosX;
}

int MyPoint::getX() {
	return mPosX;
}

void MyPoint::setY(int mPosY) {
	this->mPosY = mPosY;
}

int MyPoint::getY() {
	return mPosY;
}

float MyPoint::distance(MyPoint p) {
	return sqrt(pow(p.getX() - this->mPosX, 2) + pow(p.getY() - this->mPosY, 2));
}