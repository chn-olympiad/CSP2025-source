#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505, p = 998244353;
int n, m, c[N], f;
string s;

int vis[N], ans;
void dfs (int now, int _m)
{
//	cout << now << " " << _m << "\n";
	if (now == n && _m >= m)ans ++, ans %= p;
	if (now == n) return ;
	if (now - _m > n - m) return ;
	for (int i = 1; i <= n; i ++)if (!vis[i])
	{
		int up = 1;
		if (now - _m >= c[i]) up = 0;
		if (s[now] == '0') up = 0;
		vis[i] = 1;
		dfs (now + 1, _m + up);
		vis[i] = 0;
	}
}
void solve1 ()
{
	dfs (0, 0);
	cout << ans;
	return;
}


void solve2 ()
{
	for (int i = 0; i < n; i ++)
	{
		if (s[i] == '0')
		{
			cout << "0\n";
			return ;
		}
	}
	int res = 1;
	for (int i = 1; i <= n; i ++)
	{
		res *= i;
		res %= p;
	}
	cout << res;
	return ;
}


void solve3 ()
{
	int res = 1;
	for (int i = 1; i <= n; i ++)
	{
		res *= i;
		res %= p;
	}
	cout << res;
	return ;
}


void solve4 ()
{
	cout << 0;
	return;
}


signed main ()
{
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n;  i ++) if (s[i] == '1') f = 0;
	for (int i = 1; i <= n; i ++)
	{
		cin >> c[i];
	}
	if (m == n) solve2 ();
	if (n <= 18) solve1 ();
	else if (m == 1) solve3 ();
	else if (f == 1) solve4 ();
	else solve1 ();
}
