#ifndef CAMERA_H_
#define CAMERA_H_

#include "global.h"

class Camera {
public:
  Camera(glm::vec3 direction = CAMERA_DIRECTION, glm::vec3 position = CAMERA_POSITION, 
    glm::vec3 worldUp = CAMERA_WORLDUP, float pitch = CAMERA_PITCH, float yaw = CAMERA_YAW, 
    float sensitivity = CAMERA_SENSITIVITY, float speed = CAMERA_SPEED);
  ~Camera();

  glm::mat4 getView();
  glm::mat4 getProjection();

  void setDirection(glm::vec3 direction);
  void update(float deltaTime);

private:
  glm::vec3 direction;
  glm::vec3 position;
  glm::vec3 worldUp;
  glm::vec3 front;
  glm::vec3 right;
  glm::vec3 up;
  float pitch;
  float yaw;
  float speed;
  float sensitivity;

  void locate();
  void rotate();
};

#endif
