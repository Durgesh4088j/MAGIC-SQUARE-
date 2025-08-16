#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> magicSquare(int n) {
    vector<vector<int>> square(n, vector<int>(n, 0));
    int r = n / 2, c = n - 1;

    for (int val = 1; val <= n * n;) {
        if (r < 0 && c == n) {
            r = 0; 
            c = n - 2;
        }
        if (c == n) c = 0;
        if (r < 0) r = n - 1;

        if (square[r][c] != 0) {
            c -= 2; 
            r++;
            continue;
        }
        else {
            square[r][c] = val++;
        }

        r--; 
        c++;
    }
    return square;
}

int main() {
    int n = 5;
    auto result = magicSquare(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
