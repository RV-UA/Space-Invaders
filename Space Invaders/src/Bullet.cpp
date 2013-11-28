/*
 * Bullet.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: robin
 */

#include "Bullet.h"

namespace objects {

Bullet::Bullet() : Entity(Position(0,0), sf::Color::Green,0 , up, 4,4){
}

Bullet::Bullet(MoveDirection dir, double speed, Position pos, sf::Color c) : Entity(pos, c, speed , dir, 4,4){
	if (dir == right || dir == left) {
		throw(Exception("INVALID DIRECTION FOR A BULLET"));
	}
	else {
		direction_ = dir;
	}
	position_ = pos;
}

Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
}


void Bullet::move() {
	switch(direction_) {
	case up:
		position_.second -= speed_;
		break;
	case down:
		position_.second += speed_;
	}
	sprite_.setPosition(position_);
}

void Bullet::draw(sf::RenderWindow& w) {
	sprite_.draw(w);
}


MoveDirection Bullet::getDirection() const {
	return direction_;
}

} /* namespace objects */
