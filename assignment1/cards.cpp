#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(void)
{    
    freopen("cards.inp","r",stdin);
    freopen("cards.out","w",stdout);
    int n;
    cin>>n;

    int totalsum = (n*(n+1))/2;
    int totalsqr = (n*(n+1)*(2*n+1))/6; //제곱의 합
    int partsum=0;
    int partsqr=0;
  
  
    int num;
    for(int i=0;i<n-2;i++)
    {
        cin>>num;
        partsum+=num;
        partsqr+=(num*num);        
    }

    int a = totalsqr-partsqr;
    int b = totalsum-partsum;

    cout<<(b-sqrt(2*a-b*b))/2<<'\n'<<(b+sqrt(2*a-b*b))/2;

    return 0;
}
