#include <vector>
#include <string>
#include <iostream>
using namespace std;

using Plateau = vector<vector<int>>;

/** Fonction indiquant si le jeu est saturé 
 * @param plateau le plateau du jeu
 * @return false si le jeu n'est pas saturé 
 * (cases non toutes remplies), true sinon
 */
bool jeuSaturé(Plateau plateau);

/** Fonction indiquant si un déplacement est possible
 * @param plateau le plateau du jeu
 * @return false si aucun déplacement est possible, true sinon
 * Implémentée par Huynh Anh
 */
bool déplacementPossible(Plateau plateau);

/** Permet de savoir si deux plateaux sont égaux
 * @param plateau le premier plateau
 * @param plateau1 le second plateau
 * @return true si les plateaux sont égaux, false sinon
 * Implémentée par Huynh Anh
 **/
bool estEgal(Plateau plateau, Plateau plateau1);

/** Fonction indiquant si une ligne est remplie et que celle-ci 
 * comporte 2 doublons consécutifs
 * @param plateau le plateau
 * @param ligne un entier
 * @return true si la ligne est remplie et comporte 2 doublons consécutifs, false sinon
 * Implémentée par Huynh Anh
 */
bool lignePlateauRemplie(Plateau plateau, int ligne);

/** Fonction indiquant si une colonne est remplie et que celle-ci 
 * comporte 2 doublons consécutifs
 * @param plateau le plateau
 * @param colonne un entier
 * @return true si la colonne est remplie et comporte 2 doublons consécutifs, false sinon
 * Implémentée par Huynh Anh
 */
bool colonnePlateauRemplie(Plateau plateau, int colonne);

/** Créé un ficher stockant le nom du joueur et son score 
 * Implémentée par Auguste
 */

void HighScoreTXT();

/** Ecrit dans le fichier highscore.txt le score de la partie
 * @param score un entier le score de la partie
 * Implémentée par Auguste
 **/
void HighScoreFinal(int score);

/**affiche en ASCII "2048"
 * Implémentée par Auguste
 */
void ASCII2048();

/**affiche "WIN" en ASCII
 * Implémentée par Auguste
 **/
void Win();

/**affiche "GAME OVER" en ASCII
 * Implémentée par Auguste
 **/
void GameOver();

/** Affiche le plateau avec des "*"
 * @param plateau le plateau
 * Implémentée par Huynh Anh
 */
void dessinebis(Plateau plateau);

/** Détermine si la partie est gagnée ou perdue
 * @param plateau 
 * @return false : si la partie gagnée ou perdue, true sinon
 * Implémentée par Auguste
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
 * Implémentée par Auguste
**/
Plateau déplacement(Plateau plateau, char Touche);

/** Affiche les règles du 2048
 * Implémentée par Auguste, modifiée par Huynh Anh
 */
void Tutoriel();

/** génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @return 2 ou 4
 *  Implémentée par Auguste
 **/
int tireDeuxOuQuatre();

/** génère un plateau de dimensions 4*4 ne contenant que des 0
 *  @return un plateau vide
 *  Implémentée par Huynh Anh
 **/
Plateau plateauVide();

/** génère deux nombres sur des cases aléatoires d'un plateau vide
 *  @return un plateau en début de jeu
 *  Implémentée par Huynh Anh
 **/
Plateau plateauInitial();

/** déplace les tuiles d'un plateau vers la gauche et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers la gauche
 *  Implémentée par Huynh Anh & Auguste
 **/

Plateau déplacementGauche(Plateau plateau);

/** déplace les tuiles d'un plateau vers la droite et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers la droite
 *  Implémentée par Huynh Anh & Auguste
 **/
Plateau déplacementDroite(Plateau plateau);

/** déplace les tuiles d'un plateau vers le haut et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers le haut
 *  Implémentée par Huynh Anh & Auguste
 **/
Plateau déplacementHaut(Plateau plateau);

/** déplace les tuiles d'un plateau vers le bas et les combine si possible
 *  @param plateau le plateau
 *  @return le plateau une fois déplacé vers le bas
 *  Implémentée par Huynh Anh & Auguste
 **/
Plateau déplacementBas(Plateau plateau);
