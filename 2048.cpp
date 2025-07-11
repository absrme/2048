#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <iomanip>
#include <curses.h> 
#include <cstdio>
#include <fstream> 
#include <chrono>
#include <thread>
#include "2048.hpp"

#define RESET   "\033[0m"
#define WHITE   "\033[37m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"

using namespace std;
using Plateau = vector<vector<int>>;

int score = 0;

void HighScoreTXT(){
    string nom;
    cout << "Quel est ton nom pour cette partie ?";
    cin >> nom;
    ofstream fichier;
    fichier.open("highscore.txt");
    if (fichier){
        fichier << nom << " ";
        fichier.close();
    }
    else {
        fichier << "erreur à l'ouverture de highscore.txt" << endl;
        fichier.close();
    }
}

void HighScoreFinal(int score){
    ofstream fichier;
    fichier.open("highscore.txt");
    if (fichier){
        fichier << score << endl;
        fichier.close();
    }
    else {
        cout << "erreur à l'ouverture de highscore.txt" << endl;
    }
}

void ASCII2048(){
    cout << GREEN << R"(

                                              ,---.-,    
                                       ,--,  '   ,'  '.  
          ,----,     ,----..         ,--.'| /   /      \.
        .'   .' \   /   /   \     ,--,  | :.   ;  ,/.  : 
      ,----,'    | /   .     : ,---.'|  : ''   |  | :  ; 
      |    :  .  ;.   /   ;.  \;   : |  | ;'   |  ./   : 
      ;    |.'  /.   ;   /  ` ;|   | : _' ||   :       , 
      `----'/  ; ;   |  ; \ ; |:   : |.'  | \   \     /  
        /  ;  /  |   :  | ; | '|   ' '  ; :  ;   ,   '\.  
       ;  /  /-, .   |  ' ' ' :\   \  .'. | /   /      \.
      /  /  /.`| '   ;  \; /  | `---`:  | '.   ;  ,/.  : 
    ./__;      :  \   \  ',  /       '  ; |'   |  | :  ; 
    |   :    .'    ;   :    /        |  : ;'   |  ./   : 
    ;   | .'        \   \ .'         '  ,/ |   :      /  
    `---'            `---`           '--'   \   \   .'   
                                             `---`-'     
    
    )" << RESET << endl;
}

void GameOver(){
    cout << GREEN << R"(

         ▗▄▄▖ ▗▄▖ ▗▖  ▗▖▗▄▄▄▖     ▗▄▖ ▗▖  ▗▖▗▄▄▄▖▗▄▄▖
        ▐▌   ▐▌ ▐▌▐▛▚▞▜▌▐▌       ▐▌ ▐▌▐▌  ▐▌▐▌   ▐▌ ▐▌
        ▐▌▝▜▌▐▛▀▜▌▐▌  ▐▌▐▛▀▀▘    ▐▌ ▐▌▐▌  ▐▌▐▛▀▀▘▐▛▀▚▖
        ▝▚▄▞▘▐▌ ▐▌▐▌  ▐▌▐▙▄▄▖    ▝▚▄▞▘ ▝▚▞▘ ▐▙▄▄▖▐▌ ▐▌




 )" << RESET << endl;
}

void Win(){
    cout << GREEN << R"(

        ▗▖ ▗▖▗▄▄▄▖▗▖  ▗▖
        ▐▌ ▐▌  █  ▐▛▚▖▐▌
        ▐▌ ▐▌  █  ▐▌ ▝▜▌
        ▐▙█▟▌▗▄█▄▖▐▌  ▐▌




    )" << RESET << endl; 
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
            string non = "C'est un jeu de plateau 4x4 qui contient des puissances de 2 ! Tu peux déplacer ces puissances en utilisant les touches du clavier Z,Q,S ou D et si deux tuiles sont adjacentes et que le glissement des tuiles est dans la bonne direction, alors, tu gagnes des points et elles se combinent ! À chaque déplacement, une nouvelle puissance apparaît, à toi de jouer maintenant !";
            for (int i = 0; i < non.size(); i++){
                cout << non[i] << flush; // flush permet d'afficher directement et de ne pas attendre que le buffer/tampon est plein
                this_thread::sleep_for(chrono::milliseconds(40)); // Attente de 40 ms après chaque affichage
            }
            this_thread::sleep_for(chrono::seconds(1));
            cout << endl;
            break;
        }
        if (reponse == 'o'){
            string oui = "OK ! Que le jeu commence !";
            for (auto valeur:oui){
                cout << valeur << flush;
                this_thread::sleep_for(chrono::milliseconds(40));
            }
            cout << endl;
            this_thread::sleep_for(chrono::seconds(1));
            break;
        }
        else { 
            while (reponse != 'n' and reponse != 'o'){
               cout << "Choisis bien entre o (oui) et n (non) !" << endl;
               cin >> reponse;
            break;
            }
        }
    }
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
    for(int i = 0; i < 2; i++){ //2 tours de boucle pour 2 cases aléatoires
        ligne = rand() % 4; // Choisi aléatoirement un indice de ligne entre 0 et 3
        colonne = rand() % 4; // De même pour la colonne
        t[ligne][colonne] = tireDeuxOuQuatre(); //la case du tableau aléatoire
    }
    return t; //retour du tableau
}

Plateau plateauPlacementAléatoire(Plateau t){
    int ligne; 
    int colonne;
    while (true){ // Boucle continue tant que l'indice n'est pas placé
        ligne = rand() % 4; // Choisi un indice de ligne aléatoire entre 0 et 3
        colonne = rand () % 4; // De même pour colonne
        if (t[ligne][colonne] == 0){ // Si la case est vide, place le nombre tiré aléatoirement
            t[ligne][colonne] = tireDeuxOuQuatre();
            break;
        }
    }
    return t;
}

bool lignePlateauRemplie(Plateau plateau, int ligne){
    for (int i = 0; i < plateau.size(); i++){
        if (plateau[ligne][i] == 0){
            return false;
        }
    }
    if (plateau[ligne][0] == plateau[ligne][1] and plateau[ligne][2] == plateau[ligne][3]){
        return true;
    }
    return false;
}

bool colonnePlateauRemplie(Plateau plateau, int colonne){
    for (int i = 0; i < plateau.size(); i++){
        if (plateau[i][colonne] == 0){
            return false;
        }
    }
    if (plateau[0][colonne] == plateau[1][colonne] and plateau[2][colonne] == plateau[3][colonne]){
        return true;
    }
    return false;
}

Plateau déplacementDroite(Plateau plateau){
    for(int i = 0; i < plateau.size();i++){
        int coup = 1;
        if (lignePlateauRemplie(plateau, i)){
            coup = 0;
        }
        for(int k = 0; k < 3; k++){
            for (int j = plateau[i].size() - 1; j > 0; j--){
                if (plateau[i][j-1] != 0 and plateau[i][j] == 0){
                    plateau[i][j] = plateau[i][j-1];
                    plateau[i][j-1] = 0;
                }
                if (plateau[i][j-1] == plateau[i][j] and plateau[i][j] != 0 and coup < 2){
                    plateau[i][j] *= 2;
                    plateau[i][j-1] = 0;
                    score = score + plateau[i][j];
                    coup++;
                }
            }
        }
    }
    return plateau;
}

Plateau déplacementGauche(Plateau plateau){
    for (int i = 0; i < plateau.size(); i++){
        int coup = 1;
        if (lignePlateauRemplie(plateau, i)){
            coup = 0;
        }
        for(int k = 0; k < 3; k++){
            for (int j = 0; j < plateau[i].size() -1; j++){
                if (plateau[i][j] == 0 and plateau[i][j+1] != 0){
                    plateau[i][j] = plateau[i][j+1];
                    plateau[i][j+1] = 0;
                }
                if (plateau[i][j+1] == plateau[i][j] and plateau[i][j] != 0 and coup < 2){
                    plateau[i][j] *= 2;
                    plateau[i][j+1] = 0;
                    score = score + plateau[i][j];
                    coup++;
                }
            }
        }
    }
    return plateau;
}

Plateau déplacementBas(Plateau plateau){
    for (int i = 0; i < plateau.size(); i++){
        int coup = 1;
        if (colonnePlateauRemplie(plateau, i)){
            coup = 0;
        }
        for(int k = 0; k < 3; k++){
            for (int j = plateau[i].size() - 1; j > 0; j--){
                if (plateau[j-1][i] != 0 and plateau[j][i] == 0){
                    plateau[j][i] = plateau[j-1][i];
                    plateau[j-1][i] = 0;
                }
                if (plateau[j-1][i] == plateau[j][i] and plateau[j][i] != 0 and coup < 2){
                    plateau[j][i] *= 2;
                    plateau[j-1][i] = 0;
                    score = score + plateau[j][i];
                    coup++;
                }
            }
        }
    }
    return plateau;
}

Plateau déplacementHaut(Plateau plateau){
    for (int i = 0; i < plateau.size(); i++){
        int coup = 1;
        if (colonnePlateauRemplie(plateau, i)){
            coup = 0;
        }
        for(int k = 0; k < 3; k++){
            for (int j = 0; j < plateau[i].size() - 1; j++){
                if (plateau[j][i] == 0 and plateau[j+1][i] != 0){
                    plateau[j][i] = plateau[j+1][i];
                    plateau[j+1][i] = 0;
                }
                if (plateau[j][i] == plateau[j+1][i] and plateau[j][i] != 0 and coup < 2){
                    plateau[j][i] = plateau[j][i] * 2;
                    plateau[j+1][i] = 0;
                    score = score + plateau[j][i];
                    coup++;
                }
            }
        }
    }
    return plateau;
}

Plateau déplacement(Plateau plateau, char Touche){
    while (Touche != 'z' and Touche != 'q' and Touche != 's' and Touche != 'd'){
        cout << "La touche n'est pas reconnue..." << endl;
        cout << "Choisi une touche entre z,q,s,d !" << endl;
        cin >> Touche;
    }
    if (Touche == 'z'){
        plateau = déplacementHaut(plateau);
        cout << "Score : " << score << endl;
        return plateau;
    }
    if (Touche == 'q'){
        plateau = déplacementGauche(plateau);
        cout << "Score : " << score << endl;
        return plateau;
    }
    if (Touche == 's'){
        plateau = déplacementBas(plateau);
        cout << "Score : " << score << endl;
        return plateau;
    }
    if (Touche == 'd'){
        plateau = déplacementDroite(plateau);
        cout << "Score : " << score << endl;
        return plateau;
    }
    return plateau;
}

void dessinebis(Plateau p){
    cout << "Score : " << score << endl;
    int espacement = 5;
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
                cout << "*" << GREEN << setw(espacement) << valeur << RESET;
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

bool déplacementPossible(Plateau plateau){
    if (estEgal(plateau, déplacementDroite(plateau)) and estEgal(plateau, déplacementGauche(plateau)) and estEgal(plateau, déplacementHaut(plateau)) and estEgal(plateau, déplacementBas(plateau))){
        return false;
    }
    else {
        return true;
    }
}

bool jeuSaturé(Plateau plateau){
    for (int i = 0; i < plateau.size(); i++){
        for (int j = 0; j < plateau[i].size(); j++){
            if (plateau[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

bool ConditionFinDeJeu(Plateau t){
    int comptecases = 0;
    for(int i = 0; i < t.size(); i++){
        for (int k = 0; k < t[0].size(); k++){
            if (t[i][k] != 0){
                comptecases++;
            }
            if (t[i][k] == 2048){
                Win();
                return false;
            }
        }
    }
    if (comptecases == 16){
        if (not(déplacementPossible(t))){
            GameOver();
            return false;
        }
    }
    return true;
}
