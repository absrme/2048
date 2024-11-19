#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;
using Plateau = vector<vector<int>>;
Plateau déplacementDroite(Plateau plateau){
for (int i = 0; i<plateau.size(); i++){
        for (int j = 0; j<plateau[i].size(); j++){
            if (plateau[i+1][j+1] == 0 or plateau[i][j]==plateau[i+1][j+1]){
                plateau[i+1][j+1] = plateau[i][j];
                plateau[i][j]==0;
            }
        }
    }
}
