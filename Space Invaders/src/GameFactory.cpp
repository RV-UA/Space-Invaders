/*
 * GameFactory.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: robin
 */

#include "GameFactory.h"

namespace game {

GameFactory::GameFactory() {
	// TODO Auto-generated constructor stub

}

GameFactory::~GameFactory() {
	// TODO Auto-generated destructor stub
}

std::shared_ptr<GameModel> GameFactory::createGameModel(std::string filename) {
	std::shared_ptr<GameModel> ret(new GameModel());

	sf::Color bgColor;
	unsigned int width;
	unsigned int height;
	double alienSpeed;
	int gunFireSpeed;
	int bulletUpdateDelay;
	int alienPerRow;
	int nrAlienRows;
	int nrAlien1;
	int nrAlien2;
	int nrAlien3;
	int nrBunkers;
	std::string alienFile = "./Alien1";
	std::string bunkerFile = "./Bunker";
	std::string gunFile = "./Gun";

	parse::readWindow(filename, bgColor, width, height,
			alienSpeed, gunFireSpeed, bulletUpdateDelay,
			alienPerRow, nrAlienRows,
			nrAlien1, nrAlien2, nrAlien3,
			nrBunkers);

	ret->bgColor_ = bgColor;
	ret->width_ = width;
	ret->height_ = height;
	ret->alienSpeed_ = alienSpeed;
	ret->gunFireSpeed_ = gunFireSpeed;
	ret->bulletUpdateDelay_= bulletUpdateDelay;

	// Create Aliens: + put them on the right positions

	std::shared_ptr<objects::Alien> tempAlien( ret->ef_.createAlien(alienFile));
	double speed = tempAlien->getSpeed();
	int switchDir = tempAlien->getSwitchDir();
	int moveHor = tempAlien->getMoveHor();
	int alienWidth = tempAlien->getSizeX();
	int alienHeight = tempAlien->getSizeY();
	int space_Aliens_x = (width - (speed* (switchDir / moveHor)+50+alienWidth) - alienPerRow*alienWidth) / (alienPerRow-1);
	int space_Aliens_y = 50;

	// set aliens on their right positions
	int count = 0;
	for (int i = 0; i < nrAlienRows; i++) {
		for (int j = 0; j < alienPerRow; j++) {
			ret->aliens_.push_back(objects::EntityFactory::createAlien(alienFile));

			objects::Position pos = ret->aliens_.at(count)->getPosition();
			pos.first+= 50 + j*space_Aliens_x + j* alienWidth;
			pos.second += 10 + i* space_Aliens_y + i * alienHeight;

			ret->aliens_.at(count)->setPosition(pos);
			std::cout << " ALien pos : " << pos.first << " , " << pos.second;
			std::cout << " ALien position : " << ret->aliens_.at(count)->getPosition().first << " , " << ret->aliens_.at(count)->getPosition().second << std::endl;;

			count++;
		}
	}

	//create Bunkers and set to their appropriate positions
	std::shared_ptr<objects::Bunker> tempBunker( ret->ef_.createBunker(bunkerFile));
	int bunkerWidth = tempBunker->getSizeX();
	int space_Bunker_x = (width - 100 - nrBunkers*bunkerWidth) / (nrBunkers-1);


	// set Bunkers on their right positions
	for (int i = 0; i < nrBunkers; i++) {
		ret->bunkers_.push_back(ret->ef_.createBunker(bunkerFile));

		objects::Position pos = ret->bunkers_.at(i)->getPosition();
		pos.first = 50 + (i)*space_Bunker_x + (i)* bunkerWidth;

		ret->bunkers_.at(i)->setPosition(pos);
		std::cout << "BunkerPosition: " << pos.first << " , " << pos.second << std::endl;
	}

	// create gun:
	ret->gun_ = ret->ef_.createGun(gunFile);
	objects::Position gunpos(width/2, height - ret->gun_->getSizeY() - 20);
	ret->gun_->setPosition(gunpos);
	std::cout << "gun pos: " << gunpos.first << " , " << gunpos.second << std::endl;

	std::cout << "gun position: " << ret->gun_->getPosition().first << " , " << ret->gun_->getPosition().second << std::endl;

	return ret;
}

} /* namespace game */
