/*
 * utilities.h
 *
 *  Created on: Nov 19, 2013
 *      Author: robin
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "Entity.h"

namespace utility {
std::vector<std::string> split(std::string);
std::pair<std::string, std::string> splitAtEq(std::string);
bool intersects(std::shared_ptr<objects::Entity>,std::shared_ptr<objects::Entity> );
}



#endif /* UTILITIES_H_ */
