#include "Engine.h"
#include <iostream>


void Engine::initGL(unsigned int versionMajor, unsigned int versionMinor) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, versionMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, versionMinor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    glewInit();
}

void Engine::createWindow(const char* title, unsigned int width, unsigned int height) {
    m_GameWindow = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!m_GameWindow) {
        return;
    }
    glfwMakeContextCurrent(m_GameWindow);
}

bool Engine::IsVisible() {
    return (bool)glfwGetWindowAttrib(m_GameWindow, GLFW_VISIBLE);
}
