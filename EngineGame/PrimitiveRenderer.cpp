#include "PrimitiveRenderer.h"
#include "Point2D.h"




void PrimitiveRenderer::createTriangle(Point2D *p1, Point2D *p2, Point2D *p3) {
    // wspolrzedne punktow
  //  int x1;
    GLfloat vertices[] = {
     p1->getX(), p1->getY(),0.0,
      p2->getX(), p2->getY(),0.0,
       p3->getX(), p3->getY(),0.0
        };
     

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}


/*void PrimitiveRenderer::createTriangle(float x1, float y1, float  x2, float y2, float x3, float y3) {
    // wspolrzedne punktow
    GLfloat vertices[] = {
        x1,  y1, 0,
        x2,  y2, 0,
        x3,  y3, 0 };


    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}
*/

/*void PrimitiveRenderer::createQuat(float x1, float y1, float  x2, float y2, float x3, float y3, float x4, float y4) {
    GLfloat vertices[] = {
    x1,  y1, 0,
    x2,  y2, 0,
    x3,  y3, 0,
    x4,  y4, 0 };*/

    void PrimitiveRenderer::createQuat(Point2D* p1, Point2D* p2) {
        GLfloat vertices[] = {
        p1->getX(), p1->getY(),0.0,
        p2->getX(), p1->getY(), 0.0,
        p2->getX(), p2->getY(), 0.0,
        p1->getX(),  p2->getY(), 0.0
        };

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_QUADS, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

    


