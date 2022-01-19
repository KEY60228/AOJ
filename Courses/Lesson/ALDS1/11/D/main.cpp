#include <iostream>
#include <vector>
#include <stack>
// #include <fstream>

#define ll long long int

using namespace std;

const ll NIL = -1;

vector<ll> dfs(ll r, ll c, vector<ll> color, vector<vector<ll>> M) {
    stack<ll> S;
    S.push(r);
    color[r] = c;

    while (!S.empty()) {
        ll u = S.top();
        S.pop();
        for (ll i = 0; i < M[u].size(); i++) {
            ll v = M[u][i];
            if (color[v] == NIL) {
                color[v] = c;
                S.push(v);
            }
        }
    }

    return color;
}

vector<ll> assignColor(vector<ll> color, vector<vector<ll>> M) {
    ll id = 1;
    for (ll i = 0; i < color.size(); i++) {
        if (color[i] == NIL) {
            color = dfs(i, id++, color, M);
        }
    }
    return color;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> v(n);
    for (ll i = 0; i < m; i++) {
        ll s, t;
        cin >> s >> t;
        v[s].push_back(t);
        v[t].push_back(s);
    }

    vector<ll> color(n, NIL);
    color = assignColor(color, v);

    ll q;
    cin >> q;

    for (ll i = 0; i < q; i++) {
        ll s, t;
        cin >> s >> t;
        if (color[s] == color[t]) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
