#include <GL/glew.h>
#include <GLFW/glfw3.h>
//#include<glm/glm.h>

enum AnimationType
{
	Run,
	Jump,
	Attact

};

class Player {
	//float position = { x,y };
	//glm::vec2 position = glm::vex2(x, y);

public:

	
	void move();
};