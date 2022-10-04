
#ifndef __ASTEROIDS_H__
#define __ASTEROIDS_H__ 1

#include "drawable.h"
#include "vector_helper.h"

class Asteroids : public Drawable {
public:
	Asteroids();
	Asteroids(const Asteroids& other);
	~Asteroids();

	void loadVertex();
	void init();
	void update(const sf::RenderWindow& window);

	const sf::Vertex* points();
	unsigned char size() const;
	bool isDisable()const;
	void setDisable(const bool b);

private:
	sf::Vertex* points_;
	sf::Vector2f velocity_;
	unsigned char id_, size_;
	bool isDisable_;

};

#endif // __ASTEROIDS_H__
