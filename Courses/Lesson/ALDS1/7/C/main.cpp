#include <iostream>
#include <vector>
// #include <fstream>

#define MAX 10000
#define NIL -1
#define ll long long int

using namespace std;

struct Node {
    int p;
    int l;
    int r;
};
vector<Node> T(MAX);

void preParse(ll u) {
    if (u == NIL) return;
    cout << " " << u;
    preParse(T[u].l);
    preParse(T[u].r);
}

void inParse(ll u) {
    if (u == NIL) return;
    inParse(T[u].l);
    cout << " " << u;
    inParse(T[u].r);
}

void postParse(ll u) {
    if (u == NIL) return;
    postParse(T[u].l);
    postParse(T[u].r);
    cout << " " << u;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        T[i].p = NIL;
    }

    for (ll i = 0; i < n; i++) {
        ll v, l, r;
        cin >> v >> l >> r;
        T[v].l = l;
        T[v].r = r;
        if (l != NIL) T[l].p = v;
        if (r != NIL) T[r].p = v;
    }

    ll root;
    for (ll i = 0; i < n; i++) {
        if (T[i].p == NIL) {
            root = i;
        }
    }

    cout << "Preorder" << endl;
    preParse(root);
    cout << endl;
    cout << "Inorder" << endl;
    inParse(root);
    cout << endl;
    cout << "Postorder" << endl;
    postParse(root);
    cout << endl;

    return 0;
}
