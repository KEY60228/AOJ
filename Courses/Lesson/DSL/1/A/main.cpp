#include <iostream>
#include <vector>
// #include <fstream>

#define ll long long int

using namespace std;

class DisjointSet {
    public:
        vector<ll> rank, p;

        DisjointSet() {}
        DisjointSet(ll size) {
            rank.resize(size, 0);
            p.resize(size, 0);
            for (ll i = 0; i < size; i++) {
                makeSet(i);
            }
        }

        void makeSet(ll x) {
            p[x] = x;
            rank[x] = 0;
        }

        bool same(ll x, ll y) {
            return findSet(x) == findSet(y);
        }

        void unite(ll x, ll y) {
            link(findSet(x), findSet(y));
        }

        void link(ll x, ll y) {
            if (rank[x] > rank[y]) {
                p[y] = x;
            } else {
                p[x] = y;
                if (rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
        }

        ll findSet(ll x) {
            if (x != p[x]) {
                p[x] = findSet(p[x]);
            }
            return p[x];
        }
};

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    ll n, q;
    cin >> n >> q;

    DisjointSet ds = DisjointSet(n);

    for (ll i = 0; i < q; i++) {
        ll t, a, b;
        cin >> t >> a >> b;
        if (t == 0) {
            ds.unite(a, b);
        } else if (t == 1) {
            if (ds.same(a, b)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}
