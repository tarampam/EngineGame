#include "Circle.h"

Circle::Circle(std::string id, glm::vec3 position, glm::vec3 size, Point2D *point, float ray)
	:ShapeObject(id, position, size), DrawableObject(id, position, size), TransformableObject(id, position, size)
{
	this->point = point;
	this->ray = ray;
}

void Circle::draw() {
	PrimitiveRenderer *renderer = new PrimitiveRenderer();
	renderer->createCircle(this->point, this->ray);
}

void Circle::translate(glm::vec3 moveVector)
{
	this->point->setX(point->getX() + moveVector.x);
	this->point->setY(point->getY() + moveVector.y);
}

void Circle::rotate(float angle, glm::vec3 moveVector)
{
}

void Circle::scale(float k, glm::vec3 scaleVector)
{
}
