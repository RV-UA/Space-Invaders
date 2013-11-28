/*
 * Bullet.h
 *
 *  Created on: Nov 19, 2013
 *      Author: robin
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "Entity.h"
#include <iostream>
#include "Exception.h"

namespace objects {

class Bullet : public objects::Entity {
/*
 *	class depicting the bullets shot by gun and aliens
 */
public:
	//! A default constructor
	Bullet();
	//! A constructor taking all necessary attributes
	/**
	 * @param direction the direction in which the bullet will fly (can only be up or down)
	 *
	 */
	Bullet(MoveDirection direction, double speed, Position pos, sf::Color c);
	//! An empty destructor
	virtual ~Bullet();
	//! A function moving the bullet in direction
	void move();
	//! A function drawing the bullet
	/**
	 * @param w the window used to display the game
	 */
	virtual void draw(sf::RenderWindow& w);
	//! A getter for the direction
	MoveDirection getDirection() const;
private:
};

} /* namespace objects */

#endif /* BULLET_H_ */
