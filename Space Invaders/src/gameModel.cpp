/*
 * gameModel.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: robin
 */

#include "gameModel.h"

namespace game {

GameModel::GameModel() :
	width_(0),
	height_(0),
	alienSpeed_(0),
	won_("you won"),
	lost_("you lost"),
	pause_("Game Paused"),
	win_(false),
	lose_(false),
	dead_(false),
	gunFireSpeed_(0),
	gunLastFired_(0),
	bgColor_(sf::Color::Black),
	level_(1),
	bulletUpdateDelay_(0),
	paused_(false),
	pauseTime_(0),
	score_(0)
	{
	arial_.loadFromFile("arial.ttf");
	clock_.restart();
}


GameModel::~GameModel() {
	aliens_.clear();
	bunkers_.clear();
	bullets_.clear();
}

int GameModel::getTime() {
	return pauseTime_+ clock_.getElapsedTime().asMilliseconds();
}

} /* namespace game */
