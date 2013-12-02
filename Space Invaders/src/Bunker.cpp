/*
 * bunker.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: robin
 */

#include "Bunker.h"

namespace objects {

Bunker::Bunker() :Entity(Position(100,0), sf::Color::Yellow, 0, none, 50,20), health_(10) {
}

Bunker::Bunker(Position p) : Entity(p, sf::Color::Yellow, 0, none, 50,20), health_(10) {
}

Bunker::Bunker(Position p, int h, sf::Color c, unsigned int sx, unsigned int sy) : Entity(p, c, 0, none, sx, sy), health_(h){
	std::cout << "position: " << "( " << position_.first << " , " << position_.second << ")" << std::endl;
}

Bunker::~Bunker() {
	// TODO Auto-generated destructor stub
}

void Bunker::hit() {
	if (health_ > 0)
	{
		health_--;
	}
}

bool Bunker::alive() {
	return (health_ >0);
}

void Bunker::draw(sf::RenderWindow& w) {
	// draw the bunker
	sprite_.draw(w);
}

int Bunker::getHealth() const{
	return health_;
}

Position Bunker::getPosition() const {
	return position_;
}

void Bunker::setPosition(Position p) {
	position_ = p;
	sprite_.setPosition(position_);
}

} /* namespace objects */
