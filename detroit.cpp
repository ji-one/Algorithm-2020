#include <bits/stdc++.h>
using namespace std;
int a[10][10];
int col[10][10];
int row[10][10];
int candidate[10];
vector<pair<int, pair<int, int>>> v;
int n;
int cnt = 0;
bool check(int x, int y, int val)
{
	if (row[y][val] != 1 & col[x][val] != 1)
		return true;
	else
		return false;
}

void dfs(int idx)
{
	if (idx == v.size())
	{
		++cnt;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		int x = v[idx].second.first;
		int y = v[idx].second.second;

		if (check(x, y, i))
		{
			a[y][x] = i;
			col[x][i] = 1;
			row[y][i] = 1;
			dfs(idx + 1);
			a[y][x] = 0;
			col[x][i] = 0;
			row[y][i] = 0;
		}
	}
	return;
}

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("detroit.inp", "r", stdin);
	freopen("detroit.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 0)
			{
				v.push_back({0, {j, i}});
				candidate[i]++;
			}
			else
			{
				if (col[j][a[i][j]]|| row[i][a[i][j]])
				{
					cout << 0;
					return 0;
				}
				col[j][a[i][j]] = 1;
				row[i][a[i][j]] = 1;
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		v[i].first = candidate[v[i].second.second];
	}
	sort(v.begin(), v.end());
	dfs(0);
	cout << cnt;

	return 0;
}
