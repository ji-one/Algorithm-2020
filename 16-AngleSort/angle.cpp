#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int x, y, index;
};
vector<Point> Q1, Q2;
Point p;

int ccw(Point a, Point b, Point c)
{
    int sarea = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + c.x * b.y + a.x * c.y);
    if (sarea < 0)
        return -1;
    else if (sarea > 0)
        return 1;
    else
        return 0;
}
int distance(Point a, Point b)
{
    int d = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return d;
}

bool compare(Point a, Point b)
{
    if (ccw(p, a, b) > 0)
    {
        return true;
    }
    else if (ccw(p, a, b) < 0)
    {
        return false;
    }
    else
    {
        if (distance(a, p) < distance(b, p))
            return true;
        else
            return false;
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("angle.inp", "r", stdin);
    freopen("angle.out", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y >= 0)
            Q1.push_back({x, y, i + 1});
        else
            Q2.push_back({x, y, i + 1});
    }

    p.x = 0, p.y = 0;
    sort(Q1.begin(), Q1.end(), compare);
    for (int i = 0; i < Q1.size(); i++)
    {
        cout << Q1[i].index << '\n';
    }
    sort(Q2.begin(), Q2.end(), compare);
    for (int i = 0; i < Q2.size(); i++)
    {
        cout << Q2[i].index << '\n';
    }
    return 0;
}
