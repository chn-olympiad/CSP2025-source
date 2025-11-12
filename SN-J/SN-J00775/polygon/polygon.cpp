// xianshitieyizhongxue wangzhengqinghe 13891989834 chusan
#include<bits/stdc++.h>
#define fir first
#define sec second
#define ll long long
#define ull unsigned ll
#define ldb long double
#define inf 1000000000
#define infll 1000000000000000000ll
#define mod 998244353
#define maxn 5000
#define maxa 5000
using namespace std;
int aqx, n, A[maxn + 10], F[maxa + 10][maxa + 10];
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	return;
}
void solve()
{
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> A[i];
	sort(A + 1, A + n + 1);
	F[0][0] = 1;
	for (int i = 1;i <= n;i++) for (int j = 0;j <= maxa;j++)
	{
		F[i][j] = F[i - 1][j];
		if (j >= A[i]) F[i][j] = (F[i][j] + F[i - 1][j - A[i]]) % mod;
	}
	int ans = 1;
	for (int i = 1;i <= n;i++) ans = ans * 2 % mod;
	ans = (ans + mod - 1) % mod;
	for (int i = 1;i <= n;i++) for (int j = 0;j <= A[i];j++) ans = (ans + mod - F[i - 1][j]) % mod;
	cout << ans << "\n";
	return;
}
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	init();
	aqx = 1;
	while (aqx--) solve();
	return 0;
}
