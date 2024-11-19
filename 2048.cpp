#include <vector>
#include <string>
#include <iostream>
#include <random>
using namespace std;

using Plateau = vector<vector<int>>;

int tireDeuxOuQuatre(){
    int proba = 1 + rand() % 11;
    if (proba <= 9){
        return 2;
    }
    else {
        return 4;
    }
}

Plateau plateauVide(){
    Plateau t;
    t = Plateau(4);
    for (int i = 0; i < 4; i++){
        t[i] = vector<int>(4);
    }
    for (int i = 0; i < 4; i++){
        for (int k = 0; t[i].size() < 4; k++){
            t[i][k] = 0;
        }
    }
    return t;
}

Plateau plateauInitial(){
    Plateau t;
    t = plateauVide();
    int place = 0;
    while(place != 2){
        int ligne = 0 + rand() % 4;
        int colonne = 0 + rand() % 4;
        t[ligne][colonne] = tireDeuxOuQuatre();
        place++;
    }
    return t;
}
void affichePlateauTab(Plateau t){
    for (int i = 0; i < t.size();i++){
        for (int k = 0; k < t[i].size(); k++){
            cout << t[i][k] << " ";
        }
        cout << endl;
    }
}

Plateau déplacementDroite(Plateau plateau){
     for (int i = 0; i<plateau.size(); i++){
        for (int j = 0; j<plateau[i].size(); j++){
            if (plateau[i+1][j+1] == 0 or plateau[i][j]==plateau[i+1][j+1]){
                plateau[i+1][j+1] = plateau[i][j];
                plateau[i][j]==0;
            }
        }
    }
    return plateau;
}
Plateau déplacementHaut(Plateau plateau){
    for (int i = 0; i<plateau.size(); i++){
        for (int j = 0; j<plateau[i].size(); j++){
            if (plateau[i+1][j] == 0 or plateau[i][j]==plateau[i+1][j]){
                plateau[i+1][j] = plateau[i][j];
                plateau[i][j]==0;
            }
        }
    }
    return plateau;
}
int main(){
    affichePlateauTab(plateauVide());
    affichePlateauTab(plateauInitial());
}
