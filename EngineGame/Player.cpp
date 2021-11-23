#include "Player.h"

Player::Player(std::string id, glm::vec3 position, glm::vec3 size, Point2D* point1, Point2D* point2)
	:ShapeObject(id, position, size), DrawableObject(id, position, size), TransformableObject(id, position, size)
{
	this->point1 = point1;
	this->point2 = point2;
}

void Player::draw()
{
	PrimitiveRenderer *primitive = new PrimitiveRenderer();
	primitive->createQuat(this->point1, this->point2);
;}

void Player::translate(glm::vec3 moveVector)
{
}

void Player::rotate(float angle, glm::vec3 moveVector)
{
}

void Player::scale(float k, glm::vec3 scaleVector)
{
}

void Player::move(GLFWwindow* m_GameWindow, Point2D* point)
{
	if (glfwGetKey(m_GameWindow, GLFW_KEY_W) == GLFW_PRESS) {
		this->point1->setY(this->point1->getY() + point->getY());
		this->point2->setY(this->point2->getY() + point->getY());
	}
	if (glfwGetKey(m_GameWindow, GLFW_KEY_S) == GLFW_PRESS) {
		this->point1->setY(this->point1->getY() - point->getY());
		this->point2->setY(this->point2->getY() - point->getY());
	}
	if (glfwGetKey(m_GameWindow, GLFW_KEY_A) == GLFW_PRESS) {
		this->point1->setX(this->point1->getX() - point->getX());
		this->point2->setX(this->point2->getX() - point->getX());
	}
	if (glfwGetKey(m_GameWindow, GLFW_KEY_D) == GLFW_PRESS) {
		this->point1->setX(this->point1->getX() + point->getX());
		this->point2->setX(this->point2->getX() + point->getX());
	}
}