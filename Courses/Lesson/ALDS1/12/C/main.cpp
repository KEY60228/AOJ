#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
// #include <fstream>

#define ll long long int

using namespace std;

ll INFTY = (1<<21);
ll WHITE = 0;
ll GRAY = 1;
ll BLACK = 2;
vector<vector<pair<ll, ll>>> adj;

void dijkstra(ll n) {
    priority_queue<pair<ll, ll>> PQ;
    vector<ll> color(n, WHITE);
    vector<ll> d(n, INFTY);

    d[0] = 0;
    PQ.push({0, 0});
    color[0] = GRAY;
    while (!PQ.empty()) {
        pair<ll, ll> f = PQ.top();
        PQ.pop();
        ll u = f.second;
        color[u] = BLACK;

        if (d[u] < f.first * -1) {
            continue;
        }

        for (ll j = 0; j < adj[u].size(); j++) {
            ll v = adj[u][j].first;
            if (color[v] == BLACK) {
                continue;
            }
            if (d[v] > d[u] + adj[u][j].second) {
                d[v] = d[u] + adj[u][j].second;
                PQ.push({d[v] * -1, v});
                color[v] = GRAY;
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
        ll u, k;
        cin >> u >> k;
        vector<pair<ll, ll>> tmp;
        for (ll j = 0 ; j < k; j++) {
            ll v, c;
            cin >> v >> c;
            tmp.push_back({v, c});
        }
        adj.push_back(tmp);
    }

    dijkstra(n);

    return 0;
}
