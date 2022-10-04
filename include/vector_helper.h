
#ifndef __VEC_HELPER_H__
#define __VEC_HELPER_H__ 1

#include <SFML/System/Vector2.hpp>

class Vec_Helper : public sf::Vector2f {
public:
	Vec_Helper();
	Vec_Helper(const Vec_Helper& other);
	~Vec_Helper();

	static sf::Vector2f GetForward(float angle);
	static sf::Vector2f Normalized(const sf::Vector2f& v);
	static float Magnitude(const sf::Vector2f& v);

	static float SetRandomCos(float min = 1.0f, float max = 6.28f);
	static float SetRandomSin(float min = 1.0f, float max = 6.28f);
	static float SetRandomPosX(float min = 0, float max = 0, int width = 1024);
	static float SetRandomPosY(float min = 0, float max = 0, int height = 680);

	static bool CircularCollision(const sf::Vector2f& c1, const sf::Vector2f& c2, float r1, float r2);

};

inline Vec_Helper::Vec_Helper() {

}

inline Vec_Helper::Vec_Helper(const Vec_Helper& other){
 	*this = other;
}

inline Vec_Helper::~Vec_Helper(){

}

inline sf::Vector2f Vec_Helper::GetForward(float angle){
	return sf::Vector2f(cosf((angle * 3.14f) / 180.0f), sinf((angle * 3.14f) / 180.0f));
}

inline sf::Vector2f Vec_Helper::Normalized(const sf::Vector2f& v){
	return sf::Vector2f(v.x / Magnitude(v), v.y / Magnitude(v));
}

inline float Vec_Helper::Magnitude(const sf::Vector2f& v){
	return sqrtf(v.x * v.x + v.y * v.y);
}

inline float Vec_Helper::SetRandomCos(float max, float min){
	return cosf((float) min + rand()/(float) (RAND_MAX) * max);
}

inline float Vec_Helper::SetRandomSin(float max, float min){
	return sinf((float) min + rand()/(float) (RAND_MAX) * max);
}

inline float Vec_Helper::SetRandomPosX(float min, float max, int width){
	return (float) (min + (float)(rand()% width) - max);
}

inline float Vec_Helper::SetRandomPosY(float min, float max, int height){
	return (float) (min + (float)(rand()% height) - max);
}

inline bool Vec_Helper::CircularCollision(const sf::Vector2f& c1, const sf::Vector2f& c2, float r1, float r2){
	sf::Vector2f tmp = c1 - c2;
	float length = Magnitude(tmp);
	return length <= r1 + r2;
}

#endif // __VEC_HELPER_H__
