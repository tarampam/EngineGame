#include "Point2D.h"

Point2D::Point2D(float x, float y)
{
	this->x = x;
	this->y = y;
	this->z = 0.0;
}

Point2D::Point2D()
{
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}

float Point2D::getX() {
	return this->x;
}

float Point2D::getY() {
	return this->y;
}

void Point2D::setX(float x) {
	this->x = x;
}

void Point2D::setY(float y) {
	this->y = y;
}

void Point2D::setXY(float x, float y) {
	this->x = x;
	this->y = y;
}
