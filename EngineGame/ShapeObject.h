#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "PrimitiveRenderer.h"
#include <glm.hpp>
class ShapeObject: virtual public DrawableObject, virtual public TransformableObject
{
public:
	ShapeObject(std::string id);
};

