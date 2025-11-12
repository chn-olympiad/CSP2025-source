#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int l[10005];
long long sum;

struct Road
{
	int u, v, w;
}r[1000005];

bool Cmp(Road a, Road b)
{
	if(a.w < b.w)return 1;
	return 0;
}

int Find_Root(int x)
{
	if(x == l[x])return x;
	else return Find_Root(l[x]);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("rode.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)cin >> r[i].u >> r[i].v >> r[i].w;
	for(int i = 1; i <= n; i++)l[i] = i;
	sort(r + 1, r + 1 + m, Cmp);
	for(int i = 1; i <= m; i++)
	{
		if(Find_Root(r[i].u) != Find_Root(r[i].v))
		{
			sum += r[i].w;
			l[r[i].v] = l[r[i].u];
		}
	}
	cout << sum;
	return 0;
}
