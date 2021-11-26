#include "GameObject.h"

GameObject::GameObject(const std::string& id = nullptr)
{
	this->id = id;
}

GameObject::GameObject()
{
	this->id = "";
}
