#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
double rst=2000000000.0;
double x,y,z;//P
int binarySearch(double lx, double ly,double lz, double rx, double ry, double rz)
{
    double mx = (lx + rx)/2.0;
    double my = (ly + ry)/2.0;
    double mz = (lz + rz)/2.0;

    double ld = sqrt(pow((x-lx),2)+pow(y-ly,2)+pow(z-lz,2)); //왼쪽 선분 거리
    double rd = sqrt(pow((x-rx),2)+pow(y-ry,2)+pow(z-rz,2)); //오른쪽 선분 거리
    double md = sqrt(pow((x-mx),2)+pow(y-my,2)+pow(z-mz,2)); 

    if(abs(md-rst)<=0.000000000001)
    {
        return 0;
    }

    if(md<rst)
    {
        rst=md;
    }

    if(rd<ld)
    {
        binarySearch(mx,my,mz,rx,ry,rz);
    }
    else
    {
        binarySearch(lx,ly,lz,mx,my,mz);
    }
    
    return 0;
}
int main(void)
{    
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    freopen("station.inp","r",stdin);
    freopen("station.out","w",stdout);
    double x1,x2,y1,y2,z1,z2;//A B
    cin>>x1>>y1>>z1>>x2>>y2>>z2>>x>>y>>z;
    binarySearch(x1,y1,z1,x2,y2,z2);
    if(rst-floor(rst)<=0.00000000001) 
    {
        cout<<static_cast<int>(rst);
    }
    else cout<<ceil(rst)<<'\n';
    
    return 0;
}
