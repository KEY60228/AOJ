#include <iostream>
#include <vector>
#include <algorithm>
// #include <fstream>

using namespace std;

static const int MMAX = 20;
static const int NMAX = 50000;
static const int INFTY = (1 << 29);

vector<int> getTheNumberOfCoin(int n, int m, vector<int> C) {
    vector<int> T(NMAX + 1, INFTY);
    T[0] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j + C[i] <= n; j++) {
            T[j + C[i]] = min(T[j + C[i]], T[j] + 1);
        }
    }

    return T;
}

void solve(int n, int m, vector<int> C) {
    vector<int> T = getTheNumberOfCoin(n, m, C);
    cout << T[n] << endl;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int n, m;
    cin >> n >> m;

    vector<int> C(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> C[i];
    }
    solve(n, m, C);

    return 0;
}
