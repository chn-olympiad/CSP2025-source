#include<bits/stdc++.h>
using namespace std;
struct stu
{
	long long u,v,w;
};
stu a[10000005];
long long W[10005];
long long f[10005];
long long g[10005][10005];
long long n,m,k;
long long cnt=0;
bool cmp(stu a,stu b)
{
	return a.w<b.w;
}
long long find(long long x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
long long unionn(long long x,long long y)
{
	f[find(x)]=find(y);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(g,0x3f,sizeof g);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		long long u,v,w;
		cin>>u>>v>>w;
		g[min(u,v)][max(u,v)]=min(g[min(u,v)][max(u,v)],w);
	}
	for(long long i=1;i<=k;i++)
	{
		long long c;
		cin>>c;
		for(long long j=1;j<=n;j++)
		  cin>>W[j];
		for(long long j=1;j<=n;j++)
		  for(long long l=j+1;l<=n;l++)
		    g[j][l]=min(g[j][l],c+W[j]+W[l]);
	}
	for(long long i=1;i<=n;i++)
	  for(long long j=i+1;j<=n;j++) 
	    if(g[i][j]!=0x3f3f3f3f3f3f3f3f)
	      a[++cnt].u=i,a[cnt].v=j,a[cnt].w=g[i][j];
	sort(a+1,a+1+cnt,cmp);
	for(long long i=1;i<=n;i++) f[i]=i;
	long long ans=0,q=0;
	for(long long i=1;i<=cnt;i++)
	{
		if(find(a[i].u)!=find(a[i].v))
		{
			ans+=a[i].w;
			q++;
			unionn(a[i].u,a[i].v);
		}
		if(q==n-1) break;
	}
	cout<<ans;
	return 0;
}
