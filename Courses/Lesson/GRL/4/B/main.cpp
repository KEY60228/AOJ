#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
// #include <fstream>

#define ll long long int
#define MAX 100000
#define INFTY 1<<29

using namespace std;

vector<vector<ll>> G(MAX);
list<ll> out;
vector<bool> V;
vector<ll> indeg;

void bfs(ll s) {
    queue<ll> q;
    q.push(s);
    V[s] = true;

    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        out.push_back(u);
        for (ll i = 0; i < G[u].size(); i++) {
            ll v = G[u][i];
            indeg[v]--;
            if (indeg[v] == 0 && !V[v]) {
                V[v] = true;
                q.push(v);
            }
        }
    }
}

void tsort(ll N) {
    for (ll i = 0; i < N; i++) {
        indeg.push_back(0);
    }

    for (ll u = 0; u < N; u++) {
        for (ll i = 0; i < G[u].size(); i++) {
            ll v = G[u][i];
            indeg[v]++;
        }
    }

    for (ll u = 0; u < N; u++) {
        if (indeg[u] == 0 && !V[u]) {
            bfs(u);
        }
    }

    for (auto itr = out.begin(); itr != out.end(); itr++) {
        cout << *itr << endl;
    }
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    ll N, M;
    cin >> N >> M;

    for (ll i = 0; i < N; i++) {
        V.push_back(false);
    }

    for (ll i = 0; i < M; i++) {
        ll s, t;
        cin >> s >> t;
        G[s].push_back(t);
    }

    tsort(N);

    return 0;
}
