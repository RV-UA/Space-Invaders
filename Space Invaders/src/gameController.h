/*
 * gameController.h
 *
 *  Created on: Nov 29, 2013
 *      Author: robin
 */

#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include"gameModel.h"
#include "GameFactory.h"

namespace game {

class GameController {
public:
	//! Constructor with modelptr
	GameController(std::shared_ptr<ModelPtr> model);
	//! Destructor
	virtual ~GameController();
	//! A function setting the time for 1 cycle:
	void startCycle();
	//! A function pausing the game
	void pause();
	//! A function continuing the game:
	void go();
	//! A function firing the gun
	void fireGun();
	//! A function moving the aliens, bullets and letting the aliens fire
	void moveAndFire();
	//! A function moving the gun
	/**
	 * @param dir the direction in which the gun will move (can only be left or right)
	 */
	void moveGun(objects::MoveDirection dir );
	//! A function performing all checks
	void check();
	//! A function restarting the game:
	void restart();

private:
	//! A function checking collisions between aliens and bullets,
	//! between bullets and the gun, between bullets and Bunkers
	//! and between aliens and the gun


	void checkCollision();
	void checkBoundaries();

	std::shared_ptr<ModelPtr> model_; //! the model this controller controls
	int time_ ; //! the time on which a cycle starts:
};

} /* namespace game */

#endif /* GAMECONTROLLER_H_ */
