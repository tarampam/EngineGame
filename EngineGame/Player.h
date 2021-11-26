#pragma once
#include "ShapeObject.h"
#include <iostream>

class Player:public ShapeObject {
	Point2D *point1;
	Point2D *point2;
public:

	Player(std::string id, Point2D* point1, Point2D* point2);

	void draw() override;
	void translate(glm::vec3 moveVector) override;
	void rotate(float angle, glm::vec3 moveVector) override;
	void scale(float k, glm::vec3 scaleVector) override;

	void move(GLFWwindow* m_GameWindow, Point2D* point);
};