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
#define WHITE   "\033[37m"      /* White */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */

using namespace std;
using Plateau = vector<vector<int>>;

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
    cout << R"(

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
    
    )" << endl;
}

void GameOver(){
    cout << R"(

         ▗▄▄▖ ▗▄▖ ▗▖  ▗▖▗▄▄▄▖     ▗▄▖ ▗▖  ▗▖▗▄▄▄▖▗▄▄▖
        ▐▌   ▐▌ ▐▌▐▛▚▞▜▌▐▌       ▐▌ ▐▌▐▌  ▐▌▐▌   ▐▌ ▐▌
        ▐▌▝▜▌▐▛▀▜▌▐▌  ▐▌▐▛▀▀▘    ▐▌ ▐▌▐▌  ▐▌▐▛▀▀▘▐▛▀▚▖
        ▝▚▄▞▘▐▌ ▐▌▐▌  ▐▌▐▙▄▄▖    ▝▚▄▞▘ ▝▚▞▘ ▐▙▄▄▖▐▌ ▐▌




 )" << endl;
}

void Win(){
    cout << R"(

        ▗▖ ▗▖▗▄▄▄▖▗▖  ▗▖
        ▐▌ ▐▌  █  ▐▛▚▖▐▌
        ▐▌ ▐▌  █  ▐▌ ▝▜▌
        ▐▙█▟▌▗▄█▄▖▐▌  ▐▌




)" << endl; }


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
    return true;
}

bool colonnePlateauRemplie(Plateau plateau, int colonne){
    for (int i = 0; i < plateau.size(); i++){
        if (plateau[i][colonne] == 0){
            return false;
        }
    }
    return true;
}

