//xianshitieyizhongxue wangzhengqinghe 13891989834 chusan
#include<bits/stdc++.h>
#define fir first
#define sec second
#define ll long long
#define ull unsigned ll
#define ldb long double
#define inf 1000000010
#define infll 1000000000000000010ll
#define mod 998244353
#define maxn 18
using namespace std;
int aqx, n, m, C[maxn + 10], F[(1 << maxn) + 10][maxn + 10], G[510][510];
string s;
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	return;
}
void solve()
{
	cin >> n >> m >> s; s = "0" + s;
	for (int i = 1;i <= n;i++) cin >> C[i];
	if (m == n)
	{
		for (int i = 1;i <= n;i++) if (s[i] == '0') {cout << "0\n"; return;}
		for (int i = 1;i <= n;i++) if (!C[i]) {cout << "0\n"; return;}
		int ans = 1;
		for (int i = 1;i <= n;i++) ans = 1ll * i % mod;
		cout << ans << "\n"; return;
	}
	F[0][0] = 1;
	for (int st = 0;st < (1 << n) - 1;st++) 
	{
		int t = __builtin_popcount(st);
		for (int i = 0;i <= t;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				if ((st >> (j - 1)) & 1) continue;
				int ne = (st | (1 << (j - 1)));
				if ((s[t + 1] == '0') || (t - i >= C[j])) F[ne][i] = (F[ne][i] + F[st][i]) % mod;
				else F[ne][i + 1] = (F[ne][i + 1] + F[st][i]) % mod;
			}
		}
	}
	int ans = 0;
	for (int i = m;i <= n;i++) ans = (ans + F[(1 << n) - 1][i]) % mod;
	cout << ans << "\n"; return;
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	init();
	aqx = 1;
	while (aqx--) solve();
	return 0;
}
