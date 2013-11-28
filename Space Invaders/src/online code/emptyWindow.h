#include <SFML/Graphics.hpp>
#include <iostream>

void emptyWindow()
{
	/*
	 * create an empty window
	 */


	std::cout << "What color do you want? " << "\n";
	std::cout << "enter the red component \t" ;
	int red, blue, green;
	std::cin >> red;
	std::cout << "enter the green component \t";
	std::cin >> green;
	std::cout << "enter the blue component \t";
	std::cin >> blue;

	std::cout << "you chose " << red << " , " << green << " , " << blue << " as your color \n enjoy \n";

	sf::VideoMode VMode(800,600,32);	//	800 by 600 window, 32 bit color
	sf::RenderWindow window(VMode, "SFML Tutorial - Empty window" );


	while (window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			switch(event.type)
			{
			case(sf::Event::Closed):
				window.close();
				break;
			default:
				break;
			}
		}
		window.clear(sf::Color(red,green,blue));
		window.display();
	}
}
