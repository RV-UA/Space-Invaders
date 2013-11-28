/*
 * Alien.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: robin
 */

#include "Alien.h"

namespace objects {

Alien::Alien() : Entity(), down_(false){

	position_ = Position(50,50);
	time_ = 1;
	move_time_ = 1;
	direction_= right;
	fireTime_ = rand() % 300 + 100;
}

Alien::Alien(Position p, sf::Color c, double s, unsigned int sx, unsigned int sy)
	: Entity(p, c, s, right, sx, sy),
	time_(1),
	move_time_(1),
	fireTime_(rand()%300+100),
	down_(false)
{
	direction_ = right;
}


Alien::~Alien() {
	// TODO Auto-generated destructor stub
}

void Alien::setMove(MoveDirection dir){
	direction_ = dir;
}

void Alien::move() {
	if (down_) {
		position_.second+=5*speed_;
		down_ = false;
	}
	if (move_time_ % 10 == 0)
	{
		switch(direction_)
		{
		case right:
			position_.first+= speed_;
			break;
		case left:
			position_.first-=speed_;
			break;
		case down:
			position_.second+=5;
			break;
		}
	}
	if (move_time_ % 300 == 0 ) {
		switch(direction_)
		{
		case right:
			setMove(left);
			break;
		case left:
			setMove(right);
			break;
		}
	}
	if (move_time_ % 1200   == 0) {
		move_time_ = 1;
		down_ = true;
	}
	sprite_.setPosition(position_);
	move_time_++;
	// TODO: add going down
}

Position Alien::getPosition() const {
	return position_;
}

void Alien::setPosition(Position p) {
	position_ = p;
	sprite_.setPosition(position_);
}

AlienType1::AlienType1(Position p, double s, sf::Color c, unsigned int sx, unsigned int sy) : Alien(p, c, s, sx, sy) {
	time_ = 1;
	direction_ = right;
}

std::shared_ptr<Bullet> AlienType1::fire() {
	// create new bullet
	// fire in certain dir
	if (time_ % fireTime_ != 0)
	{
		time_++;
		return nullptr;
	}
	time_ = 0;
	time_++;
	fireTime_ = rand() % 300 +150;
	// create bullet and set direction
	// calculate position to be middle of gun

	Position pos(this->getPosition());
	pos.first+=(this->getSizeX()/2)-2;
	std::shared_ptr<Bullet> ret (new Bullet(down, speed_, pos, this->getColor()));
	return ret;
}

void AlienType1::draw(sf::RenderWindow& w) {
	// draw the alien
	sprite_.draw(w);
}

} /* namespace objects */
