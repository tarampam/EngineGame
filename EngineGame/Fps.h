#pragma once
#include <GLFW/glfw3.h>

#include <windows.h> 
#include <sstream>
class Fps
{
public:
	int max_fps = 65;
	bool print_fps = true;
	int FPS_count = 0;

	void CalculateFrameRate(GLFWwindow* pWindow);
	long long int GetFPSCount();
	void DisplayFrameRate(GLFWwindow* pWindow, const std::string& title);
	void CalculateFrameRateDeprecated();
};

