/*
 * Gun.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: robin
 */

#include "Gun.h"

namespace objects {

Gun::Gun() : Entity(Position(320,400), sf::Color::Green, 2,none, 40, 10), lives_(3) {
}


Gun::Gun(double s) :Entity(Position(320, 400), sf::Color::Green, s, none, 40, 10), lives_(3) {
}

Gun::Gun(double s, Position p, sf::Color c, unsigned int sx, unsigned int sy) : Entity(p,c,s, none, sx, sy), lives_(3) {
}

Gun::~Gun() {
	// TODO Auto-generated destructor stub
}

std::shared_ptr<Bullet> Gun::fire() {
	// create bullet and set direction
	// calculate position to be middle of gun

	Position pos(this->getPosition());
	pos.first+=(this->getSizeX()/2)-2;
	std::shared_ptr<Bullet> ret (new Bullet(up, speed_, pos, this->getColor()));
	return ret;
}

void Gun::move() {
	switch(direction_) {
	case right:
		position_.first+= speed_;
		// check boundaries
		break;
	case left:
		position_.first-= speed_;
		// check boundaries
		break;
	case down:
		// check boundaries
		break;
	case up:
		break;
	}
	sprite_.setPosition(position_);
}

void Gun::setMove(MoveDirection dir) {
	direction_ = dir;
}

void Gun::draw(sf::RenderWindow& w) {
	//draw the gun
	sprite_.draw(w);
}

void Gun::setPosition(Position p) {
	position_ = p;
	sprite_.setPosition(position_);
	std::cout << "position: " << getPosition().first << " , " << getPosition().second << std::endl;

}

double Gun::getSpeed() const {
	return speed_;
}

void Gun::liveDecr() {
	lives_--;
}
void Gun::liveIncr() {
	lives_++;
}

unsigned int Gun::getLives() const {
	return lives_;
}

} /* namespace objects */
