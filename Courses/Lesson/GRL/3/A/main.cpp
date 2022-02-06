#include <iostream>
#include <vector>
#include <set>
// #include <fstream>

#define ll long long int
#define MAX 100000

using namespace std;

vector<vector<ll>> G(MAX);
vector<bool> visited(MAX);
vector<ll> prenum(MAX), parent(MAX), lowest(MAX);
ll timer;

void dfs(ll current, ll prev) {
    prenum[current] = lowest[current] = timer;
    timer++;

    visited[current] = true;

    ll next;
    for (ll i = 0; i < G[current].size(); i++) {
        next = G[current][i];
        if (!visited[next]) {
            parent[next] = current;
            dfs(next, current);
            lowest[current] = min(lowest[current], lowest[next]);
        } else if (next != prev) {
            lowest[current] = min(lowest[current], prenum[next]);
        }
    }
}

void art_points(ll N) {
    for (ll i = 0; i < N; i++) {
        visited[i] = false;
    }
    timer = 1;
    dfs(0, -1);

    set<ll> ap;
    int np = 0;
    for (ll i = 1; i < N; i++) {
        ll p = parent[i];
        if (p == 0) {
            np++;
        } else if (prenum[p] <= lowest[i]) {
            ap.insert(p);
        }
    }
    if (np > 1) {
        ap.insert(0);
    }
    for (auto itr = ap.begin(); itr != ap.end(); itr++) {
        cout << *itr << endl;
    }
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    ll N, m;
    cin >> N >> m;

    for (ll i = 0; i < m; i++) {
        ll s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    art_points(N);

    return 0;
}
