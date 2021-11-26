#include "PrimitiveRenderer.h"
//TODO:refactor
void PrimitiveRenderer::createTriangle(Point2D *p1, Point2D *p2, Point2D *p3) {
    GLfloat vertices[] = {
     p1->getX(), p1->getY(),DOUBLE_0,
     p2->getX(), p2->getY(),DOUBLE_0,
     p3->getX(), p3->getY(),DOUBLE_0
    };

    display(vertices, GL_TRIANGLES, 3);
    }

    void PrimitiveRenderer::createQuat(Point2D* p1, Point2D* p2) {
        createQuat(p1, p2, -1);
    }

    void PrimitiveRenderer::createQuat(Point2D* p1, Point2D* p2, GLuint texture) {
        GLfloat vertices[] = {
        p1->getX(), p1->getY(),DOUBLE_0,
        p2->getX(), p1->getY(), DOUBLE_0,
        p2->getX(), p2->getY(), DOUBLE_0,
        p1->getX(),  p2->getY(), DOUBLE_0
        };
        display(vertices, GL_QUADS, 4);
    }

    void PrimitiveRenderer::createPoint(Point2D* p1) {
        GLfloat pointVertex[] = { p1->getX(), p1->getY(), DOUBLE_0 };
        display(pointVertex, GL_POINTS, 1);
    }

    void PrimitiveRenderer::createLineIncremental(Point2D* p1, Point2D* p2)
    {
        float x;
        float dy, dx, y, m;
        float x0 = p1->getX();
        float x1 = p2->getX();
        float y0 = p1->getY();
        float y1 = p2->getY();

        dy = y1 - y0;
        dx = x1 - x0;
        m = dy / dx;
        y = y0;
        for (x = x0; x <= x1; x++) {
            GLfloat pointVertex[] = { x, (float)(y + 0.5), DOUBLE_0 };
            display(pointVertex, GL_POINTS, 1);
            y += m;
        }
    }

    void PrimitiveRenderer::createLine(Point2D* p1, Point2D* p2) {
        GLfloat vertices[] = {
            p1->getX(), p1->getY(),DOUBLE_0,
            p2->getX(), p2->getY(),DOUBLE_0
        };
        display(vertices, GL_LINES, 2);
    }

    void PrimitiveRenderer::cretaeLineBySegment(LineSegment* s1)
    {
        GLfloat vertices[] = {
            s1->getPoint1()->getX(), s1->getPoint1()->getY(), DOUBLE_0,
            s1->getPoint2()->getX(), s1->getPoint2()->getY(),DOUBLE_0
        };
        display(vertices, GL_LINES, 2);
    }

    void PrimitiveRenderer::createCircle(Point2D* p1, float r)
    {
        float a, step;
        float x, y;

        float xc = p1->getX();
        float yc = p1->getY();
        unsigned int value = 0xffffffff;

        step = 1.0 / r;
        glBegin(GL_LINE_LOOP);
        for (a = 0; a < (2 * PI); a += step) {
            glVertex2f(
                x = xc + r * cos(a) + 0.5,
                y = yc + r * sin(a) + 0.5
            );
        }
        glEnd();

    }

    void PrimitiveRenderer::createEllipse(Point2D* p1,float stAngle, float endAngle, int rx, int ry)
    {
        float a;
        float x, y;

        float xc = p1->getX();
        float yc = p1->getY();
        unsigned int value = 0xffffffff;

        glBegin(GL_LINE_STRIP);
        for (a = stAngle; a <= endAngle; a+=0.001) {
            glVertex2f(
                x = xc + rx * cos(a),
                y = yc + ry * sin(a)
            );
        }
        glEnd();

    }


    void PrimitiveRenderer::display(GLfloat vertices[], int GLShapeType, int verticesAmount, GLuint texture) {
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glDrawArrays(GLShapeType, 0, verticesAmount);
        glDisableClientState(GL_VERTEX_ARRAY);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        if (texture == -1)
        {
            glBindTexture(GL_TEXTURE_2D, texture);
        }
    }

    void PrimitiveRenderer::display(GLfloat vertices[], int GLShapeType, int verticesAmount) {
        display(vertices, GL_TRIANGLES, 3, -1);
    }

    void PrimitiveRenderer::craeteLineLoop(Point2D* p1, Point2D* p2, Point2D* p3, Point2D* p4, Point2D* p5)
    {
        GLfloat vertices[] = {
            p1->getX(), p1->getY(), DOUBLE_0,
            p2->getX(), p2->getY(), DOUBLE_0,
            p3->getX(), p3->getY(), DOUBLE_0,
            p4->getX(), p5->getY(), DOUBLE_0,
            p5->getX(), p5->getY(), DOUBLE_0
        };

           display(vertices, GL_LINE_LOOP, 5);                     
    }

    void PrimitiveRenderer::craeteLineStrip(Point2D* p1, Point2D* p2, Point2D* p3, Point2D* p4, Point2D* p5)
    {
        GLfloat vertices[] = {
           p1->getX(), p1->getY(), DOUBLE_0,
           p2->getX(), p2->getY(), DOUBLE_0,
           p3->getX(), p3->getY(), DOUBLE_0,
           p4->getX(), p5->getY(), DOUBLE_0,
           p5->getX(), p5->getY(), DOUBLE_0
        };

        display(vertices, GL_LINE_STRIP, 5);
    };
