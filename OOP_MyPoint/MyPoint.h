#ifndef MYPOINT_H
#define MYPOINT_H
class MyPoint
{
public:
	MyPoint();
	MyPoint(int mPosX, int mPosY);
	void Display();
	void setX(int mPosX);
	int getX();
	void setY(int mPosY);
	int getY();
	float distance(MyPoint p);
private:
	int mPosX, mPosY;
};
#endif // !
