#include <vector>
#include <string>
#include <iostream>
using namespace std;

using Plateau = vector<vector<int>>;

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
    for (int i = 0; t.size(); i++){
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
    t = plateauVide();
    int place = 0;

}
int main(){

}