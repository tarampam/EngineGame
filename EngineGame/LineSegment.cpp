#include "LineSegment.h"

LineSegment::LineSegment(std::string id, Point2D *point1, Point2D *point2)
	:TransformableObject(id)
{
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

void LineSegment::translate(glm::vec3 moveVector)
{
	this->point1->setXY(point1->getX() + moveVector.x, point1->getY() + moveVector.y);
	this->point2->setXY(point2->getX() + moveVector.x, point2->getY() + moveVector.y);
}

void LineSegment::rotate(float angle, glm::vec3 moveVector)
{
	this->point1->setX(moveVector.x + (point1->getX() - moveVector.x) * cos(angle) - (point1->getY() - moveVector.y) * sin(angle));
	this->point1->setY(moveVector.y + (point1->getX() - moveVector.x) * sin(angle) + (point1->getY() - moveVector.y) * cos(angle));
	this->point2->setX(moveVector.x + (point2->getX() - moveVector.x) * cos(angle) - (point2->getY() - moveVector.y) * sin(angle));
	this->point2->setY(moveVector.y + (point2->getX() - moveVector.x) * sin(angle) + (point2->getY() - moveVector.y) * cos(angle));
}

void LineSegment::scale(float k, glm::vec3 scaleVector)
{
	this->point1->setXY(scaleVector.x * k + (1 - k) * point1->getX(), scaleVector.y * k + (1 - k) * point1->getY());
	this->point2->setXY(scaleVector.x * k + (1 - k) * point2->getX(), scaleVector.y * k + (1 - k) * point2->getY());
}
