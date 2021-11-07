#pragma once
#include "Point2D.h"
#include <iostream>
class LineSegment {

	Point2D *point1;
	Point2D *point2;

public:
	LineSegment(Point2D *point1, Point2D *point2);

	Point2D* getPoint1();
	Point2D* getPoint2();

	void setPoint1(Point2D *point1);
	void setPoint2(Point2D *point2);

	void showCoordinatePoints();
};

