#include <bits/stdc++.h>
#define val first
#define u second.first
#define v second.second
using namespace std;
typedef pair<int, pair<int, int> > pr;

const int N = 1e5 + 5;

int t, n;
int a[N][4], cnt[4], bel[N];
priority_queue<pr> q[3];

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int maxn = 0, id = -1;
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] > maxn) maxn = a[i][j], id = j;
		}
		cnt[id]++, bel[i] = id;
		ans += maxn;
		for (int j = 0; j < 3; j++)
			if (id != j) q[id].push({a[i][j] - a[i][id], {i, j}});
		if (cnt[id] > n / 2)
		{
			while (q[id].size() && bel[q[id].top().u] != id)
			{
				q[id].pop();
			}
			pr now = q[id].top();
			q[id].pop();
			ans += now.val;
			cnt[id]--, cnt[now.v]++;
			bel[now.u] = now.v;
			for (int j = 0; j < 3; j++)
			{
				if (j != now.v)
				{
					q[now.v].push({a[i][now.v] - a[i][j], {now.v, j}});
				}
			}
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
		bel[i] = 0;
	for (int i = 0; i < 3; i++)
	{
		while (q[i].size()) q[i].pop();
		cnt[i] = 0;
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}