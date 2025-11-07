#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream f("pro.txt");
    int S, n, e, t = 0;
    f >> S >> n >> e;

    int p = 1, k = 0;
    while (p * e <= S && k < n) {
        p = p * e;
        k++;
    }
   
    while (S > 0) {
        if (S >= p) {
            cout << S / p << " bancnote de valoarea " << p << endl;
            t = t + S / p;  
            S = S % p;     
        }
        p = p / e;  
    }
    
    cout << t; 
    
    return 0;
}