#include <SFML/Graphics.hpp>

int images_and_sprites()
{
    sf::VideoMode VMode(800, 600, 32);
    sf::RenderWindow Window(VMode, "SFMLCoder Tutorial - Empty Window");

    sf::Texture texture;
    if (!texture.loadFromFile("./../image.png"))
        return 1;

    sf::Sprite Sprite;
    Sprite.setTexture(texture);
    Sprite.setPosition(100.0f, 30.0f);
    Sprite.setRotation(30.0f);
    Sprite.setScale(.5f, .3f);
    Sprite.setColor(sf::Color(255, 0, 0, 128));

    sf::Sprite Sprite2;
    Sprite2.setTexture(texture);
    Sprite2.setPosition(0.0f, 0.0f); // to reveal other sprites, change the values to 200.0f, 200.0f
    Sprite2.scale((float)VMode.width, (float)VMode.height); // to reveal other sprites, change the values to .8f, .8f

    sf::Texture texture2;
    if (!texture2.loadFromFile("./../graphics-sprites.png"))
        return 1;

    sf::Sprite Sprite3;
    Sprite3.setTexture(texture2);

    Sprite3.setPosition(100.0f, 50.0f);
    Sprite3.setScale(.4f, .4f);


    while (Window.isOpen())
    {
        sf::Event Event;
        while (Window.pollEvent(Event))
        {
            switch (Event.type)
            {
            case sf::Event::Closed:
                Window.close();
                break;
            default:
                break;
            }
        }

        Window.clear(sf::Color(0, 255, 255));

        Window.draw(Sprite3);
        Window.draw(Sprite);
        Window.draw(Sprite2);

        Window.display();

    }


    return 0;
}
