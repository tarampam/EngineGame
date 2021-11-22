#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
class ShapeObject: virtual public DrawableObject, virtual public TransformableObject
{
public:
	ShapeObject(std::string id, glm::vec3 position, glm::vec3 size);
};

