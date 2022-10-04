
#include "drawable.h"

Drawable::Drawable(){
  position_ = sf::Vector2f(0.0f, 0.0f);
  scale_ = sf::Vector2f(0.0f, 0.0f);
  rotation_ = 0.0f;
  vertices_ = 1;
}

Drawable::Drawable(const Drawable& other){
  position_ = other.position_;
  scale_ = other.scale_;
  rotation_ = other.rotation_;
  vertices_ = other.vertices_;
}

Drawable::~Drawable(){

}

void Drawable::draw(sf::RenderWindow& window, const sf::Vertex* vertex){
  transform_ = sf::Transform::Identity;
  transform_.translate(position_);
  transform_.rotate(rotation_);
  transform_.scale(scale_);
  window.draw(vertex, vertices_, sf::LineStrip, transform_);
}

void Drawable::windowMargins(const sf::RenderWindow& window){
  if(position_.x > (float)window.getSize().x + scale_.x) position_.x = -scale_.x;
  else if(position_.x < -scale_.x) position_.x = (float)window.getSize().x + scale_.x;

  if(position_.y > (float)window.getSize().y + scale_.y) position_.y = -scale_.y;
  else if(position_.y < -scale_.y) position_.y = (float)window.getSize().y + scale_.y;
}

void Drawable::set_position(const sf::Vector2f& v){
  position_ = v;
}

void Drawable::set_position(float x, float y){
  position_.x = x;
  position_.y = y;
}

void Drawable::set_scale(const sf::Vector2f& v){
  scale_ = v;
}

void Drawable::set_scale(float x, float y){
  scale_.x = x;
  scale_.y = y;
}

void Drawable::set_rotation(const float radians){
  rotation_ = radians;
}

sf::Vector2f Drawable::position() const {
  return position_;
}

sf::Vector2f Drawable::scale() const {
  return scale_;
}

float Drawable::rotation() const {
  return rotation_;
}

void Drawable::set_vertices(const unsigned int& vertices){
  vertices_ = vertices;
}

unsigned int Drawable::vertices() const {
  return vertices_;
}

sf::Transform Drawable::transform() const {
  return transform_;
}
