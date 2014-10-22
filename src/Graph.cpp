#include "Graph.h"
#include <string>
#include <iostream>

// constructor initializing all the sfml objects necesary for drawing
//
Graph::Graph(Grafic* aux):
    RectInputNrDiv(sf::Vector2i(520,90),sf::Vector2i(150,60)),
    RectInputFunction(sf::Vector2i(385,260),sf::Vector2i(340,50)),
    RectInputCapatInfIntegrala(sf::Vector2i(150,350),sf::Vector2i(100,50)),
    RectInputCapatSupIntegrala(sf::Vector2i(150,185),sf::Vector2i(100,50)),
    RectInputGOButton(sf::Vector2i(340,445),sf::Vector2i(100,70))
{
    ind = 0;

    grafic = aux;

    font.loadFromFile("arial.ttf");

    TextNrDiv.setFont(font);
    TextNrDiv.setString("Numar Diviziuni:");
    TextNrDiv.setPosition(sf::Vector2f(80,80));
    TextNrDiv.setCharacterSize(60);
    TextNrDiv.setColor(sf::Color::Black);

    RSInputNrDiv.setSize(sf::Vector2f(150,60));
    RSInputNrDiv.setPosition(sf::Vector2f(520,90));
    RSInputNrDiv.setFillColor(sf::Color::White);

    TextIntegrala.setFont(font);
    TextIntegrala.setString("f(x)dx");
    TextIntegrala.setPosition(sf::Vector2f(150,260));
    TextIntegrala.setCharacterSize(40);
    TextIntegrala.setColor(sf::Color::Black);

    Textfx.setFont(font);
    Textfx.setString("f(x)=");
    Textfx.setPosition(sf::Vector2f(300,260));
    Textfx.setCharacterSize(40);
    Textfx.setColor(sf::Color::Black);

    ImageIntegralSign.loadFromFile("Integrala.png");
    ImageIntegralSign.setSmooth(1);
    SpriteIntegralSign.setTexture(ImageIntegralSign);
    SpriteIntegralSign.setPosition(50,200);
    SpriteIntegralSign.setScale(sf::Vector2f(0.9,0.9));

    TextCapatInfIntegrala.setFont(font);
    TextCapatInfIntegrala.setString("a=");
    TextCapatInfIntegrala.setPosition(sf::Vector2f(100,350));
    TextCapatInfIntegrala.setCharacterSize(35);
    TextCapatInfIntegrala.setColor(sf::Color::Black);

    TextCapatSupIntegrala.setFont(font);
    TextCapatSupIntegrala.setString("b=");
    TextCapatSupIntegrala.setPosition(sf::Vector2f(100,185));
    TextCapatSupIntegrala.setCharacterSize(35);
    TextCapatSupIntegrala.setColor(sf::Color::Black);

    RSInputFunction.setSize(sf::Vector2f(340,50));
    RSInputFunction.setPosition(sf::Vector2f(385,260));
    RSInputFunction.setFillColor(sf::Color::White);

    RSInputCapatInfIntegrala.setSize(sf::Vector2f(100,50));
    RSInputCapatInfIntegrala.setPosition(sf::Vector2f(150,350));
    RSInputCapatInfIntegrala.setFillColor(sf::Color::White);

    RSInputCapatSupIntegrala.setSize(sf::Vector2f(100,50));
    RSInputCapatSupIntegrala.setPosition(sf::Vector2f(150,185));
    RSInputCapatSupIntegrala.setFillColor(sf::Color::White);

    RSInputGOButton.setSize(sf::Vector2f(100,70));
    RSInputGOButton.setPosition(sf::Vector2f(340,445));
    RSInputGOButton.setFillColor(sf::Color::Yellow);

    TextGOButton.setFont(font);
    TextGOButton.setString("GO");
    TextGOButton.setPosition(sf::Vector2f(350,450));
    TextGOButton.setCharacterSize(50);
    TextGOButton.setColor(sf::Color::Black);

    TextInputNrDiv.setFont(font);
    TextInputNrDiv.setString("");
    TextInputNrDiv.setPosition(sf::Vector2f(520,90));
    TextInputNrDiv.setCharacterSize(50);
    TextInputNrDiv.setColor(sf::Color::Black);

    TextInputFunction.setFont(font);
    TextInputFunction.setString("");
    TextInputFunction.setPosition(sf::Vector2f(385,260));
    TextInputFunction.setCharacterSize(35);
    TextInputFunction.setColor(sf::Color::Black);

    TextInputIntegralaCapatInf.setFont(font);
    TextInputIntegralaCapatInf.setString("");
    TextInputIntegralaCapatInf.setPosition(sf::Vector2f(150,350));
    TextInputIntegralaCapatInf.setCharacterSize(35);
    TextInputIntegralaCapatInf.setColor(sf::Color::Black);

    TextInputIntegralaCapatSup.setFont(font);
    TextInputIntegralaCapatSup.setString("");
    TextInputIntegralaCapatSup.setPosition(sf::Vector2f(150,185));
    TextInputIntegralaCapatSup.setCharacterSize(35);
    TextInputIntegralaCapatSup.setColor(sf::Color::Black);
}



