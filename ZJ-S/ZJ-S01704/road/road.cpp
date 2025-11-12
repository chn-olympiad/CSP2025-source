#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,c[11][10001],a[10011],p;
long long s,ans=1e18;
struct way
{
	int u,v,w;
}ways[1100011],t[1100011];
bool cmp(way x,way y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>t[i].u>>t[i].v>>t[i].w;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)cin>>c[i][j];
	}
	for(int j=0;j<(1<<k);j++)
	{
		s=0,p=0;
		for(int i=1;i<=m;i++)ways[i].u=t[i].u,ways[i].v=t[i].v,ways[i].w=t[i].w;
		for(int i=1;i<=n;i++)a[i]=i;
		for(int l=1;l<=k;l++)
		{
			if(j&(1<<(l-1)))
			{
				s+=c[l][0];
				for(int i=1;i<=n;i++)ways[m+i+n*p].u=i,ways[m+i+n*p].v=n+p+1,ways[m+i+n*p].w=c[l][i];
				p++;
				a[n+p]=n+p;
			}
		}
		sort(ways+1,ways+m+n*p+1,cmp);
		for(int i=1;i<=m+n*p;i++)
		{
			if(a[ways[i].u]!=a[ways[i].v])
			{
				for(int q=1;q<=n+p;q++)
				{
					int tt=a[ways[i].v];
					if(a[q]==tt)
					{
						a[q]=a[ways[i].u];
					}
				}
				s+=ways[i].w;
			}
		}
		ans=min(ans,s);
	}
	cout<<ans;
	return 0;
}
