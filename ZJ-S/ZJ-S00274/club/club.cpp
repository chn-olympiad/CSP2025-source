#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n, a[5][N];
int sum[5];
int ans;
int b[N], lb;
int mx[N];
void solve()
{
	cin >> n; ans = 0; lb = 0;
	for (int j = 1; j <= 3; j ++) sum[j] = 0;
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= 3; j ++)
		{
			cin >> a[j][i];
		}
	}
	for (int i = 1; i <= n; i ++)
	{
		mx[i] = 1;
		for (int j = 1; j <= 3; j ++)
		{
			if (a[j][i] > a[mx[i]][i]) mx[i] = j;
		}
		sum[mx[i]] ++;
		ans += a[mx[i]][i];
	}
	int tot = 0, op = 0;
	for (int j = 1; j <= 3; j ++)
	{
		if (sum[j] > n / 2) tot = sum[j] - n / 2, op = j;
	}
	for (int i = 1; i <= n; i ++)
	{
		if (mx[i] == op)
		{
			int th = 0;
			for (int j = 1; j <= 3; j ++)
			{
				if (j == mx[i]) continue;
				th = max(th, a[j][i]);
			}
			b[++ lb] = a[op][i] - th;
		}
	}
	sort(b + 1, b + 1 + lb);
	for (int i = 1; i <= tot; i ++) ans -= b[i];
	cout << ans << '\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
	int T = 1; cin >> T;
	while (T --) solve();
	return 0;
}

