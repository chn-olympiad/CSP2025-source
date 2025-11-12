#include<bits/stdc++.h>
using namespace std;
const int N=10005,M=1e6+5;
struct FZH
{
	int u,v,w;
	int isrural;
}edge[M];
int m,n,k;
int c[20];
int cedge[20][10010];
bool vis[20];
bool haveedge[N][N];
int fa[N];
long long ans;
int cnt;
bool cmp(FZH a,FZH b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
} 
long long kruskal()
{
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int u=find(edge[i].u),v=find(edge[i].v);
		if(u==v) continue;
		fa[u]=v;
		if(edge[i].isrural && !vis[edge[i].isrural])
		{
			ans+=c[edge[i].isrural];
			vis[i]=true;	
		} 
		ans+=edge[i].w;
		if(++cnt==n-1)  break;
	} 
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) 
	{
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
		haveedge[edge[i].u][edge[i].v]=true;
	}	
	for(int j=1;j<=k;j++)//乡村 
	{
		cin>>c[j];
		for(int i=1;i<=n;i++) cin>>cedge[j][i];		
	}
	if(k!=0)
	{
		for(int i=1;i<=m;i++)//边 
		{
			for(int j=1;j<=k;j++)//乡村 
			{
				if(cedge[j][edge[i].u]+cedge[j][edge[i].v]+c[j]<edge[i].w)
				{
					edge[i].isrural=j;//记录通过乡村的下标 
					edge[i].w=cedge[j][edge[i].u]+cedge[j][edge[i].v];		
				}	
			}	
		}		
	}
	if(k!=0)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)//每两个点之间 
			{
				if(!haveedge[i][j])
				{
					edge[++m].u=i;
					edge[m].v=j;		
					edge[m].w=INT_MAX;		
					for(int l=1;l<=k;l++)
					{	
						if(cedge[l][edge[m].u]+cedge[l][edge[m].v]+c[l]<edge[m].w)
						{
							edge[m].isrural=l;//记录通过乡村的下标 
							edge[m].w=cedge[l][edge[m].u]+cedge[l][edge[m].v];		
						}					
					}
				} 
			}	
		} 		
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	cout<<kruskal();
	return 0;
}
