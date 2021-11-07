#include "Engine.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
int main(void)
{
    Engine engine;
    engine.initGL(3, 3);

    engine.createWindow("Hello", SCREEN_WIDTH, SCREEN_HEIGHT);
    engine.initPointDrawer();
    GLfloat pointVertex[] = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };

    engine.mouseProcess();

    
    while (!glfwWindowShouldClose(engine.m_GameWindow))
    {
        /* Render here */
        engine.clearScreen();
        engine.timer();

        engine.createPoints();

        engine.processInputKey();

        /* Swap front and back buffers */
        glfwSwapBuffers(engine.m_GameWindow);

        /* Poll for and process events */
        glfwPollEvents();

    }

    engine.cleanup();

    return 0;
}

