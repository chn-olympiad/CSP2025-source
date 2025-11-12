#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,vil[15],t;
long long ans;
struct edge
{
	int u,v,w,sp;
	bool operator<(const edge k)const
	{
		return w<k.w;
	}
}
e[1000005];
int vis[10005],fa[100005];
int getfa(int x)
{
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
void merge(int a,int b)
{
	a=getfa(a),b=getfa(b);
	fa[a]=b;
}
int kruskal(int p)
{
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	int cnt=0,cost=0;
	for(int i=1;i<=m+p;i++)
	{
		int s=e[i].u,t=e[i].v,c=e[i].w,f=e[i].sp;
		s=getfa(s),t=getfa(t);
		if(s==t)
			continue;
		if(f!=0)
		{
			if(p&(1<<f)!=0)
				cnt++,cost+=c,fa[s]=t;
		}
			
		else if(f==0)
			cost+=c,merge(s,t);
		else
			continue;
	}
	return cost;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		e[i]=(edge){u,v,w,0};
		e[i]=(edge){v,u,w,0};
	}
	for(int i=1;i<=k;i++)
	{
		cin>>vil[i];
		for(int j=1;j<=n;j++)
		{
			cin>>w;
			e[m+i]=(edge){n+i,j,w,i};
			e[m+i]=(edge){j,n+i,w,i};
		}	
	}
	sort(e+1,e+m+k+1);
	/*
	for(int i=1;i<=m+k;i++)
		cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<" "<<e[i].sp<<endl;
	*/
	ans=kruskal(0);
	if(k==0)
	{
		ans=kruskal(0);
		cout<<ans;
		return 0;
	}
	else
	{
		for(int i=0;i<(1<<k);i++)
		{
			//cout<<i<<" ";
			long long now=0;
			for(int j=1;j<=n;j++)
				if(i&(1<<j))
					now+=vil[j];
			now+=kruskal(i);
			//cout<<now<<endl;
			ans=min(ans,now);
		}
		cout<<ans;
	}
	
	return 0;
} 
/*
6 8 0
1 2 1
1 4 3
1 6 4
2 5 2
3 6 3
3 4 2
4 5 1
5 6 2
*/
