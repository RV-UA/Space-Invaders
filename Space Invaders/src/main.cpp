
#include <iostream>
#include "utilities.h"
#include "read.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include "EntityFactory.h"
#include "GameFactory.h"
#include "gameView.h"
#include "gameController.h"
#include <ctime>
using std::cout;
using std::endl;
int main()
{
	srand(time(0));

	game::GameFactory gf;

	std::shared_ptr<game::GameModel> gm = gf.createGameModel("../field");

	std::cout << "game Model made" << std::endl;
	game::GameController controller(gm);
	std::cout << "game Controller made" << std::endl;
	game::GameView viewer(gm);
	std::cout << "game viewer made " << std::endl;

	sf::VideoMode videoMode(viewer.getWidth(), viewer.getHeight());
	sf::RenderWindow window(videoMode,"Space Invaders");

	std::cout << "start while loop" << std::endl;
	std::clock_t t;

	unsigned int tps = CLOCKS_PER_SEC; // ticks per second
	unsigned int ticks = tps/50; // the nr of ticks for a 60th of a second
	try {

	while (window.isOpen()) {
		t = clock();

		if (t % ticks != 0) {
			sf::Event event;
			while (window.pollEvent(event))
			{
				if ( (event.type == sf::Event::Closed) ||
					((event.type == sf::Event::KeyPressed) && (event.key.code==sf::Keyboard::Escape)) )
					window.close();
			}
			continue;
		}

		controller.startCycle();
		if (viewer.lost()) {
			viewer.draw(window);
		}
		else if (viewer.won()) {
			window.close();
		}
		else if (viewer.paused()) {
			std::cout << "paused" << std::endl;
			sf::Event event;
			while (window.pollEvent(event))
			{
				if ( (event.type == sf::Event::Closed) ||
					((event.type == sf::Event::KeyPressed) && (event.key.code==sf::Keyboard::Escape)) )
					window.close();
				else if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::P)) {
					controller.go();
				}
			}
		}
		else {
			viewer.draw(window);
			sf::Event event;
			while (window.pollEvent(event))
			{
				if ( (event.type == sf::Event::Closed) ||
					((event.type == sf::Event::KeyPressed) && (event.key.code==sf::Keyboard::Escape)) )
					window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				controller.moveGun(objects::left);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				controller.moveGun(objects::right);
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				controller.fireGun();
			}
			// move all objects;
			controller.moveAndFire();

			controller.check();
		}
	}
	}
	catch(Exception& e) {
		std::cout << "error: " << e.what() << std::endl;
		throw(0);
	}


	cout << "============="<<endl;
	cout << "Program Ended" << endl;


}
