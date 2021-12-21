#include <iostream>
#include <vector>
#include <algorithm>
// #include <fstream>

#define ll long long int

using namespace std;

vector<ll> pre, in, post;
ll pos;

void rec(ll l, ll r) {
    if (l >= r) return;
    ll root = pre[pos++];
    ll m = distance(in.begin(), find(in.begin(), in.end(), root));
    rec(l, m);
    rec(m + 1, r);
    post.push_back(root);
}

void solve(ll n) {
    pos = 0;
    rec(0, pre.size());
    for (ll i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << post[i];
    }
    cout << endl;
}

int main() {
    // ifstream inin("input.txt");
    // cin.rdbuf(inin.rdbuf());

    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        ll k;
        cin >> k;
        pre.push_back(k);
    }

    for (ll i = 0; i < n; i++) {
        ll k;
        cin >> k;
        in.push_back(k);
    }

    solve(n);

    return 0;
}
