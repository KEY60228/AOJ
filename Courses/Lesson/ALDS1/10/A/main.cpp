#include <iostream>
#include <vector>
// #include <fstream>

#define ll long long int

using namespace std;

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    ll n;
    cin >> n;

    vector<ll> v(45);
    v[0] = 1;
    v[1] = 1;
    for (ll i = 2; i <= n; i++) {
        v[i] = v[i - 2] + v[i - 1];
    }

    cout << v[n] << endl;

    return 0;
}

