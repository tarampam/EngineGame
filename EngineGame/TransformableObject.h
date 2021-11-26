#pragma once
#include "GameObject.h"
class TransformableObject: virtual public GameObject
{
public:
	TransformableObject(std::string id);
	virtual void translate(glm::vec3 moveVector);
	virtual void rotate(float angle, glm::vec3 moveVector);
	virtual void scale(float k, glm::vec3 scaleVector);
};

