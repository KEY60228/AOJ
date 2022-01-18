#include <iostream>
#include <vector>
#include <queue>
// #include <fstream>

#define ll long long int

using namespace std;

const ll N = 100;
const ll INFTY = (1 << 21);
ll d[N];

void dfs(vector<vector<ll>> M, ll s) {
    queue<ll> q;
    q.push(s);
    for (ll i = 0; i < M.size(); i++) {
        d[i] = INFTY;
    }
    d[s] = 0;

    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (ll v = 0; v < M.size(); v++) {
            if (M[u][v] == 0) continue;
            if (d[v] != INFTY) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    ll n;
    cin >> n;

    vector<vector<ll>> M(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++) {
        ll u, k;
        cin >> u >> k;
        for (ll j = 0; j < k; j++) {
            ll v;
            cin >> v;
            M[u - 1][v - 1] = 1;
        }
    }

    dfs(M, 0);

    for (ll i = 0; i < n; i++) {
        if (d[i] == INFTY) {
            cout << i + 1 << " " << -1 << endl;
        } else {
            cout << i + 1 << " " << d[i] << endl;
        }
    }

    return 0;
}
