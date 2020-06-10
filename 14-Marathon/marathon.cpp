#include <bits/stdc++.h>
using namespace std;
int d[51];
int INF = 200000000;
int k, vi, vj, l;
vector<pair<int, int>> v[51];
int dijkstra(int start, int end)
{
    for (int i = 1; i <= 50; i++)
    {
        d[i] = INF;
    }
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if (d[current] < distance)
            continue;
        for (int i = 0; i < v[current].size(); i++)
        {
            if (v[current][i].first != INF)
            {
                int next = v[current][i].second;
                int nextDistance = distance + v[current][i].first;

                if (nextDistance < d[next])
                {
                    d[next] = nextDistance;
                    pq.push({-nextDistance, next});
                }
            }
        }
    }
    return d[end];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("marathon.inp", "r", stdin);
    freopen("marathon.out", "w", stdout);
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> vi;
        while (1)
        {
            cin >> vj;
            if (vj == 0)
                break;
            cin >> l;
            v[vi].push_back({l, vj});
        }
    }
    int rst = INF;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            int dis = v[i][j].first;
            int adj = v[i][j].second;
            int idx;
            for (int t = 0; t < v[adj].size(); t++)
                if (v[adj][t].second == i)
                    idx = t;
            v[i][j].first = INF;
            v[adj][idx].first = INF;
            int tmp = dijkstra(adj, i);
            if (rst > tmp + dis)
                rst = tmp + dis;
            v[i][j].first = dis;
            v[adj][idx].first = dis;
        }
    }
    if (rst == INF)
        cout << 0;
    else
        cout << rst;
}
