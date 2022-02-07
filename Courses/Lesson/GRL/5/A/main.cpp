#include <iostream>
#include <vector>
#include <queue>
// #include <fstream>

#define ll long long int
#define MAX 100000
#define INFTY 1<<30

using namespace std;

class Edge {
    public:
        ll t, w;
        Edge() {}
        Edge(ll t, ll w): t(t), w(w) {}
};

vector<vector<Edge>> G(MAX);
vector<ll> d(MAX);

void bfs(ll s, ll n) {
    for (ll i = 0; i < n; i++) {
        d[i] = INFTY;
    }

    queue<ll> Q;
    Q.push(s);
    d[s] = 0;

    ll u;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (ll i = 0; i < G[u].size(); i++) {
            Edge e = G[u][i];
            if (d[e.t] == INFTY) {
                d[e.t] = d[u] + e.w;
                Q.push(e.t);
            }
        }
    }
}

void solve(ll n) {
    bfs(0, n);
    ll maxv = 0;
    ll tgt = 0;
    for (ll i = 0; i < n; i++) {
        if (d[i] == INFTY) {
            continue;
        }
        if (maxv < d[i]) {
            maxv = d[i];
            tgt = i;
        }
    }

    bfs(tgt, n);
    maxv = 0;
    for (ll i = 0; i < n; i++) {
        if (d[i] == INFTY) {
            continue;
        }
        maxv = max(maxv, d[i]);
    }

    cout << maxv << endl;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    ll n;
    cin >> n;

    for (ll i = 0; i < n - 1; i++) {
        ll s, t, w;
        cin >> s >> t >> w;
        G[s].push_back(Edge(t, w));
        G[t].push_back(Edge(s, w));
    }

    solve(n);

    return 0;
}
