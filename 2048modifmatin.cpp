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
// modif rand() dans tireDeuxOuQuatre() et dans PlateauInitial()
// dis-moi si t'as un pb lors de l'affichage du plateau
//////////////////////////////////////////////////
int tireDeuxOuQuatre(){
    int proba = 1 + rand() % 10; // Choisi un nombre entre 1 et 10
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
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <iomanip>
using namespace std;
using Plateau = vector<vector<int>>;

//////////////////////////////////////////////////
// MODIF DE LA FONCTION DEPLACEMENT DROITE (cas dans lesquels il ne s'assemble pas)
// + CELLE DE GAUCHE 
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
        ligne = rand() % 4; //indice de ligne aléatoire entre 0 et 3
        colonne = rand() % 4; //indice de colonne aléatoire entre 0 et 3
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

// J'ai un petit pb si on a un 2048, l'affichage est mauvais et faudrait 
// modifier l'espacement et donc faire un tableau plus grand 
// (si on a des nombres plus grand que 2048)
void dessinebis(Plateau p){
    int espacement = 5;
    for (int ligne = 0; ligne < p.size(); ligne++){
        for (int i = 0; i < espacement*4 + 5; i++){
            cout << "*"; // Première ligne de "*"
        }
        cout << endl;
        for (int colonne = 0; colonne < p[0].size(); colonne++){
            if (p[ligne][colonne] == 0){
                cout << "*" << setw(espacement) << " "; // Si la case est vide
            }
            else{
                string valeur = to_string(p[ligne][colonne]);
                int taille = (to_string(p[ligne][colonne]) + ' ').size() - 1;
                if (taille == 1){ // Si la case contient un nombre < 10
                    valeur.push_back(' ');
                    valeur.push_back(' ');
                }
                if (taille == 3 or taille == 2){ Si la case contient un nombre < 1000
                    valeur.push_back(' ');
                }
                cout << "*" << setw(espacement) << valeur; 
            }
        }
        cout << "*" << endl; // Dernier "*" manquant
    }
    for (int i = 0; i < espacement*4 + 5; i++){
            cout << "*"; // Dernière ligne de "*"
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
