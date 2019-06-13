#include <Game.h>

Game::Game(): window(), menu(window.get()), 
  shaderGameObject("./res/shader/GameObject.vs", "./res/shader/GameObject.fs") {

}

Game::~Game() {

}

void Game::init() {
  plane.init();
}

void Game::clear() {
  glClear(GL_COLOR_BUFFER_BIT);
}

void Game::update() {
  currTime = (float)glfwGetTime();

  camera.update(currTime - lastTime);

  lastTime = currTime;
}

void Game::render() {
  plane.render(shaderGameObject, camera);
  menu.show();
  window.show();
}

bool Game::isClose() {
  return glfwWindowShouldClose(window.get());
}

void Game::processInput() {
  if (glfwGetKey(window.get(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window.get(), true);
  }

  glm::vec3 direction(0.0f, 0.0f, 0.0f);

  if (glfwGetKey(window.get(), GLFW_KEY_W) == GLFW_PRESS || glfwGetKey(window.get(), GLFW_KEY_UP)) {
    direction.z += 1.0f;
  }
  if (glfwGetKey(window.get(), GLFW_KEY_S) == GLFW_PRESS || glfwGetKey(window.get(), GLFW_KEY_DOWN)) {
    direction.z -= 1.0f;
  }
  if (glfwGetKey(window.get(), GLFW_KEY_A) == GLFW_PRESS || glfwGetKey(window.get(), GLFW_KEY_LEFT)) {
    direction.x -= 1.0f;
  }
  if (glfwGetKey(window.get(), GLFW_KEY_D) == GLFW_PRESS || glfwGetKey(window.get(), GLFW_KEY_RIGHT)) {
    direction.x += 1.0f;
  }

  camera.setDirection(direction);
}