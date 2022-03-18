#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
// #include <fstream>

using namespace std;

struct Rectangle {
    int height;
    int pos;
};

int compute(int size, vector<int> buffer) {
    stack<Rectangle> S;
    int maxv = 0;
    buffer[size] = 0;

    for (int i = 0; i <= size; i++) {
        Rectangle rect;
        rect.height = buffer[i];
        rect.pos = i;
        if (S.empty()) {
            S.push(rect);
        } else {
            if (S.top().height < rect.height) {
                S.push(rect);
            } else if (S.top().height > rect.height) {
                int target = i;
                while (!S.empty() && S.top().height >= rect.height) {
                    Rectangle pre = S.top();
                    S.pop();
                    int area = pre.height * (i - pre.pos);
                    maxv = max(maxv, area);
                    target = pre.pos;
                }
                rect.pos = target;
                S.push(rect);
            }
        }
    }
    return maxv;
}

int getLargestRectangle(vector<vector<int>> v) {
    vector<vector<int>> T(v.size(), vector<int>(v[0].size() + 1));
    for (int j = 0; j < v[0].size(); j++) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i][j]) {
                T[i][j] = 0;
            } else {
                T[i][j] = i > 0 ? T[i - 1][j] + 1 : 1;
            }
        }
    }

    int maxv = 0;
    for (int i = 0; i < v.size(); i++) {
        maxv = max(maxv, compute(v[i].size(), T[i]));
    }
    return maxv;
}

void solve(vector<vector<int>> v) {
    cout << getLargestRectangle(v) << endl;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int h, w;
    cin >> h >> w;

    vector<vector<int>> v(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> v[i][j];
        }
    }
    solve(v);

    return 0;
}
