#pragma once
#include "common.h"
#include <GLFW/glfw3.h>
#include "SOIL.h"

static GLsizei WIDTH = 640, HEIGHT = 480; //размеры окна
glm::vec3 cameraPos(0.0, 0.0, 3.0);
glm::vec3 lightPos(0.0, 2.0, 0.0);
void clear(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);               GL_CHECK_ERRORS;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); GL_CHECK_ERRORS;
}

void windowResize(GLFWwindow* window, int width, int height)
{
    WIDTH  = width;
    HEIGHT = height;
}




