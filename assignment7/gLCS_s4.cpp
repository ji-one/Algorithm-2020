#include <bits/stdc++.h>
using namespace std;

ifstream  in("gLCS.inp");
ofstream out("gLCS.out");
string a, b;
vector<string> ans;
vector< pair<int, int> > vec;
const int space = 5;
int cache[501 +space][501 +space], lena, lenb, len = 1;
void print(int, int, string, int);

void init(){

    in>>a>>b;
    memset(cache, 0, sizeof(cache));
    lena = a.length(); lenb = b.length();

    for(int i = space; i< lena + space; i++){
        for(int j = space; j< lenb + space; j++){
            if(a[i-space] != b[j-space])    continue;
            cache[i][j] = max(cache[i-1][j-1], max(cache[i-2][j-1], max(cache[i-1][j-2], cache[i-2][j-2]) ) ) +1;
            if( len < cache[i][j] ){
                vec.clear();
                len = cache[i][j];
            }
            if(len == cache[i][j])  vec.push_back(make_pair(i,j));
        }
    }
}

void Solve(){

    for(auto s: vec){
        string temp = "";
        print(s.first, s.second, temp, len);
    }
    sort(ans.begin(), ans.end());
    out<<*(ans.begin())<<endl;
}

void print(int i, int j, string k, int s){

    if(s == 1){
        k += a[i-space];
        reverse(k.begin(), k.end());
        ans.push_back(k);
        return;
    }
    if(s-1 == cache[i-1][j-1]) print(i-1, j-1, k+a[i-space], s-1);
    if(s-1 == cache[i-1][j-2]) print(i-1, j-2, k+a[i-space], s-1);
    if(s-1 == cache[i-2][j-1]) print(i-2, j-1, k+a[i-space], s-1);
    if(s-1 == cache[i-2][j-2]) print(i-2, j-2, k+a[i-space], s-1);
}

int main(void){

    init();
    Solve();
    in.close(); out.close();
    return 0;
}