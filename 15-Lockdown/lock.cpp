#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[50];
int a[50][50];
vector<int> v[1000];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int discovered[1000];
int number;
bool isCut[1000];
//vector<pair<int,int>> cut;
int tmp[1000];
bool visited[50][50];
vector<int> path;
int t;
int cnt = 0;

void bfs(int ci, int cj, vector<int> path)
{
    queue<pair<pair<int, int>, vector<int>>> q;
    q.push({{ci, cj}, path});
    while (!q.empty())
    {
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        visited[cy][cx] = true;
        vector<int> cv = q.front().second;
        q.pop();
        if (s[cy][cx] == 'T')
        {
            ++cnt;
            for (int i = 0; i < cv.size(); i++)
            {
                tmp[cv[i]]++;
                //cout << cv[i] << ' ';
            }
            //cout << '\n';
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                vector<int> nv = cv;
                //int nvisited =
                if (nx >= 0 && ny >= 0 && nx < m && ny < n)
                {
                    if (s[ny][nx] != '#' && !visited[ny][nx])
                    {
                        //nv.push_back(a[ny][nx]);
                        //visited[ny][nx] = true;
                        if (isCut[a[ny][nx]] && s[ny][nx] != 'T')
                        {
                            nv.push_back(a[ny][nx]);
                        }
                        q.push({{ny, nx}, nv});
                    }
                }
            }
        }
    }
}/*

void DFS(int x, int y, vector<int> path, int idx)
{
    visited[y][x] = true;
    if (isCut[a[y][x]] && s[y][x] != 'T')
        path.push_back(a[y][x]);

    if (s[y][x] == 'T')
    {
        ++cnt;

        for (int i = 0; i < path.size(); i++)
        {
            tmp[path[i]]++;
        }
        return;
    }
    if (idx >= t - 1)
        return;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx >= 0 && ny >= 0 && nx < m && ny < n)
        {
            if (s[ny][nx] != '#' && s[ny][nx] != 'S' && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                DFS(nx, ny, path, idx + 1);
                visited[ny][nx] = false;
            }
        }
    }
}*/

int dfs(int here, bool isRoot)
{
    discovered[here] = ++number;
    int ret = discovered[here];
    int child = 0;
    for (int i = 0; i < v[here].size(); i++)
    {
        int next = v[here][i];
        if (discovered[next])
        {
            ret = min(ret, discovered[next]);
            continue;
        }
        child++;
        int prev = dfs(next, false);
        if (!isRoot && prev >= discovered[here])
            isCut[here] = true;
        ret = min(ret, prev);
    }

    if (isRoot)
        isCut[here] = (child >= 2);

    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("lock.inp", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n >> m;
    int sx, sy;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int num = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = num++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] != '#')
            {
                ++t;
                for (int k = 0; k < 4; k++)
                {
                    int x = j + dx[k];
                    int y = i + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && s[y][x] != '#')
                    {
                        v[a[i][j]].push_back(a[y][x]);
                    }
                }
            }
            if (s[i][j] == 'S')
            {
                sx = j;
                sy = i;
            }
        }
    }
    for (int i = 1; i <= n * m; i++)
    {
        if (v[i].size() != 0)
        {
            if (!discovered[i])
                dfs(i, true);
        }
    }
    isCut[a[sy][sx]] = 0;
    bool flag = false;
    for (int i = 1; i <= n * m; i++)
    {
        if (isCut[i])
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        bfs(sy, sx,path);
        //DFS(sx, sy, path, 0);
        if (cnt != 0)
        {
            vector<pair<int, int>> rst;
            //cout << "cnt: " << cnt << '\n';
            for (int i = 1; i <= n * m; i++)
            {
                if (tmp[i] != 0 && tmp[i] == cnt)
                {
                    rst.push_back({i - ((i - 1) / m) * m, (i - 1) / m + 1});
                }
            }
            sort(rst.begin(), rst.end());
            cout << rst.size() << '\n';
            for (int i = 0; i < rst.size(); i++)
            {
                cout << rst[i].first << ' ' << rst[i].second << '\n';
            }
        }
        else
        {
            cout << 0 << '\n';
            return 0;
        }
    }
    else
        cout << 0 << '\n';

    return 0;
}
