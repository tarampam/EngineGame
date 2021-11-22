#pragma once
#include "Point2D.h"
#include <string>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
class GameObject
{
private: 
	std::string id;
	glm::vec3 position;
	glm::vec3 size;

public:
	GameObject(const std::string& id, glm::vec3 position, glm::vec3 size);
	GameObject();
	glm::vec3 getPosition(int instance_ID, glm::vec3& cords);
	const std::string& getId() const { return this->id; };
	//size
};

