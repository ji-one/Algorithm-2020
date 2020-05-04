#include<bits/stdc++.h>
using namespace std;

int d[100001];
int a[11];

int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	freopen("tube.inp","r",stdin);
	freopen("tube.out","w",stdout);
	
	int l;
	cin >> l;
	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> a[i];
		d[a[i]] = 1;
	}

	for (int i = 0; i < k; i++)
	{
		for (int j = a[i]; j <= l; j++)
		{
			if (d[j] == 0 && d[j - a[i]] > 0)
			{
				d[j] = d[j - a[i]] + 1;
			}
			else if (d[j - a[i]] > 0)
			{
				d[j] = min(d[j], d[j - a[i]] + 1);
			}
		}
	}

	if (d[l] == 0) cout << 0;
	else cout << d[l];

}
