#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ans,n,m,k,u,v,head,tail,minn;
ll f[10005],zhen[15][10005],c[15],dis[10005],q[100005],li[10005];
struct node
{
	ll v,len;
};
vector<node>a[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dis,0x7f,sizeof(dis));
	memset(li,0x7f,sizeof(li));
	int i,j,len;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		scanf("%lld %lld %lld",&u,&v,&len );
		a[u].push_back({v,len});
		a[v].push_back({u,len});
	}
	for(i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(j=1;j<=n;j++)
		{
			scanf("%lld",&zhen[i][j]);
		}
	}
	if(k==0)
	{
		head=0,tail=1;
		q[1]=1;
		dis[1]=0;
		li[1]=0;
		while(head<tail)
		{
			head++;
			u=q[head];
			len=a[u].size();
			for(i=0;i<len;i++)
			{
				v=a[u][i].v;
				if(dis[u]+a[u][i].len<dis[v])
				{
					dis[v]=dis[u]+a[u][i].len;
					li[v]=a[u][i].len;
					q[++tail]=v;
				}
			}
		}
		for(i=1;i<=n;i++)
		ans+=li[i];
		cout<<ans;
		return 0;
	}
	head=0,tail=1;
		q[1]=1;
		dis[1]=0;
		li[1]=0;
		while(head<tail)
		{
			head++;
			u=q[head];
			len=a[u].size();
			for(i=0;i<len;i++)
			{
				minn=INT_MAX;
				v=a[u][i].v;
				for(j=1;j<=k;j++)
				minn=min(a[u][i].len,min(minn,zhen[j][u]+zhen[j][v]));
				if(dis[u]+minn<dis[v])
				{
					dis[v]=dis[u]+minn;
					li[v]=minn;
					q[++tail]=v;
				}
			}
		}
		for(i=1;i<=n;i++)
		ans+=li[i];
		cout<<ans;
	return 0;
}

