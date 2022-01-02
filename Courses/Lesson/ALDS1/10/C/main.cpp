#include <iostream>
#include <string>
#include <algorithm>
// #include <fstream>

#define ll long long int

using namespace std;

ll N = 1000;

ll lcs(string X, string Y) {
    ll c[N + 1][N + 1];
    ll maxl = 0;

    X = ' ' + X;
    Y = ' ' + Y;

    for (ll i = 0; i < X.size(); i++) {
        c[i][0] = 0;
    }
    for (ll i = 0; i < Y.size(); i++) {
        c[0][i] = 0;
    }

    for (ll i = 1; i < X.size(); i++) {
        for (ll j = 1; j < Y.size(); j++) {
            if (X[i] == Y[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
            maxl = max(maxl, c[i][j]);
        }
    }

    return maxl;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
    }

    return 0;
}

