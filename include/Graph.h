

// Graph screen
// button interactions and writing interactions


#ifndef GRAPH_H
#define GRAPH_H

#include <App.h>
#include "Grafic.h"

class Graph : public App
{
    public:
        Graph(Grafic*);

        //supra-defined functions of parent class

        //handles the user interactions, clicks and writing events
        virtual int handleinput(sf::RenderWindow&);
        //basic sfml drawing
        virtual void render(sf::RenderWindow&);

        void check();

    private:
        int ind;
        Grafic* grafic;

        //sfml objects used for drawing
        sf::Font font;
        sf::Text TextNrDiv;
        sf::Text TextIntegrala;
        sf::Text TextGOButton;
        sf::Text TextInputNrDiv;
        sf::Text TextInputFunction;
        sf::Text TextCapatInfIntegrala;
        sf::Text TextCapatSupIntegrala;
        sf::Text Textfx;
        sf::Text TextInputIntegralaCapatInf;
        sf::Text TextInputIntegralaCapatSup;
        sf::Texture ImageIntegralSign;
        sf::Sprite SpriteIntegralSign;
        sf::RectangleShape Background;
        sf::RectangleShape RSInputNrDiv;
        sf::RectangleShape RSInputFunction;
        sf::RectangleShape RSInputCapatInfIntegrala;
        sf::RectangleShape RSInputCapatSupIntegrala;
        sf::RectangleShape RSInputGOButton;
        sf::Rect<int> RectInputNrDiv;
        sf::Rect<int> RectInputFunction;
        sf::Rect<int> RectInputCapatInfIntegrala;
        sf::Rect<int> RectInputCapatSupIntegrala;
        sf::Rect<int> RectInputGOButton;


};

#endif // GRAPH_H
