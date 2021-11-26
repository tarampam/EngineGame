#pragma once
#include "ShapeObject.h"
class Quat: public ShapeObject
{
private:
	Point2D* p1;
	Point2D* p2;
public:
	Quat(std::string id, Point2D* p1, Point2D* p2);

	void draw() override;
	void translate(glm::vec3 moveVector) override;
	void rotate(float angle, glm::vec3 moveVector) override;
	void scale(float k, glm::vec3 scaleVector) override;
};

