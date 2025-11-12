#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,s,p[10010],b[10010],c[10010][10010],w[10010][10010],g[20],u[10010][10010],t[20];
long long Min;
void dfs(int a,long long l,int r)
{
	if(l>=Min) return;
	if(r==n)
	{
		Min=min(Min,l);
		return;
	}
	for(int i=1;i<=p[a];i++)
	  if(!b[c[a][i]])
	  {
	  	b[c[a][i]]=1;
	  	dfs(i,l+w[a][c[a][i]],r+1);
	  	b[c[a][i]]=0;
	  }
}
void bfs(int a,long long l,int r)
{
	if(l>=Min) return;
	if(r==n)
	{
		Min=min(Min,l);
		return;
	}
	for(int i=1;i<=p[a];i++)
	{
		if(!b[c[a][i]])
	    {
	  		b[c[a][i]]=1;
	  		bfs(i,l+w[a][c[a][i]],r+1);
	  		for(int j=1;j<=k;j++)
	      	  if(g[j]) bfs(i,l+u[j][c[a][i]],r+1);
	            else
				{
					g[j]=1;
	            	bfs(i,l+u[j][c[a][i]]+t[i],r+1);
				}
			b[c[a][i]]=0;
	    }
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&s);
		c[x][++p[x]]=y;
		c[y][++p[y]]=x;
		w[x][y]=s;
		w[y][x]=s;
	}
	if(k==0)
	{
		Min=0x3f3f3f3f3f3f3f3f;
		dfs(1,0,1);
		cout<<Min<<endl;
		return 0;
	}
	int bo=1;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&t[i]);
		if(t[i]!=0) bo=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&u[i][j]);
			if(u[i][j]!=0) bo=0;
		}
	}
	if(bo)
	{
		cout<<0<<endl;
		return 0;
	}
	Min=0x3f3f3f3f3f3f3f3f;
	bfs(1,0,1);
	cout<<Min<<endl;
	return 0;
}