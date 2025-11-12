#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans=0,cnt;
int f[10000005];
struct pp
{
	int x,y,w;
}r[10000005];
struct edge
{
	int x;
	int a[10000005];
}e[15];
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool cmp(pp x,pp y)
{
	return x.w<y.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	cnt=m;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		r[i].x=u;
		r[i].y=v;
		r[i].w=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>e[i].x;
		for(int j=1;j<=n;j++)
		{
			cin>>e[i].a[j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				cnt++;
				r[cnt].x=j;
				r[cnt].y=k;
				r[cnt].w=e[i].a[j]+e[i].a[k]+e[i].x;
			}
		}
	}
	sort(r+1,r+cnt+1,cmp);
//	for(int i=1;i<=cnt;i++){cout<<r[i].x<<' '<<r[i].y<<' '<<r[i].w<<endl;}
	for(int i=1;i<=cnt;i++)
	{
		int l=find(r[i].x);
		int j=find(r[i].y);
		if(l!=j)
		{
			ans+=r[i].w;
			f[l]=j;
		}
	}
	cout<<ans;
	return 0;
}
