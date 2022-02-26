#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
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
// 線分sに対する点pの射影を返す
Point project(Segment s, Point p) {
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / base.norm();
    return s.p1 + base * r;
}
// 線分sを対象軸とした点pの線対称の点を返す
Point reflect(Segment s, Point p) {
    return p + (project(s, p) - p) * 2.0;
}
// 3点の位置関係を返す
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
int ccw(Point p0, Point p1, Point p2) {
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS) return CLOCKWISE;
    if (dot(a, b) < -EPS) return ONLINE_BACK;
    if (a.norm() < b.norm()) return ONLINE_FRONT;
    return ON_SEGMENT;
}
// 線分と線分が交差しているか返す
bool intersect(Point p1, Point p2, Point p3, Point p4) {
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
bool intersect(Segment s1, Segment s2) {
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}
// 2点間の距離を返す
double getDistance(Point a, Point b) {
    return abs((a - b).abs());
}
// 点と直線の距離を返す
double getDistanceLP(Line l, Point p) {
    return abs(cross(l.p2 - l.p1, p - l.p1)) / abs((l.p2 - l.p1).abs());
}
// 点と線分の距離を返す
double getDistanceSP(Segment s, Point p) {
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs((p - s.p1).abs());
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs((p - s.p2).abs());
    return getDistanceLP(s, p);
}
// 線分と線分の距離を返す
double getDistance(Segment s1, Segment s2) {
    if (intersect(s1, s2)) return 0.0;
    return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)), min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

void solve(Point p0, Point p1, Point p2) {
    switch (ccw(p0, p1, p2)) {
        case COUNTER_CLOCKWISE:
            cout << "COUNTER_CLOCKWISE" << endl;
            break;
        case CLOCKWISE:
            cout << "CLOCKWISE" << endl;
            break;
        case ONLINE_BACK:
            cout << "ONLINE_BACK" << endl;
            break;
        case ONLINE_FRONT:
            cout << "ONLINE_FRONT" << endl;
            break;
        case ON_SEGMENT:
            cout << "ON_SEGMENT" << endl;
            break;
    }
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    double p1x, p1y, p2x, p2y;
    cin >> p1x >> p1y >> p2x >> p2y;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        double px, py;
        cin >> px >> py;

        solve(Point(p1x, p1y), Point(p2x, p2y), Point(px, py));
    }

    return 0;
}
