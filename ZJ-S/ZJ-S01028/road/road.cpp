//bqq miaomiaomiao
//can i get 56 pts? plssssss.
//i forgot minnest shengchengshu qwq...
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	int u,v;
	ll w;
}a[11000010];
int fa[10010];
int find(int x)
{
	if(x==fa[x])
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
ll c[20],w[20][10010];
int xb[20];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		if(u>v)
		{
			swap(u,v);
		}
		a[i]={u,v,w};
	}
	int suba=0;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i])
		{
			suba=1;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>w[i][j];
			if(!w[i][j])
			{
				xb[i]=j;
			}
		}
	}
	if(!k)
	{
		sort(a+1,a+m+1,cmp);
		ll ans=0;
		for(int i=1;i<=m;i++)
		{
			int fx=find(a[i].u),fy=find(a[i].v);
			if(find(fx)!=find(fy))
			{
				ans+=a[i].w,fa[fy]=fa[fx];
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(!suba)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==xb[i])
				{
					continue;
				}
				int u=j,v=xb[i];
				if(u>v)
				{
					swap(u,v);
				}
				a[++m]={u,v,w[i][j]};
			}
		}
		sort(a+1,a+m+1,cmp);
		ll ans=0;
		for(int i=1;i<=m;i++)
		{
			int fx=find(a[i].u),fy=find(a[i].v);
			if(find(fx)!=find(fy))
			{
				ans+=a[i].w,fa[fy]=fa[fx];
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+m+1,cmp);
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		int fx=find(a[i].u),fy=find(a[i].v);
		if(find(fx)!=find(fy))
		{
			ans+=a[i].w,fa[fy]=fa[fx];
		}
	}
	if(n<=1e3)
	{
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int l=j+1;l<=n;l++)
				{
					a[++m]={j,l,(ll)(c[i]+w[i][j]+w[i][l])};
				}
			}
			if(clock()/CLOCKS_PER_SEC>0.90)
			{
				cout<<ans<<endl;
				return 0;
			}
		}
		sort(a+1,a+m+1,cmp);
		ll ans2=0;
		for(int i=1;i<=m;i++)
		{
			int fx=find(a[i].u),fy=find(a[i].v);
			if(find(fx)!=find(fy))
			{
				ans2+=a[i].w,fa[fy]=fa[fx];
			}
			if(clock()/CLOCKS_PER_SEC>0.95)
			{
				cout<<ans<<endl;
				return 0;
			}
		}
		cout<<(ll)min(ans,ans2)<<endl;
	}
	else
	{
		cout<<ans<<endl;
	}
	return 0;
}