#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;

const int mod = 998244353;

#define ll long long

int n, m;

ll ans;

int s[N], c[N];

ll f[19][1 << 19][19];

/*
选了i，死了j的可行的方案数 
*/

int input()
{
	char c;
	cin >> c;
	return c - '0';
}

int _count(int x)
{
	int ans = 0;
	while(x)
	{
		ans += x & 1;
		x >>= 1;
	}
	return ans;
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) s[i] = input();
	for (int i = 0; i < n; i++) cin >> c[i];
	f[0][0][0] = 1;
	for (int l = 1; l <= n; l++)
	{
		for (int i = 0; i < (1 << n); i++)
		{
			for (int k = 0; k < n; k++)	
			{
				if (i & (1 << k)) continue;
				for (int j = 0; j < c[k]; j++)
					f[l][i | (1 << k)][j + !s[l]] =
					 (f[l][i | (1 << k)][j + !s[l]] + f[l - 1][i][j]) % mod;
				for (int j = c[k]; j <= n; j++)
					f[l][i | (1 << k)][j + 1] =
					 (f[l][i | (1 << k)][j + 1] + f[l - 1][i][j]) % mod;
			}
		}
	}
	for (int i = 0; i <= n - m; i++) 
		ans = (ans + f[n][(1 << n) - 1][i]) % mod;
	cout << ans;
	return 0;
}
/*
3 2
101
1 1 2

2

-------------------

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

2204128
*/

