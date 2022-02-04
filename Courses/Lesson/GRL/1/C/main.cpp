#include <iostream>
#include <vector>
#include <algorithm>
// #include <fstream>

#define ll long long int

using namespace std;

static const ll INFTY = (1LL<<32);

vector<vector<ll>> floyd(ll n, vector<vector<ll>> d) {
    for (ll k = 0; k < n; k++) {
        for (ll i = 0; i < n; i++) {
            if (d[i][k] == INFTY) {
                continue;
            }
            for (ll j = 0; j < n; j++) {
                if (d[k][j] == INFTY) {
                    continue;
                }
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    return d;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    ll n, e;
    cin >> n >> e;

    vector<vector<ll>> d(n, vector<ll>(n));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            d[i][j] = (i == j) ? 0 : INFTY;
        }
    }

    for (ll i = 0; i < e; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        d[u][v] = c;
    }

    d = floyd(n, d);

    bool negative = false;
    for (ll i = 0; i < n; i++) {
        if (d[i][i] < 0) {
            negative = true;
        }
    }

    if (negative) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                if (j != 0) {
                    cout << " ";
                }
                if (d[i][j] == INFTY) {
                    cout << "INF";
                } else {
                    cout << d[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}