Plateau déplacementDroite(Plateau plateau){
    for(int i = 0; i < plateau.size();i++){
        int coup = 1;
        if (lignePlateauRemplie(plateau, i)){
            coup = 0;
        }
        for(int k = 0; k < 3; k++){
            for (int j = plateau[i].size() - 1; j > 0; j--){ // Déplace les tuiles vers la droite
                if (plateau[i][j-1] != 0 and plateau[i][j] == 0){
                    plateau[i][j] = plateau[i][j-1];
                    plateau[i][j-1] = 0;
                }
                if (plateau[i][j-1] == plateau[i][j] and coup < 2){
                    plateau[i][j] *= 2;
                    plateau[i][j-1] = 0;
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
            for (int j = 0; j < plateau[i].size() -1; j++){ //Colonnes
                if (plateau[i][j] == 0 and plateau[i][j+1] != 0){
                    plateau[i][j] = plateau[i][j+1];
                    plateau[i][j+1] = 0;
                }
                if (plateau[i][j+1] == plateau[i][j] and coup < 2){
                    plateau[i][j] *= 2;
                    plateau[i][j+1] = 0;
                    coup++;
                }
            }
        }
    }
    return plateau;
}

Plateau déplacementBas(Plateau plateau){
    for (int i = 0; i < plateau.size(); i++){
            for(int k = 0; k < 3; k++){
                for (int j = plateau[i].size() - 1; j > 0; j--){
                    if (plateau[j-1][i] != 0 and plateau[j][i] == 0){
                        plateau[j][i] = plateau[j-1][i];
                        plateau[j-1][i] = 0;
                    }
                    if (plateau[j-1][i] == plateau[j][i]){ // Si la case d'au dessus est égale à la case actuelle dans la boucle
                        plateau[j][i] *= 2;
                        plateau[j-1][i] = 0;
                    }
                }
            }
        }
    return plateau;
}

Plateau déplacementHaut(Plateau plateau){
    for (int i = 0; i<plateau.size(); i++){
        for(int k = 0; k < 3; k++){
            for (int j = 0; j < plateau[i].size() - 1; j++){
                    if (plateau[j][i] == 0 and plateau[j+1][i] != 0){
                        plateau[j][i] = plateau[j+1][i];
                        plateau[j+1][i] = 0;
                    }
                    if (plateau[j][i] == plateau[j+1][i]){
                        plateau[j][i] *= 2;
                        plateau[j+1][i] = 0;
                    }
                }
            }
        }
    return plateau;
}

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
                cout << "*" << setw(espacement) << valeur << RESET;
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
// void test(){
//     char Touche;
//     cout << "Test rapide que les fonctions marchent..." << endl;
//     cout << "Affichage du plateau vide..." << endl;
//     dessinebis(plateauVide());
//     cout << "Affichage du plateau initial..." << endl;
//     Plateau t2;
//     Plateau t4;
//     t2 = plateauInitial();
//     t4 = plateauInitial();
//     dessinebis(t2);
//     dessinebis(t4);
//     cout << "Ok, maintenant on teste de déplacer le tableau..." << endl;
//     cout << "Entre Z,Q,S ou D pour déplacer le tableau..." << endl;
//     cin >> Touche;
//     dessinebis(déplacement(t2,Touche));
//     dessinebis(déplacement(t4,Touche));
// }

void testVilain(){
    vector<vector<int>>(t);
    t = vector<vector<int>>(4);
    t = {{0,0,0,0},{0,0,4,16},{0,0,0,0},{0,0,0,0}};
    if (estEgal(déplacementDroite({{0,0,0,0},{2,2,8,8},{0,0,0,0},{0,0,0,0}}),t)){
        cout << "atchoum" << endl;
    }
    t = {{0,0,0,0},{0,0,4,8},{0,0,0,0},{0,0,0,0}};
    if (estEgal(déplacementDroite({{0,0,0,0},{0,4,4,4},{0,0,0,0},{0,0,0,0}}),t)){
        cout << "à tes souhaits" << endl;
    }
    t = {{0,0,0,0},{0,0,2,4},{0,0,0,0},{0,0,0,0}};
    if (estEgal(déplacementDroite({{0,0,0,0},{2,2,0,2},{0,0,0,0},{0,0,0,0}}),t)){ // working OK
        cout << "merce" << endl;
    }
    t = {{0,0,4,4},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    if (estEgal(déplacementDroite({{2,2,2,2},{0,0,0,0},{0,0,0,0},{0,0,0,0}}),t)){ // working OK
        cout << "SAUVE" << endl;
    }
    t = {{0,0,4,4},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    if (estEgal(déplacementDroite({{0,2,2,4},{0,0,0,0},{0,0,0,0},{0,0,0,0}}),t)){
        cout << "rizz" << endl;
    }
    // t = {{2048,0,16,10000},{0,0,4,16},{0,32,0,0},{0,4096,128,0}};
    // dessinebis(t);
    // t = {{0,0,0,2},{2,0,0,0},{2,0,0,0},{4,8,4,0}};
    // dessinebis(déplacementHaut(t));
}
bool déplacementPossible(Plateau plateau){
    if (estEgal(plateau, déplacementDroite(plateau)) and estEgal(plateau, déplacementGauche(plateau)) and estEgal(plateau, déplacementHaut(plateau)) and estEgal(plateau, déplacementBas(plateau))){
        return false;
    }
    else return true;
}

bool ConditionFinDeJeu(Plateau t){
    int comptecases = 0;
    for(int i = 0; i < t.size(); i++){
        for (int k = 0; k < t[0].size(); k++){
        if (t[i][k]!=0){
            comptecases++;
        }
        if (t[i][k]==2048){
            return false;
        }
        }}

    if (comptecases >= 16){
        cout << "Jeu saturé, partie perdue :/" << endl;
        GameOver();
        return false;
    }
    return true;
}

int main(){
    //Initialisation
    Plateau t;
    char Touche;
    //Cosmétiques
    ASCII2048();
    Tutoriel();
    HighScoreTXT();
    // Déroulement de la partie partie
    t = plateauVide();
    plateauInitial(t);
    dessinebis(t);
    while(ConditionFinDeJeu(t)==true){
        cout << "Score : " << score << endl;
        cout << "Choisis une touche entre Z,Q,S,D !" << endl;
        cin >> Touche;
        t = déplacement(t,Touche);
        dessinebis(t);
        t = plateauPlacementAléatoire(t);
        dessinebis(t);
     }
}
