#pragma once
#include "GameObject.h"
class DrawableObject: virtual public GameObject
{
public:
	virtual void draw();
	DrawableObject(std::string id);
};

