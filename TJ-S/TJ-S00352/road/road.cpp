#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
ll ans;
int tot;
struct node
{
	int v,w;
};
int f[10005];
int cs[15][10005];
int find(int x)
{
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
struct edge
{
	int u,v,w;
}bian[2000005];
bool cmp(edge A,edge B)
{
	return A.w<B.w;
}
void kruskal()
{
	int cnt1=0;
	ans=0;
	for(int i=1;i<=tot;i++)
	{
		if(find(bian[i].u)!=find(bian[i].v))
		{
			f[find(bian[i].u)]=find(bian[i].v);
			ans+=bian[i].w;
			cnt1++;
			if(cnt1==n-1)break;
		}
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		bian[++tot]={u,v,w};
	}
	for(int i=1;i<=k;i++)
	{
		cin>>cs[i][0];
		if(cs[i][0]==0)
		{
			int ling;
			for(int j=1;j<=n;j++)
			{
				cin>>cs[i][j];
				if(cs[i][j]==0)ling=j;
			}
			for(int j=1;j<=n;j++)
			{
				bian[++tot]={ling,j,cs[i][j]};
			}
		}
		else for(int j=1;j<=n;j++)
		{
			cin>>cs[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	sort(bian+1,bian+tot+1,cmp);
	kruskal();
	cout<<ans;
	return 0;
}
