#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5010;
const int mod = 998244353;
int n;
int a[N];
int cnt;

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0;i < n; i ++)
	{
		cin >> a[i];
	}
	for (int i = 0;i <= (1 << n); i ++)
	{
		int sum = 0, maxx = 0, ans = 0;
		for (int j = 0;j < n; j ++)
		{
			if ((i & (1 << j)) != 0)
			{
				ans ++;
				maxx = max (maxx, a[j]);
				sum += a[j];
			}
		}
		if (maxx * 2 < sum && ans >= 3) cnt = (cnt + 1) % mod ;
	}
	cout << cnt;
	return 0;
}
