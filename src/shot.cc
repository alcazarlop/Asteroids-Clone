
#include "shot.h"

Shot::Shot(){
  speed_ = 15.0f;
  elapsedTime_ = 0;
  isDisable_ = true;
  velocity_ = sf::Vector2f(0.0f, 0.0f);
  set_position(-1000.0f, -1000.0f);
}

Shot::Shot(const Shot& other){
  velocity_ = other.velocity_;
  isDisable_ = other.isDisable_;
  speed_ = other.speed_;
  elapsedTime_ = other.elapsedTime_;
  set_position(other.position());
  set_scale(other.scale());
}

Shot::~Shot(){

}

void Shot::init(const sf::Vector2f& player_pos, const float& rot){
  set_scale(1.0f, 1.0f);
  set_vertices(5);
  set_position(player_pos);
  velocity_ = Vec_Helper::GetForward(rot);
  points_[0] = sf::Vector2f(-0.5f, -0.5f);
  points_[1] = sf::Vector2f(0.5f, -0.5f);
  points_[2] = sf::Vector2f(0.5f, 0.5f);
  points_[3] = sf::Vector2f(-0.5f, 0.5f);
  points_[4] = sf::Vector2f(-0.5f, -0.5f);
  isDisable_ = false;
}

void Shot::update(const sf::RenderWindow& window){
  if(elapsedTime_ <= 40){
    elapsedTime_++;
    set_position(position() + velocity_ * speed_);
    windowMargins(window);
  }
  else {
    elapsedTime_ = 0;
    isDisable_ = true;
  }
}

const sf::Vertex* Shot::points(){
  return points_;
}

bool Shot::isDisable() const {
  return isDisable_;
}

void Shot::setDisable(const bool b){
  isDisable_ = b;
}
