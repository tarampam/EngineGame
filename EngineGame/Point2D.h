#pragma once
class Point2D
{
	float x;
	float y;
	float z;

public:
	Point2D(float x, float y);
	Point2D();
	float getX();
	float getY();

	void setX(float x);
	void setY(float y);
	void setXY(float x, float y);
};

