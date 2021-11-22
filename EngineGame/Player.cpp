#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Player.h"

#include <glm/glm.h>
void Player:: move() 
{
	float position = { x, y }

	if (glfwGetKey(m_GameWindow, GLFW_KEY_W) == GLFW_PRESS) {
		position.y -= 0.01f;
	}
	if (glfwGetKey(m_GameWindow, GLFW_KEY_S) == GLFW_PRESS) {
		position.y += 0.01f;
	}
	if (glfwGetKey(m_GameWindow, GLFW_KEY_A) == GLFW_PRESS) {
		position.x -= 0.01f;
	}

	if (glfwGetKey(m_GameWindow, GLFW_KEY_D) == GLFW_PRESS) {
		position.x += 0.01f;
	}
}