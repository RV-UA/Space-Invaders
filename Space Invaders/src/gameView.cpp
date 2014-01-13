/*
 * gameView.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: robin
 */

#include "gameView.h"

namespace game {

GameView::GameView(std::shared_ptr<ModelPtr> model) : model_(model){
}
GameView::~GameView() {
	// TODO Auto-generated destructor stub
}

unsigned int GameView::getWidth() {
	return model_->model->width_;
}
unsigned int GameView::getHeight() {
	return model_->model->height_;
}

bool GameView::lost() {
	return model_->model->lose_;
}

bool GameView::won() {
	return model_->model->win_;
}
bool GameView::paused() {
	return model_->model->paused_;
}

void GameView::draw(sf::RenderWindow& window) {
	window.clear(model_->model->bgColor_);
	if (model_->model->paused_) {
		drawPause(window);
	}
	else if (model_->model->dead_) {
		// currently nothing
		model_->model->dead_ = false;
	}
	else if (model_->model->lose_) {
		drawLost(window);
	}
	else if (model_->model->win_) {
		drawWon(window);
	}
	else { // normal game
		sf::Text points("Points= " + utility::toString(model_->model->score_));
		sf::Text lives ("Lives= " + utility::toString(model_->model->gun_->getLives()));
		points.setPosition(10, 20);
		lives.setPosition(model_->model->width_/2, 20);

		//window.draw(points);
		//window.draw(lives);
		//window.draw(model_->model->levelText_);

		drawGun(window);
		drawAliens(window);
		drawBunkers(window);
		drawBullets(window);
	}
	window.display();
}

void GameView::drawGun(sf::RenderWindow& window) {
	model_->model->gun_->draw(window);
}

void GameView::drawAliens(sf::RenderWindow& window) {
	for (auto a : model_->model->aliens_) {
		a->draw(window);
	}
}

void GameView::drawBunkers(sf::RenderWindow& window) {
	for (auto b : model_->model->bunkers_) {
		b->draw(window);
	}
}

void GameView::drawBullets(sf::RenderWindow& window) {
	for (auto b : model_->model->bullets_) {
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
	//window.draw(model_->model->lost_);
	std::cout << " Game Lost" << std::endl;
}


} /* namespace game */
