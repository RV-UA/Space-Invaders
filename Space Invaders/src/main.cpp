
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

	std::shared_ptr<game::GameModel> gm = gf.createGameModel("../informationFiles/level1");
	std::shared_ptr<game::ModelPtr> ptr(new game::ModelPtr);
	ptr->model = gm;
	std::cout << "game Model made" << std::endl;
	game::GameController controller(ptr);
	std::cout << "game Controller made" << std::endl;
	game::GameView viewer(ptr);
	std::cout << "game viewer made " << std::endl;

	sf::VideoMode videoMode(viewer.getWidth(), viewer.getHeight());
	sf::RenderWindow window(videoMode,"Space Invaders");

	std::cout << "start while loop" << std::endl;
	std::clock_t t;

	unsigned int tps = CLOCKS_PER_SEC; // ticks per second
	unsigned int ticks = tps/50; // the nr of ticks for a 60th of a second
	try {

	while (window.isOpen()) {

		controller.startCycle();
		if (viewer.lost()) {
			viewer.draw(window);
			sf::Event event;
			while (window.pollEvent(event))
			{
				if ( (event.type == sf::Event::Closed) ||
					((event.type == sf::Event::KeyPressed) && (event.key.code==sf::Keyboard::Escape)) )
					window.close();
				else if ((event.type == sf::Event::KeyPressed) && (event.key.code==sf::Keyboard::Return)) {
					controller.restart();
				}
			}
		}
		else if (viewer.won()) {
			viewer.draw(window);
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
				else if ( (event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::P)) {
					controller.go();
				}
			}
		}



		else {
			t = clock();

			if (t % ticks != 0) {
				std::cout << "While skipped:" << std::endl;
				sf::Event event;
				while (window.pollEvent(event))
				{
					if ( (event.type == sf::Event::Closed) ||
						((event.type == sf::Event::KeyPressed) && (event.key.code==sf::Keyboard::Escape)) )
						window.close();
				}
				continue;
			}

			viewer.draw(window);
			sf::Event event;
			while (window.pollEvent(event))
			{
				if ( (event.type == sf::Event::Closed) ||
					((event.type == sf::Event::KeyPressed) && (event.key.code==sf::Keyboard::Escape)) )
					{window.close();}
				else if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::P) ) {
					std::cout << "Paused" << std::endl;
					controller.pause();
				}
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
