#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	int x;
	ll w;
};
int n,m,k;
ll c[10020],s[10020],ans=1e18;
vector <node> v[10020];
bool flag[10010],f[10020],e;
void dfs(int x,ll s)
{
	e=1;
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==0)
		{
			e=0;
			break;
		}
	}
	if(e==1)
	{
		ans=min(ans,s);
		return;
	}
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i].x;
		ll w=v[x][i].w;
		if(flag[y]==1) continue;
		flag[y]=1;
		if(y>n)
		{
			f[y]=1;
			dfs(y,s+w+c[y]);
			f[y]=0;
		}
		else dfs(y,s+w);
		flag[y]=0;
	}
}
int main()
{
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k); 
	for(int i=1;i<=m;i++)
	{
		int x,y;
		ll w;
		scanf("%d %d %lld",&x,&y,&w);
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[n+i]);
		for(int j=1;j<=n;j++)
		{
			ll w;
			scanf("%lld",&w);
			v[n+i].push_back({j,w});
			v[j].push_back({n+i,w});
		}
	}
	flag[1]=1;
	dfs(1,0);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
