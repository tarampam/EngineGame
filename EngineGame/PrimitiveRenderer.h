#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

#include "Point2D.h"

class PrimitiveRenderer
{
public:
    void createTriangle(Point2D *p1, Point2D *p2, Point2D *p3);
   // void  createTriangle(float x1, float y1, float  x2, float y2, float x3, float y3);
    void createQuat(Point2D* p1, Point2D* p2);

};
