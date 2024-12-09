#include <iostream>
#include "2048.hpp"
using namespace std;

void testdéplacement(){
    vector<vector<int>>(t);
    t = vector<vector<int>>(4);
    t = {{0,0,0,0},{0,0,4,16},{0,0,0,0},{0,0,0,0}};
    if (estEgal(déplacementDroite({{0,0,0,0},{2,2,8,8},{0,0,0,0},{0,0,0,0}}),t)){
        cout << "double coup !" << endl;
    }
    t = {{0,0,0,0},{0,0,4,8},{0,0,0,0},{0,0,0,0}};
    if (estEgal(déplacementDroite({{0,0,0,0},{0,4,4,4},{0,0,0,0},{0,0,0,0}}),t)){
        cout << "triple valeur !" << endl;
    }
    t = {{0,0,0,0},{0,0,2,4},{0,0,0,0},{0,0,0,0}};
    if (estEgal(déplacementDroite({{0,0,0,0},{2,2,0,2},{0,0,0,0},{0,0,0,0}}),t)){ // working OK
        cout << "bon balaiement du déplacement !" << endl;
    }
    t = {{0,0,4,4},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    if (estEgal(déplacementDroite({{2,2,2,2},{0,0,0,0},{0,0,0,0},{0,0,0,0}}),t)){ // working OK
        cout << "coup précis !" << endl;
    }
    t = {{0,0,4,4},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    if (estEgal(déplacementDroite({{0,2,2,4},{0,0,0,0},{0,0,0,0},{0,0,0,0}}),t)){
        cout << "déplacement réussi !" << endl;
    }
    // t = {{2048,0,16,10000},{0,0,4,16},{0,32,0,0},{0,4096,128,0}};
    // dessinebis(t);
    // t = {{0,0,0,2},{2,0,0,0},{2,0,0,0},{4,8,4,0}};
    // dessinebis(déplacementHaut(t));
}

void testFonctionnementJeu(){
    if (ConditionFinDeJeu({{0,0,0,0}, {2048, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}) == false){
        cout << "gagné !" << endl;
    }
    dessinebis({{2048,0,16,10000},{0,0,4,16},{0,32,0,0},{0,4096,128,0}});
}
int main(){
    testdéplacement();
    testFonctionnementJeu();
}