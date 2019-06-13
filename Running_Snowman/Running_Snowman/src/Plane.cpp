#include "Plane.h"

Plane::Plane() {

}

Plane::~Plane() {

}

void Plane::init() {
  float plane[] = {
    /*
    vec3                    vec2           vec3               vec3
    position                texture        normal             color
    */
     20.0f, -6.0f,  20.0f,  20.0f,  0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f, 1.0f,
    -20.0f, -6.0f, -20.0f,   0.0f, 20.0f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f, 1.0f,
    -20.0f, -6.0f,  20.0f,   0.0f,  0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f, 1.0f,

     20.0f, -6.0f,  20.0f,  20.0f,  0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f, 1.0f,
     20.0f, -6.0f, -20.0f,  20.0f, 20.0f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f, 1.0f,
    -20.0f, -6.0f, -20.0f,   0.0f, 20.0f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f, 1.0f,
  };
  int planeSize = sizeof(plane) / sizeof(float);

  for (int i = 0; i < planeSize; ++i) {
    data.push_back(plane[i]);
  }

  ResourceManager::loadTexture(texture, "./res/texture/container.jpg");

  // VBO
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), &data[0], GL_DYNAMIC_DRAW);

  // VAO
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(5 * sizeof(float)));
  glEnableVertexAttribArray(2);
  glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(8 * sizeof(float)));
  glEnableVertexAttribArray(3);
}

void Plane::render(Shader& shader, Camera& camera) {
  shader.use();

  shader.setInt("texture", 0);
  shader.setMat4("model", glm::mat4(1.0f));
  shader.setMat4("view", camera.getView());
  shader.setMat4("projection", camera.getProjection());

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture);

  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
}