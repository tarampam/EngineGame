#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#define PI 3.14159265

#include "Point2D.h"
#include "LineSegment.h"


#define DOUBLE_0  0.0

class PrimitiveRenderer
{
public:
      void createTriangle(Point2D* p1, Point2D* p2, Point2D* p3);

    void createQuat(Point2D* p1, Point2D* p2);
    void createPoint(Point2D* p1);
    void createLineIncremental(Point2D* p1, Point2D* p2);
    void createLine(Point2D* p1, Point2D* p2);
    void cretaeLineBySegment(LineSegment* s1);
    void createCircle(Point2D* p1, int r);
    void createEllipse(Point2D* p1, float stAngle, float endAngle, int rx, int ry);

    void display(GLfloat vertices[], int GLShapeType, int verticesAmount);

    //TODO: trzeba pomyœeæ jak zrobiæ to dynamicznie przydzielaj¹c iloœæ punktów do linii ³amanej otwartej lub zamkniêtej
    void craeteLineLoop(Point2D* p1, Point2D* p2, Point2D* p3, Point2D* p4, Point2D* p5); 

    void craeteLineStrip(Point2D* p1, Point2D* p2, Point2D* p3, Point2D* p4, Point2D* p5);
};