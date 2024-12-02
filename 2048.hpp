#include <vector>
#include <string>
#include <iostream>
using namespace std;

using Plateau = vector<vector<int>>;
// A faire documentation déplacement() et dessinebis()

void testVilain();

void HighScoreTXT();

void HighScoreFinal(int score);

void ASCII2048();

void dessinebis(Plateau plateau);

bool ConditionFinDeJeu(Plateau plateau);

Plateau plateauPlacementAléatoire(Plateau plateau);

Plateau déplacement(Plateau plateau, char Touche);

/** Affiche les règles du 2048
 * @return un affichage selon la réponse à la question
 */
void Tutoriel();

/** Calcule le score à un instant de la partie
 * @param plateau un plateau 
 * @return le score
 */
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

/** Ajoute un élément dans le plateau aléatoirement
 * @param plateau le plateau
 * @return le plateau avec une nouvelle case contenant 2 ou 4 placé aléatoirement (dans une case vide)
 */
Plateau plateauPartie(Plateau plateau);

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

/** déplace les tuiles d'un plateau dans la direction donnée et génère une nouvelle tuile si le déplacement est valide
 *  @param plateau le plateau
 *  @param direction la direction
 *  @return le plateau déplacé dans la direction
 **/
// Plateau déplacement(Plateau plateau, int direction);
/** affiche un plateau
 * @param p le plateau
 **/
string dessine(Plateau p);

/** permet de savoir si une partie est terminée
 *  @param plateau un plateau
 *  @return true si le plateau est vide, false sinon
 **/
bool estTerminé(Plateau plateau);

/** permet de savoir si une partie est gagnée
 * @param plateau un plateau
 * @return true si le plateau contient un 2048, false sinon
 **/
bool estGagnant(Plateau plateau);
