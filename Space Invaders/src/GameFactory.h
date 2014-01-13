/*
 * GameFactory.h
 *
 *  Created on: Nov 29, 2013
 *      Author: robin
 */

#ifndef GAMEFACTORY_H_
#define GAMEFACTORY_H_

#include "gameModel.h"

namespace game {

class GameFactory {
public:
	GameFactory();
	virtual ~GameFactory();
	static std::shared_ptr<GameModel> createGameModel(std::string filename);
};

} /* namespace game */

#endif /* GAMEFACTORY_H_ */
