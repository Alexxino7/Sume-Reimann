#include "Menu.h"

//constructor is initializing the objects used for drawing
Menu::Menu():
    RectMenuButton(sf::Vector2i(300,150), sf::Vector2i(200,100))
{
    font.loadFromFile("arial.ttf");

    MenuButton.setSize(sf::Vector2f(200,100));
    MenuButton.setFillColor(sf::Color::Yellow);
    MenuButton.setPosition(300,150);

    TextMenuButton.setFont(font);
    TextMenuButton.setString("Grafic");
    TextMenuButton.setPosition(310,160);
    TextMenuButton.setCharacterSize(65);
    TextMenuButton.setColor(sf::Color::Blue);

}

// handling the input
// only close window event, and clicking the menu button
// the menu button gives the control of the app pointer to the graph object
int Menu::handleinput(sf::RenderWindow& window){

    sf::Event event;
    while(window.pollEvent(event)){

        if(event.type == sf::Event::Closed)
            window.close();

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && RectMenuButton.contains(sf::Mouse::getPosition(window)))
            return 2;

    }

}

// basic sfml drawing of objescts
void Menu::render(sf::RenderWindow& window){

    window.clear(sf::Color::Green);

    window.draw(MenuButton);
    window.draw(TextMenuButton);

    window.display();

}


