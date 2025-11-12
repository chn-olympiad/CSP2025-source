#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int start,to,w;
}edge[2000005];
node edge2[2000005];
int country[15][10015];
int cost[15];
int n,m,k;
int n2,m2;
bool cmp(node e1,node e2)
{
	return e1.w<e2.w;
}
int fa[10015];
int getfa(int u)
{
	if(fa[u]==u) return u;
	else return fa[u]=getfa(fa[u]);
}
void merge(int u,int v)
{
	int fau=getfa(u);
	int fav=getfa(v);
	fa[fau]=fav;
}
ll kruskal()
{
	for(int i=1;i<=m;i++) edge2[i]=edge[i];
	sort(edge2+1,edge2+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	int cnt1=0;
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		if(cnt1==n-1)
		{
			return ans;
		}
		int u=edge2[i].start;
		int v=edge2[i].to;
		int w=edge2[i].w;
		if(getfa(u)==getfa(v)) continue;
		ans+=w;
		merge(u,v);
		cnt1++;
	}
}
bool vis[15];
ll dfs(int u)
{
	if(u==k+1)
	{
		ll ans=0;
		int cnt=m;
		int cnt2=0;
		for(int i=1;i<=k;i++)
		{
			if(!vis[i]) continue;
			ans+=cost[i];
			cnt2++;
			for(int j=1;j<=n;j++)
			{
				edge[++cnt].start=i+n;
				edge[cnt].to=j;
				edge[cnt].w=country[i][j];
			}
		}
		m2=m;
		m=cnt;
		n2=n;
		n+=cnt2;
		//for(int i=1;i<=m;i++) cout<<edge[i].start<<' '<<edge[i].to<<' '<<edge[i].w<<endl;
		//cout<<endl;
		ans+=kruskal();
		m=m2,n=n2;
		return ans;
	}
	ll ans1=dfs(u+1);
	vis[u]=1;
	ll ans2=dfs(u+1);
	vis[u]=0;
	return min(ans1,ans2);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>edge[i].start>>edge[i].to>>edge[i].w; 
	}
	if(k==0)
	{
		cout<<kruskal();
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>cost[i];
		for(int j=1;j<=n;j++) cin>>country[i][j];
	}
	cout<<dfs(1);
	return 0;
}