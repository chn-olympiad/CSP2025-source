# include <bits/stdc++.h>
using namespace std;
# define int long long
typedef long long ll;
typedef unsigned long long ull;
# define lc (u << 1)
# define rc (u << 1 | 1)
# define fi first
# define se second
const int N = 505, mod = 998244353;

int n, m;
string s;
int c[N];
int ord[N];
signed main ()
{
	freopen ("employ.in", "r", stdin); freopen ("employ.out", "w", stdout);
	ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	cin >> n >> m >> s; s = " " + s; 
	bool flag = 0;
	for (int i = 1; i <= n; i ++ )
	{
		if (s[i] == '0')
		{
			flag = 1;
			break;
		}
	}
	for (int i = 1; i <= n; i ++ )
	{
		cin >> c[i];
		ord[i] = i;
	}
	if (n <= 10)
	{
		int ans = 0;
		do
		{
			int sum = 0;
			int shibai = 0;
			for (int i = 1; i <= n; i ++ )
			{
				if (shibai >= c[ord[i]])
				{
					shibai ++ ;
					continue;
				}
				if (s[i] == '0')
					shibai ++ ;
				else
					sum ++ ;
			}
			if (sum >= m)
				ans = (ans + 1) % mod;
		} while (next_permutation (ord + 1, ord + 1 + n));
		cout << ans << "\n";
	}
	else if (m == n)
		cout << 1 << "\n";
	else if (!flag)
	{
		int ans = 1;
		for (int i = 1; i <= n; i ++ )
			ans = ans * i % mod;
		cout << ans << "\n";
	}
	return 0;
}

