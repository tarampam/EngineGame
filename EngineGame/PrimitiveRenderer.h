#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

#include "Point2D.h"

#define DOUBLE_0  0.0

class PrimitiveRenderer
{
public:
      void createTriangle(Point2D* p1, Point2D* p2, Point2D* p3);

    void createQuat(Point2D* p1, Point2D* p2);

    void display(GLfloat vertices[], int GLShapeType, int verticesAmount);

    //TODO: trzeba pomyœeæ jak zrobiæ to dynamicznie przydzielaj¹c iloœæ punktów do linii ³amanej otwartej lub zamkniêtej
    void craeteLineLoop(Point2D* p1, Point2D* p2, Point2D* p3, Point2D* p4, Point2D* p5); 

    void craeteLineStrip(Point2D* p1, Point2D* p2, Point2D* p3, Point2D* p4, Point2D* p5);
};