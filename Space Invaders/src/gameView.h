/*
 * gameView.h
 *
 *  Created on: Nov 29, 2013
 *      Author: robin
 */

#ifndef GAMEVIEW_H_
#define GAMEVIEW_H_

#include <SFML/Graphics.hpp>
#include "gameModel.h"
#include <memory>

namespace game {

class GameView {
	friend class GameController;
public:
	//! constructor with GameModel given
	GameView(std::shared_ptr<ModelPtr>);
	//! destructor
	virtual ~GameView();
	unsigned int getWidth();
	unsigned int getHeight();
	bool lost();
	bool won();
	bool paused();
	//! A function drawing the game
	void draw(sf::RenderWindow& window);
private:
	//! A function drawing the gun
	void drawGun(sf::RenderWindow& window);
	//! A function drawing the aliens
	void drawAliens(sf::RenderWindow& window);
	//! A function drawing the Bunkers
	void drawBunkers(sf::RenderWindow& window);
	//! A function drawing the Bullets
	void drawBullets(sf::RenderWindow& window);
	//! A function drawing pause
	void drawPause(sf::RenderWindow& window);
	//! A function drawing lost
	void drawLost(sf::RenderWindow& window);
	//! A function drawing won
	void drawWon(sf::RenderWindow& window);

	std::shared_ptr<ModelPtr> model_; //! the model the viewer is viewing

};

} /* namespace game */

#endif /* GAMEVIEW_H_ */
