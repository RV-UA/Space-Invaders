/*
 * readAlien.h
 *
 *  Created on: Nov 19, 2013
 *      Author: robin
 */

#ifndef READALIEN_H_
#define READALIEN_H_


#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <memory>
#include "Entity.h"
#include "utilities.h"
#include "Alien.h"
#include "Bunker.h"
#include "Gun.h"
#include "Exception.h"

namespace parse {
	//! A function reading an object from a file
	std::shared_ptr<objects::Entity> readFile(std::string file);
	//! A function reading an Alien from a file
	std::shared_ptr<objects::Alien> readAlien(std::string file);
	//! A function reading a Bunker from a file
	std::shared_ptr<objects::Bunker> readBunker(std::string file);
	//! A function reading a Gun from a file
	std::shared_ptr<objects::Gun> readGun(std::string file);
	//! A function reading all parameters for the window from a file
	/**
	 * @param file the file from which will be read
	 * @param width the width of the field
	 * @param height the height of the field
	 * @param BgColor the background color of the playing field
	 * @param aliensPerRow the nr of aliens on 1 row of aliens
	 * @param nrRows the nr of rows of aliens on the playing field
	 * @param nrAlien1 the nr of rows of aliens of type 1
	 * @param nrAlien2 the nr of rows of aliens of type 2
	 * @param nrAlien3 the nr of rows of aliens of type 3
	 * @param nrBunkers the nr of bunkers on the field
	 */
	void readWindow(std::string file, sf::Color& BgColor, unsigned int &width, unsigned int &height, double& alienSpeed, int& gunFireSpeed,int& bulletUpdateDelay,int& aliensPerRow,int& nrRows , int& nrAlien1 , int& nrAlien2 ,int& nrAlien3, int& nrBunkers );
}


#endif /* READALIEN_H_ */
