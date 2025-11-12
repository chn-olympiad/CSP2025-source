#include<bits/stdc++.h>
using namespace std;
const int M=1e7+5,N=1e6+5;
struct Edge{
	int u,v,w;
}edge[M];
int c[20][N];
int cnt=0,sk[20];
bool cmp(Edge q,Edge w){
	return q.w<w.w;
}
int fa[N];
//void dfs(int nw,int k)
//{
//	if(nw==k+1)
//	{
//		int cnt2=0,yk=n;
//		cnt2=i;
//		for(int i=1;i<=k;i++)
//		{
//			if(sk[i]==1)
//			{
//				yk++;
//				for(int j=1;j<=n;j++)
//				{
//					edge2[++cnt2].u=yk,edge2[cnt2].v=j,edge2[cnt2].w=c[i][j];
//				}
//			}
//		}
//		sort(edge2+1,edge2+1+cnt2,cmp);
//	}
//	sk[nw]=1;
//	dfs(nw+1,k);
//	sk[nw]=0;
//	dfs(nw+1,k);
//}
int getfa(int now){
	return (fa[now]==now)?now:fa[now]=getfa(fa[now]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0,edgesum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edge[++cnt].u=u,edge[cnt].v=v,edge[cnt].w=w;
	}
	for(int i=1;i<=k;i++)
	{
		int a;
		cin>>a;
		for(int j=1;j<=n;j++)
		{
			int b;
			cin>>b;
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(edge+1,edge+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		if(getfa(u)==getfa(v)) continue;
		fa[u]=v;
		ans+=w,edgesum++;
		if(edgesum==n-1) break;
	}
	cout<<ans;
	return 0;
}
