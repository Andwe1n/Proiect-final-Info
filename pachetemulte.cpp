#include<iostream>
#include<fstream>
using namespace std;

const int N = 100005;
int n;
int spatiu[N]; // spatiu[i] = ce pachet este în poziția i (0 = gol)
int pozitie[N]; // pozitie[i] = la ce poziție se află pachetul i
int liber; // poziția liberă (n+1)
int mutari = 0;

int mutari_de_la[2 * N]; // de unde mutăm
int mutari_la[2 * N]; // unde mutăm

// Mută pachetul din poziția 'de_la' în poziția liberă
void muta(int de_la) {
    mutari++;
    mutari_de_la[mutari] = de_la;
    mutari_la[mutari] = liber;
    
    spatiu[liber] = spatiu[de_la]; // punem pachetul în poziția liberă
    pozitie[spatiu[de_la]] = liber; // actualizăm poziția pachetului
    spatiu[de_la] = 0; // poziția anterioară devine goală
    liber = de_la; // devine noua poziție liberă
}

int main() {
    ifstream f("pachete_multe.in");
    ofstream g("pachete_multe.out");

    f >> n;

    // Citim pachetele din primele n poziții
    for (int i = 1; i <= n; ++i) {
        f >> spatiu[i];
        pozitie[spatiu[i]] = i;
    }

    // Poziția n+1 este goală
    spatiu[n + 1] = 0;
    liber = n + 1;

    // Parcurgem toate pozițiile de la 1 la n
    for (int i = 1; i <= n; ++i) {
        if (spatiu[i] != i) {
            if (spatiu[i] != 0) {
                muta(i); // eliberăm poziția i
            }
            muta(pozitie[i]); // aducem pachetul i la poziția i
        }
    }

    // Scriem rezultatul
    g << mutari << endl;
    for (int i = 1; i <= mutari; ++i) {
        g << mutari_de_la[i] << " " << mutari_la[i] << endl;
    }

    return 0;}