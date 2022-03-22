#include <iostream>
#include <vector>
// #include <fstream>

#define N 8
#define FREE -1
#define NOT_FREE 1

using namespace std;

vector<vector<bool>> X;
vector<int> ROW, COL, DPOS, DNEG;

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (X[i][j]) {
                if (ROW[i] != j) {
                    return;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (ROW[i] == j ? "Q" : ".");
        }
        cout << endl;
    }
}

void recursive(int i) {
    if (i == N) {
        printBoard();
        return;
    }

    for (int j = 0; j < N; j++) {
        if (NOT_FREE == COL[j] || NOT_FREE == DPOS[i + j] || NOT_FREE == DNEG[i - j + N - 1]) {
            continue;
        }
        ROW[i] = j;
        COL[j] = DPOS[i + j] = DNEG[i - j + N - 1] = NOT_FREE;
        recursive(i + 1);
        ROW[i] = COL[j] = DPOS[i + j] = DNEG[i - j + N - 1] = FREE;
    }
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int n;
    cin >> n;

    vector<vector<bool>> x(N, vector<bool>(N, false));
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        x[r][c] = true;
    }
    vector<int> row(N, FREE);
    vector<int> col(N, FREE);
    vector<int> dpos(2 * N - 1, FREE);
    vector<int> dneg(2 * N - 1, FREE);

    X = x;
    ROW = row;
    COL = col;
    DPOS = dpos;
    DNEG = dneg;

    recursive(0);

    return 0;
}
