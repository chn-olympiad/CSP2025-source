#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10,M=1e6+10;
struct edg
{
	int u,v,w;
	bool operator <(const edg x) const
	{
		return w<x.w;
	}
};
int n,m,k,kk,ans,ind,nm,fa[N],v[11],a[N],l[11];
edg e1[M],e2[M],e[11][N];
int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
void pre()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int x,y,z,c;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e1[i].u>>e1[i].v>>e1[i].w;
	}
	sort(e1+1,e1+1+m);
	pre();
	ind=ans=0;
	for(int i=1;i<=m;i++)
	{
		x=find(e1[i].u);y=find(e1[i].v);
		if(x!=y)
		{
			e2[++ind]=e1[i];
			ans+=e1[i].w;
			fa[x]=y;
		}
		if(ind==n-1)
		{
			break;
		}
	}
	// cout<<ans<<"\n";
	for(int i=1;i<=k;i++)
	{
		cin>>v[i];
		x=1;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			if(a[j]<a[x])
			{
				x=j;
			}
		}
		v[i]+=a[x];
		if(v[i]==0)
		{
			for(int j=1;j<=n;j++)
			{
				if(j!=x&&a[j]<e2[n-1].w)
				{
					e2[++ind].u=x;
					e2[ind].v=j;
					e2[ind].w=a[j];
				}
			}
			i--;k--;
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			if(j!=x&&a[j]<e2[n-1].w)
			{
				e[i][++l[i]].u=x;
				e[i][l[i]].v=j;
				e[i][l[i]].w=a[j];
			}
		}
	}
	if(ind>n-1)
	{
		z=ans=0;
		pre();
		sort(e2+1,e2+1+ind);
		for(int i=1;i<=ind;i++)
		{
			x=find(e2[i].u);y=find(e2[i].v);
			if(x!=y)
			{
				e1[++z]=e2[i];
				ans+=e2[i].w;
				fa[x]=y;
			}
			if(z==n-1)
			{
				break;
			}
		}
		for(int i=1;i<n;i++)
		{
			e2[i]=e1[i];
		}
	}
	kk=(1<<k)-1;
	for(int dd=1;dd<=kk;dd++)
	{
		z=0;
		for(int i=1;i<=k;i++)
		{
			if((dd>>(i-1))%2==1)
			{
				z+=v[i];
			}
		}
		if(z>ans)
		{
			continue;
		}
		ind=0;
		for(int i=1;i<n;i++)
		{
			e1[++ind]=e2[i];
		}
		for(int i=1;i<=k;i++)
		{
			if((dd>>(i-1))%2==1)
			{
				for(int j=1;j<=l[i];j++)
				{
					if(e[i][j].w<e1[n-1].w)
					{
						e1[++ind]=e[i][j];
					}
				}
			}
		}
		sort(e1+1,e1+1+ind);
		pre();
		c=0;
		for(int i=1;i<=ind;i++)
		{
			x=find(e1[i].u);y=find(e1[i].v);
			if(x!=y)
			{
				z+=e1[i].w;
				fa[x]=y;
				c++;
			}
			if(z>=ans||c==n-1)
			{
				break;
			}
		}
		ans=min(ans,z);
	}
	cout<<ans;
}