

bool begin_mem;

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
using namespace std;

const int N = 2000010;
const int inf = 1e18;
const int mod = 998244353;

namespace Luminescent
{
	
} using namespace Luminescent;



namespace Loyalty
{
	string s1[N], s2[N];
	int ok[N];
	using ull = unsigned long long;
	const ull base = 13331;
	ull ht1[N], ht2[N], bit[N];
	inline ull get(ull *h, int l, int r)
	{
		return h[r] - h[l - 1] * bit[r - l + 1];
	}
	map<pair<ull, ull>, int> mp[N];
//	__gnu_pbds::gp_hash_table<pair<ull, ull>, int> mp[N];
	inline __int128 make(ull a, ull b)
	{
		return (__int128)a * ULLONG_MAX + b;
	}
	inline void solve(int ca_, int atc_)
	{
		bit[0] = 1;
		for (int i = 1; i < N; ++i)
			bit[i] = bit[i - 1] * base;
		int n, q;
		cin >> n >> q;
		for (int i = 1; i <= n; ++i)
		{
			cin >> s1[i] >> s2[i], ok[i] = (int)(s1[i] == s2[i]);
			ull sh1 = 0, sh2 = 0;
			for (char &j : s1[i])
				sh1 = sh1 * base + j;
			for (char &j : s2[i])
				sh2 = sh2 * base + j;
			++mp[(int)s1[i].size()][{sh1, sh2}];
		}
		while (q--)
		{
			string t1, t2;
			cin >> t1 >> t2;
			if (t1.size() != t2.size())
				cout << 0 << '\n';
			else
			{
				int m = t1.size();
				t1 = ' ' + t1, t2 = ' ' + t2;
				int psl = 1, psr = m;
				while (t1[psl] == t2[psl])
					++psl;
				while (t1[psr] == t2[psr])
					--psr;
				for (int i = 1; i <= m; ++i)
				{
					ht1[i] = ht1[i - 1] * base + t1[i];
					ht2[i] = ht2[i - 1] * base + t2[i];
				}
				int cnt = 0;
				for (int len = psr - psl + 1; len <= m; ++len)
				{
					for (int l = 1, r = len; r <= m; ++l, ++r)
					{
						if (l <= psl && psr <= r)
						{
							if (get(ht1, 1, l - 1) != get(ht2, 1, l - 1) || get(ht1, r + 1, m) != get(ht2, r + 1, m))
								continue;
							ull sh1 = get(ht1, l, r), sh2 = get(ht2, l, r);
							cnt += mp[len][{sh1, sh2}];
						}
					}
				}
				cout << cnt << '\n';
			}
		}
	}
}

bool end_mem;

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout << fixed << setprecision(15);
	int T = 1;
//	cerr << "!!!\n";
//	cin >> T;
	for (int i = 1; i <= T; ++i)
		Loyalty::solve(i, T);
	cerr << "Memory Used " << abs(&begin_mem - &end_mem) / 1048576. << '\n';
	return 0;
}

// rp++
// 12499 12499 12499
// please ac


