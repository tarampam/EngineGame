#include "Engine.cpp"

int main(void)
{
    GLFWwindow* window;

    Engine engine;
    engine.initGL(3, 3);

    engine.createWindow("Hello", 800, 600);



    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(engine.m_GameWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(engine.m_GameWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}