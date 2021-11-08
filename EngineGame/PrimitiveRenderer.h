#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

#include "Point2D.h"
#include "LineSegment.h"

#define DOUBLE_0  0.0

class PrimitiveRenderer
{
public:
    void createTriangle(Point2D *p1, Point2D *p2, Point2D *p3);
    void createQuat(Point2D* p1, Point2D* p2);
    void createPoint(Point2D* p1);
    void createLineIncremental(Point2D* p1, Point2D* p2);
    void createLine(Point2D* p1, Point2D* p2);
    void cretaeLineBySegment(LineSegment* s1);

    void display(GLfloat vertices[], int GLShapeType, int verticesAmount);
};
