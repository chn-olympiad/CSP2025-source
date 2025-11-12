#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,fa[10010];
struct node{
	int u,v,w;
}e[2000010];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(x)]=find(y);
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			if(find(e[i].u)!=find(e[i].v))
			{
				merge(e[i].u,e[i].v);
				ans+=e[i].w;
				n--;
			}
			if(n==1)
			{
				cout<<ans;
				return 0;	
			} 
		}
	}
	else cout<<0;
	return 0;
} 
