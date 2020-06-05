#include <bits/stdc++.h>
using namespace std;
vector<int> c; //capacity
vector<int> v; //start
vector<int> g; //goal
bool visited1[21][21][21];
bool visited2[21][21][21][21];
bool visited3[21][21][21][21][21];
bool visited4[21][21][21][21][21][21];
int cnt = 0;
int k;
//visited
void bfs()
{
    queue<pair<vector<int>, int>> q;
    q.push({v, 0});

    while (!q.empty())
    {
        vector<int> cur = q.front().first;
        int count = q.front().second;
        q.pop();
        /* for (int i = 0; i < k; i++)
        {
            cout << cur[i] << ' ';
        }
        cout << '\n';*/

        if (k == 3)
        {
            visited1[cur[0]][cur[1]][cur[2]] = true;
        }
        else if (k == 4)
        {
            visited2[cur[0]][cur[1]][cur[2]][cur[3]] = true;
        }
        else if (k == 5)
        {
            visited3[cur[0]][cur[1]][cur[2]][cur[3]][cur[4]] = true;
        }
        else if (k == 6)
        {
            visited4[cur[0]][cur[1]][cur[2]][cur[3]][cur[4]][cur[5]] = true;
        }

        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++) //i->j 로 붓는다
            {
                vector<int> next;
                if (i != j)
                {
                    if (cur[i] != 0)
                    {
                        int nj;
                        if (cur[i] + cur[j] > c[j])
                        {
                            nj = c[j];
                        }
                        else
                            nj = cur[i] + cur[j];

                        int ni = cur[i] - (nj - cur[j]);
                        if (ni != cur[i] && nj != cur[j])
                        {
                            for (int t = 0; t < k; t++)
                            {
                                if (t == i)
                                {
                                    next.push_back(ni);
                                }
                                else if (t == j)
                                {
                                    next.push_back(nj);
                                }
                                else
                                {
                                    next.push_back(cur[t]);
                                }
                            }

                            if (k == 3)
                            {
                                if (!visited1[next[0]][next[1]][next[2]])
                                {
                                    visited1[next[0]][next[1]][next[2]] = true;
                                }
                                else
                                    continue;
                            }
                            else if (k == 4)
                            {
                                if (!visited2[next[0]][next[1]][next[2]][next[3]])
                                {
                                    visited2[next[0]][next[1]][next[2]][next[3]] = true;
                                }
                                else
                                    continue;
                            }
                            else if (k == 5)
                            {
                                if (!visited3[next[0]][next[1]][next[2]][next[3]][next[4]])
                                {
                                    visited3[next[0]][next[1]][next[2]][next[3]][next[4]] = true;
                                }
                                else
                                    continue;
                            }
                            else if (k == 6)
                            {
                                if (!visited4[next[0]][next[1]][next[2]][next[3]][next[4]][next[5]])
                                {
                                    visited4[next[0]][next[1]][next[2]][next[3]][next[4]][next[5]] = true;
                                }
                                else
                                    continue;
                            }

                            //check
                            bool flag = true;
                            for (int i = 0; i < k; i++)
                            {
                                if (g[i] != next[i])
                                {
                                    flag = false;
                                    break;
                                }
                            }
                            if (flag)
                            {
                                cnt = count + 1;
                                return;
                            }
                            q.push({next, count + 1});
                        }
                    }
                }
            }
        }
    }
    cnt = 0;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("bucket.inp", "r", stdin);
    freopen("bucket.out", "w", stdout);
    cin >> k;
    int total = 0;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        c.push_back(x);
    }
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        sum += x;
    }
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        g.push_back(x);
        total += x;
    }
    if (sum != total)
    {
        cout << 0;
        return 0;
    }
    bfs();
    cout << cnt;
    return 0;
}
