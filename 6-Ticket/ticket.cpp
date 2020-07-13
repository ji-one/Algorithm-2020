#include <bits/stdc++.h>
using namespace std;
int day[366];
int dp[366];
int main()
{
    freopen("ticket.inp", "r", stdin);
    freopen("ticket.out", "w", stdout);
    int s, d, t, w; //1회권, 1일권, 3일권, 일주일권
    cin >> s >> d >> t >> w;
    int n;
    int lastday = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d, r;
        cin >> d >> r;
        day[d] = r;
        lastday = max(lastday, d);
    }

    for (int i = 1; i <= lastday; i++)
    {
        dp[i] = min(dp[i - 1] + day[i] * s, dp[i - 1] + d);
        if (i >= 3)
        {
            dp[i] = min(dp[i], dp[i - 3] + t);
        }
        if (i % 7 == 0)
        {
            dp[i] = min(dp[i], dp[i - 7] + w);
        }
        if (i > 7)
        {
            dp[i] = min(dp[i], dp[i - (i % 7)] + w);
        }
    }
    /*for (int i = 1; i <= lastday; i++)
    {
        cout << dp[i] << ' ';
    }*/
    cout<<dp[lastday];
    return 0;
}
