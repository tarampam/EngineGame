#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Engine
{
	GLFWwindow* m_GameWindow;

	//inicjacja biblioteki graficznej
	void initGL(unsigned int versionMajor, unsigned int versionMinor);

	//parametryzowanie trybu graficznego
	void createWindow(const char* title, unsigned int width, unsigned int height);

	bool IsVisible();
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

	//g��wna p�tla gry korzystaj�ca z czasomierza

	//obs�uga klawiatury i myszy
	//klawiatura
	void processInputKey(GLFWwindow* window, double dt);

	//czyszczenie ekranu bitmay do zadanego koloru
	void clearScreen();

	//obs�uga b��d�w z mo�liwo�ci� wy�wietlania lub logowanie pliku komunikat�w

	//zamkni�cie gry - deinicjacja biblioteki, sprz�tanie pami�ci
	void cleanup();
};
