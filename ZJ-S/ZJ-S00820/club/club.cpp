#include <bits/stdc++.h>
#define int long long
#define lll unsigned long long
#define vc vector
#define pi pair<int, int>
#define mkp make_pair
#define INF 2147483647
#define endl "\n"
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

constexpr int N = 100011;

struct node
{
	int x, y, z;
}a[N];
int T, n, m, ans;
priority_queue<pi, vc<pi>, greater<pi> > q[4];


void solve()
{
	for (int i = 1; i <= 3; i++)
	{
		while (!q[i].empty()) q[i].pop();
	}
	ans = 0;
	cin >> n;
	m = n / 2;
	for (int i = 1; i <= n; i++)
	{
		int mx, d, id;
		cin >> a[i].x >> a[i].y >> a[i].z;
		mx = max({a[i].x, a[i].y, a[i].z});
		if(mx == a[i].x)
		{
			d = min(a[i].x - a[i].y, a[i].x - a[i].z);
			if(q[1].size() < m) q[1].push(mkp(d, i));
			else
			{
				if(d < q[1].top().first)
				{
					if(a[i].y > a[i].z) q[2].push(mkp(a[i].y - a[i].z, i));
					else q[3].push(mkp(a[i].z - a[i].y, i));
				}
				else
				{
					id = q[1].top().second;
					q[1].pop();
					q[1].push(mkp(d, i));
					if(a[id].y > a[id].z) q[2].push(mkp(a[id].y - a[id].z, id));
					else q[3].push(mkp(a[id].z - a[id].y, id));
				}
			}
		}
		else if(mx == a[i].y)
		{
			d = min(a[i].y - a[i].x, a[i].y - a[i].z);
			if(q[2].size() < m) q[2].push(mkp(d, i));
			else
			{
				if(d < q[2].top().first)
				{
					if(a[i].x > a[i].z) q[1].push(mkp(a[i].x - a[i].z, i));
					else q[3].push(mkp(a[i].z - a[i].x, i));
				}
				else
				{
					id = q[2].top().second;
					q[2].pop();
					q[2].push(mkp(d, i));
					if(a[id].x > a[id].z) q[1].push(mkp(a[id].x - a[id].z, id));
					else q[3].push(mkp(a[id].z - a[id].x, id));
				}
			}
		}
		else if(mx == a[i].z)
		{
			d = min(a[i].z - a[i].x, a[i].z - a[i].y);
			if(q[3].size() < m) q[3].push(mkp(d, i));
			else
			{
				if(d < q[3].top().first)
				{
					if(a[i].x > a[i].y) q[1].push(mkp(a[i].x - a[i].y, i));
					else q[2].push(mkp(a[i].y - a[i].x, i));
				}
				else
				{
					id = q[3].top().second;
					q[3].pop();
					q[3].push(mkp(d, i));
					if(a[id].x > a[id].y) q[1].push(mkp(a[id].x - a[id].y, id));
					else q[2].push(mkp(a[id].y - a[id].x, id));
				}
			}
		}
	}
	for (int i = 1; i <= 3; i++)
	{
//		cout << i << ": ";
		while (!q[i].empty())
		{
			if(i == 1) ans += a[q[i].top().second].x;
			if(i == 2) ans += a[q[i].top().second].y;
			if(i == 3) ans += a[q[i].top().second].z;
//			cout << q[i].top().second << " ";
			q[i].pop();
		}
//		cout << endl;
	}
	cout << ans << endl;
}

signed main()
{
	IOS;
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}
/*
100pts
*/
