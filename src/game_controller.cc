
#include "game_controller.h"

GameController::GameController(){
  dificulty_ = 0;
  asteroidCount_ = 0;
}

GameController::GameController(const GameController& other){
  player_ = other.player_;
}

GameController::~GameController(){

}

void GameController::init(){
  window_.create(sf::VideoMode(1024, 680), "Asteroids");
  window_.setFramerateLimit(60);
  player_.init(window_);
  for(unsigned int i = 0; i < kAsteroidPool; ++i){
    asteroids_[i].loadVertex();
    asteroids_[i].init();
  }
  levelManager();
}

int GameController::loop(){

  srand((unsigned int) time(nullptr));
  init();

  while(window_.isOpen()){
    inputHandler();
    update();
    collision();
    render();
  }

  return 0;
}

void GameController::inputHandler(){
  sf::Event event;
  while (window_.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window_.close();
    }
  }
  if(player_.isAlive())
   player_.input();
}

void GameController::update(){
  if(player_.isAlive())
    player_.update(window_);
  else
    player_.respawn(window_);
  for(int i = 0; i < kShotPool; ++i)
    if(!player_.shot_[i].isDisable())
      player_.shot_[i].update(window_);
  for(unsigned int i = 0; i < kAsteroidPool; ++i)
    if(!asteroids_[i].isDisable())
      asteroids_[i].update(window_);
  if(asteroidCount_ <= 0){
    dificulty_++;
    levelManager();
  }
}

void GameController::collision(){
  for(int i = 0; i < kShotPool; ++i){
    for(unsigned int j = 0; j < kAsteroidPool; ++j){
      if(Vec_Helper::CircularCollision(player_.shot_[i].position(), asteroids_[j].position(),
         player_.shot_[i].scale().x, asteroids_[j].scale().x) 
         && !player_.shot_[i].isDisable()
         && !asteroids_[j].isDisable()){

        player_.shot_[i].setDisable(true);
        asteroids_[j].setDisable(true);
        asteroidCount_--;
        break;
      }
      if(Vec_Helper::CircularCollision(player_.position(), asteroids_[j].position(), 
         player_.scale().x, asteroids_[j].scale().x) 
         && player_.isAlive()
         && !asteroids_[j].isDisable()){

        player_.setAlive(false);
        asteroids_[j].setDisable(true);
        asteroidCount_--;
        break;
      }
    }
  }
}

void GameController::render(){
  window_.clear(sf::Color::Black);
  if(player_.isAlive())
    player_.draw(window_, player_.points());
  for(int i = 0; i < kShotPool; ++i)
    if(!player_.shot_[i].isDisable())
      player_.shot_[i].draw(window_, player_.shot_[i].points());
  for(unsigned int i = 0; i < kAsteroidPool; ++i)
    if(!asteroids_[i].isDisable())
      asteroids_[i].draw(window_, asteroids_[i].points());
  window_.display();
}

void GameController::levelManager(){
  if(dificulty_ > 6) dificulty_ = 6;
  for(unsigned int i = 0; i < 4 + (unsigned int)(dificulty_ * 2); ++i){
    if(asteroids_[i].isDisable()){
      asteroids_[i].setDisable(false);
      asteroidCount_++;
    }
  }
}
