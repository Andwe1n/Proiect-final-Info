#include <iostream>
#include <fstream>
using namespace std;

bool viz[20];

int main() {
    ifstream f("orase.in");
    ofstream g("orase.out");
    
    int n, i, j, oras_start, oras_curent;
    int cost_minim = 9999, cost_total = 0, oras_urmator;
    int distanta[20][20];
    
    // Citim numărul de orașe
    f >> n;
    
    // Citim matricea de distanțe
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            f >> distanta[i][j];
            viz[j] = false;  // Inițializăm toate orașele ca nevizitate
        }
    
    // Citim orașul de start
    f >> oras_start;
    oras_curent = oras_start;
    viz[oras_curent] = true;  // Marcăm orașul de start ca vizitat
    
    // Algoritm Greedy - vizităm n-1 orașe rămase
    for (i = 1; i < n; i++) {
        cost_minim = 9999;  // Resetăm costul minim pentru fiecare pas
        
        // Găsim cel mai apropiat oraș nevizitat
        for (j = 1; j <= n; j++)
            if (distanta[oras_curent][j] < cost_minim && viz[j] == false) {
                cost_minim = distanta[oras_curent][j];
                oras_urmator = j;
            }
        
        // Actualizăm costul total și mutăm comis-voiajorul
        cost_total = cost_total + cost_minim;
        oras_curent = oras_urmator;
        viz[oras_curent] = true;  // Marcăm orașul ca vizitat
    }
    
    // Adăugăm costul de întoarcere la orașul de start
    cost_total = cost_total + distanta[oras_curent][oras_start];
    
    g << "Costul minim al drumului este: " << cost_total;
    
    f.close();
    g.close();
    return 0;
}