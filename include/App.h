

//The base class for the screen subclasses


#ifndef APP_H
#define APP_H

#include<SFML/Graphics.hpp>

class App{

    public:

        //virtual functions supra-defined in subclasses
        virtual int handleinput(sf::RenderWindow&) = 0;
        virtual void render(sf::RenderWindow&) = 0;

};

#endif // APP_H
