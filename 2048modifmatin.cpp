#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <iomanip>
using namespace std;
using Plateau = vector<vector<int>>;

//////////////////////////////////////////////////
// MODIF DE LA FONCTION DEPLACEMENT DROITE (pour que les cases identiques s'assemblent) 
// CELLE DE GAUCHE (même chose + balayement différent des indices et fonctionne au top)
// ajout fonction dessinebis je retente dessine + tard
// ajout fonction estgagnant pas testé
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
        for (int k = 0; k < 4; k++){
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
    for(int i = 0; i < 2; i++){ //2 tours de boucle car 2 cases aléatoires
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
        for (int j = 0; j < plateau[i].size()-1; j++){
            if (plateau[i][j] == plateau[i][j+1]){
                plateau[i][j+1] = plateau[i][j+1] * 2;
                plateau[i][j] = 0;
            }
            if (plateau[i][j+1] == 0 and plateau[i][j] != 0){
                plateau[i][j+1] = plateau[i][j];
                plateau[i][j] = 0;
            }
        }
    }
    return plateau;
}

Plateau déplacementGauche(Plateau plateau){
     for (int i =plateau.size() - 1; i >= 0; i--){
        for (int j = plateau[i].size() - 1; j >= 1; j--){
            if (plateau[i][j-1] == plateau[i][j]){
                plateau[i][j-1] = plateau[i][j-1] * 2;
                plateau[i][j] = 0;
            }
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
void dessinebis(Plateau p){
    int espacement = 5;
    for (int ligne = 0; ligne < p.size(); ligne++){
        for (int i = 0; i < espacement*4 + espacement; i++){
            cout << "*";
        }
        cout << endl;
        for (int colonne = 0; colonne < p[0].size(); colonne++){
            if (p[ligne][colonne] == 0){
                cout << "*" << setw(espacement) << " ";
            }
            else{
                cout << "*" << setw(espacement) << p[ligne][colonne];
            }
        }
        cout << "*" << endl;
    }
    for (int i = 0; i < espacement*4 + espacement; i++){
            cout << "*";
        }
    cout << endl;
}

bool estGagnant(Plateau plateau){
    for(int i = 0; i < plateau.size(); i++){
        for (int k = 0; k < plateau[0].size(); k++){
            if (plateau[i][k] == 2048){
                return true;
            }
        }
    }
    return false;
}
int main(){
    char Touche;
    cout << "Test rapide que les fonctions marchent..." << endl;
    cout << "Affichage du plateau vide..." << endl;
    dessinebis(plateauVide());
    cout << "Affichage du plateau initial..." << endl;
    Plateau t2;
    Plateau t4;
    t2 = plateauInitial();
    t4 = plateauInitial();
    dessinebis(t2);
    dessinebis(t4);
    cout << "Ok, maintenant on teste de déplacer le tableau..." << endl;
    cout << "Entre Z,Q,S ou D pour déplacer le tableau..." << endl;
    cin >> Touche;
    dessinebis(déplacement(t4,Touche));
    dessinebis(déplacement(t2,Touche));
}
