#include <bits/stdc++.h>
using namespace std;
int d[31][31][2];
vector<char> oper;
vector<int> num;
int main()
{
	freopen("1.inp", "r", stdin);
	freopen("mgame.out", "w", stdout);
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '+' || s[i] == '-' || s[i] == '*')
		{
			oper.push_back(s[i]);
		}
		else
		{
			num.push_back(s[i] - '0');
		}
	}

	int n = num.size();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			d[i][j][0] = INT_MAX;
			d[i][j][1] = INT_MIN;
		}
	}

	for (int i = 0; i < n; i++)
	{
		d[i][i][0] = num[i]; //min
		d[i][i][1] = num[i]; //max
	}
	int mini, maxi;
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 0; j + i < n; j++)
		{
			for (int k = j; k < j + i; k++)
			{
				if (oper[k] == '-')
				{
					mini = d[j][k][0] - d[k + 1][j + i][1];
					maxi = d[j][k][1] - d[k + 1][j + i][0];
				}
				else if (oper[k] == '+')
				{
					mini = d[j][k][0] + d[k + 1][j + i][0];
					maxi = d[j][k][1] + d[k + 1][j + i][1];
				}
				else if (oper[k] == '*')
				{
					mini = min(d[j][k][0] * d[k + 1][j + i][0], min(d[j][k][1] * d[k + 1][j + i][0], d[j][k][0] * d[k + 1][j + i][1]));
					maxi = max(d[j][k][1] * d[k + 1][j + i][1], d[j][k][0] * d[k + 1][j + i][0]);
				}

				d[j][j + i][0] = min(d[j][j + i][0], mini);
				d[j][j + i][1] = max(d[j][j + i][1], maxi);
			}
		}
	}
	cout << d[0][n - 1][1];
	return 0;
}
