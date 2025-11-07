#include <iostream>
#include <fstream>
using namespace std;

int a[101][101];

int main() {
    ifstream f("arici.in");
    int i, j, n, m;
    f >> n >> m;
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            f >> a[i][j];
            if (a[i][j - 1] < a[i - 1][j])
                a[i][j] = a[i][j] + a[i - 1][j];  
            else
                a[i][j] = a[i][j] + a[i][j - 1];  
        }
    }
    cout << a[n][m];
    
    return 0;
}