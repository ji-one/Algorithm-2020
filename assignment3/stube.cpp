#include <bits/stdc++.h>
using namespace std;
double rst = 2000000000.0;
double x, y, z; //closest point
int check(double n)
{
    if(abs(n-floor(n))<=0.00001) 
    {
        return static_cast<int>(n);
    }
    else
    {
        return ceil(n);    
    }
}

int binarySearch(double lx, double ly, double lz, double rx, double ry, double rz)
{
    double mx = (lx + rx) / 2.0;
    double my = (ly + ry) / 2.0;
    double mz = (lz + rz) / 2.0;

    double ld = sqrt(pow((x - lx), 2) + pow(y - ly, 2) + pow(z - lz, 2));
    double rd = sqrt(pow((x - rx), 2) + pow(y - ry, 2) + pow(z - rz, 2));
    double md = sqrt(pow((x - mx), 2) + pow(y - my, 2) + pow(z - mz, 2));

    
    //if (ld == rd)
    if(abs(md-rst)<=0.0000001)
    {
        x = mx;
        y = my;
        z = mz;
        return 0;
    }

    if (md < rst)
    {
        rst = md;
    }

    if (rd < ld)
    {
        binarySearch(mx, my, mz, rx, ry, rz);
    }
    else
    {
        binarySearch(lx, ly, lz, mx, my, mz);
    }
    return 0;
}
int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    freopen("8.inp", "r", stdin);
    freopen("stube.out", "w", stdout);
    double x1, x2, y1, y2, z1, z2, x3, x4, y3, y4, z3, z4; //A B C D
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3 >> x4 >> y4 >> z4;
    x = x3;
    y = y3;
    z = z3;
    int prev = 2000000000;

    double a = x2 - x1;
    double b = x3 - x4;
    double c = x3 - x1;
    double d = y2 - y1;
    double e = y3 - y4;
    double f = y3 - y1;

    double t = (c * e - f * b) / (e * a - b * d);
    double s = (d * c - a * f) / (d * b - a * e);

    if ((t * (z2 - z1) + s * (z3 - z4)) == z3 - z1)
    {
        if (t >= 0 && t <= 1 && s >= 0 && s <= 1)
        {
            cout << 0;
            return 0;
        }
    }


    while (1)
    {
        binarySearch(x1, y1, z1, x2, y2, z2);
        int d1 = check(rst);
        cout<<"d1 : "<<setprecision(10)<<rst<<'\n';
        if (prev <= d1)
        {
            cout << prev;
            break;
        }
        rst = 2000000000.0;
        binarySearch(x3, y3, z3, x4, y4, z4);
        cout<<"d2 : "<<rst<<'\n';
        int d2 = check(rst);

        if (d1 <= d2)
        {
            cout << d1;
            break;
        }  
        rst = 2000000000.0;
        prev = d2;
    }
    return 0;
}
