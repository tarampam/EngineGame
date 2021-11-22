#pragma once
#include "GameObject.h"
class TransformableObject: virtual public GameObject
{
public:
	TransformableObject(std::string id, glm::vec3 position, glm::vec3 size);
	virtual void translate(glm::vec3 moveVector);
	virtual void rotate(float angle, glm::vec3 moveVector);
	virtual void scale(float k, glm::vec3 scaleVector);
};

