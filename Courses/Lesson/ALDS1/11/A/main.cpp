#include <iostream>
#include <vector>
// #include <fstream>

#define ll long long int

using namespace std;

ll N = 100;

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    ll n;
    cin >> n;

    vector<vector<ll>> v(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++) {
        ll u, k;
        cin >> u >> k;
        for (ll j = 0; j < k; j++) {
            ll m;
            cin >> m;
            v[u - 1][m - 1] = 1;
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (j != 0) {
                cout << " ";
            }
            cout << v[i][j];
        }
        cout << endl;
    }

    return 0;
}
