#include <iostream>
using namespace std;
#define D1 10000
struct PNT
{
    double x;
    double y;
};
bool A(PNT p, PNT q, PNT r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}
int B(PNT p, PNT q, PNT r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}
bool C(PNT p1, PNT q1, PNT p2, PNT q2)
{
    int u = B(p1, q1, p2);
    int v = B(p1, q1, q2);
    int f = B(p2, q2, p1);
    int g = B(p2, q2, q1);
    if (u != v && f != g)
        return true;
    if (u == 0 && A(p1, p2, q1))
        return true;
    if (v == 0 && A(p1, q2, q1))
        return true;
    if (f == 0 && A(p2, p1, q2))
        return true;
    if (g == 0 && A(p2, q1, q2))
        return true;
    return false;
}
bool pinsidepolygon(PNT polygon[], int n, PNT p)
{
    if (n < 3)
        return false;
    PNT extreme = {D1, p.y};
    int count = 0, i = 0;
    do
    {
        int next = (i + 1) % n;
        if (C(polygon[i], polygon[next], p, extreme))
        {
            if (B(polygon[i], p, polygon[next]) == 0)
                return A(polygon[i], p, polygon[next]);
            count++;
        }
        i = next;
    } while (i != 0);

    return count % 2 == 1;
}
int main()
{
    PNT polygon1[] = {{1, 0}, {8, 3}, {8, 8}, {1, 5}};
    int n = sizeof(polygon1) / sizeof(polygon1[1]);
    PNT p = {3, 5};
    pinsidepolygon(polygon1, n, p) ? cout << "True \n" : cout << "False \n";

    PNT polygon2[] = {{-3, 2}, {-2, -0.8}, {0, 1.2}, {2.2, 0}, {2, 4.5}};
    p = {0, 0};
    n = sizeof(polygon2) / sizeof(polygon2[-3]);
    pinsidepolygon(polygon2, n, p) ? cout << "True \n" : cout << "False \n";
    return 0;
}
