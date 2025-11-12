#include <bits/stdc++.h>
#define int long long
using namespace std;

struct edge
{
	int u,v,dis;
};

int n,m,k,c[15],z,fa[10015],qtt,ans;
edge e[1500005];

int fd(int x)
{
	return (fa[x] == x?x:fa[x] = fd(fa[x]));
}

bool merge(int x,int y)
{
	x = fd(x),y = fd(y);
	if (x == y) return false;
	qtt--;
	fa[x] = y;
	return true;
}

bool cmp(edge e1,edge e2)
{
	return e1.dis < e2.dis;
}

int solve(int sta)
{
	for (int i = 1;i <= n+k;i++) fa[i] = i;
	qtt = n+k;
	int ret = 0;
	for (int i = 1;i <= z;i++)
	{
		if (qtt == 1 || ret >= ans) break;
		if (e[i].u > n && ((sta>>(e[i].u-n-1))&1) == 0) continue;
		if (e[i].v > n && ((sta>>(e[i].v-n-1))&1) == 0) continue;
		if (merge(e[i].v,e[i].u)) ret += e[i].dis;
	}
	return ret;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++) cin >> e[i].u >> e[i].v >> e[i].dis;
	for (int i = 1;i <= k;i++)
	{
		int mx = 0;
		cin >> c[i];
		mx = max(mx,c[i]);
		for (int j = 1;j <= n;j++)
		{
			int pos = m+(i-1)*n+j;
			e[pos].u = n+i,e[pos].v = j;
			cin >> e[pos].dis;
			mx = max(mx,e[pos].dis);
		}
		if (mx == 0)
		{
			cout << 0 << '\n';
			return 0;
		}
	}
	z = m+n*k;
	ans = 1e18;
	sort(e+1,e+z+1,cmp);
	for (int i = 0;i < (1<<k);i++)
	{
		int sm = 0;
		for (int j = 0;j < k;j++) if ((i>>j)&1) sm += c[j+1];
		ans = min(ans,solve(i)+sm);
	}
	cout << ans;
	return 0;
}
