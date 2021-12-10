#include <iostream>
#include <vector>
// #include <fstream>

#define MAX 100001

using namespace std;

struct Node {
    int p;
    int l;
    int r;
};
vector<Node> T(MAX);
vector<int> D(MAX);
int n;

void print(int u) {
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].p << ", ";
    cout << "depth = " << D[u] << ", ";

    if (T[u].p == -1) {
        cout << "root, ";
    } else if (T[u].l == -1) {
        cout << "leaf, ";
    } else {
        cout << "internal node, ";
    }

    cout << "[";

    for (int i = 0, c = T[u].l; c != -1; i++, c = T[c].r) {
        if (i != 0) {
            cout << ", ";
        }
        cout << c;
    }

    cout << "]" << endl;
}

void rec(int u, int p) {
    D[u] = p;
    if (T[u].r != -1) {
        rec(T[u].r, p);
    }
    if (T[u].l != -1) {
        rec(T[u].l, p + 1);
    }
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    cin >> n;

    for (int i = 0; i < n; i++) {
        T[i] = Node{-1, -1, -1};
    }

    int l;
    for (int i = 0; i < n; i++) {
        int v, d;
        cin >> v >> d;
        for (int j = 0; j < d; j++) {
            int c;
            cin >> c;
            if (j == 0) {
                T[v].l = c;
            } else {
                T[l].r = c;
            }
            l = c;
            T[c].p = v;
        }
    }

    int r;
    for (int i = 0; i < n; i++) {
        if (T[i].p == -1) {
            r = i;
        }
    }

    rec(r, 0);

    for (int i = 0; i < n; i++) {
        print(i);
    }

    return 0;
}
