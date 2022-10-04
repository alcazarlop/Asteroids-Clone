
#include "asteroids.h"
#include <stdio.h>

Asteroids::Asteroids(){
  velocity_ = sf::Vector2f(0.0f, 0.0f);
  size_ = 3;
  isDisable_ = true;
}

Asteroids::Asteroids(const Asteroids& other){
  velocity_ = other.velocity_;
  id_ = other.id_;
  size_ = other.size_;
  isDisable_ = other.isDisable_;
}

Asteroids::~Asteroids(){

}

void Asteroids::loadVertex(){
  id_ = rand()%4;
  switch(id_){
    case 0: 
      points_ = new sf::Vertex[13];
      points_[0] = sf::Vector2f(-0.7f, 0.0f);
      points_[1] = sf::Vector2f(-1.0f, -0.5f);
      points_[2] = sf::Vector2f(-0.5f, -1.0f);
      points_[3] = sf::Vector2f(0.0f, -0.5f);
      points_[4] = sf::Vector2f(0.5f, -1.0f);
      points_[5] = sf::Vector2f(1.0f, -0.5f);
      points_[6] = sf::Vector2f(0.5f, -0.2f);
      points_[7] = sf::Vector2f(1.0f, 0.2f);
      points_[8] = sf::Vector2f(0.4f, 1.0f);
      points_[9] = sf::Vector2f(-0.3f, 0.6f);
      points_[10] = sf::Vector2f(-0.7f, 1.0f);
      points_[11] = sf::Vector2f(-1.0f, 0.5f);
      points_[12] = sf::Vector2f(-0.7f, 0.0f);
      set_vertices(13);
    break;
    case 1:
      points_ = new sf::Vertex[12];
      points_[0] = sf::Vector2f(-1.0f, -0.2f);
      points_[1] = sf::Vector2f(-0.4f, -1.0f);
      points_[2] = sf::Vector2f(0.4f, -1.0f);
      points_[3] = sf::Vector2f(1.0f, -0.2f);
      points_[4] = sf::Vector2f(1.0f, 0.2f);
      points_[5] = sf::Vector2f(0.4f, 1.0f);
      points_[6] = sf::Vector2f(0.0f, 1.0f);
      points_[7] = sf::Vector2f(0.0f, 0.2f);
      points_[8] = sf::Vector2f(-0.4f, 1.0f);
      points_[9] = sf::Vector2f(-1.0f, 0.2f);
      points_[10] = sf::Vector2f(-0.5f, 0.0f);
      points_[11] = sf::Vector2f(-1.0f, -0.2f);
      set_vertices(12);    
    break;
    case 2:
      points_ = new sf::Vertex[13];
      points_[0] = sf::Vector2f(-1.0f, -0.5f);
      points_[1] = sf::Vector2f(-0.5f, -0.5f);
      points_[2] = sf::Vector2f(-0.6f, -1.0f);
      points_[3] = sf::Vector2f(0.2f, -1.0f);
      points_[4] = sf::Vector2f(1.0f, -0.6f);
      points_[5] = sf::Vector2f(1.0f, -0.3f);
      points_[6] = sf::Vector2f(0.0f, 0.0f);
      points_[7] = sf::Vector2f(1.0f, 0.4f);
      points_[8] = sf::Vector2f(0.6f, 1.0f);
      points_[9] = sf::Vector2f(0.1f, 0.7f);
      points_[10] = sf::Vector2f(-0.6f, 1.0f);
      points_[11] = sf::Vector2f(-1.0f, 0.2f);
      points_[12] = sf::Vector2f(-1.0f, -0.5f);
      set_vertices(13);
    break;
    case 3:
      points_ = new sf::Vertex[11];
      points_[0] = sf::Vector2f(-1.0f, -0.6f);
      points_[1] = sf::Vector2f(-0.5f, -1.0f);
      points_[2] = sf::Vector2f(0.0f, -0.6f);
      points_[3] = sf::Vector2f(0.5f, -1.0f);
      points_[4] = sf::Vector2f(1.0f, -0.5f);
      points_[5] = sf::Vector2f(0.7f, -0.1f);
      points_[6] = sf::Vector2f(1.0f, 0.5f);
      points_[7] = sf::Vector2f(0.3f, 1.0f);
      points_[8] = sf::Vector2f(-0.7f, 1.0f);
      points_[9] = sf::Vector2f(-1.0f, 0.7f);
      points_[10] = sf::Vector2f(-1.0f, -0.6f);
      set_vertices(11);
    break;
  }
}

void Asteroids::init(){
  switch(rand()%4){
    case 0: set_position(scale().x, Vec_Helper::SetRandomPosY(scale().x, scale().y)); //Borde izquierdo
            velocity_ = sf::Vector2f(Vec_Helper::SetRandomCos(0.5f, 1.57f), Vec_Helper::SetRandomSin());
    break;
    case 1: set_position(1024.0f - scale().x, Vec_Helper::SetRandomPosY(0.5f, scale().y)); //Borde derecho
            velocity_ = sf::Vector2f(Vec_Helper::SetRandomCos(1.57f, 4.71f), Vec_Helper::SetRandomSin()); 
    break;
    case 2: set_position(Vec_Helper::SetRandomPosX(scale().x, scale().y), scale().y); //Borde superior 
            velocity_ = sf::Vector2f(Vec_Helper::SetRandomCos(), Vec_Helper::SetRandomSin(0.5f, 3.14f));
    break;
    case 3: set_position(Vec_Helper::SetRandomPosX(scale().x, scale().y), 680.0f - scale().y); //Borde inferior 
            velocity_ = sf::Vector2f(Vec_Helper::SetRandomCos(), Vec_Helper::SetRandomSin(3.14f, 6.28f));
    break;
  }
  set_rotation((float) (rand()%360));
  set_scale(30.0f, 30.0f);
}

void Asteroids::update(const sf::RenderWindow& window){
  set_position(position() + velocity_ * 3.0f);
  windowMargins(window);
}

const sf::Vertex* Asteroids::points(){
  return points_;
}

unsigned char Asteroids::size() const {
  return size_;
}

bool Asteroids::isDisable() const {
  return isDisable_;
}

void Asteroids::setDisable(const bool b){
  isDisable_ = b;
}
