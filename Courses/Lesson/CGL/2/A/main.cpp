#include <iostream>
#include <vector>
#include <cmath>
// #include <fstream>

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

using namespace std;

// 点を表す
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
// ベクトルを表す
typedef Point Vector;
// 線分を表す
struct Segment {
    Point p1;
    Point p2;
};
// 直線を表す
typedef Segment Line;
// 円を表す
class Circle {
    public:
        Point c;
        double r;
        Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
};
// 多角形を表す
typedef vector<Point> Polygon;

// ベクトルの内積を求める
double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}
// ベクトルの外積を求める
double cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}
// 線分が平行するか判定
bool isParallel(Segment s1, Segment s2) {
    return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}
// 線分が直交するか判定
bool isOrthogonal(Segment s1, Segment s2) {
    return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

void solve(Segment s1, Segment s2) {
    if (isParallel(s1, s2)) {
        cout << 2 << endl;
    } else if (isOrthogonal(s1, s2)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;
        cin >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y >> p4x >> p4y;

        solve(Segment{Vector(p1x, p1y), Vector(p2x, p2y)}, Segment{Vector(p3x, p3y), Vector(p4x, p4y)});
    }

    return 0;
}
