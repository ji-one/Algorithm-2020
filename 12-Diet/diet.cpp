#include <bits/stdc++.h>
using namespace std;
class Diet
{
public:
    int p, f, s, v, c;

    Diet &operator+(Diet &d)
    {
        p += d.p;
        f += d.f;
        s += d.s;
        v += d.v;
        c += d.c;
        return *this;
    }
    Diet &operator-(Diet &d)
    {
        p -= d.p;
        f -= d.f;
        s -= d.s;
        v -= d.v;
        c -= d.c;
        return *this;
    }
} diet;
Diet d;
int k;
int m[4];
int sum = -1;
int minCost = INT_MAX;
vector<Diet> v;
vector<int> ch;
vector<vector<int>> rst;
bool visited[100];
void dfs(int idx, Diet pd, vector<int> choose)
{
    if (minCost < pd.c)
    {
        return;
    }
    if (idx == k)
    {
        if (m[0] <= pd.p && m[1] <= pd.f && m[2] <= pd.s && m[3] <= pd.v)
        {
            if (minCost > pd.c)
            {
                sum = pd.p + pd.f + pd.s + pd.v;
                minCost = pd.c;
                rst.clear();
                rst.push_back(choose);
                return;
            }
            else if (minCost == pd.c)
            {
                int s = pd.p + pd.f + pd.s + pd.v;
                if (sum < s)
                {
                    rst.clear();
                    sum = s;
                    rst.push_back(choose);
                    return;
                }
                else if (sum == s)
                {
                    if (!choose.empty())
                    {
                        rst.push_back(choose);
                    }
                    return;
                }
                return;
            }
        }
        return;
    }
    pd = pd + v[idx];
    visited[idx] = true;
    choose.push_back(idx + 1);
    dfs(idx + 1, pd, choose);
    pd = pd - v[idx];
    choose.pop_back();
    visited[idx] = false;
    dfs(idx + 1, pd, choose);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("diet.inp", "r", stdin);
    freopen("diet.out", "w", stdout);
    cin >> k;
    for (int i = 0; i < 4; i++)
    {
        cin >> m[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> diet.p >> diet.f >> diet.s >> diet.v >> diet.c;
        v.push_back(diet);
    }

    dfs(0, d, ch);

    sort(rst.begin(), rst.end());

    for(int i=0;i<rst[0].size();i++)
    {
        cout<<rst[0][i]<<' ';
    }

    return 0;
}
