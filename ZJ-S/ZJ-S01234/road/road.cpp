#include<bits/stdc++.h>
using namespace std;
const int N=1e4+51;
const int M=1e6+51;
int n,m,k,tot;
int val[15],fa[N];
bool vis[15];
long long ans=1e18;
struct road
{
	int u,v,w;
}r[M+N*10];
bool cmp(road a,road b)
{
	return a.w<b.w;
}
bool spA=true;
int dis[N];
bool cho[N];
int findfa(int u)
{
	return fa[u]==u?u:fa[u]=findfa(fa[u]);
}
long long chk(long long s,int tt)
{
	int cnt=0;
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	for(int i=1;i<=m+n*k&&cnt<tt;i++)
		if((r[i].u<=n||vis[r[i].u-n])&&(r[i].v<=n||vis[r[i].v-n]))
		{
			int fu=findfa(r[i].u),fv=findfa(r[i].v);
			if(fu==fv) continue;
			fa[fu]=fv;
			cnt++;
			s+=r[i].w;
			if(s>=ans) return 1000000000000000000ll;
		}
	return s;
}
void dfs(int now=1,long long v=0ll,int num=0)
{
	if(v>=ans) return;
	if(now>k)
	{
		ans=min(ans,chk(v,num+n));
		return;
	}
	if(!spA) dfs(now+1,v,num);
	vis[now]=true;
	dfs(now+1,v+val[now],num+1);
	vis[now]=false;
}
bool cmp1(road x,road y)
{
	return x.u!=y.u?x.u<y.u:x.v!=y.v?x.v<y.v:x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		//r[i].u=rand()%n+1,r[i].v=rand()%n+1,r[i].w=rand()+1;
		cin>>r[i].u>>r[i].v>>r[i].w;
		if(r[i].u>r[i].v) swap(r[i].u,r[i].v);
	}
	for(int i=1;i<=k;i++)
	{
		//val[i]=rand()+1;
		cin>>val[i];
		spA&=(val[i]==0);
		bool ff=false;
		for(int j=1,w;j<=n;j++)
		{
			//w=rand()+1;
			cin>>w;
			ff|=(w==0);
			r[m+(i-1)*n+j]={j,i+n,w};
		}
		spA&=ff;
	}
	sort(r+1,r+1+m+n*k,cmp1);
	for(int i=1;i<=m+n*k;i++)
	{
		r[++tot]=r[i];
		while(i<m+n*k&&r[i].u==r[i+1].u&&r[i].v==r[i+1].v) i++;
	}
	sort(r+1,r+1+tot,cmp);
//	for(int i=1;i<=m+n*k;i++)
//		cout<<r[i].u<<" "<<r[i].v<<" "<<r[i].w<<"\n";
	dfs();
	cout<<ans<<"\n";
}