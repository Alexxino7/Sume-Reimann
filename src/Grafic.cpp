#include "Grafic.h"
#include <map>
#include <iostream>
#include <vector>


Grafic::Grafic():
    grafic(sf::LinesStrip),
    OX(sf::LinesStrip),
    OY(sf::LinesStrip),
    diviz(sf::Quads),
    borders(sf::Lines)
{
    capat_inf = capat_sup = div = 0;
    fct.clear();

    OX.append(sf::Vertex(sf::Vector2f(-10000,0),sf::Color::White));
    OX.append(sf::Vertex(sf::Vector2f(10000,0),sf::Color::White));
    OY.append(sf::Vertex(sf::Vector2f(0,-10000),sf::Color::White));
    OY.append(sf::Vertex(sf::Vector2f(0,10000),sf::Color::White));

}

void Grafic::initial(){

    init();
    std::vector<std::pair<float,float> > coords;
    std::map<std::string, float > aux;
    aux["e"]=e;
    aux["pi"]=PI;

    double val;

//    std::cout<<a <<" "<< b<< " "<< div;

    for(double i=capat_inf; i<=capat_sup; i+=(double)(capat_sup-capat_inf)/1000+0.0000001){
        aux["x"]=i;
        val = eval(fct, aux);
        std::cout << i <<" " << val << "\n";
        coords.push_back(std::make_pair(i,val));
    }

    for(int i=0;i<coords.size();i++)
        grafic.append(sf::Vertex(sf::Vector2f(coords[i].first,-coords[i].second),sf::Color::Red));

    double k = (capat_sup-capat_inf)/div;
    for(double i=capat_inf; i<capat_sup; i+=k+0.01){
        aux["x"]=i+k/2;
        diviz.append(sf::Vertex(sf::Vector2f(i,0),sf::Color::Green));
        diviz.append(sf::Vertex(sf::Vector2f(i,-eval(fct, aux)),sf::Color::Green));
        diviz.append(sf::Vertex(sf::Vector2f(i+k,-eval(fct, aux)),sf::Color::Green));
        diviz.append(sf::Vertex(sf::Vector2f(i+k,0),sf::Color::Green));
        borders.append(sf::Vertex(sf::Vector2f(i+k,0),sf::Color::Yellow));
        borders.append(sf::Vertex(sf::Vector2f(i+k,-eval(fct, aux)),sf::Color::Yellow));
    }

    view.setCenter(0,0);
    view.setSize(20,20);


}

int Grafic::handleinput(sf::RenderWindow& window){

    sf::Event event;

    while(window.pollEvent(event)){

        if(event.type == sf::Event::Closed){
            window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    {view.move( 0, -2.5); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  {view.move( 0,  2.5); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  {view.move(-2.5,  0); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {view.move( 2.5,  0); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract) ||  sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))    {view.zoom(1.1f);}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add) ||  sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))    {view.zoom(0.9f);}

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { std::cout<<sf::Mouse::getPosition(window).x <<" "<<sf::Mouse::getPosition(window).y<<"\n"; }

    }

}

void Grafic::render(sf::RenderWindow& window){

    window.setView(view);

    window.clear(sf::Color::Black);

    window.draw(diviz);
    window.draw(borders);

    window.draw(OX);
    window.draw(OY);

    window.draw(grafic);

    window.display();

}
