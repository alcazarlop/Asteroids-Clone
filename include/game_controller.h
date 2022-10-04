
#ifndef __GAME_CONTROLLER_H__
#define __GAME_CONTROLLER_H__ 1

#include <SFML/Graphics.hpp>
#include <vector>
#include <stdio.h>

#include "player.h"
#include "shot.h"
#include "asteroids.h"

const unsigned int kAsteroidPool = 12;

class GameController {
public:
	GameController();
	GameController(const GameController& other);
	~GameController();

	void init();
	int loop();
	void inputHandler();
	void update();
	void collision();
	void render();
	void levelManager();

private:
	sf::RenderWindow window_;
	Player player_;
	Asteroids asteroids_[kAsteroidPool];
	unsigned char dificulty_, asteroidCount_;

};

#endif // __GAME_CONTROLLER_H__