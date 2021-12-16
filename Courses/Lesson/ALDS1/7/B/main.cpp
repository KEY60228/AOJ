#include <iostream>
#include <vector>
// #include <fstream>

#define MAX 10000
#define NIL -1
#define ll long long int

using namespace std;

struct Node {
    ll parent;
    ll left;
    ll right;
};

vector<Node> T(MAX);
vector<ll> D(MAX), H(MAX);

void setDepth(ll u, ll d) {
    if (u == NIL) return;
    D[u] = d;
    setDepth(T[u].left, d + 1);
    setDepth(T[u].right, d + 1);
}

ll setHeight(ll u) {
    ll h1 = 0, h2 = 0;
    if (T[u].left != NIL) {
        h1 = setHeight(T[u].left) + 1;
    }
    if (T[u].right != NIL) {
        h2 = setHeight(T[u].right) + 1;
    }
    return H[u] = (h1 > h2 ? h1 : h2);
}

int getSibling(ll u) {
    if (T[u].parent == NIL) {
        return NIL;
    }
    if (T[T[u].parent].left != u && T[T[u].parent].left != NIL) {
        return T[T[u].parent].left;
    }
    if (T[T[u].parent].right != u && T[T[u].parent].right != NIL) {
        return T[T[u].parent].right;
    }
    return NIL;
}

void print(ll u) {
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "sibling = " << getSibling(u) << ", ";
    ll deg = 0;
    if (T[u].left != NIL) deg++;
    if (T[u].right != NIL) deg++;
    cout << "degree = " << deg << ", ";
    cout << "depth = " << D[u] << ", ";
    cout << "height = " << H[u] << ", ";

    if (T[u].parent == NIL) {
        cout << "root" << endl;
    } else if (T[u].left == NIL && T[u].right == NIL) {
        cout << "leaf" << endl;
    } else {
        cout << "internal node" << endl;
    }
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        T[i].parent = NIL;
    }

    for (ll i = 0; i < n; i++) {
        ll v, l, r;
        cin >> v >> l >> r;
        T[v].left = l;
        T[v].right = r;
        if (l != NIL) {
            T[l].parent = v;
        }
        if (r != NIL) {
            T[r].parent = v;
        }
    }

    ll root = 0;
    for (ll i = 0; i < n; i++) {
        if (T[i].parent == NIL) {
            root = i;
        }
    }

    setDepth(root, 0);
    setHeight(root);

    for (ll i = 0; i < n; i++) {
        print(i);
    }

    return 0;
}
