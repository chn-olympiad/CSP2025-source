#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,len,c[20],w[20][20005],siz[20005];
vector<pair<int,int>>vec[20005];
struct node{
	int u,v;
	ll w;
	int op;
}a[10000005];
int fa[20005];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
ll solve(int sta)
{
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	ll sum=0,cnt=0;
	for(int i=0;i<k;i++)
	{
		if((sta>>i)&1) sum+=c[i+1];
	}
	for(int i=1;i<=len;i++)
	{
		if(cnt==n+10) break;
		int fx=find(a[i].u);
		int fy=find(a[i].v);
		if(a[i].u==a[i].v) continue;
		if(a[i].op!=0&&(!(sta>>(a[i].op-1))&1)) continue;
		if(siz[fx]>siz[fy]) swap(fx,fy);
		if(fx!=fy) siz[fy]+=siz[fx],cnt++,fa[fx]=fy,sum+=a[i].w;
//		cout<<a[i].w<<" "<<sum<<"\n";
	}
	return sum;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		vec[u].push_back({v,w});
		vec[v].push_back({u,w});
		a[++len]={u,v,w,0};
	}
	bool flag=1;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		if(c[i]!=0) flag=0;
		for(int j=1;j<=n;j++) 
		{
			scanf("%lld",&w[i][j]);
		} 
		for(int j=1;j<=n;j++)
		{
			for(int x=j+1;x<=n;x++)
			{
				vec[j].push_back({x,w[i][j]+w[i][x]});
				vec[x].push_back({j,w[i][j]+w[i][x]});
				a[++len]={j,x,w[i][j]+w[i][x],i};
			}
		}
	}
	if(flag)
	{
		sort(a+1,a+len+1,cmp);
		ll ans=0,cnt=0;
		for(int i=1;i<=len;i++)
		{
			if(cnt==n+10) break;
			int fx=find(a[i].u);
			int fy=find(a[i].v);
			if(a[i].u==a[i].v) continue;
			if(siz[fx]>siz[fy]) swap(fx,fy);
			if(fx!=fy) 
			{
				cnt++;
				fa[fx]=fy;
				siz[fy]+=siz[fx];
				ans+=a[i].w;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	sort(a+1,a+len+1,cmp);
	ll ans=9e18;
	for(int i=0;i<(1ll<<k);i++)
	{
		ll res=solve(i);
//		printf("%lld\n",res);
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}//	Ren5Jie4Di4Ling5%

//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4

