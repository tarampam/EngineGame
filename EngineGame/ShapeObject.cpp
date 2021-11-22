#include "ShapeObject.h"

ShapeObject::ShapeObject(std::string id, glm::vec3 position, glm::vec3 size)
	:DrawableObject(id, position, size), TransformableObject(id, position, size){}
