#include <global.h>

// Window
const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 1000;
const char* WINDOW_TITLE = "Running Snowman";

// GameObject
const glm::vec3 GAMEOBJECT_POSITION = glm::vec3(0.0f, 0.0f, 0.0f);
const glm::vec3 GAMEOBJECT_SIZE = glm::vec3(1.0f, 1.0f, 1.0f);

// Camera
const glm::vec3 CAMERA_DIRECTION = glm::vec3(0.0f, 0.0f, 0.0f);
const glm::vec3 CAMERA_POSITION = glm::vec3(0.0f, 0.0f, 20.0f);
const glm::vec3 CAMERA_WORLDUP = glm::vec3(0.0f, 1.0f, 0.0f);
const float CAMERA_PITCH = 0.0f;
const float CAMERA_YAW = 0.0f;
const float CAMERA_SENSITIVITY = 0.1f;
const float CAMERA_SPEED = 5.0f;

// mouse
bool isFirstMouse = true;
extern double lastX = WINDOW_WIDTH / 2.0f;
extern double lastY = WINDOW_HEIGHT / 2.0f;
extern double currX = WINDOW_WIDTH / 2.0f;
extern double currY = WINDOW_HEIGHT / 2.0f;