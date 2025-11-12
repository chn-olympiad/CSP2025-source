#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int MAXN = 1e6+10;


struct Node
{
	int u,v,w;
} e[MAXN];
ll n,m,k,a[11][MAXN],c[MAXN],cnt = 0,fa[MAXN];
bool vis[MAXN];

bool cmp(Node a,Node b)
{
	return a.w < b.w;
}

int find(int x)
{
	return fa[x] == x ? x : x = find(fa[x]);
}


int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
	{
		fa[i] = i;
	}
	for(int i=1;i<=m;i++)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin >> c[i];
		for(int j=1;j<=n;j++)
		{
			cin >> a[i][j];
		}
	}
	int tt = 1,ans = 0;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int u = e[i].u,v = e[i].v;
		int fx = find(u),fy = find(v);
		if(fx != fy)
		{
			bool flag = false;
			int tt;
			fa[fx] = fy;
			cnt++;
			for(int j=1;j<=k;j++)
			{
				if(c[j] + a[j][u] + a[j][v] <= e[i].w)
				{
					flag = true;
					tt = c[j] + a[j][u] + a[j][v];
					c[j] = a[j][u] = a[j][v] = 0;
				}
			}
			if(flag)
			{
				ans = ans + tt;
			}
			else
			{
				ans += e[i].w;
			}
		}
		if(cnt >= n - 1) break;
	}
	cout << ans;
	return 0;
}
