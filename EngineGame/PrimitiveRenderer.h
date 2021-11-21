#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

#include "Point2D.h"
#include "LineSegment.h"

#define DOUBLE_0  0.0

struct Color {
    GLfloat r, g, b;

};


class PrimitiveRenderer
{
public:
      void createTriangle(Point2D* p1, Point2D* p2, Point2D* p3);

    void createQuat(Point2D* p1, Point2D* p2);
    void createPoint(Point2D* p1);
    void createLineIncremental(Point2D* p1, Point2D* p2);
    void createLine(Point2D* p1, Point2D* p2);
    void cretaeLineBySegment(LineSegment* s1);

    void display(GLfloat vertices[], int GLShapeType, int verticesAmount);

    //TODO: trzeba pomyœeæ jak zrobiæ to dynamicznie przydzielaj¹c iloœæ punktów do linii ³amanej otwartej lub zamkniêtej
    void craeteLineLoop(Point2D* p1, Point2D* p2, Point2D* p3, Point2D* p4, Point2D* p5); 

    void craeteLineStrip(Point2D* p1, Point2D* p2, Point2D* p3, Point2D* p4, Point2D* p5);

    Color getPixelColor(GLint x, GLint y);
    void setPixelColor(GLint x, GLint y, Color color);


    //wype³nienie obszaru kolorem przez spójnoœæ
    void boundaryFill(GLint x, GLint y, Color fill_color, Color boundary_color);

    void floodFill(GLint x, GLint y, Color newColor);
    void floodFill(GLint x, GLint y, Color newColor, Color oldColor);
};