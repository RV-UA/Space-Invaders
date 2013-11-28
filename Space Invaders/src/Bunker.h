/*
 * bunker.h
 *
 *  Created on: Nov 19, 2013
 *      Author: robin
 */

#ifndef BUNKER_H_
#define BUNKER_H_

#include "Entity.h"
#include <iostream>

namespace objects {

class Bunker: public objects::Entity {
/*
 * class that represents the bunkers where you can hide behind
 */
public:
	//! A default constructor
	Bunker();

	//! A constructor with a given position (used for testing)
	Bunker(Position);

	//! A constructor with all necessary attributes given
	/**
	 * @param position the position of the leftmost point of the bunker
	 * @param health the health of the bunker when it is 0 bunker is destroyed
	 * @param c the color of the bunker
	 * @param sx the width of the bunker
	 * @param sy the height of the bunker
	 */
	Bunker(Position position, int health, sf::Color c, unsigned int sx, unsigned int sy);
	virtual ~Bunker();

	//! A function decrementing health with 1
	void hit();

	//! A function doing nothing as a Bunker can not move
	void move(){}	// can not move

	//! A function checking if the health of the bunker is > 0
	/**
	 * @return true if health > 0, false if health <= 0
	 */
	bool alive();

	//! A function drawing the bullet in the window
	/**
	 * @param w a window used to display the game
	 */
	void draw(sf::RenderWindow& w);

	//! getter for health (mostly used for testing )
	int getHealth() const;
	//! getter for the position
	Position getPosition() const;
	//! setter for position
	/**
	 * @param a valid position where the bunker will be put
	 */
	void setPosition( Position p);
private:
	int health_;	//! keeps track of the strength of health (if <= 0 -> gone)
};

} /* namespace objects */

#endif /* BUNKER_H_ */
