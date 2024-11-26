#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <iomanip>
#include <curses.h> // ajout curses.h jsp pq pour l'instant 
#include <cstdio>
using namespace std;
using Plateau = vector<vector<int>>;
// !!!!!!!!!!!!! SUPER IMPORTANT !!!!!!!!!!!!! si tu veux compiler, il faut rajouter -lncurses en argument
// pour la bibliothèque curses.h :
// sudo apt-get install libncurses5-dev libncursesw5-dev
// Petite modification à faire sur le score pour avoir le changement seulement lorsque deux cases se somment
// Rattraper le cas lorsque l'utilisateur ne mets pas un char
// Manque fonct° s'il n'y a plus de mouvements possible
void ASCII2048(){
    cout << R"(

                                              ,---.-,    
                                       ,--,  '   ,'  '.  
          ,----,     ,----..         ,--.'| /   /      \ 
        .'   .' \   /   /   \     ,--,  | :.   ;  ,/.  : 
      ,----,'    | /   .     : ,---.'|  : ''   |  | :  ; 
      |    :  .  ;.   /   ;.  \;   : |  | ;'   |  ./   : 
      ;    |.'  /.   ;   /  ` ;|   | : _' ||   :       , 
      `----'/  ; ;   |  ; \ ; |:   : |.'  | \   \     /  
        /  ;  /  |   :  | ; | '|   ' '  ; :  ;   ,   '\  
       ;  /  /-, .   |  ' ' ' :\   \  .'. | /   /      \ 
      /  /  /.`| '   ;  \; /  | `---`:  | '.   ;  ,/.  : 
    ./__;      :  \   \  ',  /       '  ; |'   |  | :  ; 
    |   :    .'    ;   :    /        |  : ;'   |  ./   : 
    ;   | .'        \   \ .'         '  ,/ |   :      /  
    `---'            `---`           '--'   \   \   .'   
                                             `---`-'     
    
    )" << endl;
}


void Tutoriel(){
    char reponse;
    cout << "Bienvenue sur le 2048 de Huỳnh anh et Auguste ! " << endl;
    cout << "Connais-tu les règles du jeu ? [o/n]" << endl;
    cin >> reponse;
    while(true){
        if (reponse == 'X'){
            cout << "super" << endl;
            break;
        } 
        if (reponse == 'n'){
            cout << "C'est un jeu de plateau 4x4 qui contient des puissances de 2 !";
            cout << " Tu peux déplacer ces puissances en utilisant les touches du clavier Z,Q,S ou D";
            cout << " et si deux tuiles sont adjacentes et que le glissement des tuiles est dans ";
            cout << "la bonne direction, alors, tu gagnes des points et elles se combinent ! ";
            cout << "À chaque déplacement, une nouvelle puissance apparaît, à toi de jouer maintenant !" << endl;
            break;
        }
        if (reponse == 'o'){
            cout << "OK ! Que le jeu commence !" << endl;
            cout << "C'est parti !" << endl;
            break;
        }
        else { while (reponse != 'n' and reponse != 'o'){
               cout << "Choisis bien entre o (oui) et n (non) !" << endl;
               cin >> reponse;
            break;
     }}
}}

int Score(Plateau plateau){
    int score = 0;
    for(int i = 0; i<plateau.size(); i++){
        for (int j = 0; j<plateau[i].size(); j++){
            score = score + plateau[i][j];
        }
    }
    return score;
}
int tireDeuxOuQuatre(){
    int proba = 1 + rand() % 10;
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
        ligne = rand() % 4; //indice de ligne aléatoire entre 0 et 3
        colonne = rand() % 4; //indice de colonne aléatoire entre 0 et 3
        t[ligne][colonne] = tireDeuxOuQuatre(); //la case du tableau aléatoire
    }
    return t; //retour du tableau
}

Plateau plateauPartie(Plateau t){
    int ligne; 
    int colonne;
    while (true){
        ligne = rand() % 4;
        colonne = rand () % 4;
        if (t[ligne][colonne] == 0){ // Si la case est vide, place le nombre tiré aléatoirement
            t[ligne][colonne] = tireDeuxOuQuatre();
            break;
        }
    }
    return t;
}

// void affichePlateau(Plateau t){
//     for (int i = 0; i < t.size();i++){
//         for (int k = 0; k < t[i].size(); k++){
//             cout << t[i][k] << " "; //affiche les cases du tableau de la ligne i
//         }
//         cout << endl; //retour à la ligne avant de passer à la ligne suivante
//     }
// }


Plateau déplacementDroite(Plateau plateau){
    for(int i = 0; i < plateau.size();i++){
        int rep = 0;
        while (rep != 3){
            for (int j = plateau[i].size() - 1; j > 0 ; j--){
                if (plateau[i][j-1] == plateau[i][j]){
                    plateau[i][j] *= 2;
                    plateau[i][j-1] = 0;
                }
                if (plateau[i][j-1] != 0 and plateau[i][j] == 0){
                    plateau[i][j] = plateau[i][j-1];
                    plateau[i][j-1] = 0;
                }
            }
            rep++;
        }
    }
    return plateau;
}
Plateau déplacementGauche(Plateau plateau){
     for (int i =0; i < plateau.size(); i++){
        int répétition = 0;
        while(répétition != 3){ // Permet de s'assurer que toutes les cases sont différentes et bien placés
            for (int j = 0; j < plateau[i].size() - 1; j++){
                if (plateau[i][j+1] == plateau[i][j]){
                    plateau[i][j] *= 2;
                    plateau[i][j+1] = 0;
                }
                if (plateau[i][j] == 0 and plateau[i][j+1] != 0){
                    plateau[i][j] = plateau[i][j+1];
                    plateau[i][j+1] = 0;
                }
            }
            répétition++;
        }
    }
    return plateau;
}

Plateau déplacementBas(Plateau plateau){
    for (int i = 0; i < plateau.size(); i++){
        int rep = 0;
        while (rep != 3){
            for (int j = plateau[i].size() - 1; j > 0; j--){
                if (plateau[j-1][i] == plateau[j][i]){ // Si la case d'au dessus est égale à la case actuelle dans la boucle
                    plateau[j][i] *= 2;
                    plateau[j-1][i] = 0;
                }
                if (plateau[j-1][i] != 0 and plateau[j][i] == 0){
                    plateau[j][i] = plateau[j-1][i];
                    plateau[j-1][i] = 0;
                }
            }
            rep++;
        }
    }
     return plateau;
}

Plateau déplacementHaut(Plateau plateau){
    for (int i = 0; i<plateau.size(); i++){
        int loop = 0;
        while (loop != 3){
            for (int j = 0; j<plateau[i].size() - 1; j++){
                if (plateau[j][i] == plateau[j+1][i]){
                    plateau[j][i] *= 2;
                    plateau[j+1][i] = 0;
                }
                if (plateau[j][i] == 0 and plateau[j+1][i] != 0){
                    plateau[j][i] = plateau[j+1][i];
                    plateau[j+1][i] = 0;
                }
            }
            loop++;
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
        cout << "Score : " << Score(plateau)  << endl;
        return plateau;
    }
    if (Touche == 'q'){
        plateau = déplacementGauche(plateau);
        cout << "Score : " << Score(plateau)  << endl;
        return plateau;
    }
    if (Touche == 's'){
        plateau = déplacementBas(plateau);
        cout << "Score : " << Score(plateau)  << endl;
        return plateau;
    }
    if (Touche == 'd'){
        plateau = déplacementDroite(plateau);
        cout << "Score : " << Score(plateau)  << endl;
        return plateau;
    }
    cout << "La touche n'est pas reconnue..." << endl;
    return plateau;
}
void dessinebis(Plateau p){
    int espacement = 5; // Taille d'une case (longueur en cractères)
    for (int ligne = 0; ligne < p.size(); ligne++){
        for (int i = 0; i < espacement * 4 + 5; i++){ // 4 * la taille d'une case pour les 4 cases + la séparation des cases et extremités
            cout << "*"; // Première ligne de "*"
        }
        cout << endl;
        for (int colonne = 0; colonne < p[0].size(); colonne++){
            if (p[ligne][colonne] == 0){
                cout << "*" << setw(espacement) << " "; // Reserve un espace de "espacement" ; cas vide donc ne n'affiche aucun entier
            }
            else{
                string valeur = to_string(p[ligne][colonne]);
                int taille = (to_string(p[ligne][colonne])).size();
                if (taille == 1){ // Si p[ligne][colonne] < 10 (composé de 1 ou 2 chiffres)
                    valeur.push_back(' ');
                    valeur.push_back(' ');
                }
                else if (taille <= 4){ // Si p[ligne][colonne] < 10000 (le nombre contient 3 ou 4 chiffres)
                    valeur.push_back(' ');
                }
                cout << "*" << setw(espacement) << valeur;
            }
        }
        cout << "*" << endl;
    }
    for (int i = 0; i < espacement * 4 + 5; i++){
            cout << "*"; // Dernière ligne de "*"
        }
    cout << endl;
}
bool estEgal(Plateau plateau, Plateau plateau1){
    for (int i = 0; i < plateau.size(); i++){
        for (int j = 0; j < plateau[i].size(); j++){
            if (plateau[i][j] != plateau1[i][j]){
                return false;
            }
        }
    }
    return true;
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
void test(){
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
    dessinebis(déplacement(t2,Touche));
    dessinebis(déplacement(t4,Touche));
}

void testVilain(){
    vector<vector<int>>(t);
    t = vector<vector<int>>(4);
    t = {{0,0,0,0},{0,0,4,16},{0,0,0,0},{0,0,0,0}};
    if (estEgal(déplacementDroite({{0,0,0,0},{2,2,8,8},{0,0,0,0},{0,0,0,0}}),t)){
        cout << "yeepee" << endl;
    }
    t = {{0,0,0,0},{0,0,4,8},{0,0,0,0},{0,0,0,0}};
    if (estEgal(déplacementDroite({{0,0,0,0},{0,4,4,4},{0,0,0,0},{0,0,0,0}}),t)){
        cout << "yeepee" << endl;
    }
    t = {{2048,0,16,10000},{0,0,4,16},{0,32,0,0},{0,4096,128,0}};
    dessinebis(t);
}

int main(){
    Tutoriel();
    // Déroulement d'une partie 
    Plateau t;
    char Touche; 
    t = plateauInitial();
    dessinebis(t);
    while(true){
        cout << "Choisi une touche entre Z,Q,S,D !" << endl;
        cin >> Touche;
        t = déplacement(t,Touche);
        cout << "Voici le plateau après ton déplacement !" << endl;
        dessinebis(déplacement(t,Touche));
        t = plateauPartie(t);
        cout << "Voici le tableau après un placement aléatoire !" << endl;
        dessinebis(t);
    }
    // testVilain();
}

