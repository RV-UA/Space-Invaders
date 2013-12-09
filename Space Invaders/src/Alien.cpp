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
	direction_= right;
	fireTime_ = 1000;
	switchDirection_time_ = 1000;
	moveVertical_time_ = 2000;
	moveHorizontal_time_ = 100;
	lastFired_ = 0;
	lastMoved_=0;
	lastChangedDir_ = 0;
	lastMovedDown_= 0;
	fireChance_ = 10;
	score_ = 100;
}

Alien::Alien(Position p, sf::Color c, double s, unsigned int sx, unsigned int sy)
	: 	Entity(p, c, s, right, sx, sy),
		switchDirection_time_ ( 1000),
		moveVertical_time_( 2000 ),
		moveHorizontal_time_(100),
		fireTime_(1000),
		down_(false),
		lastFired_(0),
		lastMoved_(0),
		lastChangedDir_(0),
		lastMovedDown_(0),
		fireChance_(10),
		score_(100)
{
	direction_ = right;
}


Alien::~Alien() {
	// TODO Auto-generated destructor stub
}

void Alien::setMove(MoveDirection dir){
	direction_ = dir;
}

void Alien::move(int time) {
	if (down_) {
		position_.second+=5*speed_;
		down_ = false;
	}
	if (time - lastMoved_ > moveHorizontal_time_)
	{
		lastMoved_ = time;
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
	if (time - lastChangedDir_ > switchDirection_time_  ) {
		lastChangedDir_ = time;
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
	if (time - lastMovedDown_ >moveVertical_time_ ) {
		lastMovedDown_ = time;
		down_ = true;
	}
	sprite_.setPosition(position_);
	// TODO: add going down
}

Position Alien::getPosition() const {
	return position_;
}

void Alien::setPosition(Position p) {
	position_ = p;
	sprite_.setPosition(position_);
}

int Alien::getScore() const {
	return score_;
}

AlienType1::AlienType1(Position p, double s, sf::Color c, unsigned int sx, unsigned int sy) : Alien(p, c, s, sx, sy) {
	direction_ = right;
}

std::shared_ptr<Bullet> AlienType1::fire(int time) {
	// create new bullet
	// fire in certain dir
	if (time-lastFired_ < fireTime_)
	{
		return nullptr;
	}
	std::cout << "time: " << time << " lastFired_ = " << lastFired_ << " FireTime = " << fireTime_ << std::endl;
	// create bullet and set direction
	// calculate position to be middle of gun
	lastFired_ = time;

	int chance = rand()%100;
	if (chance <= fireChance_) {
		Position pos(this->getPosition());
		pos.first+=(this->getSizeX()/2)-2;
		std::shared_ptr<Bullet> ret (new Bullet(down, speed_, pos, this->getColor()));
		return ret;
	}
	else {
		return nullptr;
	}
}

void AlienType1::draw(sf::RenderWindow& w) {
	// draw the alien
	sprite_.draw(w);
}

} /* namespace objects */
