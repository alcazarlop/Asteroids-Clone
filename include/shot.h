
#ifndef __SHOT_H__
#define __SHOT_H__ 1

#include "drawable.h"
#include "vector_helper.h"

class Shot : public Drawable {
public:
	Shot();
	Shot(const Shot& other);
	~Shot();

	void init(const sf::Vector2f& player_pos, const float& rot);
	void update(const sf::RenderWindow& window);

	const sf::Vertex* points();
	bool isDisable() const;
	void setDisable(const bool b);

private:
	sf::Vertex points_[5];
	sf::Vector2f velocity_;
	unsigned char elapsedTime_;
	float speed_;
	bool isDisable_;

};

#endif // __SHOT_H__
