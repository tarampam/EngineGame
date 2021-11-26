#pragma once
#include "Point2D.h"
#include <iostream>
#include "TransformableObject.h"
class LineSegment: public TransformableObject
{

	Point2D *point1;
	Point2D *point2;

public:
	LineSegment(std::string id, Point2D *point1, Point2D *point2);

	Point2D* getPoint1();
	Point2D* getPoint2();

	void setPoint1(Point2D *point1);
	void setPoint2(Point2D *point2);

	void showCoordinatePoints();
	
	void translate(glm::vec3 moveVector) override;
	void rotate(float angle, glm::vec3 moveVector) override;
	void scale(float k, glm::vec3 scaleVector) override;
};

