
#include <iostream>
#include "utilities.h"
#include "read.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include "EntityFactory.h"
using std::cout;
using std::endl;
int main()
{
	srand(time(0));
	cout << "Program Started" << endl;
	cout << endl;
	// setup all elements of playing field:
	cout << "Setting up playing field" << endl;
		// setup aliens
		cout << "\tSetting up aliens" << endl;
		// setup bunkers
		cout << "\tSetting up bunkers" << endl;
		// setup gun
		cout << "\tSetting up gun" << endl;

	cout << endl;
	// start playing:
	cout << "Starting playing" << endl;
		// read input
		cout << "\t" << "reading input" << endl;
		// handling input
		cout << "\t" << "handling input" << endl;
		// move and fire aliens
		cout << "\t" << "aliens moving and firing" << endl;
		// check for hits by bullets
		cout << "\t" << "checking hits by bullets" << endl;
			cout << "\t\t" << "checking gun" << endl;
			cout << "\t\t" << "checking aliens" << endl;
			cout << "\t\t" << "checking bunkers" << endl;
		// update playing screen
		cout << "\t" << "updating screen" << endl;
		// checking end conditions
		cout << "\t" << "checking end conditions" << endl;
	cout << endl;
	// breaking down game
	cout << "Break down" << endl;
	cout << endl;

	/*cout << "testing splitAtEq" << endl;
	std::string test = "hier=daar";
	std::pair<std::string, std::string> rec = utility::splitAtEq(test);
	cout << rec.first << endl;
	cout << rec.second << endl;*/

	bool win = false;	// set to true if all aliens are dead;
	bool dead = false;	// set to true if gun is hit
	bool lose = false; // set to true if all lives are gone


	unsigned int width = 0;
	unsigned int height= 0;
	sf::Color bgColor;

	objects::EntityFactory ef;

	int alienPerRow, nrAlienRows, alien1, alien2, alien3, nrBunkers;

	parse::readWindow("field", width, height, bgColor, alienPerRow, nrAlienRows, alien1, alien2, alien3, nrBunkers);

	sf::Text won("You have won this game.\n\n Congratulations !");
	won.setPosition(width/2-won.getGlobalBounds().width/2,height/2-won.getGlobalBounds().height/2);
	won.setColor(sf::Color::Green);

	sf::Font mb;
	mb.loadFromFile("arial.ttf");
	sf::Text lost("lost", mb, 10);
	lost.setPosition(width/2-lost.getGlobalBounds().width/2,height/2-lost.getGlobalBounds().height/2);
	//lost.setPosition(250, 100);
	lost.setColor(sf::Color::Cyan);

	std::vector<std::shared_ptr<objects::Alien> > aliens;
	std::vector<std::shared_ptr<objects::Bunker> > bunkers;
	std::vector<std::shared_ptr<objects::Bullet> > bullets;

	std::shared_ptr<objects::Alien> tempAlien( ef.createAlien("Alien1"));
	int alienWidth = tempAlien->getSizeX();
	int alienHeight = tempAlien->getSizeY();
	int space_Aliens_x = (width - 200 - alienPerRow*alienWidth) / (alienPerRow-1);
	int space_Aliens_y = 50;

	// set aliens on their right positions
	int count = 0;
	for (int i = 0; i < nrAlienRows; i++) {
		for (int j = 0; j < alienPerRow; j++) {
			aliens.push_back(ef.createAlien("Alien1"));

			objects::Position pos = aliens.at(count)->getPosition();
			pos.first+= 50 + j*space_Aliens_x + j* alienWidth;
			pos.second += 10 + i* space_Aliens_y + i * alienHeight;

			aliens.at(count)->setPosition(pos);
			count++;
		}
	}

	std::shared_ptr<objects::Bunker> tempBunker( ef.createBunker("Bunker"));
	int bunkerWidth = tempBunker->getSizeX();
	int space_Bunker_x = (width - 100 - nrBunkers*bunkerWidth) / (nrBunkers-1);


	// set Bunkers on their right positions
	for (int i = 0; i < nrBunkers; i++) {
		bunkers.push_back(ef.createBunker("Bunker"));

		objects::Position pos = bunkers.at(i)->getPosition();
		pos.first = 50 + (i)*space_Bunker_x + (i)* bunkerWidth;

		bunkers.at(i)->setPosition(pos);
	}


	sf::VideoMode videoMode(width, height);
	sf::RenderWindow window(videoMode,"Space Invaders");

	//sf::Text lost("Hope this works");

	std::shared_ptr<objects::Gun> gun = ef.createGun("Gun");
	//bunkers.push_back(parse::readBunker("Bunker"));


	int time_fired = 0;

	try {

	while (window.isOpen()){
		window.clear(bgColor);
		// check endOfGame
		if (win) {
			std::cout << "YOU WON !!!"<< std::endl;
			break;
		}
		else if (lose) {
			window.clear(sf::Color::Red);
			window.draw(lost);
			window.display();
			//std::cout << "YOU LOST !!!" << std::endl;
			sf::Event event;
			while (window.pollEvent(event))
			{
				if ( (event.type == sf::Event::Closed) ||
					((event.type == sf::Event::KeyPressed) && (event.key.code==sf::Keyboard::Escape)) )
					window.close();
			}
			//break;
		}
		else {
			if (dead) {
				std::cout << "You lost 1 live!" << std::endl;
				// TODO add "dead" gun
				dead = false;
			}
			gun->draw(window);
			for (auto b : bullets) {
				b->draw(window);
			}
			for (auto a : aliens) {
				a->draw(window);
			}
			for (auto b : bunkers) {
				b->draw(window);
			}
			window.display();

			sf::Event event;
			while (window.pollEvent(event))
			{
				if ( (event.type == sf::Event::Closed) ||
					((event.type == sf::Event::KeyPressed) && (event.key.code==sf::Keyboard::Escape)) )
					window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				gun->setMove(objects::left);
				gun->move();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				gun->setMove(objects::right);
				gun->move();
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				if (time_fired == 0) {
					bullets.push_back(gun->fire());
					time_fired = 40;
				}
			}
			if (time_fired > 0) {
				time_fired --;
			}
			// move all objects;
			for (auto c : aliens) {
				c->move();
			}
			for (auto b : bullets) {
				b->move();
			}

			// fire aliens

			for (auto a : aliens) {
				bool fire = true;
				for (auto b : aliens) {
					if ((b->getPosition().first == a->getPosition().first) && (b->getPosition().second > a->getPosition().second)) {
						fire = false;
						}
					}
				if (fire) {
					std::shared_ptr<objects::Bullet> temp(a->fire());
					if (temp != nullptr) {
						bullets.push_back(temp);
					}
				}
			}

			// check for gun in screen

			if ((gun->getPosition().first <= gun->getSpeed()) ) {
				gun->setPosition(objects::Position(gun->getSpeed(),gun->getPosition().second));
			}
			else if (gun->getPosition().first > width-gun->getSizeX()) {
				gun->setPosition(objects::Position(width-gun->getSizeX(), gun->getPosition().second));
			}

			// check for bullets out of screen
			for (unsigned int i = 0; i < bullets.size(); i++)
			{
				if ((bullets.at(i)->getPosition().first < 0) || (bullets.at(i)->getPosition().first > width)) {
					bullets.erase(bullets.begin()+i);
					i--;
				}
				else if ((bullets.at(i)->getPosition().second < 0) || (bullets.at(i)->getPosition().second > height)) {
					bullets.erase(bullets.begin()+i);
					i--;
				}
				else {
					// nothing wrong
					continue;
				}
			}
			// check for aliens out of screen
			for (unsigned int i = 0; i < aliens.size(); i++)
			{
				if ((aliens.at(i)->getPosition().second < 0) || (aliens.at(i)->getPosition().second > height)) {
					aliens.erase(aliens.begin()+i);
					i--;
				}
				else if ((aliens.at(i)->getPosition().first < 0) || (aliens.at(i)->getPosition().first > width)) {
					aliens.erase(aliens.begin()+i);
					i--;
				}
				else {
					// nothing wrong
					continue;
				}
			}

			// check for bullets hitting bunkers
			for (unsigned int i = 0; i< bullets.size(); i++) {
				for (unsigned int j = 0; j < bunkers.size(); j++) {
					bool hit = utility::intersects(bullets.at(i), bunkers.at(j));
					if (hit) {
						bullets.erase(bullets.begin()+i);
						i--;
						bunkers.at(j)->hit();
						if (!bunkers.at(j)->alive()) {	// check for destroyed bunkers
							bunkers.erase(bunkers.begin()+j);
							j--;
						}
						break;
					}
				}
			}

			// check for bullets hitting aliens		not those fired by aliens
			for (unsigned int i = 0; i< bullets.size(); i++) {
				for (unsigned int j = 0; j < aliens.size(); j++) {
					if (bullets.at(i)->getDirection() == objects::down) {
						break;
					}
					bool hit = utility::intersects(bullets.at(i), aliens.at(j));
					if (hit) {
						bullets.erase(bullets.begin()+i);
						i--;
						aliens.erase(aliens.begin()+j);
						j--;
						break;
					}
				}
			}

			// check for bullets hitting gun 	not those fired by gun
			for (unsigned int i = 0; i< bullets.size(); i++) {
				if (bullets.at(i)->getDirection() == objects::up) {
					continue;
				}
				bool hit = utility::intersects(bullets.at(i), gun);
				if (hit) {
					gun->liveDecr();
					bullets.erase(bullets.begin()+i);
					i--;
					dead = true;
					if (gun->getLives() <= 0) {
						lose = true;
					}
				}
			}
			//TODO check for aliens hitting gun
			for (unsigned int i = 0; i< aliens.size(); i++) {
				bool hit = utility::intersects(aliens.at(i), gun);
				if (hit) {
					lose = true;
					//gun->liveDecr();
					aliens.erase(aliens.begin()+i);
					break;
				}
			}

			// check nr of aliens left:
			// if 0 -> print win screen (now still exit)
			if (aliens.size() == 0) {
				win = true;
			}
		}
	}
	}
	catch(Exception& e) {
		std::cout << e.what() << std::endl;
		throw(0);
	}


	cout << "============="<<endl;
	cout << "Program Ended" << endl;


}
