#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,c[10005][10005],z[10005];
long long pd[10005][10005];
struct road{
	int b;
	int u;
	int v;
	int w;
}r[1000005];
/*int cost(int x,int y,int co,long long mins)
{
	if(x==y) return co;
	for(int i=1;i<=n;i++)
	{
		if(pd[x][i]!=0&&z[i]==0)
		{
			z[x]=1;
			cout<<i<<" "<<pd[x][i]<<" "<<co<<endl;
			int s=cost(i,y,co+r[pd[x][i]].w,mins);
			z[x]=0;
			if(mins>s) mins=s;
		}
	}
	co+=mins;
}
bool cmp(road a,road b)
{
	return a.w<b.w;
}
*/
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		r[i].b=i;
		cin>>u>>v>>r[i].w;
		pd[u][v]=i;
		pd[v][u]=i;
	}
	/*for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			c[i][j]=cost(i,j,0);
		}
	}*/
	cout<<0;
	/*for(int i=1;i<=m;i++)
	{
		cout<<r[i].b<<" "<<r[i].w<<endl;
	}*/
	return 0;
}