#ifndef PLANE_H_
#define PLANE_H_

#include "global.h"
#include "Shader.h"
#include "Camera.h"
#include "ResourceManager.h"

class Plane {
public:
  Plane();
  ~Plane();

  void init();
  void render(Shader& shader, Camera& camera);

private:
  vector<float> data;
  unsigned int VAO;
  unsigned int VBO;
  unsigned int texture;

};

#endif