
#ifndef __DRAWABLE_H__
#define __DRAWABLE_H__ 1

#include <SFML/Graphics.hpp>

class Drawable {
public:
	Drawable();
	Drawable(const Drawable& other);
	~Drawable();

	void draw(sf::RenderWindow& window, const sf::Vertex* vertex);
	void windowMargins(const sf::RenderWindow& window);

	void set_position(const sf::Vector2f& v);
	void set_scale(const sf::Vector2f& v);
	void set_rotation(const float radians);

	void set_position(float x, float y);
	void set_scale(float x, float y);

	sf::Vector2f position() const;
	sf::Vector2f scale() const;
	float rotation() const;

	void set_vertices(const unsigned int& vertices);
	unsigned int vertices() const;
	sf::Transform transform() const;

private:
	sf::Vector2f position_;
	sf::Vector2f scale_;
	float rotation_;
	sf::Transform transform_;

	unsigned int vertices_;

};

#endif // __DRAWABLE_H__
