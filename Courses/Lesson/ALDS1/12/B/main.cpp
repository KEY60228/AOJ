#include <iostream>
#include <vector>
// #include <fstream>

#define ll long long int

using namespace std;

ll INFTY = (1<<21);
ll WHITE = 0;
ll GRAY = 1;
ll BLACK = 2;
vector<vector<ll>> M;

void dijkstra(ll n) {
    vector<ll> d(n, INFTY);
    vector<ll> color(n, WHITE);

    d[0] = 0;
    color[0] = GRAY;
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
                if (d[v] > d[u] + M[u][v]) {
                    d[v] = d[u] + M[u][v];
                    color[v] = GRAY;
                }
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
    }
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
        ll u, k;
        cin >> u >> k;
        for (ll j = 0; j < k; j++) {
            ll v, c;
            cin >> v >> c;
            M[u][v] = c;
        }
    }

    dijkstra(n);

    return 0;
}