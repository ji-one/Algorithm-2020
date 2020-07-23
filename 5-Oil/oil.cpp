#include <bits/stdc++.h>
#include "oil.h"
using namespace std;

typedef struct
{
    int a;
    int b;
} Pos;

vector<Pos> range(int s, int e)
{
    Pos x, y;
    vector<Pos> v;
    int m = (s + e) / 2;
    x.a = s;
    x.b = m;
    y.a = m + 1;
    y.b = e;
    v.push_back(x);
    v.push_back(y);
    return v;
}

int solve(Pos p, bool flag)
{
    int rst, state;
    if (p.a == p.b)
        return p.a;

    vector<Pos> v;
    v = range(p.a, p.b);
    if (flag == 0) //starting point
    {
        state = observe(v[0].a, v[0].b);
        if (state == 1)
        {
            rst = v[0].a;
        }
        else if (state == 2)
        {
            rst = solve(v[0], 0);
        }
        else
        {
            rst = solve(v[1], 0);
        }
    }
    else //ending point
    {
        state = observe(v[1].a, v[1].b);
        if (state == 1)
        {
            rst = v[1].b;
        }
        else if (state == 2)
        {
            rst = solve(v[1], 1);
        }
        else
        {
            rst = solve(v[0], 1);
        }
    }
    return rst;
}
int main()
{
    initial();
    int n = oil_size();
    Pos p;
    p.a = 0, p.b = n - 1;
    int i = solve(p, 0);
    int j = solve(p, 1);
    oil_report(i, j);
    return 0;
}
