#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
// #include <fstream>

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

using namespace std;

class Point {
    public:
        double x;
        double y;
        Point(double x = 0.0, double y = 0.0): x(x), y(y) {}

        Point operator + (Point p) {
            return Point(x + p.x, y + p.y);
        }
        Point operator - (Point p) {
            return Point(x - p.x, y - p.y);
        }
        Point operator * (double k) {
            return Point(x * k, y * k);
        }
        Point operator / (double k) {
            return Point(x / k, y / k);
        }
        bool operator < (const Point &p) const {
            return x != p.x ? x < p.x : y < p.y;
        }
        bool operator == (const Point &p) const {
            return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
        }

        // ベクトルの大きさを返す
        double abs() {
            return sqrt(norm());
        }
        // ベクトルのノルムを返す
        double norm() {
            return x * x + y * y;
        }
};
class EndPoint {
    public:
        Point p;
        int seg, st;
        EndPoint() {}
        EndPoint(Point p, int seg, int st): p(p), seg(seg), st(st) {}

        bool operator < (const EndPoint &ep) const {
            if (p.y == ep.p.y) {
                return st < ep.st;
            } else {
                return p.y < ep.p.y;
            }
        }
};
struct Segment {
    Point p1;
    Point p2;
};

EndPoint EP[2 * 100000];

int manhattanIntersection(vector<Segment> S) {
    int n = S.size();

    for (int i = 0, k = 0; i < n; i++) {
        if (S[i].p1.y == S[i].p2.y) {
            if (S[i].p1.x > S[i].p2.x) {
                swap(S[i].p1, S[i].p2);
            }
        } else if (S[i].p1.y > S[i].p2.y) {
            swap(S[i].p1, S[i].p2);
        }

        if (S[i].p1.y == S[i].p2.y) {
            EP[k++] = EndPoint(S[i].p1, i, LEFT);
            EP[k++] = EndPoint(S[i].p2, i, RIGHT);
        } else {
            EP[k++] = EndPoint(S[i].p1, i, BOTTOM);
            EP[k++] = EndPoint(S[i].p2, i, TOP);
        }
    }

    sort(EP, EP + (2 * n));

    set<int> BT;
    BT.insert(1000000001);
    int cnt = 0;

    for (int i = 0; i < 2 * n; i++) {
        if (EP[i].st == TOP) {
            BT.erase(EP[i].p.x);
        } else if (EP[i].st == BOTTOM) {
            BT.insert(EP[i].p.x);
        } else if (EP[i].st == LEFT) {
            set<int>::iterator b = BT.lower_bound(S[EP[i].seg].p1.x);
            set<int>::iterator e = BT.upper_bound(S[EP[i].seg].p2.x);
            cnt += distance(b, e);
        }
    }

    return cnt;
}

void solve(vector<Segment> S) {
    cout << manhattanIntersection(S) << endl;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int n;
    cin >> n;

    vector<Segment> v;
    for (int i = 0; i < n; i++) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v.push_back(Segment{Point(x1, y1), Point(x2, y2)});
    }
    solve(v);

    return 0;
}
