/*
 * gameController.cpp
 *
 *  Created on: Nov 29, 2013
 *      Author: robin
 */

#include "gameController.h"

namespace game {

GameController::GameController(std::shared_ptr<GameModel> model) : model_(model), time_(0){
}

GameController::~GameController() {
	// TODO Auto-generated destructor stub
}

void GameController::startCycle() {
	time_ = model_->getTime();
}

void GameController::pause() {
	model_->pauseTime_+= model_->getTime();
	model_->paused_ = true;
}

void GameController::go() {
	model_->clock_.restart();
	model_->paused_ = false;
}


void GameController::fireGun() {
	if (time_ - model_->gunLastFired_ >= model_->gunFireSpeed_) {
		model_->bullets_.push_back(model_->gun_->fire());
		model_->gunLastFired_ = time_;
	}
}

void GameController::moveAndFire() {

	// fire aliens

	for (auto a : model_->aliens_) {
		bool fire = true;
		// let only the aliens up front fire
		for (auto b : model_->aliens_) {
			if ((b->getPosition().first == a->getPosition().first) && (b->getPosition().second > a->getPosition().second)) {
				fire = false;
				}
			}
		if (fire) {
			std::shared_ptr<objects::Bullet> temp(a->fire(time_));
			if (temp != nullptr) {
				model_->bullets_.push_back(temp);
			}
		}
	}


	// move all objects;
	for (auto b : model_->bullets_) {
		b->move(time_, model_->bulletUpdateDelay_);
	}

	for (auto c : model_->aliens_) {
		c->move(time_);
	}

}

void GameController::moveGun(objects::MoveDirection dir) {
	std::cout << "moving gun" << std::endl;
	if (dir != objects::right && dir != objects::left) {
		throw(Exception("A GUN CAN ONLY MOVE LEFT OR RIGHT"));
	}
	else {
		model_->gun_->setMove(dir);
		model_->gun_->move();
	}
}

void GameController::check() {
	checkBoundaries();
	checkCollision();
	// check nr of aliens left:
	if (model_->aliens_.size() == 0) {
		model_->win_ = true;
	}

}

void GameController::checkCollision() {
	// check for bullets hitting bunkers
	for (unsigned int i = 0; i< model_->bullets_.size(); i++) {
		for (unsigned int j = 0; j < model_->bunkers_.size(); j++) {
			bool hit = utility::intersects(model_->bullets_.at(i), model_->bunkers_.at(j));
			if (hit) {
				model_->bullets_.erase(model_->bullets_.begin()+i);
				i--;
				model_->bunkers_.at(j)->hit();
				if (!model_->bunkers_.at(j)->alive()) {	// check for destroyed bunkers
					model_->bunkers_.erase(model_->bunkers_.begin()+j);
					j--;
				}
				break;
			}
		}
	}

	// check for bullets hitting aliens		not those fired by aliens
	for (unsigned int i = 0; i< model_->bullets_.size(); i++) {
		for (unsigned int j = 0; j < model_->aliens_.size(); j++) {
			if (model_->bullets_.at(i)->getDirection() == objects::down) {
				break;
			}
			bool hit = utility::intersects(model_->bullets_.at(i), model_->aliens_.at(j));
			if (hit) {
				model_->score_ += model_->aliens_.at(j)->getScore();
				std::cout << "Score = " << model_->score_ << std::endl;
				model_->bullets_.erase(model_->bullets_.begin()+i);
				i--;
				model_->aliens_.erase(model_->aliens_.begin()+j);
				j--;
				break;
			}
		}
	}

	// check for bullets hitting gun 	not those fired by gun
	for (unsigned int i = 0; i< model_->bullets_.size(); i++) {
		if (model_->bullets_.at(i)->getDirection() == objects::up) {
			continue;
		}
		bool hit = utility::intersects(model_->bullets_.at(i), model_->gun_);
		if (hit) {
			std::cout << "gun hit" << std::endl;
			model_->gun_->liveDecr();
			model_->bullets_.erase(model_->bullets_.begin()+i);
			i--;
			model_->dead_ = true;
			if (model_->gun_->getLives() <= 0) {
				model_->lose_ = true;
			}
		}
	}
	// check for aliens hitting gun
	for (unsigned int i = 0; i< model_->aliens_.size(); i++) {

		bool hit = utility::intersects(model_->aliens_.at(i), model_->gun_);
		if (hit) {
			std::cout << "alien hit gun" << std::endl;
			std::cout << " ALien position : " << model_->aliens_.at(i)->getPosition().first << " , " << model_->aliens_.at(i)->getPosition().second << std::endl;;
			std::cout << " gun position : " << model_->gun_->getPosition().first << " , " << model_->gun_->getPosition().second << std::endl;;

			model_->lose_ = true;
			//gun->liveDecr();
			model_->aliens_.erase(model_->aliens_.begin()+i);
			break;
		}
	}
	// check for aliens hitting bunkers:
	for (unsigned int i = 0; i< model_->aliens_.size(); i++) {
		for (unsigned int j = 0; j < model_->bunkers_.size(); j++) {
			bool hit = utility::intersects(model_->aliens_.at(i), model_->bunkers_.at(j));
			if (hit) {
				model_->aliens_.erase(model_->aliens_.begin()+i);
				i--;
				model_->bunkers_.erase(model_->bunkers_.begin()+j);
				j--;
				break;
			}
		}
	}

}

void GameController::checkBoundaries () {
	// check for gun in screen

	if ((model_->gun_->getPosition().first <= model_->gun_->getSpeed()) ) {
		model_->gun_->setPosition(objects::Position(model_->gun_->getSpeed(),model_->gun_->getPosition().second));
	}
	else if (model_->gun_->getPosition().first > model_->width_ - model_->gun_->getSizeX()) {
		model_->gun_->setPosition(objects::Position(model_->width_ - model_->gun_->getSizeX(), model_->gun_->getPosition().second));
	}

	// check for bullets out of screen
	for (unsigned int i = 0; i < model_->bullets_.size(); i++)
	{
		if ((model_->bullets_.at(i)->getPosition().first < 0) || (model_->bullets_.at(i)->getPosition().first > model_->width_)) {
			model_->bullets_.erase(model_->bullets_.begin()+i);
			i--;
		}
		else if ((model_->bullets_.at(i)->getPosition().second < 0) || (model_->bullets_.at(i)->getPosition().second > model_->height_)) {
			model_->bullets_.erase(model_->bullets_.begin()+i);
			i--;
		}
		else {
			// nothing wrong
			continue;
		}
	}
	// check for aliens out of screen
	for (unsigned int i = 0; i < model_->aliens_.size(); i++)
	{
		if ((model_->aliens_.at(i)->getPosition().second < 0) || (model_->aliens_.at(i)->getPosition().second > model_->height_)) {
			model_->aliens_.erase(model_->aliens_.begin()+i);
			i--;
		}
		else if ((model_->aliens_.at(i)->getPosition().first < 0) || (model_->aliens_.at(i)->getPosition().first > model_->width_)) {
			model_->aliens_.erase(model_->aliens_.begin()+i);
			i--;
		}
		else {
			// nothing wrong
			continue;
		}
	}
}


} /* namespace game */
