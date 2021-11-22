#include "TransformableObject.h"
TransformableObject::TransformableObject(std::string id, glm::vec3 position, glm::vec3 size)
	:GameObject(id, position, size) {}

void TransformableObject::translate(glm::vec3 moveVector)
{
}

void TransformableObject::rotate(float angle, glm::vec3 moveVector)
{
}

void TransformableObject::scale(float k, glm::vec3 scaleVector)
{
}
