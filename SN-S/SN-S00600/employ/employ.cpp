#include <bits/stdc++.h>

using namespace std;

#define int long long

inline int read ()
{
	int x = 0, w = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9')
		w = (ch == '-' ? -1 : w), ch = getchar ();
	while (ch >= '0' && ch <= '9')
		x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar (); 
	return x * w;
}

const int N = 507, M = 1e6 + 1e5, T = 20, Mod = 998244353;

int n, m, c[N], s[N], p[N], f[M][T];

string t;

signed main ()
{
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	n = read (), m = read ();
	cin >> t;
	for (int i = 1; i <= n; ++ i)
		s[i] = t[i - 1] - '0';
	for (int i = 1; i <= n; ++ i)
		c[i] = read ();
	if (n <= 0)
	{
		int res = 0;
		for (int i = 1; i <= n; ++ i)
			p[i] = i;
		do
		{
			int sum = 0;
			for (int i = 1; i <= n; ++ i)
				if (!s[i] || (s[i] && sum >= c[p[i]]))
						++ sum;
			if (n - sum >= m)
				++ res;
		}while (next_permutation (p + 1, p + n + 1));
		cout << res << '\n';
	}
	else if (n <= 18)
	{
		f[0][0] = 1;
		for (int i = 0; i < (1 << n); ++ i)
		{
			int sum = 0;
			for (int j = 1; j <= n; ++ j)
				if (i & (1 << j - 1))
					++ sum;
			for (int j = 0; j <= sum; ++ j)
				for (int k = 1; k <= n; ++ k)
					if (! (i & (1 << k - 1)))
						if (s[sum + 1] && sum - j < c[k])
							(f[i | (1 << k - 1)][j + 1] += f[i][j]) %= Mod; 
						else
							(f[i | (1 << k - 1)][j] += f[i][j]) %= Mod; 
		}
		int res = 0;
		for (int i = m; i <= n; ++ i)
			(res += f[(1 << n) - 1][i]) %= Mod;
		cout << res << '\n';
	}
	else if (m == n)
	{
		int res = 1;
		for (int i = 1; i <= n; ++ i)
			if (!c[i] || !s[i])
				res = 0;
		for (int i = 1; i <= n; ++ i)
			(res *= i) %= Mod;
		cout << res << '\n';
	}
	else
	{
		int res = 1;
		for (int i = 1; i <= n; ++ i)
			(res *= i) %= Mod;
		cout << res << '\n';
	}
	return 0;
}
