#include <iostream>
#include <vector>
#include <algorithm>
// #include <fstream>

#define ll long long int
#define MAX 100000
#define INFTY 1<<29

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

class Edge {
    public:
        ll source, target, cost;
        Edge(ll source = 0, ll target = 0, ll cost = 0): source(source), target(target), cost(cost) {}
        bool operator < (const Edge &e) const {
            return cost < e.cost;
        }
};

ll kruskal(ll N, vector<Edge> edges) {
    ll totalCost = 0;
    sort(edges.begin(), edges.end());

    DisjointSet dset = DisjointSet(N + 1);

    for (ll i = 0; i < N; i++) {
        dset.makeSet(i);
    }

    ll source, target;
    for (ll i = 0; i < edges.size(); i++) {
        Edge e = edges[i];
        if (!dset.same(e.source, e.target)) {
            totalCost += e.cost;
            dset.unite(e.source, e.target);
        }
    }
    return totalCost;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    ll N, M;
    cin >> N >> M;

    vector<Edge> edges;
    for (ll i = 0; i < M; i++) {
        ll source, target, cost;
        cin >> source >> target >> cost;
        edges.push_back(Edge(source, target, cost));
    }

    cout << kruskal(N, edges) << endl;

    return 0;
}
