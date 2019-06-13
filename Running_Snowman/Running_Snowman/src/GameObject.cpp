#include <GameObject.h>

GameObject::GameObject() {

}

GameObject::~GameObject() {

}

void GameObject::init(glm::vec3 position, glm::vec3 size) {
  this->position = position;
  this->size = size;
}

void GameObject::update(float deltaTime) {

}
