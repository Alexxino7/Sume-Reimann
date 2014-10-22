

// first screen showing
// inherits from App class


#ifndef MENU_H
#define MENU_H

#include "App.h"

class Menu : public App
{
    public:
        Menu();

        //supra-defined functions of parent class

        //handles the user input, only left-clicks
        virtual int handleinput(sf::RenderWindow&);
        // basic sfml drawing
        virtual void render(sf::RenderWindow&);

    //sfml obects used for drawing
    private:
        sf::Font font;
        sf::RectangleShape MenuButton;
        sf::Text TextMenuButton;
        sf::Rect<int> RectMenuButton;
};

#endif // MENU_H
