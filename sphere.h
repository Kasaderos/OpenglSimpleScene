#pragma once
#include "common.h"
#include <GLFW/glfw3.h>
#include "global.h"
namespace Sphere{

    void setUniforms(ShaderProgram *p){
        glm::mat4 model(1.0f);
        glm::mat4 trans(1.0f);
        glm::mat4 view(1.0f);
        glm::mat4 projection(1.0f);

        trans = glm::scale(trans, glm::vec3(0.75));
        model = glm::translate(model, glm::vec3(1.0f, 0.5, abs(sinf32((float)glfwGetTime() * 1.0))));
        model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0, 0.0, 0.0));
        view = glm::lookAt(cameraPos, glm::vec3(0.0), glm::vec3(0.0, 1.0, 0.0));
        projection = glm::perspective(45.0f, (float)WIDTH / HEIGHT, 0.1f, 100.0f);
		p->SetUniform("model", model);
		p->SetUniform("trans", trans);
		p->SetUniform("view", view);
		p->SetUniform("projection", projection);
        p->SetUniform("viewPos", cameraPos);
		p->SetUniform("lightPos", lightPos);
    }
}