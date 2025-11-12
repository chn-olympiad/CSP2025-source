#include <bits/stdc++.h>
using namespace std;
struct dt
{
	int u, v, w, t;
};
vector<dt> lst;
int n, m, k;
int c[11];
int vis[11];
int fa[1000100];
int find(int x)
{
	if (fa[x] == x)
		return x;
	int tmp = find(fa[x]);
	fa[x] = tmp;
	return tmp;
}
bool rule(dt a, dt b)
{
	return a.w < b.w;
}
int cn(int u, int v, int w)
{
	int fu = find(u), fv = find(v);
	if (fu == fv)
		return 0;
	fa[fu] = fv;
	return w;
}
int ecn(int u, int v, int w,int t)
{
	//cout<<DEBUG<<u<<" "<<v<<'\n';
	if(!vis[t])return 0;
	int fu = find(u), fv = find(v);
	if (fu == fv)
		return 0;
	fa[fu] = fv;
	return w;
}
int mintree(int n, int m)
{
	int u, v, w;
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> u>> v>> w;
		lst.push_back({u, v, w, 0});
	}
	for (int i = 1; i <= n+k; i++)
		fa[i] = i;
	sort(lst.begin(), lst.end(), rule);
	for (int i = 0; i < m; i++)
	{
		ans += cn(lst[i].u, lst[i].v, lst[i].w);
	}
	cout << ans << '\n';
	return 0;
}
int extree(int n, int m){
	sort(lst.begin(), lst.end(), rule);
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		ans += ecn(lst[i].u, lst[i].v, lst[i].w,lst[i].t);
	}
		return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	
	cin >> n >> m >> k;
	if (k == 0)
		mintree(n, m);
	else
	{
		int u, v, w;
		bool flag=true;
		for (int i = 0; i < m; i++)
		{
			cin >> u, v, w;
			lst.push_back({u, v, w, 0});
		}
		for (int i = 0; i < k; i++)
		{
			cin >> c[i];
			if(c[i])flag=false;
			for (int j = 1; j <= n; j++)
			{
				cin >> w;
				lst.push_back({n + i, j, w, i});
			}
		}
		int ans=0;
		for(int i=0;i<(1<<k);i++){
			memset(vis,0,sizeof(vis));
			memset(fa,0,sizeof(fa));
			int vn=0,si=i,tmp=0;
			for(int j=0;j<k;j++){
				if(i%2)tmp+=c[vn];
				vis[vn]=i%2;
				si /=2;
				vn++;
			}
			tmp += extree(n,(int)lst.size());
			ans = max(ans,tmp);
		}
		cout<<ans<<'\n';
	}
	return 0;
}