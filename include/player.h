
#ifndef __PLAYER_H__
#define __PLAYER_H__ 1

#include "drawable.h"
#include "vector_helper.h"
#include "shot.h"

const unsigned int kShotPool = 8;

class Player : public Drawable {
public:
	Player();
	Player(const Player& other);
	~Player();

	void init(const sf::RenderWindow& window);
	void input();
	void update(const sf::RenderWindow& window);
	void respawn(const sf::RenderWindow& window);

	bool isAlive() const;
	void setAlive(const bool b);
	const sf::Vertex* points();

	Shot shot_[kShotPool];

private:
	sf::Vertex points_[5];
	sf::Vector2f velocity_;
	bool hasFired_, isAlive_;
	unsigned char elapsedTimeBetweenShoots_;

};

#endif // __PLAYER_H__
