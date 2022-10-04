
#include "player.h"

Player::Player(){
  velocity_ = sf::Vector2f(0.0f, 0.0f);
  hasFired_ = false;
  isAlive_ = true;
  elapsedTimeBetweenShoots_ = 0;
}

Player::Player(const Player& other){
  velocity_ = other.velocity_;
}

Player::~Player(){

}

void Player::init(const sf::RenderWindow& window){
  set_scale(10.0f, 10.0f);
  set_position((float)(window.getSize().x >> 1), (float)(window.getSize().y >> 1));
  set_vertices(5);
  points_[0] = sf::Vector2f(-0.25f, 0.5f);
  points_[1] = sf::Vector2f(1.25f, 0.0f);
  points_[2] = sf::Vector2f(-0.25f, -0.5f);
  points_[3] = sf::Vector2f(0.0f, -0.41f);
  points_[4] = sf::Vector2f(0.0f, 0.41f);
}

void Player::input(){
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    set_rotation(rotation() - 10.0f);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    set_rotation(rotation() + 10.0f);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    velocity_ += Vec_Helper::GetForward(rotation());
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !hasFired_){
    for(int i = 0; i < kShotPool; ++i){
      if(shot_[i].isDisable()){
        shot_[i].init(position(), rotation());
        hasFired_ = true;
        return;
      }
    }
  }
}

void Player::update(const sf::RenderWindow& window){

  float max_speed = 0.2f;
  set_position(position() + velocity_ * max_speed);
  velocity_ *= 0.99f;

  windowMargins(window);

  if(hasFired_){
    elapsedTimeBetweenShoots_++;
    if(elapsedTimeBetweenShoots_ > 5){
      elapsedTimeBetweenShoots_ = 0;
      hasFired_ = false;
    }
  }

}

void Player::respawn(const sf::RenderWindow& window){
  isAlive_ = true;
  set_position((float)(window.getSize().x >> 1), (float)(window.getSize().y >> 1));
}

bool Player::isAlive() const {
  return isAlive_;
}

void Player::setAlive(const bool b){
  isAlive_ = b;
}

const sf::Vertex* Player::points() {
  return points_;
}
