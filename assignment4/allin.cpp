#include <iostream>
using namespace std;int a[500000],z,s,b,n,d,q=9000,l,r,i;int main(){freopen("allin.inp","r",stdin);freopen("allin.out","w",stdout);cin>>n;for(i=0;i<n;)cin>>a[i++];for(i=0;i<n;i++){if(a[i]<=q)q=a[i],l=i;else{d=a[i]-q;if(d>z)r=i,z=d,b=l,s=r;if(d==z&&(b<l||(b==l&&s>i)))b=l,s=i;}}cout<<b+1<<' '<<s+1;}
