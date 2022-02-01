#include <iostream>
#include <vector>
#include <algorithm>
// #include <fstream>

#define ll long long int

using namespace std;

class Node {
    public:
        ll location;
        ll p, l, r;

        Node() {}
};

class Point {
    public:
        ll id, x, y;

        Point() {};
        Point(ll id, ll x, ll y): id(id), x(x), y(y) {}
        bool operator < (const Point &p) const {
            return id < p.id;
        }

        void print() {
            cout << id << endl;
        }
};

const ll MAX = 1000000;
const ll NIL = -1;
ll N;
Point P[MAX];
Node T[MAX];
ll np;

bool lessX(const Point &p1, const Point &p2) {
    return p1.x < p2.x;
}
bool lessY(const Point &p1, const Point &p2) {
    return p1.y < p2.y;
}

ll makeKDTree(ll l, ll r, ll depth) {
    if (!(l < r)) return NIL;
    ll mid = (l + r) / 2;
    ll t = np++;
    if (depth % 2 == 0) {
        sort(P + l, P + r, lessX);
    } else {
        sort(P + l, P + r, lessY);
    }
    T[t].location = mid;
    T[t].l = makeKDTree(l, mid, depth + 1);
    T[t].r = makeKDTree(mid + 1, r , depth + 1);

    return t;
}

void find(ll v, ll sx, ll tx, ll sy, ll ty, ll depth, vector<Point> &ans) {
    ll x = P[T[v].location].x;
    ll y = P[T[v].location].y;

    if (sx <= x && x <= tx && sy <= y && y <= ty) {
        ans.push_back(P[T[v].location]);
    }

    if (depth % 2 == 0) {
        if (T[v].l != NIL) {
            if (sx <= x) find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
        }
        if (T[v].r != NIL) {
            if (x <= tx) find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
        }
    } else {
        if (T[v].l != NIL) {
            if (sy <= y) find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
        }
        if (T[v].r != NIL) {
            if (y <= ty) find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
        }
    }
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    cin >> N;
    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        P[i] = Point(i, x, y);
        T[i].l = T[i].r = T[i].p = NIL;
    }

    np = 0;

    ll root = makeKDTree(0, N, 0);

    ll q;
    cin >> q;
    vector<Point> ans;
    for (ll i = 0; i < q; i++) {
        ll sx, tx, sy, ty;
        cin >> sx >> tx >> sy >> ty;
        ans.clear();
        find(root, sx, tx, sy, ty, 0, ans);
        sort(ans.begin(), ans.end());
        for (ll j = 0; j < ans.size(); j++) {
            ans[j].print();
        }
        cout << endl;
    }

    return 0;
}
