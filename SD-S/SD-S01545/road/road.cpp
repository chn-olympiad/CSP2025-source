# include <bits/stdc++.h>
using namespace std;
const int MX = 1e4;
vector<pair<int,int> > mg[MX + 10];
struct gm
{
	int u;
	int v;
	int w;
};
gm g[MX + 10];
int f[MX + 10];
int n,m,k;
bool cmp(gm x,gm y)
{
	return x.w < y.w;
}
int gf(int num)
{
	return f[num]==num ? num : (f[num] = gf(f[num]));
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
	{
		f[i] = i;
	}
	for(int i = 1;i <= m;i++)
	{
		cin >> g[i].u >> g[i].v >> g[i].w;
	}
	sort(g + 1,g + m + 1,cmp);
	long long ans = 0;
	for(int i = 1;i <= m;i++)
	{
		int gu = gf(g[i].u),gv = gf(g[i].v);
		if(gu != gv)
		{
			ans+=g[i].w;
			mg[g[i].u].push_back({g[i].v,g[i].w});
			mg[g[i].v].push_back({g[i].u,g[i].w});
			f[gv] = gu;
		}
	}
	cout << ans << endl;
	return 0;
}
