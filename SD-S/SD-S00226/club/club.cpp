
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200010;
const int inf = 1e18;
const int mod = 998244353;

namespace Luminescent
{
	
} using namespace Luminescent;

namespace Loyalty
{
	struct Node
	{
		int x[3], sj, bx, id, bxid;
	} a[N];
	int bel[N];
	inline void solve(int ca_, int atc_)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i].x[0] >> a[i].x[1] >> a[i].x[2];
		int buc[3] = {0};
		for (int i = 1; i <= n; ++i)
		{
			int mx = max({a[i].x[0], a[i].x[1], a[i].x[2]});
			if (mx == a[i].x[0])
			{
				bel[i] = 0;
				a[i].sj = a[i].x[0];
				a[i].bx = max({a[i].x[1], a[i].x[2]});
				if (a[i].bx == a[i].x[1])
					a[i].bxid = 1;
				else
					a[i].bxid = 2;
			}
			else if (mx == a[i].x[1])
			{
				bel[i] = 1;
				a[i].sj = a[i].x[1];
				a[i].bx = max({a[i].x[0], a[i].x[2]});
				if (a[i].bx == a[i].x[0])
					a[i].bxid = 0;
				else
					a[i].bxid = 2;
			}
			else
			{
				bel[i] = 2;
				a[i].sj = a[i].x[2];
				a[i].bx = max({a[i].x[0], a[i].x[1]});
				if (a[i].bx == a[i].x[0])
					a[i].bxid = 0;
				else
					a[i].bxid = 1;
			}
			++buc[bel[i]];
			a[i].id = i;
		}
		if (max({buc[0], buc[1], buc[2]}) > n / 2)
		{
			vector<int> v;
			if (buc[0] > n / 2)
			{
				for (int i = 1; i <= n; ++i)
					if (bel[i] == 0)
						v.emplace_back(i);
			}
			else if (buc[1] > n / 2)
			{
				for (int i = 1; i <= n; ++i)
					if (bel[i] == 1)
						v.emplace_back(i);
			}
			else
			{
				for (int i = 1; i <= n; ++i)
					if (bel[i] == 2)
						v.emplace_back(i);
			}
			sort(v.begin(), v.end(), [&](int &l, int &r)
			{
				return a[l].sj - a[l].bx < a[r].sj - a[r].bx;
			});
			for (int &id : v)
			{
				--buc[bel[id]];
				++buc[a[id].bxid];
				bel[id] = a[id].bxid;
				if (max({buc[0], buc[1], buc[2]}) <= n / 2)
					break;
			}
		}
		assert(max({buc[0], buc[1], buc[2]}) <= n / 2);
//		sort(a + 1, a + n + 1, [&](auto &l, auto &r)
//		{
//			return l.id < r.id;
//		});
		int sum = 0;
		for (int i = 1; i <= n; ++i)
			sum += a[i].x[bel[i]];
		cout << sum << '\n';
	}
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout << fixed << setprecision(15);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; ++i)
		Loyalty::solve(i, T);
	return 0;
}

// rp++
// 12499 12499 12499
// please ac


/*

inline auto split(int u)
{
	auto it = se.lower_bound(Node(u));
	if (it != se.end() && it->l == u)
		return it;
	it = prev(it);
	if (it->r < u)
		return se.end();
	int ll = it->l, rr = it->r, vv = it->val;
	se.erase(it);
	se.insert(Node(ll, u - 1, vv));
	return se.insert(Node(u, rr, vv));
}

exp(-dlt / tempr) < Rand(0, 1)
dfn[u] < low[v]

*/
