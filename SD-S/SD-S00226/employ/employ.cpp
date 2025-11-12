
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200010;
const int inf = 1e18;
const int mod = 998244353;

namespace Luminescent
{
	
} using namespace Luminescent;

char s[N];
int c[N];

namespace sub1_5
{
	int f[500010][20];
	inline void solve(int n, int m)
	{
		f[0][0] = 1;
		for (int i = 0; i < (1 << n) - 1; ++i)
		{
			int len = __builtin_popcount(i);
			for (int j = 0; j <= len; ++j) // 枚举有 j 个人没能被录取 
				for (int k = 0; k < n; ++k)
					if (~i >> k & 1) // 枚举下一个要面试 k 
					{
						if (s[len + 1] == '0')
							f[i | (1 << k)][j + 1] = (f[i | (1 << k)][j + 1] + f[i][j]) % mod;
						else if (s[len + 1] == '1')
						{
							if (c[k + 1] <= j)
								f[i | (1 << k)][j + 1] = (f[i | (1 << k)][j + 1] + f[i][j]) % mod;
							else
								f[i | (1 << k)][j] = (f[i | (1 << k)][j] + f[i][j]) % mod;
						}
					}
		}
		int sum = 0;
		for (int i = 0; i <= n - m; ++i)
			sum = (sum + f[(1 << n) - 1][i]) % mod;
		cout << sum << '\n';
	}
}

namespace sub12_14
{
	inline void solve(int n)
	{
		int all = 1;
		for (int i = 1; i <= n; ++i)
			all = all * i % mod;
		int now = 1, px = 0;
		for (int i = 1; i <= n; ++i)
			if (s[i] == '1')
			{
				int cnt = 0;
				for (int j = 1; j <= n; ++j)
					if (c[j] < i)
						++cnt;
				int use = cnt - px;
				if (use <= 0)
				{
					now = 0;
					break;
				}
				now = now * use % mod;
				++px;
			}
		int fnpx = 1;
		for (int i = 1; i <= n - px; ++i)
			fnpx = fnpx * i % mod;
		now = now * fnpx % mod;
		cout << (all - now + mod) % mod << '\n';
	}
}

namespace sub15
{
	inline void solve(int n)
	{
		if (count(s + 1, s + n + 1, '0'))
			cout << 0 << '\n';
		else if (count(c + 1, c + n + 1, 0))
			cout << 0 << '\n';
		else
		{
			int fac = 1;
			for (int i = 1; i <= n; ++i)
				fac = fac * i % mod;
			cout << fac << '\n';
		}
	}
}

namespace sub18_21
{
	int pre[N];
	inline void solve(int n, int m)
	{
		int all = count(s + 1, s + n + 1, '1');
		if (all < m)
			cout << 0 << '\n';
		else
		{
//			int lz[22] = {0}, idx = 0;
//			for (int i = 1; i <= n; ++i)
//				if (s[i] == '1')
//					lz[idx++] = i;
//			int sum = 0;
//			for (int i = 1; i <= n; ++i)
//				++pre[c[i]];
//			for (int i = 1; i <= n + 1; ++i)
//				pre[i] += pre[i - 1];
//			for (int i = 0; i < (1 << all); ++i)
//			{
//				// bit=1: 入选  ;;  bit=0: 不入选 
//				int rx_cnt = __builtin_popcount(i);
//				if (rx_cnt < m)
//					continue;
//				int fx = 0, orz = 1;
//				for (int j = 0; j < all; ++j)
//				{
//					if (i >> j & 1)
//					{
//						// c[j] < i - 1 - fx
//						orz = orz * (pre[i - 1 - fx] - j) % mod;
//						++fx;
//					}
//					else
//					{
//						
//					}
//				}
//				sum = (sum + orz) % mod;
//			}
//			cout << sum << '\n';
		}
	}
}

namespace Loyalty
{
	// f[i][j]: 当前处理完了 i 集合内的答案，录取了 j 个人的方案数 
	inline void solve(int ca_, int atc_)
	{
		int n, m;
		scanf("%lld%lld", &n, &m);
		scanf("%s", s + 1);
		for (int i = 1; i <= n; ++i)
			scanf("%lld", &c[i]);
		if (n <= 18)
		{
			sub1_5::solve(n, m);
			return;
		}
		else if (m == 1)
		{
			sub12_14::solve(n);
		}
		else if (m == n)
		{
			sub15::solve(n);
		}
		else
		{
			cout << 0 << '\n';
		}
	}
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
//	cin.tie(0)->sync_with_stdio(false);
	cout << fixed << setprecision(15);
	int T = 1;
//	cin >> T;
	for (int i = 1; i <= T; ++i)
		Loyalty::solve(i, T);
	return 0;
}

// rp++
// 12499 12499 12499
// please ac










// booooooooooooooooooooom.jpg

