#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k,sum=0;
int vis[10005],fa[10005];
struct node{
	int x;
	int y;
	int v;
}e[1000005];
bool cmp(node x,node y)
{
	return x.v<y.v;
}
int dad(int x)
{
	while(fa[x]!=x)
	{
		x=fa[x];
	}
	return x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int i,j,o,p,t;
	for(i=1;i<=m;i++)
	{
		cin>>j>>o>>p;
		e[i].x=j;
		e[i].y=o;
		e[i].v=p;
	}
	int cnt=m;
	for(i=1;i<=k;i++)
	{
		cin>>t;
		for(j=1;j<=n;j++)
		{
			cin>>o;
			if(i!=j)
			{
	    		e[++cnt].x=i;
	        	e[cnt].y=j;
	        	e[cnt].v=o;			
			}
		}
	} 
	sort(e+1,e+cnt+1,cmp);
	for(i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(i=1;i<=m+k*(n-1);i++)
	{
		if(vis[e[i].x]==0||vis[e[i].y]==0||dad(e[i].x)!=dad(e[i].y))
		{
			fa[fa[e[i].y]]=fa[e[i].x];
			sum+=e[i].v;
			vis[e[i].x]=1;
			vis[e[i].y]=1;
		}
	}
	cout<<sum;
	return 0;
}
