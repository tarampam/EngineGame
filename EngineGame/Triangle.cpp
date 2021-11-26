#include "Triangle.h"

Triangle::Triangle(std::string id, Point2D* p1, Point2D* p2, Point2D* p3)
	:ShapeObject(id), DrawableObject(id), TransformableObject(id)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

void Triangle::draw()
{
	PrimitiveRenderer* renderer = new PrimitiveRenderer();
	renderer->createTriangle(this->p1, this->p2, this->p3);
}

void Triangle::translate(glm::vec3 moveVector)
{
	this->p1->setXY(p1->getX() + moveVector.x, p1->getY() + moveVector.y);
	this->p2->setXY(p2->getX() + moveVector.x, p2->getY() + moveVector.y);
	this->p3->setXY(p3->getX() + moveVector.x, p3->getY() + moveVector.y);
}

void Triangle::rotate(float angle, glm::vec3 moveVector)
{
	this->p1->setX(moveVector.x + (p1->getX() - moveVector.x) * cos(angle) - (p1->getY() - moveVector.y) * sin(angle));
	this->p1->setY(moveVector.y + (p1->getX() - moveVector.x) * sin(angle) + (p1->getY() - moveVector.y) * cos(angle));
	this->p2->setX(moveVector.x + (p2->getX() - moveVector.x) * cos(angle) - (p2->getY() - moveVector.y) * sin(angle));
	this->p2->setY(moveVector.y + (p2->getX() - moveVector.x) * sin(angle) + (p2->getY() - moveVector.y) * cos(angle));
	this->p3->setX(moveVector.x + (p3->getX() - moveVector.x) * cos(angle) - (p3->getY() - moveVector.y) * sin(angle));
	this->p3->setY(moveVector.y + (p3->getX() - moveVector.x) * sin(angle) + (p3->getY() - moveVector.y) * cos(angle));
}

void Triangle::scale(float k, glm::vec3 scaleVector)
{
	this->p1->setXY(scaleVector.x * k + (1 - k) * p1->getX(), scaleVector.y * k + (1 - k) * p1->getY());
	this->p2->setXY(scaleVector.x * k + (1 - k) * p2->getX(), scaleVector.y * k + (1 - k) * p2->getY());
	this->p3->setXY(scaleVector.x * k + (1 - k) * p3->getX(), scaleVector.y * k + (1 - k) * p3->getY());
}
