#include "PrimitiveRenderer.h"

void PrimitiveRenderer::createTriangle(Point2D *p1, Point2D *p2, Point2D *p3) {
    GLfloat vertices[] = {
     p1->getX(), p1->getY(),DOUBLE_0,
     p2->getX(), p2->getY(),DOUBLE_0,
     p3->getX(), p3->getY(),DOUBLE_0
    };

    display(vertices, GL_TRIANGLES, 3);
    }

    void PrimitiveRenderer::createQuat(Point2D* p1, Point2D* p2) {
        GLfloat vertices[] = {
        p1->getX(), p1->getY(),DOUBLE_0,
        p2->getX(), p1->getY(), DOUBLE_0,
        p2->getX(), p2->getY(), DOUBLE_0,
        p1->getX(),  p2->getY(), DOUBLE_0
        };

        display(vertices, GL_QUADS, 4);       
    }

    void PrimitiveRenderer::display(GLfloat vertices[], int GLShapeType, int verticesAmount)
    {
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glDrawArrays(GLShapeType, 0, verticesAmount);
        glDisableClientState(GL_VERTEX_ARRAY);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

    


