#include <bits/stdc++.h>
using namespace std;
int rst = INT_MAX;
int n, h;
int total = 0;
class Drone
{
public:
	int w, x, y;
} drone;
Drone start;
vector<Drone> v;
bool visited[21];
void sort(int left, int right, vector<Drone> &v)
{
	int pivot = left;
	int j = pivot;
	int i = left + 1;
	if (left < right)
	{
		for (; i <= right; i++)
		{
			if (v[i].w < v[pivot].w)
			{
				j++;
				swap(v[j], v[i]);
			}		
		}
		swap(v[left], v[j]);
		sort(left, pivot - 1, v);
		sort(pivot + 1, right, v);
	}
}
void dfs(int idx, int px, int py, int weight, int energy)
{
	if (energy >= rst)
	{
		return;
	}
	if (idx == v.size())
	{
		int dis = abs(px - start.x) + abs(py - start.y);
		int e = dis * (weight + 1) + energy;
		rst = e < rst ? e : rst;
		return;
	}

	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (!visited[i])
		{
			Drone next = v[i];

			int d = abs(px - next.x) + abs(py - next.y);

			visited[i] = true;
			dfs(idx + 1, next.x, next.y, weight - next.w, energy + d * (weight + 1));
			visited[i] = false;
		}
	}
	return;
}
int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	freopen("drone.inp", "r", stdin);
	freopen("drone.out", "w", stdout);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> h;
		if (h == 1)
			cin >> start.w >> start.x >> start.y;
		else
		{
			cin >> drone.w >> drone.x >> drone.y;
			total += drone.w;
			v.push_back(drone);
		}
	}
	sort(0, n - 2, v);
	dfs(0, start.x, start.y, total, 0);
	cout << rst;
	return 0;
}
