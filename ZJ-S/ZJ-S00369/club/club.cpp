#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N][3], f[10], b[N], c[N], cnt, tot;
int n, ans;

void init ()
{
	memset (f, 0, sizeof f);
	memset (a, 0, sizeof a);
	memset (b, 0, sizeof b);
	memset (c, 0, sizeof c);
	
	cnt = tot = ans = 0;
}

void solve ()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		int x = max (a[i][1], max (a[i][2], a[i][3]));
		ans += x;
		if (a[i][1] == x) f[1] ++, c[i] = 1;
		else if (a[i][2] == x) f[2] ++, c[i] = 2;
		else if (a[i][3] == x) f[3] ++, c[i] = 3;
	}
	int x = max (f[1], max (f[2], f[3]));
	if (x <= n / 2)
	{
		cout << ans << "\n";
		return ;
	}
	if (f[1] == x) cnt = 1;
	if (f[2] == x) cnt = 2;
	if (f[3] == x) cnt = 3;
	for (int i = 1; i <= n; i ++)
	{
		if (c[i] == cnt)
		{
			int x = max (a[i][1], max (a[i][2], a[i][3]));
			int y = a[i][1] + a[i][2] + a[i][3] - x - min (a[i][1], min (a[i][2], a[i][3]));
			b[++ tot] = x - y;
		}
	}
	sort (b + 1, b + tot + 1);
	for (int i = 1; i <= x - (n / 2); i ++)
	{
		ans -= b[i];
	}
	cout << ans << "\n";
	return ;
}

signed main ()
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie (0), cout.tie (0);
	
	int T;cin >> T;
	while (T --)
	{
		init ();
		solve ();
	}
	
}
