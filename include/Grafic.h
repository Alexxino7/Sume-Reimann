

// drawing the graph of the fucntion on the screen and the divisions
// there is no interaction with this screen besides closing the application


#ifndef GRAFIC_H
#define GRAFIC_H

#include "App.h"
#include <string>
#include "eval.h"

class Grafic : public App
{
    public:
        Grafic();

        // only handles the closed event
        virtual int handleinput(sf::RenderWindow&);

        // basic drawing
        virtual void render(sf::RenderWindow&);

        void initial();

    public:

        //
        double capat_inf,capat_sup,div,fmin,fmax;
        std::string fct;

        sf::View view;

        sf::VertexArray OX;
        sf::VertexArray OY;
        sf::VertexArray diviz;
        sf::VertexArray grafic;
        sf::VertexArray borders;
};

#endif // GRAFIC_H
