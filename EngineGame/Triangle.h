#pragma once
#include "ShapeObject.h"
#include "PrimitiveRenderer.h"
class Triangle: public ShapeObject
{
private:
	Point2D* p1;
	Point2D* p2;
	Point2D* p3;
public:
	Triangle(std::string id, glm::vec3 position, glm::vec3 size, Point2D* p1, Point2D* p2, Point2D* p3);

	void draw() override;
	void translate(glm::vec3 moveVector) override;
	void rotate(float angle, glm::vec3 moveVector) override;
	void scale(float k, glm::vec3 scaleVector) override;
};
