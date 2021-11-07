#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

class Engine
{
public:
	GLFWwindow* m_GameWindow;
	double seconds;

	//inicjacja biblioteki graficznej
	void initGL(unsigned int versionMajor, unsigned int versionMinor);

	//parametryzowanie trybu graficznego
	void createWindow(const char* title, unsigned int width, unsigned int height);

	bool isVisible();
	bool HasFocus();
	bool SetFullScreen();

	//void setWindowPosition(const glm::vec2& pos);
	//void setWindowSize(const glm::vec2& size);

	void maximizeWindow();
	void restoreWindow();
	void showWindow();
	void hideWindow();

	//parametryzowanie innych parametrow
	//liczba klatek na sekunde
	//uruchomienie obs�ugi myszy/klawiatury
	//obs�uga myszy
	static void cursorPositionCallback(GLFWwindow *window, double xpos, double ypos);
	static void cursorEnterCallback(GLFWwindow *window, int entered);
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void scrollCalback(GLFWwindow* window, double xoffset, double yoffset);
	void mouseProcess();

	//g��wna p�tla gry korzystaj�ca z czasomierza
	void timer();

	//obs�uga klawiatury i myszy
	//obs�uga klawiatury
	void processInputKey();

	//czyszczenie ekranu bitmay do zadanego koloru
	void clearScreen();

	//obs�uga b��d�w z mo�liwo�ci� wy�wietlania lub logowanie pliku komunikat�w

	//zamkni�cie gry - deinicjacja biblioteki, sprz�tanie pami�ci
	void cleanup();
	void createPoints();
	void initPointDrawer();

};
