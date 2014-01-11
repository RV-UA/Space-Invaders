
#include <iostream>
#include "utilities.h"
#include "read.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include "EntityFactory.h"
#include "GameFactory.h"
#include "gameView.h"
#include "gameController.h"
using std::cout;
using std::endl;
int main()
{
	srand(time(0));

	game::GameFactory gf;

	std::shared_ptr<game::GameModel> gm = gf.createGameModel("field");

	game::GameController controller(gm);
	game::GameView viewer(gm);

	sf::VideoMode videoMode(viewer.getWidth(), viewer.getHeight());
	sf::RenderWindow window(videoMode,"Space Invaders");

	//sf::Text lost("Hope this works");


	try {

	while (window.isOpen()) {
		controller.startCycle();
		if (viewer.lost()) {
			std::cout << "lost" << std::endl;
			window.close();
			sf::Event event;
			while (window.pollEvent(event))
			{
				if ( (event.type == sf::Event::Closed) ||
					((event.type == sf::Event::KeyPressed) && (event.key.code==sf::Keyboard::Escape)) )
					window.close();
			}
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
		std::cout << e.what() << std::endl;
		throw(0);
	}


	cout << "============="<<endl;
	cout << "Program Ended" << endl;


}
