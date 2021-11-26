#pragma once
#include "ShapeObject.h"
#include <iostream>

class Player:public ShapeObject {
	Point2D *point1;
	Point2D *point2;
	GLuint texture;
public:

	Player(std::string id, glm::vec3 position, glm::vec3 size, Point2D* point1, Point2D* point2, GLuint texture);

	void draw() override;
	void translate(glm::vec3 moveVector) override;
	void rotate(float angle, glm::vec3 moveVector) override;
	void scale(float k, glm::vec3 scaleVector) override;

	void move(GLFWwindow* m_GameWindow, Point2D* point);
};