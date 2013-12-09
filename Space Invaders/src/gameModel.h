/*
 * gameModel.h
 *
 *  Created on: Nov 29, 2013
 *      Author: robin
 */

#ifndef GAMEMODEL_H_
#define GAMEMODEL_H_

#include <SFML/Graphics.hpp>
#include "EntityFactory.h"
#include "Exception.h"
#include "read.h"
#include <memory>

namespace game {

class GameController;
class GameFactory;
class GameView;

class GameModel {
	friend GameController;
	friend GameFactory;
	friend GameView;
public:
	//! A default constructor
	GameModel();
	//! A destructor
	virtual ~GameModel();
	//! A function returing the time value of clock_
	int getTime();
private:
	unsigned int width_; //! the width of the SFML window
	unsigned int height_;//! the height of the SFML window

	double alienSpeed_; //! the speed with which all aliens move

	sf::Clock clock_;	//! the clock used to make the game be played
	int pauseTime_;		//! the time at which the game is paused

	std::shared_ptr<objects::Gun> gun_;
	std::vector<std::shared_ptr<objects::Alien> > aliens_; //! the vector with pointers to all aliens
	std::vector<std::shared_ptr<objects::Bunker> > bunkers_; //! the vector with pointers to all bunkers
	std::vector<std::shared_ptr<objects::Bullet> > bullets_; //! the vector with pointers to all bullets

	sf::Font arial_;	//! the font used in the program

	sf::Text won_;		//! the message to be printed when player won the game
	sf::Text lost_;		//! the message to be printed when player lost the game
	sf::Text pause_;	//! the message to be printed when game is paused
	sf::Color bgColor_; //! the color of the background

	bool win_;			//! is true when all aliens are dead
	bool lose_;			//! is true when all lives of gun are gone
	bool dead_;			//! is true when gun has been hit
	bool paused_;

	objects::EntityFactory ef_; //! the factory used to create all objects

	int gunFireSpeed_; //! the speed with which the gun can fire
	int gunLastFired_; //! the last time the gun was fired (based on clock_)
	int bulletUpdateDelay_; //! the speed with which bullets will be updated
	unsigned int level_; //! the level you are currently playing

	int score_; //! the score you have in the game

};

} /* namespace game */

#endif /* GAMEMODEL_H_ */
