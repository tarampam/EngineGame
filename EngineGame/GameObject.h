#pragma once
#include "Point2D.h"
#include <string>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
class GameObject
{
private: 
	std::string id;

public:
	GameObject(const std::string& id);
	GameObject();
	const std::string& getId() const { return this->id; };
};

