#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, m, a[505], c[505], sum, cnt = mod, ans;

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		a[i] = c - '0', sum +=a[i];
	}
	for (int i = 1; i <= n; i++) cin >> c[i], cnt = min(cnt, c[i]);
	if (m == n)
	{
		if (sum == n && cnt != 0)
		{
			ans = 1;
			for (int i = 2; i <= n; i++) ans = ans * i % mod;
		}
		cout << ans;
		return 0;
	}
}