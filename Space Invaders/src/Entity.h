/*
 * Entity.h
 *
 *  Created on: Nov 19, 2013
 *      Author: robin
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <utility>
#include <SFML/Graphics.hpp>

namespace objects {

typedef std::pair<unsigned int, unsigned int> Position; 	// position in the grid
enum MoveDirection{right = 0, left, down, up, none};

class DrawEntity {
public:
	//! A default constructor
	DrawEntity();
	//! A constructor taking as only parameter the position
	/**
	 * @param p the position of the rightmost corner of the object
	 */
	DrawEntity(Position p);
	//! A constructor taking all necessary attributes
	/**
	 * @param p the position of the rightmosr corner of the object
	 * @param width the width of the object
	 * @param height the height of the object
	 * @param c the color in which the object will be drawn
	 */
	DrawEntity(Position p, unsigned int width, unsigned int height, sf::Color c);

	//! A function to set the position
	void setPosition(Position p);
	//! A function to draw the object in the window
	/**
	 * @param w a window which will be used to display the game
	 */
	void draw(sf::RenderWindow& w);
private:
	//sf::Sprite sprite_;
	sf::RectangleShape rect_;	//! the shape drawn in the window

};


class Entity {
/*
 * A base class for all objects that influence the game
 */
public:
	//! A default constructor
	Entity();
	Entity(Position, sf::Color, double, MoveDirection, unsigned int, unsigned int);
	//! An empty destructor
	virtual ~Entity();
	//! A fuction used to draw the entity (pure virtual)
	virtual void draw(sf::RenderWindow& w) = 0;
	//! A function used to move the entity(pure virtual)
	virtual void move() = 0;
	//! A getter for position_
	virtual Position getPosition() const {return position_;}
	//! A getter for size_x_
	virtual unsigned int getSizeX() const {return size_x_;}
	//! A getter for size_y_
	virtual unsigned int getSizeY() const {return size_y_;}
	//! A getter for color_
	virtual sf::Color getColor() const {return color_;}
protected:
	Position position_;				//! the position of the rightmost corner of the entity
	const sf::Color color_;			//! the color of the entity
	const double speed_;			//! the speed at which the entity moves
	MoveDirection direction_;		//! the direction in which the entity moves
	const unsigned int size_x_;	//! the width of the entity
	const unsigned int size_y_;	//! the height of the entity
	DrawEntity sprite_;				//! the shape to be drawn
};

} /* namespace objects */

#endif /* ENTITY_H_ */
