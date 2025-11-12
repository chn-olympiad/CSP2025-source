#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k;
struct edge{int u;int v;int w;};
edge g[N*100],g1[N*100];
int c[15];
int a[15][N];
int fa[N];
long long mi=1e18;
long long ans;
int cnt;
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int fi(int x)
{
	return (x==fa[x]?x:(fa[x]=fi(fa[x])));
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[i]={u,v,w};
	}
	if(k==0)
	{
		sort(g+1,g+1+m,cmp);
		for(int i=1;i<=m;i++)
		{
			int x=g[i].u;
			int y=g[i].v;
			int z=g[i].w;
			int fx=fi(x);
			int fy=fi(y);
			if(fx==fy) continue;
			ans+=z;
			fa[fx]=fy;
		}
		cout<<ans;
		return 0;
	}
	else
	{
		if(n>500||m>100000)
		{
			cout<<0;
			return 0;
		}
		for(int i=1;i<=m;i++)
		{
			g1[i]=g[i];
		}
		cnt=n+1; 
		for(int i=cnt;i<k+cnt;i++)
		{
			cin>>c[i];
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=0;i<=(1<<k)-1;i++)
		{
			for(int i=1;i<=n;i++)
			{
				fa[i]=i;
			}
			for(int i=1;i<=m;i++)
			{
				g[i]=g1[i];
			}
			int lm=m;
			ans=0;
			for(int j=0;j<k;j++)
			{
				if((1<<j)&i)
				{
					ans+=c[j+cnt];
					bool flag=false;
					for(int q=1;q<=n;q++)
					{
						for(int p=q+1;p<=n;p++)
						{
							for(int r=1;r<=lm;r++)
							{
								int u=g[r].u;
								int v=g[r].v;
								int w=g[r].w;
								if((u==q&&v==p)||(u==p&&v==q))
								{
									if(a[j+cnt][p]+a[j+cnt][q]<w)
									{
										flag=true;
										g[r].w=a[j+cnt][p]+a[j+cnt][q];
										break;
									}
								}
							}
							if(!flag)
							{
								g[++lm]={p,q,a[j+cnt][p]+a[j+cnt][q]};
							}
						}
					}
				}
			}
			sort(g+1,g+lm+1,cmp);
//			for(int i=1;i<lm;i++)
//			{
//				cout<<g[i].u<<" "<<g[i].v<<" "<<g[i].w<<endl;
//			}
//			cout<<endl<<endl<<endl;
			for(int i=1;i<=lm;i++)
			{
				int x=g[i].u;
				int y=g[i].v;
				int z=g[i].w;
				int fx=fi(x);
				int fy=fi(y);
				if(fx==fy) continue;
				//cout<<x<<" "<<y<<" "<<z<<endl;
				ans+=z;
				//cout<<ans<<endl;
				fa[fx]=fy;
			}
			//cout<<ans<<endl;
			mi=min(mi,ans);
		}
		cout<<mi;
	}
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
