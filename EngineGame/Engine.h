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
	//uruchomienie obs³ugi myszy/klawiatury

	//g³ówna pêtla gry korzystaj¹ca z czasomierza

	//obs³uga klawiatury i myszy
	//klawiatura
	void processInputKey(GLFWwindow* window, double dt);

	//czyszczenie ekranu bitmay do zadanego koloru
	void clearScreen();

	//obs³uga b³êdów z mo¿liwoœci¹ wyœwietlania lub logowanie pliku komunikatów

	//zamkniêcie gry - deinicjacja biblioteki, sprz¹tanie pamiêci
	void cleanup();
};
