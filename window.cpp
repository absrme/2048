#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include "2048.hpp"
#include <SFML/Graphics.hpp>
using namespace std;

int main(){
    sf::RenderWindow window(sf::VideoMode(925, 925), "2048");
    window.setSize(sf::Vector2u(925,925));
    while (window.isOpen()){ 
        sf::Event event;
        while(window.pollEvent(event)){
            // Si l'on ferme la fenêtre
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        // Nettoie la fenêtre
        window.clear(sf::Color(185,173,161));
        sf::RectangleShape rectangle(sf::Vector2f(200.f, 200.f));
        rectangle.setFillColor(sf::Color(202,192,180));
        vector<int> x;
        x = {25, 250, 475, 700};
        for (auto abscisse:x){
            for (auto ordonnee:x){
                rectangle.setPosition(abscisse,ordonnee);
                window.draw(rectangle);
            }
        }
        rectangle.setFillColor(sf::Color(255,255,255));
        rectangle.setPosition(25,25);
        window.display();
        sf::Clock clock;
        sf:: Time elapsed = clock.restart();
        float speed = 0.1;
        rectangle.move(225, 0);
        window.draw(rectangle);
        // Rafraîchit la fenêtre
        window.display();
    }
}