// after the "graph it" button was pushed the input is transformed from text type variables into number type variables
void Graph::check(){

    int semn=1;
    sf::String aux;
    aux = TextInputNrDiv.getString();
    for(int i=0;i<aux.getSize();i++){
        if(aux[i]>='0' && aux[i]<='9')
            grafic->div = grafic->div*10 + (aux[i]-'0');
        else if(aux[i]=='-')
            semn=-1;
    }
    grafic->div*=semn;

    semn=1;
    aux = TextInputIntegralaCapatInf.getString();
    //std::cout<<aux.toAnsiString()<<std::endl;
    for(int i=0;i<aux.getSize();i++){
        if(aux[i]>='0' && aux[i]<='9')
            grafic->capat_inf = grafic->capat_inf*10 + (aux[i]-'0');
        else if(aux[i]=='-')
            semn=-1;
    }
    grafic->capat_inf*=semn;

    semn=1;
    aux = TextInputIntegralaCapatSup.getString();
    //std::cout<<aux.toAnsiString()<<std::endl;
    for(int i=0;i<aux.getSize();i++){
        if(aux[i]>='0' && aux[i]<='9')
            grafic->capat_sup = grafic->capat_sup*10 + (aux[i]-'0');
        else if(aux[i]=='-')
            semn=-1;
    }
    grafic->capat_sup*=semn;

    aux = TextInputFunction.getString();
    grafic->fct = aux.toAnsiString();


}

//handling the input
int Graph::handleinput(sf::RenderWindow& window){

    sf::Event event;
    while(window.pollEvent(event)){

        // checking which rectangle is selected
        if(event.type == sf::Event::Closed)
            window.close();
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && RectInputNrDiv.contains(sf::Mouse::getPosition(window)))
            ind = 1;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && RectInputFunction.contains(sf::Mouse::getPosition(window)))
            ind = 2;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && RectInputCapatInfIntegrala.contains(sf::Mouse::getPosition(window)))
            ind = 3;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && RectInputCapatSupIntegrala.contains(sf::Mouse::getPosition(window)))
            ind = 4;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && RectInputGOButton.contains(sf::Mouse::getPosition(window))){
            check();
            grafic->initial();
            return 3;
        }

        //getting the text input from the selected rectangle and saving it in the selected sf::Text object
        if(event.type == sf::Event::TextEntered){

            //intermediary string needed for transport to sf::Text
            sf::String aux;

            if(ind == 1){
                sf::String aux;
                if(event.text.unicode == 8 && !TextInputNrDiv.getString().isEmpty()){
                    aux = TextInputNrDiv.getString();
                    aux.erase(aux.getSize()-1,1);
                    TextInputNrDiv.setString(aux);
                }
                else
                    TextInputNrDiv.setString(TextInputNrDiv.getString()+static_cast<char>(event.text.unicode));

            }
            if(ind == 2){
                if(event.text.unicode == 8 && !TextInputFunction.getString().isEmpty()){
                    aux = TextInputFunction.getString();
                    aux.erase(aux.getSize()-1,1);
                    TextInputFunction.setString(aux);
                }
                else
                    TextInputFunction.setString(TextInputFunction.getString()+static_cast<char>(event.text.unicode));
            }
            if(ind == 3){
                if(event.text.unicode == 8 && !TextInputIntegralaCapatInf.getString().isEmpty()){
                    aux = TextInputIntegralaCapatInf.getString();
                    aux.erase(aux.getSize()-1,1);
                    TextInputIntegralaCapatInf.setString(aux);
                }
                else
                    TextInputIntegralaCapatInf.setString(TextInputIntegralaCapatInf.getString()+static_cast<char>(event.text.unicode));
            }
            if(ind == 4){
                if(event.text.unicode == 8 && !TextInputIntegralaCapatSup.getString().isEmpty()){
                    aux = TextInputIntegralaCapatSup.getString();
                    aux.erase(aux.getSize()-1,1);
                    TextInputIntegralaCapatSup.setString(aux);
                }
                else
                    TextInputIntegralaCapatSup.setString(TextInputIntegralaCapatSup.getString()+static_cast<char>(event.text.unicode));
            }

        }
    }

}

// basic SFML drawing
void Graph::render(sf::RenderWindow& window){

    window.clear(sf::Color(163,73,164));

    window.draw(Background);
    window.draw(TextNrDiv);
    window.draw(RSInputNrDiv);
    window.draw(SpriteIntegralSign);
    window.draw(RSInputFunction);
    window.draw(RSInputCapatInfIntegrala);
    window.draw(RSInputCapatSupIntegrala);
    window.draw(RSInputGOButton);
    window.draw(TextGOButton);
    window.draw(TextInputNrDiv);
    window.draw(TextInputFunction);
    window.draw(TextCapatInfIntegrala);
    window.draw(TextCapatSupIntegrala);
    window.draw(TextIntegrala);
    window.draw(Textfx);
    window.draw(TextInputIntegralaCapatInf);
    window.draw(TextInputIntegralaCapatSup);

    window.display();

}

