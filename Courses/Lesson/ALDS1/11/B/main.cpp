#include <iostream>
#include <vector>
#include <stack>
// #include <fstream>

#define ll long long int

using namespace std;

const ll N = 100;
const ll WHITE = 0;
const ll GRAY = 1;
const ll BLACK = 2;

ll tt = 1;
vector<ll> d(N), f(N);

vector<ll> dfs(vector<vector<ll>> M, ll r, vector<ll> color) {
    stack<ll> S;
    S.push(r);
    color[r] = GRAY;
    d[r] = tt++;

    while (!S.empty()) {
        ll u = S.top();
        ll v = 0;
        for (ll i = 1; i <= M[u].size(); i++) {
            if (M[u][i] == 1 && color[i] == WHITE) {
                v = i;
                break;
            }
        }
        if (v != 0) {
            color[v] = GRAY;
            d[v] = tt++;
            S.push(v);
        } else {
            S.pop();
            color[u] = BLACK;
            f[u] = tt++;
        }
    }

    return color;
}

void solve(vector<vector<ll>> M) {
    vector<ll> color(M.size(), WHITE);
    for (ll i = 0; i < M.size(); i++) {
        if (color[i] == WHITE) {
            color = dfs(M, i, color);
        }
    }
    for (ll i = 0; i < M.size(); i++) {
        cout << i + 1 << " " << d[i] << " " << f[i] << endl;
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

    solve(M);

    return 0;
}
