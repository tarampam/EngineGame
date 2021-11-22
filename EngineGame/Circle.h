#pragma once
#include "ShapeObject.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include <glm.hpp>
class Circle : public ShapeObject
{
private:
	Point2D *point;
	float ray;

public:
	Circle(std::string id, glm::vec3 position, glm::vec3 size, Point2D* point, float ray);

	void draw() override;
	void translate(glm::vec3 moveVector) override;
	void rotate(float angle, glm::vec3 moveVector) override;
	void scale(float k, glm::vec3 scaleVector) override;
};