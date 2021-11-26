#include "Engine.h"
#include <iostream>


void Engine::initGL() {
    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    glewInit();
    log._InitLog(glfwGetTime(), __FILE__, __LINE__);
}

void Engine::createWindow(const char* title, unsigned int width, unsigned int height) {
    m_GameWindow = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!m_GameWindow) {
        log.LogToFile("Failed to initialize game window");
        log.LogToConsole("Failed to initialize game window");
        return;
    }
    log._LogWindowCreation(glfwGetTime(), __FILE__, __LINE__);
    glfwMakeContextCurrent(m_GameWindow);
}

bool Engine::isVisible() {
    return (bool)glfwGetWindowAttrib(m_GameWindow, GLFW_VISIBLE);
}

bool Engine::HasFocus()
{
    return (bool)glfwGetWindowAttrib(m_GameWindow, GLFW_FOCUSED);
}

bool Engine::SetFullScreen()
{
    return false;
}

void Engine::setWindowPosition(const glm::vec2& pos)
{
    glfwSetWindowPos(m_GameWindow, (int)pos.x, (int)pos.y);
}

void Engine::setWindowSize(const glm::vec2& size)
{
    glfwSetWindowSize(m_GameWindow, (int)size.x, (int)size.y);
}

void Engine::maximizeWindow()
{
    glfwMaximizeWindow(m_GameWindow);
}

void Engine::showWindow()
{
    glfwShowWindow(m_GameWindow);
}

void Engine::hideWindow()
{
    glfwHideWindow(m_GameWindow);
}

void Engine::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    std::cout << xpos << " : " << ypos << std::endl;
}

void Engine::cursorEnterCallback(GLFWwindow* window, int entered) {
    if (entered) {
        std::cout << "Entered Window" << std::endl;
    }
}

void Engine::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        std::cout << "Right button pressed" << std::endl;
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        std::cout << "Left button pressed" << std::endl;
    }
}

void Engine::scrollCalback(GLFWwindow* window, double xoffset, double yoffset) {
    std::cout << xoffset << " : " << yoffset << std::endl;
}

void Engine::mouseProcess() {
    glfwSetCursorPosCallback(m_GameWindow, cursorPositionCallback);
    glfwSetInputMode(m_GameWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

    glfwSetCursorEnterCallback(m_GameWindow, cursorEnterCallback);

    glfwSetMouseButtonCallback(m_GameWindow, mouseButtonCallback);
    glfwSetInputMode(m_GameWindow, GLFW_STICKY_MOUSE_BUTTONS, 1);

    glfwSetScrollCallback(m_GameWindow, scrollCalback);
}


void Engine::timer() {
    seconds = glfwGetTime();
    std::cout << "Timer: "<<seconds << std::endl;
}

void Engine::processInputKey() {
    if (glfwGetKey(m_GameWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(m_GameWindow, true);
    }
    if (glfwGetKey(m_GameWindow, GLFW_KEY_SPACE) == GLFW_PRESS) {
        log.LogToFile("Space action");
        log.LogToConsole("Space action");
        glfwSetWindowShouldClose(m_GameWindow, true);
    }

}

void Engine::clearScreen(glm::vec4 color) {
    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Engine::cleanup() {
    glfwDestroyWindow(m_GameWindow);
    glfwTerminate();
}

void Engine::initPointDrawer() {
    glViewport(0.0f, 0.0f, 800, 600); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho(0, 800, 0, 600, 0, 1); // essentially set coordinate system
    glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity(); // same as above comment
}

