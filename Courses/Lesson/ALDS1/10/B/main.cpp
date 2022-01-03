#include <iostream>
#include <vector>
#include <algorithm>
// #include <fstream>

#define ll long long int

using namespace std;

ll N = 100;

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    ll n;
    cin >> n;

    vector<ll> p(N + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> p[i - 1] >> p[i];
    }

    vector<vector<ll>> m(N + 1, vector<ll>(N + 1));
    for (ll i = 1; i <= n; i++) {
        m[i][i] = 0;
    }
    for (ll l = 2; l <= n; l++) {
        for (ll i = 1; i <= n - l + 1; i++) {
            ll j = i + l - 1;
            m[i][j] = (1 << 21);
            for (ll k = i; k <= j - 1; k++) {
                m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
        }
    }

    cout << m[1][n] << endl;

    return 0;
}

