#include <iostream>
#include <vector>
// #include <fstream>

#define ll long long int

using namespace std;

ll MAX = 100;
ll INFTY = (1<<21);
ll WHITE = 0;
ll GRAY = 1;
ll BLACK = 2;
vector<vector<ll>> M;

ll prim(ll n) {
    vector<ll> d(n, INFTY);
    vector<ll> p(n, -1);
    vector<ll> color(n, WHITE);

    d[0] = 0;
    while (true) {
        ll minv = INFTY;
        ll u = -1;
        for (ll i = 0; i < n; i++) {
            if (minv > d[i] && color[i] != BLACK) {
                u = i;
                minv = d[i];
            }
        }
        if (u == -1) {
            break;
        }
        color[u] = BLACK;

        for (ll v = 0; v < n; v++) {
            if (color[v] != BLACK && M[u][v] != INFTY) {
                if (d[v] > M[u][v]) {
                    d[v] = M[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }

    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        if (p[i] != -1) {
            sum += M[i][p[i]];
        }
    }

    return sum;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        vector<ll> tmp(n, INFTY);
        M.push_back(tmp);
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            ll e;
            cin >> e;
            if (e != -1) {
                M[i][j] = e;
            }
        }
    }

    cout << prim(n) << endl;

    return 0;
}
