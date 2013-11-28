/*
 * utilities.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: robin
 */

#include "utilities.h"


std::vector<std::string> utility::split(std::string s) {
	std::vector<std::string> ret;
	int hold= 0;
	for (int i = 0; i <= s.size(); i++)
	{
		std::string temp = "";
		if (i == s.size())
		{
			temp.append(s,hold,i-hold);
			ret.push_back(temp);
		}

		else if (s.at(i) == ' ')
		{
			temp.append(s, hold, i-hold);
			ret.push_back(temp);
			while (s.at(i) == ' ')
			{
				i++;
			}
			hold = i;
		}
	}
	return ret;
}


std::pair<std::string, std::string> utility::splitAtEq(std::string s) {
	std::string r1;
	std::string r2;
	bool change  = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s.at(i) == '=') {
			r1.append(s,0,i);
			r2.append(s, i+1, s.size()-i-1);
			change = true;
			break;
		}
	}
	if (change == false)
	{
		throw(0); 	// TODO use exception
	}
	std::pair<std::string, std::string> ret(r1, r2);

	return ret;
}


bool utility::intersects(std::shared_ptr<objects::Entity> e1,std::shared_ptr<objects::Entity> e2 )
{
	// calculate the 4 corners of e1
	objects::Position e1c1, e1c2, e1c3, e1c4;
	e1c1 = e1->getPosition();
	e1c2 = e1->getPosition();
	e1c2.first+= e1->getSizeX();
	e1c3 = e1->getPosition();
	e1c3.second+= e1->getSizeY();
	e1c4 = e1->getPosition();
	e1c4.first+= e1->getSizeX();
	e1c4.second+= e1->getSizeY();


	// calculate the 4 corners of e2
	objects::Position e2c1, e2c2, e2c3, e2c4;
	e2c1 = e2->getPosition();
	e2c2 = e2->getPosition();
	e2c2.first+= e2->getSizeX();
	e2c3 = e2->getPosition();
	e2c3.second+= e2->getSizeY();
	e2c4 = e2->getPosition();
	e2c4.first+= e2->getSizeX();
	e2c4.second+= e2->getSizeY();

	// check if object 2 has a corner in object 1
	if (e2c1.first < e1c2.first  && e2c1.first > e1c1.first) {
		if (e2c1.second<e1c3.second && e2c1.second >e1c1.second) {
			return true;
		}
	}

	if (e2c2.first <= e1c2.first  && e2c2.first >= e1c1.first) {
		if (e2c2.second<=e1c3.second && e2c2.second >=e1c1.second) {
			return true;
		}
	}

	if (e2c3.first <= e1c2.first  && e2c3.first >= e1c1.first) {
		if (e2c3.second<=e1c3.second && e2c3.second >=e1c1.second) {
			return true;
		}
	}

	if (e2c4.first <= e1c2.first  && e2c4.first >= e1c1.first) {
		if (e2c4.second<=e1c3.second && e2c4.second >= e1c1.second) {
			return true;
		}
	}

	// check if object 1 has a corner in object 2
	if (e1c1.first < e2c2.first  && e1c1.first > e2c1.first) {
		if (e1c1.second<e2c3.second && e1c1.second >e2c1.second) {
			return true;
		}
	}

	if (e1c2.first <= e2c2.first  && e1c2.first >= e2c1.first) {
		if (e1c2.second<=e2c3.second && e1c2.second >=e2c1.second) {
			return true;
		}
	}

	if (e1c3.first <= e2c2.first  && e1c3.first >= e2c1.first) {
		if (e1c3.second<=e2c3.second && e1c3.second >=e2c1.second) {
			return true;
		}
	}

	if (e1c4.first <= e2c2.first  && e1c4.first >= e2c1.first) {
		if (e1c4.second<=e2c3.second && e1c4.second >= e2c1.second) {
			return true;
		}
	}



	return false;
}



