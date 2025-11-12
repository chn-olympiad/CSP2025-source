#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[100011],fa[100011],cnt,x,y,z,tj;
struct node
{
	int x,y,z;
}e[2000001];
int dis[1001][1001],d[11][1005];
long long ans;
bool cmp(const node &u,const node &v)
{
	return u.z<v.z;
}
int find(int k)
{
	while(k!=fa[k])
	{
		k=fa[k];
		fa[k]=fa[fa[k]];
	}
	return k;
}
void kruskal()
{
	int i,u,v;
	cnt=0;
	for(i=1;i<=tj;i++)
	{
		u=find(e[i].x);
		v=find(e[i].y);
		if(u==v)
		{
			continue;
		}
		fa[u]=v;
		cnt++;
		ans+=e[i].z;
		if(cnt==n-1)
		{
			break;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j,l;
	scanf("%d%d%d",&n,&m,&k);
	if(k==0)
	{
		for(i=1;i<=n;i++)
		{
			fa[i]=i;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
		}
		sort(e+1,e+m+1,cmp);
		tj=m;
		kruskal();
		cout<<ans;
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		fa[i]=i;
		for(j=i+1;j<=n;j++)
		{
			dis[i][j]=INT_MAX;
		}
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		dis[x][y]=z;
		dis[y][x]=z;
	}
	for(i=1;i<=k;i++)
	{
		for(j=0;j<=n;j++)
		{
			scanf("%d",&d[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			for(l=1;l<=k;l++)
			{
				dis[i][j]=min(dis[i][j],d[l][i]+d[l][j]);
			}
			e[++tj].x=i;
			e[tj].y=j;
			e[tj].z=dis[i][j];
		}
	}
	sort(e+1,e+tj+1,cmp);
	kruskal();
	cout<<ans;
	return 0;
}

