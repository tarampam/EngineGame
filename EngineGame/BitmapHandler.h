#pragma once
#include "Engine.h"
#include <Windows.h>
#include <gl\glu.h>
#include <gl\gl.h>
#include <GLFW/glfw3.h>
#include "vendor/stb_image.h"

#include <vector>
class BitmapHandler
{
public:
    void saveAsBMP(const char* fileName);
    GLuint loadTexture(const char* filename, int width, int height);
};