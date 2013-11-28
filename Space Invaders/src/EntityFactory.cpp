/*
 * EntityFactory.cpp
 *
 *  Created on: Nov 25, 2013
 *      Author: robin
 */

#include "EntityFactory.h"


namespace objects {

EntityFactory::EntityFactory() {
}

EntityFactory::~EntityFactory() {
}

std::shared_ptr<Alien> EntityFactory::createAlien(std::string filename) {
	std::shared_ptr<Alien> ret;
	try {
		ret = parse::readAlien(filename);
	}
	catch(Exception& e) {
		std::string err = "Failed to create Alien object. parser returned following error: \n";
		err += e.what();
		throw(Exception(err));
	}
	return ret;
}

std::shared_ptr<Bunker> EntityFactory::createBunker(std::string filename) {
	std::shared_ptr<Bunker> ret;
	try {
		ret = parse::readBunker(filename);
	}
	catch(Exception& e) {
		std::string err = "Failed to create Bunker object. parser returned following error: \n";
		err += e.what();
		throw(Exception(err));
	}
	return ret;
}

std::shared_ptr<Gun> EntityFactory::createGun(std::string filename) {
	std::shared_ptr<Gun> ret;
	try {
		ret = parse::readGun(filename);
	}
	catch(Exception& e) {
		std::string err = "Failed to create Gun object. parser returned following error: \n";
		err += e.what();
		throw(Exception(err));
	}
	return ret;
}




} /* namespace objects */
