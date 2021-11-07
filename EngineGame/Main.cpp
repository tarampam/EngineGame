#include "Engine.h"
#include "Point2D.h"
#include "LineSegment.h"
#include "PrimitiveRenderer.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
int main(void)
{
    Engine engine;
    Point2D* p1 = new Point2D(40.0, 40.5);
    Point2D* p2 = new Point2D(30.5, 10.5);
    Point2D* p3 = new Point2D(10.5, 40.5);


    Point2D* p4 = new Point2D(100, 200);
    Point2D* p5 = new Point2D(300, 400);
    Point2D* p6 = new Point2D(198, 12);

    PrimitiveRenderer *p =new PrimitiveRenderer();
    engine.initGL(3, 3);

    engine.createWindow("Hello", SCREEN_WIDTH, SCREEN_HEIGHT);
    engine.initPointDrawer();
    GLfloat pointVertex[] = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };

    engine.mouseProcess();

    
    while (!glfwWindowShouldClose(engine.m_GameWindow))
    {
        /* Render here */
        engine.clearScreen();
        //engine.timer();

        engine.createPoints();
        p->createTriangle(p1,p2,p3);
        p->createQuat(p4,p5);
        p->craeteLineLoop(p1, p2, p3, p4, p6);

        p->craeteLineStrip(p4, p5, p4, p6, p2);
        p->craeteLineStrip(p4, p5, p1, p3, p2);
        p->craeteLineLoop(p4, p5, p1, p3, p2);

        engine.processInputKey();
        /* Swap front and back buffers */
        glfwSwapBuffers(engine.m_GameWindow);

        /* Poll for and process events */
        glfwPollEvents();

    }

    engine.cleanup();

    return 0;
}

