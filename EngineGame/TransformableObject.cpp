#include "TransformableObject.h"
TransformableObject::TransformableObject(std::string id)
	:GameObject(id) {}

void TransformableObject::translate(glm::vec3 moveVector)
{
}

void TransformableObject::rotate(float angle, glm::vec3 moveVector)
{
}

void TransformableObject::scale(float k, glm::vec3 scaleVector)
{
}
