#include <iostream>
using namespace std;

int main() {
    int n, G;
    cin >> n >> G;
    int g[1001];
    
    // Citire array
    for (int i = 1; i <= n; i++)
        cin >> g[i];
    
    // Sortare descrescătoare (Bubble Sort)
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (g[i] < g[j]) {
                int aux = g[i];
                g[i] = g[j];
                g[j] = aux;
            }
    
    // Algoritm Greedy - alegem casele cu cele mai multe bomboane
    int suma = 0, nr = 0;
    for (int i = 1; i <= n; i++) {
        suma += g[i];
        nr++;
        
        // Verificăm dacă am umplut rucsacul
        if (suma >= G) {
            cout << nr;
            return 0;
        }
    }
    
    // Dacă am trecut prin toate casele și nu am adunat destul
    cout << "NU";
    return 0;
}