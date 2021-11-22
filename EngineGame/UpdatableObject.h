#pragma once
#include "GameObject.h"
class UpdatableObject: virtual public GameObject
{
public:
	UpdatableObject(std::string id, glm::vec3 position, glm::vec3 size);
	virtual void update();
};

