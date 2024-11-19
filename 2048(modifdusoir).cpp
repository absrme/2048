#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <random>
using namespace std;
using Plateau = vector<vector<int>>;

//////////////////////////////////////////////////
// LE PROGRAMME FONCTIONNE MAIS IL EST PAS TOP SUR LE RANDOM ET LE DEPLACEMENT
// L'ESSENTIEL Y EST MAIS JE SUIS TROP FATIGUé POUR CONTINUER
// COMPILE LE POUR VOIR LE PROBLEME DE RAND()
// go fuck yourselv
//////////////////////////////////////////////////

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
    int ligne;
    int colonne;
    t = plateauVide();
    for(int i = 0; i<2; i++){ //2 tours de boucle car 2 cases aléatoires
        ligne = rand() % 3; //indice de ligne aléatoire entre 0 et 3
        colonne = rand() % 3; //indice de colonne aléatoire entre 0 et 3
        t[ligne][colonne] = tireDeuxOuQuatre(); //la case du tableau aléatoire
    }
    return t; //retour du tableau
}
void affichePlateau(Plateau t){
    for (int i = 0; i < t.size();i++){
        for (int k = 0; k < t[i].size(); k++){
            cout << t[i][k] << " "; //affiche les cases du tableau de la ligne i
        }
        cout << endl; //retour à la ligne avant de passer à la ligne suivante
    }
}

Plateau déplacementDroite(Plateau plateau){
     for (int i = 0; i<plateau.size(); i++){
        for (int j = 0; j<plateau[i].size()-1; j++){
            if (plateau[i][j+1] == 0 or plateau[i][j]==plateau[i][j+1]){
                plateau[i][j+1] = plateau[i][j];
                plateau[i][j]=0;
            }
        }
    }
    return plateau;
}

Plateau déplacementGauche(Plateau plateau){
     for (int i = 0; i<plateau.size(); i++){
        for (int j = 1; j<plateau[i].size(); j++){
            if (plateau[i][j-1] == 0 or plateau[i][j-1]==plateau[i][j]){
                plateau[i][j-1] = plateau[i][j];
                plateau[i][j]=0;
            }
        }
    }
    return plateau;
}

Plateau déplacementHaut(Plateau plateau){
    for (int i = 0; i<plateau.size()-1; i++){
        for (int j = 0; j<plateau[i].size(); j++){
            if (plateau[i+1][j] == 0 or plateau[i][j]==plateau[i+1][j]){
                plateau[i+1][j] = plateau[i][j];
                plateau[i][j]=0;
            }
        }
    }
    return plateau;
}

Plateau déplacementBas(Plateau plateau){
    for (int i = 1; i<plateau.size(); i++){
        for (int j = 0; j<plateau[i].size(); j++){
            if (plateau[i-1][j] == 0 or plateau[i][j]==plateau[i-1][j]){
                plateau[i-1][j] = plateau[i][j];
                plateau[i][j]=0;
            }
        }
    }
    return plateau;
}

//////////////////////////////////////////////////////
//Je suppose pour celui-ci qu'on a déjà placé les inputs
//du style ZQSD !!!!!!!!!!!!!!
////////////////////////////////////////////////////////

Plateau déplacement(Plateau plateau, char Touche){
    if (Touche == 'z'){
        plateau = déplacementHaut(plateau);
        return plateau;
    }
    if (Touche == 'q'){
        plateau = déplacementGauche(plateau);
        return plateau;
    }
    if (Touche == 's'){
        plateau = déplacementBas(plateau);
        return plateau;
    }
    if (Touche == 'd'){
        plateau = déplacementDroite(plateau);
        return plateau;
    }
    cout << "La touche n'est pas reconnue..." << endl;
    return plateau;
}


int main(){
    char Touche;
    cout << "Test rapide que les fonctions marchent..." << endl;
    cout << "Affichage du plateau vide..." << endl;
    affichePlateau(plateauVide());
    cout << "Affichage du plateau initial..." << endl;
    affichePlateau(plateauInitial());
    cout << "Ok, maintenant on teste de déplacer le tableau..." << endl;
    cout << "Entre Z,Q,S ou D pour déplacer le tableau..." << endl;
    cin >> Touche;
    affichePlateau(déplacement(plateauInitial(),Touche));
}
