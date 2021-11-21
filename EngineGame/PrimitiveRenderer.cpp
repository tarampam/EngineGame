#include "PrimitiveRenderer.h"

#include <windows.h> 



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
        GLfloat vertices[] = {
        p1->getX(), p1->getY(),DOUBLE_0,
        p2->getX(), p1->getY(), DOUBLE_0,
        p2->getX(), p2->getY(), DOUBLE_0,
        p1->getX(),  p2->getY(), DOUBLE_0
        };

      // glColor3f(1.0, 1.0, 0.0);
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


    void PrimitiveRenderer::display(GLfloat vertices[], int GLShapeType, int verticesAmount) {
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glDrawArrays(GLShapeType, 0, verticesAmount);
        glDisableClientState(GL_VERTEX_ARRAY);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
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
    }

   struct Color PrimitiveRenderer::getPixelColor(GLint x, GLint y)
    {
        struct Color color;
        glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
        //std::cout << color.r << " " << color.g << " " << color.b << std::endl;
        return color;
    }

    void PrimitiveRenderer::setPixelColor(GLint x, GLint y, Color color)
    {
        
        glColor3f(color.r, color.g, color.b);
         glBegin(GL_POINTS);
         glVertex2i(x, y);
         glEnd();
        // glFlush();
        
    }



    /*void PrimitiveRenderer::boundaryFill(GLint x, GLint y, Color oldColor, Color newColor)
    {
        
        if (getPixelColor(x, y) != newColor.r  && getPixelColor(x, y) != newColor.g && getPixelColor(x, y) != newColor.b &&
            getPixelColor(x, y) != oldColor.r &&
            getPixelColor(x, y) != oldColor.g &&
            getPixelColor(x, y) != oldColor.b)
           {
            setPixelColor(x, y, newColor);
              boundaryFill(x + 1, y, newColor, oldColor);
              boundaryFill(x, y + 1, newColor, oldColor);
              boundaryFill(x - 1, y, newColor, oldColor);
              boundaryFill(x, y - 1, newColor, oldColor);
            }
        
    }*/


   void PrimitiveRenderer::boundaryFill(GLint x, GLint y, Color fill_color, Color boundary_color)
    {
        struct Color color;
        color = getPixelColor(x, y);

        if ((color.r != fill_color.r && color.g != fill_color.g && color.b != fill_color.b) 
            && (color.r != boundary_color.r && color.g != boundary_color.g && color.b != boundary_color.b))

        {
            setPixelColor(x, y, fill_color);
            boundaryFill(x + 1, y, fill_color, boundary_color);
            boundaryFill(x, y + 1, fill_color, boundary_color);
            boundaryFill(x - 1, y, fill_color, boundary_color);
            boundaryFill(x, y - 1, fill_color, boundary_color);
            boundaryFill(x - 1, y - 1, fill_color, boundary_color);
            boundaryFill(x - 1, y + 1, fill_color, boundary_color);
            boundaryFill(x + 1, y - 1, fill_color, boundary_color);
            boundaryFill(x + 1, y + 1, fill_color, boundary_color);
          //  Sleep(100000);
            //glFlush();
            
           // 
        }
    }

   void PrimitiveRenderer::floodFill(GLint x, GLint y, Color newColor) {

       struct Color color;
       color = getPixelColor(x, y);
       floodFill(x, y, newColor, color);

   }


    void PrimitiveRenderer::floodFill(GLint x, GLint y, Color newColor, Color oldColor)
    {
        std::cout << x << " " <<  y << std::endl;
        //Sleep(500);
       struct Color color;
        color = getPixelColor(x, y);
    

        //printf("red:%f green:%f blue:%f\n", color.r, color.g, color.b);

        if (color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
        {
            setPixelColor(x, y, newColor);
            floodFill(x + 1, y, newColor, oldColor);
            floodFill(x, y + 1, newColor, oldColor);
            floodFill(x - 1, y, newColor, oldColor);
            floodFill(x, y - 1, newColor, oldColor);

            // put new pixel with new color 
          /* glBegin(GL_POINTS);
            glColor3f(1, 1, 0);
            glVertex2i(x, y);
            glEnd();
            glFlush();*/
        }
        else {
            return;
        }
        return;
    }
    



    
      
   /* void PrimitiveRenderer::floodFill(float x, float y, glColor3b kw, glColor3b kk)
    {

    }*/

   /* void PrimitiveRenderer::floodFill(float x, float y, float  kw, float kk)
    {
        if( glReadPixels(x,y)) == kw ) return;
       if (glReadPixels(x, y)) == kk ) return;

     //  glDrawPixels()
         //  void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels)
         glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color));

         floodFill(x + 1, y, kw, kk); // Prawo
         floodFill(x, y - 1, kw, kk); // Góra
         floodFill(x - 1, y, kw, kk); // Lewo
         floodFill(x, y + 1, kw, kk); // Dó³
    }
    */
   