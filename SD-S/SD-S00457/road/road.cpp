#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mk make_pair
mt19937 rnd(time(0));
struct Edge
{
	int u,v,e;
	ll w;
}edge[1100010];
int n,m,k,num;
ll ans=11000000000000ll;
ll c[20];
bool flag=1;
int fa[10050];
int find(int x){return fa[x]==x?x:find(fa[x]);}
void merge(int x,int y){fa[find(x)]=find(y);}
bool cmp(Edge x,Edge y){return x.w<y.w;}
bool solve()
{
	for(int i=1;i<=n+k;++i)fa[i]=i;
	ll res=0;
	for(int i=1;i<=num;++i)
	{
		if(find(edge[i].u)==find(edge[i].v))continue;
		res+=edge[i].w;
		if(rnd()%2)merge(edge[i].u,edge[i].v);
		else merge(edge[i].v,edge[i].u);
	}
	cout<<res;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
		edge[i].e=0;
	}
	for(int i=1,j=m+1;i<=k;++i)
	{
		cin>>c[i];
		if(c[i]!=0)flag=0;
		bool flag1=0;
		for(int k=1;k<=n;++k,++j)
		{
			cin>>edge[j].w;
			edge[j].v=k;
			edge[j].u=i+n;
			edge[j].e=i;
			if(edge[j].w==0)flag1=1;
		}
		if(!flag1)flag=0;
	}
	num=m+n*k;
	sort(edge+1,edge+1+num,cmp);
	if(flag)
	{
		solve();
		return 0;
	}
	for(int s=0;s<(1<<k);++s)
	{
		for(int i=1;i<=n+k;++i)fa[i]=i;
		ll res=0;
		int cnt=0;
		for(int i=1;i<=k;++i)res+=c[i]*(s&1<<(i-1)),cnt-=(s&1<<(i-1));
		if(res>ans)continue;
		for(int i=1;i<=num;++i)
		{
			if(edge[i].e!=0&&(s&(1<<(edge[i].e-1)))==0)continue;
			if(find(edge[i].u)==find(edge[i].v))continue;
			cnt++;
			res+=edge[i].w;
			if(rnd()%2)merge(edge[i].u,edge[i].v);
			else merge(edge[i].v,edge[i].u);
			if(res>ans||cnt==n)break;
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}//O(2^k*mlogn),72~100pts?
