#include "Engine.h"
#include "Point2D.h"
#include "LineSegment.h"
#include "PrimitiveRenderer.h"
#include "Circle.h"
#include "Triangle.h"

#include "Player.h"


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

    Point2D* p6 = new Point2D(200, 300);
    Point2D* p7 = new Point2D(100, 100);
    Point2D* p8 = new Point2D(300, 400);
    Point2D* p9 = new Point2D(200, 200);
    Point2D* p10 = new Point2D(400, 500);
    Point2D* p11 = new Point2D(300, 300);
    Point2D* p12 = new Point2D(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    LineSegment* s1 = new LineSegment(p9, p8);

    PrimitiveRenderer *p =new PrimitiveRenderer();
    engine.initGL(3, 3);

    engine.createWindow("Hello", SCREEN_WIDTH, SCREEN_HEIGHT);
    engine.initPointDrawer();
    GLfloat pointVertex[] = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };

    engine.mouseProcess();

    int rotateFlag = 1;
    Circle* x = new Circle("1", glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), new Point2D(20.0, 20.0), 30.0);
    Triangle* t1 = new Triangle("2", glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), new Point2D(10,10), new Point2D(10, 20), new Point2D(20, 10));
    Player* singlePLayer = new Player("3", glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), new Point2D(10.0, 10.0), new Point2D(40.0, 40.0));

    Point2D* q1 = new Point2D(2.0, 2.0);
    Point2D* q2 = new Point2D(40.0, 40.0);
    Point2D* p0 = new Point2D(40.0, 40.0);

    while (!glfwWindowShouldClose(engine.m_GameWindow))
    {
        /* Render here */
        engine.clearScreen();
        //engine.timer();

        singlePLayer->draw();
        singlePLayer->move(engine.m_GameWindow, q1);

        //engine.createPoints();
        //p->createTriangle(p1,p2,p3);
        //p->createQuat(p4,p5);
       // p->craeteLineLoop(p1, p2, p3, p4, p6);

        //p->craeteLineStrip(p4, p5, p4, p6, p2);
        //p->craeteLineStrip(p4, p5, p1, p3, p2);
        //p->craeteLineLoop(p4, p5, p1, p3, p2);
        //p->createPoint(p6);
        //p->createLine(p7, p6);
        //p->cretaeLineBySegment(s1);
        //p->createLineIncremental(p11, p10);

        p->createCircle(p12, 120);
        p->createEllipse(p12, 0, 360, 120, 60);
        
        x->translate(glm::vec3(1, 1, 1));
        x->draw();

        t1->draw();
        if (rotateFlag == 1)
        {
            std::cout << 1;
            //t1->rotate(45, glm::vec3(40, 10, 0));
            t1->scale(5, glm::vec3(40, 40, 0));
            rotateFlag = 2;
        }

        engine.processInputKey();
        /* Swap front and back buffers */
        glfwSwapBuffers(engine.m_GameWindow);

        /* Poll for and process events */
        glfwPollEvents();

    }

    engine.cleanup();

    return 0;
}

