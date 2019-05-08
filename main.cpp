//internal includes
#include "common.h"
#include "ShaderProgram.h"
#include "global.h"
#include "init.h"
#include "programs.h"

//External dependencies
#define GLFW_DLL
#include <GLFW/glfw3.h>
#include <random>
#include "triangle.h"
#include "rectangle.h"
#include "textures.h"
#include "cube.h"
#include "model.h"
#include "sphere.h"


int main(int argc, char** argv)
{
	if (Init::init()) return -1;
	
	Programs programs;
	programs.add_program("vertex.glsl", "fragment.glsl", "triangle"); GL_CHECK_ERRORS;
	programs.add_program("rectangle.v", "rectangle.f", "rectangle"); GL_CHECK_ERRORS;
	programs.add_program("cube.v", "cube.f", "cube"); GL_CHECK_ERRORS;
	programs.add_program("sphere.v", "sphere.f", "sphere"); GL_CHECK_ERRORS;
    glfwSwapInterval(1); // force 60 frames per second
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	Triangle::config();
	Rectangle::config();
	Cube::config();
	GL_CHECK_ERRORS;
	Textures textures;
	textures.loadTexture("grass.png"); GL_CHECK_ERRORS;
	Model sphere("../sphere/globe-sphere.obj");
	//цикл обработки сообщений и отрисовки сцены каждый кадр
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glViewport(0, 0, WIDTH, HEIGHT);
		clear();
		programs["rectangle"]->StartUseShader();
		Rectangle::setUniforms(programs["rectangle"]);
    	glBindVertexArray(Rectangle::VAO); GL_CHECK_ERRORS;
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textures["grass.png"]);
    	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); GL_CHECK_ERRORS;
		glBindTexture(GL_TEXTURE_2D, 0);
		programs["cube"]->StartUseShader();
		
		Cube::setUniforms(programs["cube"]);
		glBindVertexArray(Cube::VAO); GL_CHECK_ERRORS;
		glDrawArrays(GL_TRIANGLES, 0, 36); GL_CHECK_ERRORS;

		programs["sphere"]->StartUseShader();
		Sphere::setUniforms(programs["sphere"]);
		sphere.Draw(*(programs["shpere"]));

		programs["cube"]->StopUseShader();
		programs["rectangle"]->StopUseShader();
		programs["sphere"]->StopUseShader();
		glfwSwapBuffers(window); 
	}

	Rectangle::del();
	Cube::del();
	glfwTerminate();
	return 0;
}
