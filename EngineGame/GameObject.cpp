#include "GameObject.h"

GameObject::GameObject(const std::string& id = nullptr, glm::vec3 position = glm::vec3(0, 0, 0), glm::vec3 size = glm::vec3(0, 0, 0))
{
	this->id = id;
	this->position = position;
	this->size = size;
}

GameObject::GameObject()
{
	this->id = "";
	this->position = glm::vec3(0, 0, 0);
	this->size = glm::vec3(0, 0, 0);
}

glm::vec3 GameObject::getPosition(int instance_ID, glm::vec3 & cords) {
	return glm::vec3();
}
