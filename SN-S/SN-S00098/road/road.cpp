#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 1e5 + 10;
long long n, m, k, num, father[100000 + 10 + 15], pay[15], flag;
struct edge
{
	long long u, v, cost;
}e[maxn];
long long lff (long long x)
{
	return x == father[x] ? x : father[x] = lff(father[x]);
}
bool cmp (const edge &l, const edge &r)
{
	return l.cost < r.cost;
}
int main ()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> e[i].u >> e[i].v >> e[i].cost;
	}
	if (k == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			father[i] = i;
		}
		sort(e + 1, e + 1 + m, cmp);
		long long tot = 0, cnt = 0;
		for (int i = 1; i <= m; i++)
		{
			long long fu = lff(e[i].u), fv = lff(e[i].v);
			if (fu != fv)
			{
				father[fu] = fv;
				tot += e[i].cost;
				//cout << e[i].u << ' ' << e[i].v << ' ' << e[i].cost << ' ' << tot << '\n';
				cnt++;
				if (cnt == n - 1)
				{
					break;
				}
			}
		}
		cout << tot;
		return 0;
	}
	num = m;
	for (int i = 1; i <= k; i++)
	{
		cin >> pay[i];
		for (int j = 1; j <= n; j++)
		{
			cin >> e[++num].cost;
			e[num].u = i, e[num].v = j;
			flag += e[num].cost + pay[i];
		}
	}
	for (int i = 1; i <= n; i++)
		{
			father[i] = i;
		}
		sort(e + 1, e + 1 + m, cmp);
		long long tot = 0, cnt = 0;
		for (int i = 1; i <= m; i++)
		{
			long long fu = lff(e[i].u), fv = lff(e[i].v);
			if (fu != fv)
			{
				father[fu] = fv;
				tot += e[i].cost;
				//cout << e[i].u << ' ' << e[i].v << ' ' << e[i].cost << ' ' << tot << '\n';
				cnt++;
				if (cnt == n - 1)
				{
					break;
				}
			}
		}
		cout << tot;
	return 0;
}
