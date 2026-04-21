#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;

    // Vector subtraction
    /*  Point A{5, 3}; Point B{2, 1}; 
    Point AB = A - B; 
    A(5,3) - B(2,1) → returns Point(3,2)    */
    Point operator-(const Point& other) const {
        return {x - other.x, y - other.y};
    }
};

// Dot product
double dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

// Cross product (2D)
double cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

// Distance between two points
double distance(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

// Distance from C to line/segment AB
double linePointDist(Point A, Point B, Point C, bool isSegment) {
    Point AB = B - A;
    Point AC = C - A;

    // Perpendicular distance to infinite line
    double dist = fabs(cross(AB, AC)) / distance(A, B);

    if (isSegment) {
        Point BC = C - B;
        if (dot(AB, BC) > 0) return distance(B, C);  // C beyond B
        if (dot(A - B, AC) > 0) return distance(A, C);  // C before A
    }

    return dist;  // perpendicular distance
}

// points: vector of polygon vertices in order (CW or CCW)
double polygonArea(const vector<Point>& points) {
    int N = points.size();
    long long area = 0;

    // Triangulate from points[0] to points[i] and points[i+1]
    for (int i = 1; i + 1 < N; i++) {
        Point a = points[i] - points[0];
        Point b = points[i+1] - points[0];
        area += cross(a, b);
    }

    return abs(area) / 2.0;  // area can be negative depending on orientation
}

/*if poiints x1, y1) and (x2, y2)
A = y2-y1
B = x2-x1
C = Ax1+By1*/
bool lineIntersection(double A1, double B1, double C1,
                      double A2, double B2, double C2,
                      Point &intersect) 
{
    double det = A1 * B2 - A2 * B1;  // determinant

    if (abs(det) < 1e-9) {
        // Lines are parallel or coincident
        return false;
    }

    intersect.x = (B2 * C1 - B1 * C2) / det;
    intersect.y = (A1 * C2 - A2 * C1) / det;
    return true;
}

int main() {
    Point A{0, 0};
    Point B{5, 0};
    Point C{3, 4};

    cout << linePointDist(A, B, C, true) << endl;  // distance from C to segment AB

    vector<Point> poly = {
        {0, 0},
        {4, 0},
        {3, 2},
        {4, 4},
        {0, 3}
    };

    cout << "Area of polygon: " << polygonArea(poly) << endl;
    
    return 0;
}
