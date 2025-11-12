#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1,K=11;
void fre()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
struct edge{int u,v,w;};
bool operator<(edge a,edge b){return a.w<b.w;}
vector<edge>vec;
int fa[N],w[K][N];
edge cur[N*K];
long long ans=1e16;
int n,m,k;
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	fre();
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		edge e;
		cin>>e.u>>e.v>>e.w;
		vec.push_back(e);
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)cin>>w[i][j];
	sort(vec.begin(),vec.end());
	for(int i=0;i<(1<<k);i++)
	{
		for(int j=1;j<=n+k;j++)fa[j]=j;
		int disc=n-1,CS=0;
		long long cost=0;
		for(int u=0;u<k;u++)
		if((i>>u)&1)
		{
			disc++;
			cost+=w[u+1][0];
			for(int v=1;v<=n;v++)
			{
				cur[++CS].u=u+n+1;
				cur[CS].v=v;
				cur[CS].w=w[u+1][v];
			}
		}
		sort(cur+1,cur+CS+1);
		int V=0,C=1;
		while(disc)
		{
			edge x;
			if(V!=(int)vec.size()&&(C==CS+1||vec[V]<cur[C]))
				x=vec[V],V++;
			else x=cur[C],C++;
			int u=x.u,v=x.v,w=x.w;
			u=find(u),v=find(v);
			if(u!=v)fa[u]=v,cost+=w,disc--;
		}
		ans=min(ans,cost);
	}
	cout<<ans<<'\n';
}
