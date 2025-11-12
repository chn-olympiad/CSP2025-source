#include <bits/stdc++.h>
using namespace std;

//const double MAX_TIME = ;

long long n, k, a[500005], xr[500005], ans, dp[5005];

bool check(long long t)
{
	long long lst = 1, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if ((xr[i] ^ xr[lst - 1]) == k) ans++, lst = i + 1; 
	}
	
	return ans >= t;
}

void dfsslow(long long x, long long lst, long long cnt)
{
	if (x > n) 
	{
		ans = max(ans, cnt);
//		cout << cnt << endl;
		return ;
	} 
	if ((xr[x] ^ xr[lst - 1]) == k) dfsslow(x + 1, x + 1, cnt + 1);
	dfsslow(x + 1, lst, cnt);
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	long long z = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		xr[i] = xr[i - 1] ^ a[i];
		z += (a[i] > 1);
	}
	if (n <= 26) 
	{
		dfsslow(1, 1, 0);
		cout << ans << endl;
	}
	else
	{
		if (n <= 5005)
		{
			for (int i = n; i >= 1; i--)
			{
				for (int j = i; j <= n; j++)
				{
					if ((xr[j] ^ xr[i - 1]) == k) dp[i] = max(dp[i], dp[j + 1] + 1);
				}
				dp[i] = max(dp[i], dp[i + 1]);
			}
			cout << dp[1];
		} else
		{
					//??正解在何 
			long long l = 1, r = n, res = 0;
			while(l <= r)
			{
				long long mid = (l + r) >> 1;
				if (check(mid)) res = mid, l = mid + 1;
				else r = mid - 1;
			}
			cout << res << endl;
		}
	}
	return 0;
}
