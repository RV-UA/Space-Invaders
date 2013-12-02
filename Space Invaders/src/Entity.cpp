/*
 * Entity.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: robin
 */

#include "Entity.h"
#include <iostream>

namespace objects {

DrawEntity::DrawEntity() {
	rect_.setPosition(0,0);
	rect_.setFillColor(sf::Color::Transparent);
	rect_.setSize(sf::Vector2f(0,0));
}

DrawEntity::DrawEntity(Position p) {
	rect_.setPosition(p.first, p.second);
	rect_.setFillColor(sf::Color::Green);
	rect_.setSize(sf::Vector2f(10,10));
}

DrawEntity::DrawEntity(Position p, unsigned int width, unsigned int height, sf::Color c) {
	rect_.setPosition(p.first, p.second);
	rect_.setFillColor(c);
	rect_.setSize(sf::Vector2f(width,height));
}
void DrawEntity::setPosition(Position p) {
	rect_.setPosition(p.first, p.second);
}

void DrawEntity::draw(sf::RenderWindow& w) {
	w.draw(rect_);
}

Entity::Entity() : speed_(0), position_(Position(0,0)), color_(sf::Color(0,0,0)), size_x_(0), size_y_(0), direction_(none){}

Entity::Entity(Position p, sf::Color c, double speed, MoveDirection dir, unsigned int sx, unsigned int sy) :
		position_(p),
		color_(c),
		speed_(speed),
		direction_(dir),
		size_x_(sx),
		size_y_(sy),
		sprite_(DrawEntity(position_, size_x_, size_y_, color_))
{
	std::cout << "position = " << position_.first << " , " << position_.second << std::endl;
}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

} /* namespace objects */
