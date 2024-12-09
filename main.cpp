#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include "2048.hpp"
#include <SFML/Graphics.hpp>
using namespace std;


int main(){
    srand(time(NULL));
    system("clear");
    ASCII2048();
    this_thread::sleep_for(chrono::seconds(2));
    Plateau t;
    char Touche; 
    t = plateauInitial();
    dessinebis(t);
    // HighScoreTXT();
    while(ConditionFinDeJeu(t)){
        cout << "Choisi une touche entre Z,Q,S,D !" << endl;
        cin >> Touche;
        t = déplacement(t,Touche);
        system("clear");
        ASCII2048();
        dessinebis(t);
        t = plateauPlacementAléatoire(t);
        system("clear");
        ASCII2048();
        dessinebis(t);
    }
}
