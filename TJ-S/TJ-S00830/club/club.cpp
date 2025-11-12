// stosto pingceji orzorz
// buyao WA TLE RE a
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a),END##i=(b);i<=END##i;++i)
#define pre(i,a,b) for(int i=(a),END##i=(b);i>=END##i;--i)
using namespace std;
typedef long long ll;
// Problem: club
const int N = 1e5 + 5;
struct node
{
	int mx, mn; // mn is cida, not min!!!
	bool operator<(const node o) const
	{
		return mx - mn < o.mx - o.mn;
	}
};
struct qwq
{
	int x, i;
	bool operator<(const qwq o) const
	{
		return x > o.x;
	}
};
int T, n; priority_queue<node> q[4]; qwq a[N][4];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T --)
	{
		scanf("%d", &n);
		rep(i, 1, n) rep(j, 1, 3) scanf("%d", &a[i][j].x), a[i][j].i = j;
		rep(i, 1, n)
		{
			sort(a[i] + 1, a[i] + 4);
			q[a[i][1].i].push({a[i][1].x, a[i][2].x});
		}
		ll ans = 0;
		rep(i, 1, 3)
		{
			int cnt = 0;
			while (q[i].size())
			{
				node t = q[i].top(); q[i].pop();
				if (++ cnt > n / 2) ans += t.mn;
				else ans += t.mx;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

