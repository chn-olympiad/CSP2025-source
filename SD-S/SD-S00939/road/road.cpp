#include <bits/stdc++.h>
using namespace std;
struct nod
{
	int u,v,w,l;
}e[6000005];
int f[1000005],cnt,ans,sum;
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
int cmp(nod a,nod b)
{
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[++cnt]={u,v,w,0};
		e[++cnt]={v,u,w,0};
	}
	for(int i=1;i<=k;i++)
	{
		int d;
		cin>>d;
		for(int j=1;j<=n;j++)
		{
			int x;
			cin>>x;
			e[++cnt]={i+n,j,x+d,i};
			e[++cnt]={j,i+n,x+d,i};
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v)
		{
			f[u]=v;
			ans+=e[i].w;
			sum++;
		}
		if(sum==n+k-1)
			break;
	}
	cout<<ans;
	return 0;
}

