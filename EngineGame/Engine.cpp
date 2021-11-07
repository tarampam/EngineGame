#include "Engine.h"
#include <iostream>


void Engine::initGL(unsigned int versionMajor, unsigned int versionMinor) {
    glfwInit();
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
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

bool Engine::isVisible() {
    return (bool)glfwGetWindowAttrib(m_GameWindow, GLFW_VISIBLE);
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
        glfwSetWindowShouldClose(m_GameWindow, true);
    }

}

void Engine::clearScreen() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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

void Engine::createPoints() {
    GLfloat pointVertex[] = { 100, 100 };
    glEnableClientState(GL_VERTEX_ARRAY); 
    glVertexPointer(2, GL_FLOAT, 0, pointVertex); 
    glDrawArrays(GL_POINTS, 0, 1);
    glDisableClientState(GL_VERTEX_ARRAY);
}

