#include <Camera.h>

Camera::Camera(glm::vec3 direction, glm::vec3 position, glm::vec3 worldUp, float pitch, float yaw, 
  float sensitivity, float speed) {
  this->direction = direction;
  this->position = position;
  this->worldUp = worldUp;
  this->pitch = pitch;
  this->yaw = yaw;
  this->sensitivity = sensitivity;
  this->speed = speed;

  locate();
}

Camera::~Camera() {

}

glm::mat4 Camera::getView() {
  return glm::lookAt(position, position + front, up);
}

glm::mat4 Camera::getProjection() {
  return glm::perspective(glm::radians(45.0f), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);
}

void Camera::setDirection(glm::vec3 direction) {
  this->direction = glm::vec3(direction.x, 0.0f, direction.z);
  if (this->direction != glm::vec3(0.0f, 0.0f, 0.0f)) {
    this->direction = glm::normalize(this->direction);
  }
}

void Camera::update(float deltaTime) {
  // move
  glm::vec3 frontXZ = glm::normalize(glm::vec3(front.x, 0.0f, front.z));
  position += (direction.z * frontXZ + direction.x * right) * deltaTime * speed;

  // gravity
  if (position.y > 0.0f) {
    position -= direction.y * worldUp * deltaTime * speed;
    position.y = max(position.y, 0.0f);
  }

  // rotate
  rotate();
}

void Camera::locate() {
  glm::quat quaternion(glm::vec3(glm::radians(pitch), glm::radians(-yaw), 0.0f));
  front = glm::vec3(glm::toMat4(quaternion) * glm::vec4(0.0f, 0.0f, -1.0f, 1.0f));
  right = glm::normalize(glm::cross(front, worldUp));
  up = glm::normalize(glm::cross(right, front));
}

void Camera::rotate() {
  if (isFirstMouse) {
    isFirstMouse = false;
    lastX = currX;
    lastY = currY;
  }

  double offsetX = currX - lastX;
  double offsetY = -(currY - lastY);

  lastX = currX;
  lastY = currY;

  yaw += offsetX * sensitivity;
  pitch += offsetY * sensitivity;

  pitch = min(pitch, 89.0f);
  pitch = max(pitch, -89.0f);

  locate();
}