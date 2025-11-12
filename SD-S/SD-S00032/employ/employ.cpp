#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long
const LL mod = 998244353;
char s[200010];
int c[200010];
int p[20];
LL f[1 << 19][20];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	if(n <= 18)
	{
		f[0][0] = 1;
		for(int i = 0; i < (1 << n); i++)
		{
			for(int k = 0; k <= __builtin_popcount(i); k++)
			{
				for(int j = 1; j <= n; j++)
				{
					if(!(i & (1 << j - 1)))
					{
						f[i | (1 << j - 1)][k + (c[j] > __builtin_popcount(i) - k && s[__builtin_popcount(i) + 1] == '1')] += f[i][k];
						f[i | (1 << j - 1)][k + (c[j] > __builtin_popcount(i) - k && s[__builtin_popcount(i) + 1] == '1')] %= mod;
					}
				}
			}
//			for(int k = 0;k <= __builtin_popcount(i);k++)
//			{
//				cout << i << ' ' << k << ' ' << f[i][k] << '\n';
//			}
		}
		LL ans = 0;
		for(int i = m; i <= n; i++)
		{
			ans += f[(1 << n) - 1][i];
			ans %= mod;
		}
		cout << ans;
	}
	else if(m == n)
	{
		for(int i = 1; i <= n; i++)
		{
			if(s[i] == '0' || c[i] == 0)
			{
				cout << 0;
				return 0;
			}
		}
		LL ans = 1;
		for(int i = 1; i <= n; i++)
		{
			ans = ans * i % mod;
		}
		cout << ans;
	}
	else
	{
		cout << 0;
	}
	return 0;
}

