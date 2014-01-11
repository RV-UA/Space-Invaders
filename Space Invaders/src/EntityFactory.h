/*
 * EntityFactory.h
 *
 *  Created on: Nov 25, 2013
 *      Author: robin
 */

#ifndef ENTITYFACTORY_H_
#define ENTITYFACTORY_H_

#include <iostream>
#include <memory>
#include "Exception.h"
#include "read.h"

namespace objects {

class EntityFactory {
public:
	EntityFactory();
	virtual ~EntityFactory();
	//! A function creating an Alien from given file
	/**
	 * @param filename a file where an Alien is described
	 * @return a pointer to a new Alien object
	 */
	static std::shared_ptr<objects::Alien> createAlien(std::string filename);

	//! A function creating a Bunker from given file
	/**
	 * @param filename a file where a Bunker is described
	 * @return a pointer to a new Bunker object
	 */
	static std::shared_ptr<Bunker> createBunker(std::string filename);

	//! A function creating a Gun from given file
	/**
	 * @param filename a file where a Gun is described
	 * @return a pointer to a new Gun object
	 */
	static std::shared_ptr<Gun> createGun(std::string filename);

	//! A function creating a Bullet from a given Entity and a direction
	/**
	 * @param entity a pointer to an Entity object which fires the bullet
	 * @param direction the direction in which the bullet is fired (up or down)
	 * @param speed the speed the bullet will fly (depends on level and object firing)
	 * @return a pointer to a new Bullet object
	 */
	//std::shared_ptr<Bullet> createBullet(const std::shared_ptr<Entity>, MoveDirection direction, int speed);
};

} /* namespace objects */

#endif /* ENTITYFACTORY_H_ */
