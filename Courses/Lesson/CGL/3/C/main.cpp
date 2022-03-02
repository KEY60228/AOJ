#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cassert>
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
bool intersect(Circle c, Line l) {
    Vector pr = project(l, c.c);
    return abs((pr - c.c).abs()) <= c.r;
}
bool intersect(Circle c1, Circle c2) {
    double d = abs((c1.c - c2.c).abs());
    return d <= (c1.r + c2.r);
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
// 線分と線分の交点を返す
Point getCrossPoint(Segment s1, Segment s2) {
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}
// 円と線分の交点を返す
pair<Point, Point> getCrossPoints(Circle c, Line l) {
    assert(intersect(c, l));
    Vector pr = project(l, c.c);
    Vector e = (l.p2 - l.p1) / abs((l.p2 - l.p1).abs());
    double base = sqrt((c.r * c.r) - (pr - c.c).norm());
    return make_pair(pr + e * base, pr - e * base);
}
// 円と円の交点を返す
double arg(Vector p) {
    return atan2(p.y, p.x);
}
Vector polar(double a, double r) {
    return Point(cos(r) * a, sin(r) * a);
}
pair<Point, Point> getCrossPoints(Circle c1, Circle c2) {
    assert(intersect(c1, c2));
    double d = abs((c1.c - c2.c).abs());
    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}
// 点の内包関係を返す
static const int CONTAINMENT_IN = 2;
static const int CONTAINMENT_ON = 1;
static const int CONTAINMENT_OUT = 0;
int contains(Polygon g, Point p) {
    int n = g.size();
    bool x = false;
    for (int i = 0; i < n; i++) {
        Point a = g[i] - p;
        Point b = g[(i + 1) % n] - p;
        if (abs(cross(a, b)) < EPS && dot(a, b) < EPS) return CONTAINMENT_ON;
        if (a.y > b.y) swap(a, b);
        if (a.y < EPS && EPS < b.y && cross(a, b) > EPS) x = !x;
    }
    return x ? CONTAINMENT_IN : CONTAINMENT_OUT;
}

void solve(Polygon g, Point p) {
    cout << contains(g, p) << endl;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int n;
    cin >> n;

    Polygon p;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        p.push_back(Point(x, y));
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        double x, y;
        cin >> x >> y;
        solve(p, Point(x, y));
    }

    return 0;
}
