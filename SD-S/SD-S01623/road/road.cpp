#include<bits/stdc++.h>
using namespace std;
const int MAXN=10010;
long long n,m,k;
struct edge
{
	long long u,v,w;
	bool operator<(const edge &x)const
	{
		return w<x.w;
	}
}e[1100010];
long long p,ans;
long long u,v,w;
long long a[15][MAXN];
long long c[15];
long long f[MAXN];
long long find(long long p)
{
	if(f[p]!=p)
	{
		f[p]=find(f[p]);
		return f[p];
	}
	else return p;
}
void add(long long x,long long y)
{
	long long fx=find(x),fy=find(y);
	if(fx!=fy) f[fx]=fy;
}
struct node
{
	long long v,p;
	bool operator<(const node& x)const
	{
		return v<x.v;
	}
};
int main()
{
	//freopen()
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v>>w;
			e[i].u=u,e[i].v=v,e[i].w=w;
		}
		/*
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
				e[++m].u=j,e[m].v=n+i,e[m].w=a[i][j]+c[i];
			}
		}
		*/
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
			for(int j=1;j<=n;j++)
			{
				cin>>c[i];	
			}	
		} 
		sort(e+1,e+m+1);
		long long num=0;
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<=m;i++)
		{
			u=e[i].u,v=e[i].v,w=e[i].w;
			long long fu=find(u),fv=find(v);
			if(fu!=fv)
			{
				ans+=w;
				add(fu,fv);
				num++;
			}
			if(num==n-1) break;
		}
		cout<<ans;
	
	/*
	else
	{
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v>>w;
			ad(u,v,w);
			ad(v,u,w);
		}
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
				ad(j,n+i,a[i][j]);
				ad(n+i,j,a[i][j]);
			}
		}
		dis[1]=0;
		q.push(1);
		for(int i=1;i<=n;i++)
		{
			p=q.top();
			q.pop();
			for(int i=h[p];i;i=e[i].u)
			{
				int t=e[i].v;
				w=e[i].w;
				if(dis[t]>w)
				{
					dis[t]=w;
					
				}
			}
		}
	}
	*/
    return 0;
}
