#include "DrawableObject.h"

void DrawableObject::draw(){}

DrawableObject::DrawableObject(std::string id, glm::vec3 position, glm::vec3 size) 
	:GameObject(id, position, size) {}
