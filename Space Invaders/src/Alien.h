/*
 * Alien.h
 *
 *  Created on: Nov 19, 2013
 *      Author: robin
 */

#ifndef ALIEN_H_
#define ALIEN_H_

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Bullet.h"
//#include "Exception.h"

namespace objects {

class Alien : public Entity {
/*
 * base class for all different aliens
 */
public:
	//! A default constructor
	Alien();
	Alien(	Position,
			sf::Color,
			double speed,
			unsigned int size_x,
			unsigned int size_y,
			unsigned int move_horizontal,
			unsigned int switch_direction,
			unsigned int fireChance,
			unsigned int score);
	//! An empty destructor
	virtual ~Alien();

	//! A function firing (pure virtual)
	/**
	 * @param time time game has been running
	 */
	virtual std::shared_ptr<Bullet> fire(int time) = 0;
	//! A function drawing the Alien on the given window (pure virtual)
	virtual void draw(sf::RenderWindow& window) = 0;
	//! A function setting the direction of the Alien;
	/**
	 * @param direction the direction in which the Alien will move (can only be right, left, down)
	 */
	virtual void setMove(MoveDirection direction);
	//! A function moving the Alien in its direction, distance is determined by the speed
	/**
	 * @param time the time the game is running
	 */
	virtual void move(int time);
	//! getter for the position of the Alien
	virtual Position getPosition() const;
	//! setter for the position
	/**
	 * @param position a new valid position
	 */
	void setPosition(Position position);

	virtual int getScore() const;

	virtual int getMoveHor() const;
	virtual int getSwitchDir() const;

protected:
	int fireTime_; 				//! time to fire
	int moveHorizontal_time_;	//! used to determine the horizontal movement of aliens
	int switchDirection_time_;	//! used to detemine switching directions
	int moveVertical_time_;		//! used to determine the vertical movement
	bool down_;					//! used to make aliens go down
	int lastFired_; 			//! the time the alien has last fired
	int lastMoved_;				//! the time the alien has last moved horizontally
	int lastChangedDir_;		//! the time the alien has last changed its moving direction
	int lastMovedDown_;			//! the time the alien has last moved down
	int fireChance_;			//! the chance the alien will fire after fireTime
	int score_; 				//! the score you get for killing the alien
};

class AlienType1 : public Alien {
public:
	AlienType1(Position,
			sf::Color,
			double speed,
			unsigned int size_x,
			unsigned int size_y,
			unsigned int move_horizontal,
			unsigned int switch_direction,
			unsigned int fireChance,
			unsigned int score);
	//! A function drawing the Alien in the window
	/**
	 * @param w a window which will be used to display the game
	 */
	virtual void draw(sf::RenderWindow& window);

	//! A function firing a bullet if it is the right time
	/**
	 * @param time the time the game is busy
	 * @return a pointer to a Bullet if time_ == fire_time_, else a nullpointer
	 */
	virtual std::shared_ptr<Bullet> fire(int time);

};

} /* namespace objects */

#endif /* ALIEN_H_ */
