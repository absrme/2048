#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;
using Plateau = vector<vector<int>>;
Plateau déplacementDroite(Plateau plateau){
for (int i = 0; i<plateau.size(); i++){
        for (int j = 0; j<plateau[i].size(); j++){
            if (plateau[i+1][j+1] == 0 or plateau[i][j]==plateau[i+1][j+1]){
                plateau[i+1][j+1] = plateau[i][j];
                plateau[i][j]==0;
            }
        }
    }
}

Plateau prochainCoup(Plateau plateau, int ligne, int colonne, string direction, string mouvement){
    if (direction == "droite"){
        if (plateau[ligne][colonne] == plateau[ligne][colonne - 1] and mouvement == "somme"){
            plateau[ligne][colonne] *= 2;
        }
        else if (plateau[ligne][colonne] == 0 and plateau[ligne][colonne - 1] != 0 and mouvement == "glissement"){
            plateau[ligne][colonne] = plateau[ligne][colonne - 1];
        }
        else {
            return plateau;
        }
        plateau[ligne][colonne - 1] = 0;
        return plateau;
    }
    if (direction == "gauche"){
        if(plateau[ligne][colonne] == plateau[ligne][colonne + 1] and mouvement == "somme"){
            plateau[ligne][colonne] *= 2;
        }
        else if (plateau[ligne][colonne] == 0 and plateau[ligne][colonne + 1] != 0 and mouvement == "glissement"){
            plateau[ligne][colonne] = plateau[ligne][colonne + 1];
        }
        else {
            return plateau;
        }
        plateau[ligne][colonne + 1] = 0;
        return plateau;
    }
    if (direction == "bas"){
        if(plateau[colonne][ligne] == plateau[colonne - 1][ligne] and mouvement == "somme"){
            plateau[colonne][ligne] *= 2;
        }
        else if(plateau[colonne][ligne] == 0 and plateau[colonne - 1][ligne] != 0 and mouvement == "glissement"){
            plateau[colonne][ligne] = plateau[colonne - 1][ligne];
        }
        else {
            return plateau;
        }
        plateau[colonne - 1][ligne] = 0;
        return plateau;
    }
    if (direction == "haut"){
        if(plateau[colonne][ligne] == plateau[colonne + 1][ligne] and mouvement == "somme"){
            plateau[colonne][ligne] *= 2;
        }
        else if (plateau[colonne][ligne] == 0 and plateau[colonne + 1][ligne] != 0 and mouvement == "glissement"){
            plateau[colonne][ligne] = plateau[colonne + 1][ligne];
        }
        else {
            return plateau;
        }
        plateau[colonne + 1][ligne] = 0;
        return plateau;
    }
    return plateau;
}

void affichePlateau(Plateau t){
    for (int i = 0; i < t.size();i++){
        for (int k = 0; k < t[i].size(); k++){
            cout << t[i][k] << " "; //affiche les cases du tableau de la ligne i
        }
        cout << endl; //retour à la ligne avant de passer à la ligne suivante
    }
}
