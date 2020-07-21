#include <bits/stdc++.h>
using namespace std;

int b,s, ans = 0;
int price[500001];
void update_answer(int _b, int _s, int value) {
    if(value < ans) return;
    if(value == ans && _b < b) return;
    if(value == ans && _b < b && _s > s) return;
    ans = value;
    b = _b;
    s = _s;
}

void solve(int lo, int hi) {
    if(lo == hi) {
        update_answer(lo,hi,0);
        return;
    }
    int mid = (lo+hi)/2;
    int lmin = 1e9, lidx = -1;
    int rmax = 0, ridx = -1;
    for(int i=lo; i<mid; i++) {
        if(lmin >= price[i]) {
            lmin = price[i];
            lidx = i;
        }
    }
    for(int i=mid; i<hi; i++) {
        if(rmax < price[i]) {
            rmax = price[i];
            ridx = i;
        }
    }
    if(rmax - lmin >= 0) {
        printf("[%d ~ %d] : found case of %d - %d: %d",lo,hi,lidx,ridx,rmax-lmin);
        update_answer(lidx, ridx, rmax - lmin);
    }
    solve(lo, mid);
    solve(mid+1, hi);
}
int main() {
    
    ifstream in("allin.inp");
    ofstream out("allin.out");
    
    int N;
    in >> N;
    for(int i=1; i<=N; i++) {
        in >> price[i];
    }
    
    solve(1,N+1);
    out << ans << '\n';
    out << b << ' ' << s;
    
    in.close();
    out.close();
    
    return 0;
}
