/*
 * readAlien.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: robin
 */


#include "read.h"
#include <fstream>

namespace parse {

	std::shared_ptr<objects::Entity> readFile(std::string filename) {
		std::ifstream in;
		in.open(filename.c_str());
		std::shared_ptr<objects::Entity> ret = nullptr;
		std::string line;
		std::pair<std::string, std::string> cls;
		// get 1st line determining alien class
		getline(in, line);
		std::vector<std::string> words = utility::split(line);
		if (words.at(0) == "Alien") {
			// readAlien
			ret = readAlien(filename);
		}
		else if (words.at(0) == "Bunker") {
			//readBunker
			ret = readBunker(filename);
		}
		else if(words.at(0) == "Gun") {
			//readGun
			ret = readGun(filename);
		}
		else {
			throw(Exception("INVALID TYPE SPECIFIED IN " + filename));
		}

		return ret;
	}

	std::shared_ptr<objects::Alien> readAlien(std::string filename) {
		std::string className = "NONE";
		std::string c = "Black";
		sf::Color color = sf::Color::Black;
		double speed = 0;
		std::pair<unsigned int, unsigned int> pos(0,0);
		std::ifstream in;
		in.open(filename.c_str());

		std::string line;
		std::pair<std::string, std::string> cls;
		// get 1st line determining alien class
		getline(in, line);
		std::vector<std::string> words = utility::split(line);
		if (words.at(0) != "Alien") {
			// invalid file
			throw(Exception(filename+ " IS NOT A FILE DESCRIBING AN ALIEN"));
		}
		else {
			std::cout << "Type " << words.at(0) << std::endl;
			try {
				cls = utility::splitAtEq(words.at(1));

			}
			catch(...) {
				throw(Exception(filename + " HAS INVALID FORMAT"));
			}
			if (cls.first != "Class")
			{
				throw(Exception("EXPECTED Class BUT GOT " + cls.first + " IN FILE " + filename ));
			}
			else
			{
				className = cls.second;
				std::cout << "ClassName " << className << std::endl;
			}

		}
		// read {
		line.clear();
		getline(in, line);
		if (line.at(0) != '{') {
			std::string err = "EXPECTED { BUT GOT " + line + " IN FILE "+filename;
			throw(Exception(err ));
		}
		// read Speed
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(filename + " HAS INVALID FORMAT"));
		}
		if (cls.first != "Speed") {
			throw(Exception("EXPECTED Speed but got " + cls.first + " IN FILE " + filename));
		}
		else {
			speed = atof(cls.second.c_str());
			std::cout << "speed = " << speed << std::endl;
		}

		pos = objects::Position(0,0);
		std::cout << "position: (" << pos.first << " , " << pos.second << ")" << std::endl;

		unsigned int size_x=0, size_y=0;
		// read size_x
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(filename + " HAS INVALID FORMAT"));
		}
		if (cls.first != "Size_x") {
			throw(Exception("EXPECTED Size_x but got " + cls.first + " IN FILE " + filename));
		}
		else {
			size_x = atoi(cls.second.c_str());
		}
		// read size_y
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(filename + " HAS INVALID FORMAT"));
		}
		if (cls.first != "Size_y") {
			throw(Exception("EXPECTED Size_y but got " + cls.first + " IN FILE " + filename));
		}
		else {
			size_y = atoi(cls.second.c_str());
		}

		// read Color
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(filename+ " HAS INVALID FORMAT"));
		}
		if (cls.first != "Color") {
			throw(Exception("EXPECTED Color but got " + cls.first + " IN FILE " + filename));
		}
		else {
			c = cls.second;
			std::cout << "Color= " << c << std::endl;
			if (c == "White") {
				color = sf::Color::White;
			}
			else if (c == "Black") {
				color = sf::Color::Black;
			}
			else if (c == "Green") {
				color = sf::Color::Green;
			}
			else if (c == "Red") {
				color = sf::Color::Red;
			}
			else if (c == "Blue") {
				color = sf::Color::Blue;
			}
			else if (c == "Yellow") {
				color = sf::Color::Yellow;
			}
			else if (c == "Magenta") {
				color = sf::Color::Magenta;
			}
			else if (c == "Cyan") {
				color = sf::Color::Cyan;
			}
			else{
				throw (Exception("UNDEFINED COLOR " + c + " PLEASE TRY ANY OF THE FOLLOWING: White, Black, Red, Green, Yellow, Blue, Magenta, Cyan"));
			}
		}
		// read }
		line.clear();
		getline(in, line);
		if (line.at(0) != '}') {
			throw(Exception("EXPECTED } but got " + line + " IN FILE " + filename));
		}
		// construct Alien
		if (className == "Alien1") {
			std::shared_ptr<objects::Alien> ret (new objects::AlienType1(pos, speed, color, size_x, size_y));
			return ret;
		}
		else{
			// return other types
		}
	}

	std::shared_ptr<objects::Bunker> readBunker(std::string filename) {
		std::string c = "Black";
		sf::Color color = sf::Color::Black;
		std::pair<unsigned int, unsigned int> pos(0,0);
		int health;
		std::ifstream in;
		in.open(filename.c_str());

		std::string line;
		std::pair<std::string, std::string> cls;
		// get 1st line determining alien class
		getline(in, line);
		std::vector<std::string> words = utility::split(line);
		if (words.at(0) != "Bunker") {
			// invalid file
			throw(Exception(filename + " IS NOT A FILE DESCRIBING A BUNKER "));
		}
		// read {
		line.clear();
		getline(in, line);
		if (line.at(0) != '{') {
			throw(Exception("EXPECTED { but got " + line + " IN FILE " + filename));
		}
		int pos_x=0, pos_y=0;
		// read pos_x
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(filename+ " HAS INVALID FORMAT"));
		}
		if (cls.first != "Pos_x") {
			throw(Exception("EXPECTED Pos_x but got " + cls.first + " IN FILE " + filename));
		}
		else {
			pos_x = atoi(cls.second.c_str());
		}
		// read pos_y
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(filename+"HAS INVALID FORMAT"));
		}
		if (cls.first != "Pos_y") {
			throw(Exception("EXPECTED Pos_y but got " + cls.first + " IN FILE " + filename));
		}
		else {
			pos_y = atoi(cls.second.c_str());
		}
		pos = std::pair<unsigned int, unsigned int>(pos_x, pos_y);
		std::cout << "position: (" << pos.first << " , " << pos.second << ")" << std::endl;

		unsigned int size_x=0, size_y=0;
		// read size_x
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(filename+" HAS INVALID FORMAT"));
		}
		if (cls.first != "Size_x") {
			throw(Exception("EXPECTED Size_x but got " + cls.first + " IN FILE " + filename));
		}
		else {
			size_x = atoi(cls.second.c_str());
		}
		// read size_y
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(filename + " HAS INVALID FORMAT");
		}
		if (cls.first != "Size_y") {
			throw(Exception("EXPECTED Size_y but got " + cls.first + " IN FILE " + filename));
		}
		else {
			size_y = atoi(cls.second.c_str());
		}


		// read Health
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(filename + " HAS INVALID FORMAT"));
		}
		if (cls.first != "Health") {
			throw(Exception("EXPECTED Health but got " + cls.first + " IN FILE " + filename));
		}
		else {
			health = atoi(cls.second.c_str());
			std::cout << "Health= " << health << std::endl;
		}


		// read color
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(filename + " HAS INVALID FORMAT"));
		}
		if (cls.first != "Color") {
			throw(Exception("EXPECTED Color but got " + cls.first + " IN FILE " + filename));
		}
		else {
			c = cls.second;
			std::cout << "color= " << c << std::endl;
			if (c == "White") {
				color = sf::Color::White;
			}
			else if (c == "Black") {
				color = sf::Color::Black;
			}
			else if (c == "Green") {
				color = sf::Color::Green;
			}
			else if (c == "Red") {
				color = sf::Color::Red;
			}
			else if (c == "Blue") {
				color = sf::Color::Blue;
			}
			else if (c == "Yellow") {
				color = sf::Color::Yellow;
			}
			else if (c == "Magenta") {
				color = sf::Color::Magenta;
			}
			else if (c == "Cyan") {
				color = sf::Color::Cyan;
			}
			else{
				throw (Exception("UNDEFINED COLOR " + c + " PLEASE TRY ANY OF THE FOLLOWING: White, Black, Red, Green, Yellow, Blue, Magenta, Cyan"));
			}
		}
		// read }
		line.clear();
		getline(in, line);
		if (line.at(0) != '}') {
			throw(Exception("EXPECTED } but got " + line + " IN FILE " + filename));
		}
		// construct Bunker
		std::shared_ptr<objects::Bunker> ret (new objects::Bunker(pos, health, color, size_x, size_y));
		return ret;

	}

	std::shared_ptr<objects::Gun> readGun(std::string filename) {
		std::string c = "Black";
		sf::Color color = sf::Color::Black;
		objects::Position pos;
		double speed = 0;
		std::ifstream in;
		in.open(filename.c_str());

		std::string line;
		std::pair<std::string, std::string> cls;
		// get 1st line determining class
		getline(in, line);
		std::vector<std::string> words = utility::split(line);
		if (words.at(0) != "Gun") {
			// invalid file
			throw(filename + " DOES NOT DESCRIBE A GUN");
		}
		// read {
		line.clear();
		getline(in, line);
		if (line.at(0) != '{') {
			throw(Exception("EXPECTED { but got " + line + " IN FILE " + filename));
		}

		// read Speed
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(filename + " HAS INVALID FORMAT"));
		}
		if (cls.first != "Speed") {
			throw(Exception("EXPECTED Speed but got " + cls.first + " IN FILE " + filename));
		}
		else {
			speed = atof(cls.second.c_str());
			std::cout << "speed = " << speed << std::endl;
		}

		// read color
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(filename + " HAS INVALID FORMAT"));
		}
		if (cls.first != "Color") {
			throw(Exception("EXPECTED Color but got " + cls.first + " IN FILE " + filename));
		}
		else {
			c = cls.second;
			std::cout << "color= " << c << std::endl;
			if (c == "White") {
				color = sf::Color::White;
			}
			else if (c == "Black") {
				color = sf::Color::Black;
			}
			else if (c == "Green") {
				color = sf::Color::Green;
			}
			else if (c == "Red") {
				color = sf::Color::Red;
			}
			else if (c == "Blue") {
				color = sf::Color::Blue;
			}
			else if (c == "Yellow") {
				color = sf::Color::Yellow;
			}
			else if (c == "Magenta") {
				color = sf::Color::Magenta;
			}
			else if (c == "Cyan") {
				color = sf::Color::Cyan;
			}
			else{
				throw (Exception("UNDEFINED COLOR " + c + " PLEASE TRY ANY OF THE FOLLOWING: White, Black, Red, Green, Yellow, Blue, Magenta, Cyan"));
			}
		}

		int pos_x=0, pos_y=0;
		// read pos_x
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(filename + " HAS INVALID FORMAT" ));
		}
		if (cls.first != "Pos_x") {
			throw(Exception("EXPECTED Pos_x but got " + cls.first + " IN FILE " + filename));
		}
		else {
			pos_x = atoi(cls.second.c_str());
		}
		// read pos_y
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(filename + " HAS INVALID FORMAT"));
		}
		if (cls.first != "Pos_y") {
			throw(Exception("EXPECTED Pos_y but got " + cls.first + " IN FILE " + filename));
		}
		else {
			pos_y = atoi(cls.second.c_str());
		}
		pos = std::pair<unsigned int, unsigned int>(pos_x, pos_y);
		std::cout << "position: (" << pos.first << " , " << pos.second << ")" << std::endl;


		unsigned int size_x=0, size_y=0;
		// read size_x
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(filename + " HAS INVALID FORMAT"));
		}
		if (cls.first != "Size_x") {
			throw(Exception("EXPECTED Size_x but got " + cls.first + " IN FILE " + filename));
		}
		else {
			size_x = atoi(cls.second.c_str());
		}
		// read pos_y
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(filename + " HAS INVALID FORMAT"));
		}
		if (cls.first != "Size_y") {
			throw(Exception("EXPECTED Size_y but got " + cls.first + " IN FILE " + filename));
		}
		else {
			size_y = atoi(cls.second.c_str());
		}


		// read }
		line.clear();
		getline(in, line);
		if (line.at(0) != '}') {
			throw(Exception("EXPECTED } but got " + line + " IN FILE " + filename));
		}
		// construct Gun
		std::shared_ptr<objects::Gun> ret (new objects::Gun(speed, pos, color, size_x, size_y));
		return ret;

	}

	void readWindow(std::string file, unsigned int &width, unsigned int &height, sf::Color& color, int& alienPerRow,int& nrAlienRows , int& nrAlien1 , int& nrAlien2 ,int& nrAlien3, int& nrBunkers ){
		std::string c = "Black";
		color = sf::Color::Black;
		std::ifstream in;
		in.open(file.c_str());

		std::string line;
		std::pair<std::string, std::string> cls;
		// get 1st line determining class
		getline(in, line);
		std::vector<std::string> words = utility::split(line);
		if (words.at(0) != "Window") {
			// invalid file
			throw(Exception(file + " DOES NOT DESCRIBE A WINDOW"));
		}
		// read {
		line.clear();
		getline(in, line);
		if (line.at(0) != '{') {
			throw(Exception("EXPECTED { but got " + line + " IN FILE " + file));
		}

		// read color
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(file + " HAS INVALID FORMAT"));
		}
		if (cls.first != "BgColor") {
			throw(Exception("EXPECTED BgColor but got " + cls.first + " IN FILE " + file));
		}
		else {
			c = cls.second;
			std::cout << "color= " << c << std::endl;
			if (c == "White") {
				color = sf::Color::White;
			}
			else if (c == "Black") {
				color = sf::Color::Black;
			}
			else if (c == "Green") {
				color = sf::Color::Green;
			}
			else if (c == "Red") {
				color = sf::Color::Red;
			}
			else if (c == "Blue") {
				color = sf::Color::Blue;
			}
			else if (c == "Yellow") {
				color = sf::Color::Yellow;
			}
			else if (c == "Magenta") {
				color = sf::Color::Magenta;
			}
			else if (c == "Cyan") {
				color = sf::Color::Cyan;
			}
			else{
				throw (Exception("UNDEFINED COLOR " + c + " PLEASE TRY ANY OF THE FOLLOWING: White, Black, Red, Green, Yellow, Blue, Magenta, Cyan"));
			}
		}

		// read width
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception( file+ " HAS INVALID FORMAT"));
		}
		if (cls.first != "Width") {
			throw(Exception("EXPECTED Width but got " + cls.first + " IN FILE " + file));
		}
		else {
			width = atoi(cls.second.c_str());
		}
		// read height
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(file + " HAS INVALID FORMAT"));
		}
		if (cls.first != "Height") {
			throw(Exception("EXPECTED Height but got " + cls.first + " IN FILE " + file));
		}
		else {
			height = atoi(cls.second.c_str());
		}
		std::cout << "Width= " << width << " height= " << height << std::endl;

		// read Aliens per row
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception( file + " HAS INVALID FORMAT"));
		}
		if (cls.first != "AlienPerRow") {
			throw(Exception("EXPECTED AlienPerRow but got " + cls.first + " IN FILE " + file));
		}
		else {
			alienPerRow = atoi(cls.second.c_str());
		}

		// read nr of rows of aliens
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(file + " HAS INVALID FORMAT"));
		}
		if (cls.first != "NrAlienRows") {
			throw(Exception("EXPECTED NrAlienRows but got " + cls.first + " IN FILE " + file));
		}
		else {
			nrAlienRows = atoi(cls.second.c_str());
		}

		// read nr of Alien 1 rows
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(file + " HAS INVALID FORMAT"));
		}
		if (cls.first != "NrAlien1") {
			throw(Exception("EXPECTED NrAlien1 but got " + cls.first + " IN FILE " + file));
		}
		else {
			nrAlien1 = atoi(cls.second.c_str());
		}

		// read nr of Alien 2 rows
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(file + " HAS INVALID FORMAT"));
		}
		if (cls.first != "NrAlien2") {
			throw(Exception("EXPECTED NrAlien2 but got " + cls.first + " IN FILE " + file));
		}
		else {
			nrAlien2 = atoi(cls.second.c_str());
		}

		// read nr of Alien 3 rows
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(file+ " HAS INVALID FORMAT"));
		}
		if (cls.first != "NrAlien3") {
			throw(Exception("EXPECTED NrAlien3 but got " + cls.first + " IN FILE " + file));
		}
		else {
			nrAlien3 = atoi(cls.second.c_str());
		}

		if (nrAlien1+nrAlien2+nrAlien3 != nrAlienRows) {
			throw (Exception("nrAlien1+nrAlien2+nrAlien3 SHOULD EQUAL nrAlienRows"));
		}

		// Read NrBunkers
		line.clear();
		getline(in, line);
		try {
			cls = utility::splitAtEq(line);
		}
		catch(...) {
			throw(Exception(file+ " HAS INVALID FORMAT"));
		}
		if (cls.first != "NrBunkers") {
			throw(Exception("EXPECTED NrBunkers but got " + cls.first + " IN FILE " + file));
		}
		else {
			nrBunkers = atoi(cls.second.c_str());
		}


		// read }
		line.clear();
		getline(in, line);
		if (line.at(0) != '}') {
			throw(Exception("EXPECTED } but got " + line + " IN FILE " + file));
		}
	}

}


