#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <cmath>
// #include <fstream>

#define N 3
#define N2 9

using namespace std;

struct Puzzle {
    int f[N2];
    int space;
    string path;

    bool operator < (const Puzzle &p) const {
        for (int i = 0; i < N2; i++) {
            if (f[i] == p.f[i]) continue;
            return f[i] > p.f[i];
        }
        return false;
    }
};

static const vector<int> dx{-1, 0, 1, 0};
static const vector<int> dy{0, -1, 0, 1};
static const vector<char> dir = {'u', 'l', 'd', 'r'};

bool isTarget(Puzzle p) {
    for (int i = 0; i < N2; i++) {
        if (p.f[i] != (i + 1)) return false;
    }
    return true;
}

string bfs(Puzzle s) {
    queue<Puzzle> Q;
    map<Puzzle, bool> V;
    Puzzle u, v;
    s.path = "";
    Q.push(s);
    V[s] = true;

    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        if (isTarget(u)) {
            return u.path;
        }

        int sx = u.space / N;
        int sy = u.space % N;
        for (int r = 0; r < 4; r++) {
            int tx = sx + dx[r];
            int ty = sy + dy[r];
            if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;

            v = u;
            swap(v.f[u.space], v.f[tx * N + ty]);
            v.space = tx * N + ty;
            if (!V[v]) {
                V[v] = true;
                v.path += dir[r];
                Q.push(v);
            }
        }
    }
    return "unsolvable";
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    Puzzle p;
    for (int i = 0; i < N2; i++) {
        cin >> p.f[i];
        if (p.f[i] == 0) {
            p.f[i] = N2;
            p.space = i;
        }
    }

    string ans = bfs(p);
    cout << ans.size() << endl;

    return 0;
}
