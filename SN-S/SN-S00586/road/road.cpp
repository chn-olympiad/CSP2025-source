#include<bits/stdc++.h>
using namespace std;
 
int n,m,k;
int a[5005][5005];
int bw[15];
int bwvis[15];
int b[15][5005];

struct nod{
	int u,w;
	int oo;
	bool operator <(const nod y) const{
	return  y.w<w;
	}
};
priority_queue<nod> q1;
priority_queue<nod> q;

int vis[10003];
int ans;


int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=w;
		a[v][u]=w;
		q1.push(nod{u,w});
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&bw[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	nod t1=q1.top();
	q.push(nod{t1.u ,0});
	while(!q.empty())
	{
		nod t=q.top();
		q.pop();
		if(vis[t.u ])
		{	
			continue;
		}
		ans+=t.w ;
		vis[t.u ]=1;
				
		for(int j=1;j<=n;j++)
		{
			if(a[t.u ][j]&&vis[j]==0)
			{	
				q.push(nod{j,a[t.u ][j]});
			}	
		}
	}
	
	printf("%d",ans);
		
		
	
		
	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/

