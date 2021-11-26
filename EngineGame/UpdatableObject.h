#pragma once
#include "GameObject.h"
class UpdatableObject: virtual public GameObject
{
public:
	UpdatableObject(std::string id);
	virtual void update();
};

