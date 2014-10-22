#include <SFML/Graphics.hpp>
#include "App.h"
#include "Menu.h"
#include "Graph.h"
#include "Grafic.h"


int main()
{

    //the only renderwindow object used troughout the program
    sf::RenderWindow window(sf::VideoMode(800,600,32),"Title");
    window.setFramerateLimit(60);

    //initailizing pointers of the application screens
    Menu* ShowingMenu = new Menu;
    Grafic* ShowingGrafic = new Grafic;
    Graph* ShowingGraph = new Graph(ShowingGrafic);

    //App object is the parent class of the screen classes and is used for changing what screen is showing
    //Menu is the first screen showing
    App* app;
    app = ShowingMenu;

    //the current screen is the one app is pointing to
    //each app->function is supra-defined in each subclass
    while(window.isOpen()){

        switch(app->handleinput(window)){
            case 1: app = ShowingMenu;break;
            case 2: app = ShowingGraph;break;
            case 3: app = ShowingGrafic;break;
            default: break;
        }
        app->render(window);

    }


    return EXIT_SUCCESS;
}
