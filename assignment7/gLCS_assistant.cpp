#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int T[501][501] = {0,};
int n,m;

string path;
queue < pair < int,int > > starts;

// boundary check를 겸한 안전한 index 참조 함수
int safe_get(int x,int y) {
    if( x<0 || y<0 ) return 0;
    return T[x][y];
}

void get_path(int x, int y, string& current_path) {
    
    // 경로 탐색
    
    // 탐색 종점에 도달했을 경우
    if(x < 0 || y < 0 || T[x][y] == 0) {
        string temp(current_path);
        reverse(temp.begin(),temp.end());
        
        // 정답 갱신
        if(path.empty()) {
            path = temp;
        }
        else if(path.compare(temp) > 0) {
            path = temp;
        }
        return;            
    }
    
    // 탐색 종점이 아닐 경우
    
    current_path.push_back(s1[x]);
    int dx[4] = {-2,-1,-2,-1}, dy[4] = {-2,-2,-1,-1};
    
    // 탐색 후보를 찾아서 DFS 경로 탐색 진행
    for(int i=0; i<4; i++) {
        int X = x + dx[i], Y = y + dy[i];
        if(T[X][Y] == T[x][y]-1) {
            get_path(X,Y,current_path);
        }
    }
    current_path.pop_back();
}

int main() {
    
    //입력 시작
    ifstream in("gLCS.inp");
    
    in >> s1 >> s2;
        
    in.close();
    
    n=s1.length(), m=s2.length();
    
    // 입력 끝
    
    // Bottom-up 방식으로 gap-LCS Table 작성
    
    int ans = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(s1[i] == s2[j]) {
                // 고려해야할 위치는 -2 -2, -2 -1, -1 -2, -1 -1
                T[i][j] = max({safe_get(i-1, j-1), safe_get(i-2, j-1), safe_get(i-1, j-2), safe_get(i-2, j-2)}) + 1;
            }
            // 경로 탐색 시작점 갱신 및 저장
            if(ans < T[i][j]) {
                while(!starts.empty()) starts.pop();
                ans = T[i][j];
            }
            if(ans == T[i][j]) {
                starts.push({i,j});
            }
        }
    }
    // gap-LCS Table 작성 종료
    
    // 경로 탐색 시작
    
    while(!starts.empty()) {
        int x = starts.front().first;
        int y = starts.front().second;
        starts.pop();
        string q("");
        get_path(x,y,q);
    }
    
    // 경로 탐색 종료
    
    // 출력 시작
    
    ofstream out("gLCS.out");
    out << path;
    out.close();
    
    // 출력 끝
    
    return 0;
}
