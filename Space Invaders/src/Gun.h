/*
 * Gun.h
 *
 *  Created on: Nov 19, 2013
 *      Author: robin
 */

#ifndef GUN_H_
#define GUN_H_

#include "Entity.h"
#include <iostream>
#include "Bullet.h"
#include <memory>
namespace objects {

class Gun: public objects::Entity {
/*
 * class representing the gun controlled by the player
 */
public:
	//! A default constructor
	Gun();
	//! A constructor taking only the speed ( used for testing)
	Gun(double speed);
	//! A constructor taking all necessary attributes
	/**
	 * @param speed the speed at which the gun moves
	 * @param position the start position of the gun
	 * @param color the color of the gun
	 * @param sx the width of the gun
	 * @param sy the height of the gun
	 */
	Gun(double speed, Position position , sf::Color color, unsigned int sx, unsigned int sy);
	//! An empty destructor
	virtual ~Gun();
	//! A function firing a bullet upwards
	/**
	 * @return a bullet moving at speed 5 upwards
	 */
	std::shared_ptr<Bullet> fire();
	//! A function moving the gun in its current direction
	void move();
	//! A function setting the direction of the gun
	/**
	 * @param MoveDirection the direction in which the gun should move (can be left, right, none)
	 */
	void setMove(MoveDirection);
	//! A function drawing the gun
	/**
	 * @param w the window used to display the game
	 */
	virtual void draw(sf::RenderWindow& w);
	//! A setter for the position
	/**
	 * @param p a valid position
	 */
	void setPosition(Position p);
	//! A getter for the speed_;
	double getSpeed() const;

	//! A function decrementing live with 1:
	void liveDecr();
	//! A function incrementing live with 1:
	void liveIncr();

	//! A getter for lives_
	unsigned int getLives() const;
private:
	unsigned int lives_;
};

} /* namespace objects */

#endif /* GUN_H_ */
