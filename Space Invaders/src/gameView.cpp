/*
 * gameView.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: robin
 */

#include "gameView.h"

namespace game {

GameView::GameView(std::shared_ptr<GameModel> model) : model_(model){
}
GameView::~GameView() {
	// TODO Auto-generated destructor stub
}

unsigned int GameView::getWidth() {
	return model_->width_;
}
unsigned int GameView::getHeight() {
	return model_->height_;
}

bool GameView::lost() {
	return model_->lose_;
}

bool GameView::won() {
	return model_->win_;
}
bool GameView::paused() {
	return model_->paused_;
}

void GameView::draw(sf::RenderWindow& window) {
	window.clear(model_->bgColor_);
	if (model_->paused_) {
		drawPause(window);
	}
	else if (model_->dead_) {
		// currently nothing
		model_->dead_ = false;
	}
	else if (model_->lose_) {
		drawLost(window);
	}
	else if (model_->win_) {
		drawWon(window);
	}
	else { // normal game
		drawGun(window);
		drawAliens(window);
		drawBunkers(window);
		drawBullets(window);
	}
	window.display();
}

void GameView::drawGun(sf::RenderWindow& window) {
	model_->gun_->draw(window);
}

void GameView::drawAliens(sf::RenderWindow& window) {
	for (auto a : model_->aliens_) {
		a->draw(window);
	}
}

void GameView::drawBunkers(sf::RenderWindow& window) {
	for (auto b : model_->bunkers_) {
		b->draw(window);
	}
}

void GameView::drawBullets(sf::RenderWindow& window) {
	for (auto b : model_->bullets_) {
		b->draw(window);
	}
}

void GameView::drawPause(sf::RenderWindow& window) {
	//window.draw(model_->pause_);
	std::cout << " Game Paused" << std::endl;
}

void GameView::drawWon(sf::RenderWindow& window) {
	//window.draw(model_->win_);
	std::cout << " Game Won" << std::endl;
}

void GameView::drawLost(sf::RenderWindow& window) {
	window.clear(sf::Color::Red);
	window.draw(model_->lost_);
	std::cout << " Game Lost" << std::endl;
}


} /* namespace game */
