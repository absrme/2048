#include <vector>
#include <string>
#include <iostream>
using namespace std;

using Plateau = vector<vector<int>>;
// A faire documentation déplacement() et dessinebis()

/** Permet de savoir si deux plateaux sont égaux
 * @param plateau le premier plateau
 * @param plateau1 le second plateau
 * @return true si les plateaux sont égaux, false sinon
 **/
bool estEgal(Plateau plateau, Plateau plateau1);

/** Fonction indiquant si une ligne est remplie et que celle-ci 
 * comporte 2 doublons consécutifs
 * @param plateau le plateau
 * @param ligne un entier
 * @return true si la ligne est remplie et comporte 2 doublons consécutifs, false sinon
 */
bool lignePlateauRemplie(Plateau plateau, int ligne);

/** Fonction indiquant si une colonne est remplie et que celle-ci 
 * comporte 2 doublons consécutifs
 * @param plateau le plateau
 * @param colonne un entier
 * @return true si la colonne est remplie et comporte 2 doublons consécutifs, false sinon
 */
bool colonnePlateauRemplie(Plateau plateau, int colonne);

/** Crée un ficher qui va stocker le nom du joueur et son score **/
void HighScoreTXT();

/** Ecrit dans le fichier highscore.txt le score de la partie
 * @param score un entier le score de la partie
 **/
void HighScoreFinal(int score);

/*ASCII2048 : affiche en ASCII "2048"*/
void ASCII2048();

/*Win : affiche "WIN" en ASCII*/
void Win();

/*GameOver : affiche "GAME OVER" en ASCII*/
void GameOver();

/** Affiche le plateau avec des "*"
 * @param plateau le plateau
 */
void dessinebis(Plateau plateau);

/** Détermine si la partie est gagnée ou perdue
 * @param plateau 
 * @return false : si la partie gagnée ou perdue, true sinon
 **/
bool ConditionFinDeJeu(Plateau plateau);

/** Place aléatoirement 2 (9 chances sur 10) ou 4 (1 chance sur 10)
* @param plateau : plateau
* @return plateau : plateau modifié avec le nombre aléatoire placé
**/
Plateau plateauPlacementAléatoire(Plateau plateau);

/** Déplace le plateau en fonctions des touches entrées
 * @param plateau : plateau du jeu
 * @param Touche : touche entrée par le joueur
 * @return plateau : plateau déplacé selon la touche entrée
**/
Plateau déplacement(Plateau plateau, char Touche);

/* Affiche les règles du 2048 */
void Tutoriel();

/** Calcule le score à un instant de la partie
 * @param plateau un plateau 
 * @return le score
**/
int Score(Plateau plateau);

/** génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @return 2 ou 4
 **/
int tireDeuxOuQuatre();

/** génère un plateau de dimensions 4*4 ne contenant que des 0
 *  @return un plateau vide
 **/
Plateau plateauVide();

/** génère deux nombres sur des cases aléatoires d'un plateau vide
 *  @return un plateau en début de jeu
 **/
Plateau plateauInitial();

/** déplace les tuiles d'un plateau vers la gauche et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers la gauche
 **/

Plateau déplacementGauche(Plateau plateau);

/** déplace les tuiles d'un plateau vers la droite et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers la droite
 **/
Plateau déplacementDroite(Plateau plateau);

/** déplace les tuiles d'un plateau vers le haut et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers le haut
 **/
Plateau déplacementHaut(Plateau plateau);

/** déplace les tuiles d'un plateau vers le bas et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers le bas
 **/
Plateau déplacementBas(Plateau plateau);

/** permet de savoir si une partie est gagnée
 * @param plateau un plateau
 * @return true si le plateau contient un 2048, false sinon
 **/
bool estGagnant(Plateau plateau);
