#include <bits/stdc++.h>
using namespace std;
const long long N=1e4+30;
long long n,m,k;
long long c[11];
long long a[11][N];
long long f[N];
struct lhz{
	long long v,u,w;
} ee[N];
long long find(int x)
{
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
void he(int x,int y)
{
	int xx=find(x),yy=find(y);
	f[xx]=yy;
}
bool cmp(lhz p,lhz q)
{
	return p.w<q.w;
}
void prime()
{
	long long ans=0;
	for(int i=1;i<=m+n*k;i++)
	{
		//cout<<ee[i].u<<" "<<ee[i].v<<" "<<ee[i].w<<" "<<find(ee[i].u)<<" "<<find(ee[i].v)<<'\n';
		if(find(ee[i].u)==find(ee[i].v))continue;
		ans+=ee[i].w;
		he(ee[i].u,ee[i].v);
	}
	cout<<ans;
} 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	 } 
	for(int i=1;i<=m;i++)
	{
		cin>>ee[i].u>>ee[i].v>>ee[i].w;
	}
	for(int i=n+1;i<=n+k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			ee[i].u=i;ee[i].v=j;ee[i].w=a[i][j];
		}
	}
	sort(ee+1,ee+1+m+k,cmp);
	prime();
	return 0;
}
//16pts
