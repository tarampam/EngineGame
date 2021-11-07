#include "LineSegment.h"

LineSegment::LineSegment(Point2D *point1, Point2D *point2) {
	this->point1 = point1;
	this->point2 = point2;
}

Point2D* LineSegment::getPoint1() {
	return this->point1;
}

Point2D* LineSegment::getPoint2() {
	return this->point2;
}

void LineSegment::setPoint1(Point2D *point1) {
	this->point1 = point1;
}

void LineSegment::setPoint2(Point2D *point2) {
	this->point2 = point2;
}

void LineSegment::showCoordinatePoints()
{
	std::cout << "Point1: x = " << this->point1->getX() << ", y = " << this->point1->getY()
		<< "; Point2: x = " << this->point2->getX() << ", y = " << this->point2->getY() << std::endl;
}
