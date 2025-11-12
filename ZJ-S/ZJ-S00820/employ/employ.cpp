#include <bits/stdc++.h>
#define int long long
#define lll unsigned long long
#define vc vector
#define pi pair<int, int>
#define mkp make_pair
#define INF 2147483647
#define St string
#define endl "\n"
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

constexpr int N = 511;
constexpr int mod = 998244353;

int n, m, tot;
int c[N], fuc[N], inv[N], a[N];
St str;
bool flag1 = 1;
namespace solve1
{
	int ans;
	int p[N];
	bitset<N> vis;
	
	void dfs(int step)
	{
		if(step > n)
		{
			int cnt = 0;
			for (int i = 1, sum = 0; i <= n; i++)
			{
				if(str[i] == '0') sum++;
				else
				{
					if(sum >= c[p[i]])
					{
						sum++;
						continue;
					}
					cnt++;
				}
			}
			if(cnt >= m) ans++;
			return ;
		}
		for (int i = 1; i <= n; i++)
		{
			if(vis[i]) continue;
			vis[i] = 1;
			p[step] = i;
			dfs(step + 1);
			vis[i] = 0;
		}
	}
	void Man()
	{
		ans = 0;
		dfs(1);
		cout << ans << endl;
	}
}

namespace solve2
{
	int C(int n, int m)
	{
		if(n < m || m < 0) return 0;
		return fuc[n] * inv[m] % mod * inv[n - m] % mod;
	}
	void Man()
	{
		int ans = 0, sum0 = 0, sum1 = 0;
		for (int i = 1; i <= n; i++)
		{
			if(!c[i]) sum0++;
			else sum1++;
			if(c[i]) a[++tot] = c[i];
		}
		sort(a + 1, a + 1 + tot, [](int x, int y){  return x < y;  });
		if(sum1 >= m)
		{
//			ans += fuc[n];
			for (int i = 1; i <= tot; i++)
			{
				for (int j = 0; j < i; j++)
				{
					for (int k = 0; k < min(c[i], n) && k <= j; k++)
					{
						ans = (ans + C(j, k) * C(j, min(i - k - 1, i - 1)) % mod * fuc[i - 1] % mod) % mod;	
					}	
				}
				cout << ans << endl;
			}
//				for (int j = 0; j <= min(n - 1, c[i] - 1); j++)
//				{
//					for (int k = 0; k <= min(sum0, c[i] - 1) && k < j; k++)
//					{
//						ans = (ans + C(j, k) * C(sum1 - 1, i - 1) % mod * fuc[j - 1] % mod + mod) % mod;
//					}
//				}
		}
		cout << ans << endl;
	}
}

signed main()
{
	IOS;
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> str;
	fuc[0] = fuc[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i <= 500; i++)
	{
		fuc[i] = fuc[i - 1] * i % mod;
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	}
	for (int i = 2; i <= 500; i++)
	{
		inv[i] = inv[i - 1] * inv[i] % mod;
	}
	str = " " + str;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if(str[i] != '1') flag1 = 0;
	}
	if(n <= 10) solve1::Man();
	else if(flag1) solve2::Man();
	else
	{
		cout << 0 << endl;
	}
	return 0;
}
/*
gu ji zhi you 2= le
qwq
wo shi tang long
*/