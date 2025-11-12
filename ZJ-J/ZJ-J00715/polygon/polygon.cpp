#include<bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)
const int N = 5010, MOD = 998244353;
int a[N];
int f[N];
int sum[N];
int maxv(int a, int b, int c)
{
	return max(a, max(b, c));
}
int find(int l, int r, int maxn)
{
	if (sum[r] - sum[l - 1] <= maxn)
		return 0;
	int ans = 0;
	ans += find(l, mid, maxn);
	ans = ans % MOD;
	ans += find(mid + 1, r, maxn);
	ans = ans % MOD;
	int j = 1;
	for (int i = r; i >= mid; i --)
	{
		if (j > mid) continue;
		if (sum[i] - sum[j - 1] >= maxn)
		{
			for (int k = j; k <= mid; k ++)
				if (sum[i] - sum[k - 1] >= maxn)
					j = k;
				else
					break;
			ans += j;
			ans = ans % MOD;
		}
	}
	return ans;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	if (n == 3)
	{
		for (int i = 1; i <= n; i ++) cin >> a[i];
		if (a[1] + a[2] + a[3] > 2 * maxv(a[1], a[2], a[3]))
			puts("1");
		else
			puts("0");
		return 0;
	}
	else
	{
		for (int i = 1; i <= n; i ++) cin >> a[i];
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i ++)
			sum[i] = sum[i - 1] + a[i];
		int ans = 0;
		for (int i = 3; i <= n; i ++)
			f[i] = find(1, i - 1, a[i]), ans += f[i], ans = ans % MOD;
		printf("%d\n", ans);
		return 0;
	}
	return 0;
}
