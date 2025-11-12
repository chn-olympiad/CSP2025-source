#include<bits/stdc++.h>
using namespace std;
struct st
{
	int u;
	int v;
	int w;
};
st r[2000005];
int f[2000005];
int find(int x)
{
	if(f[x]==x)
	{
		return x;
	}
	return f[x]=find(f[x]);
}
bool cmp(st x,st y)
{
	return x.w<y.w;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		r[i]={u,v,w};
	}
	for(int i=1;i<=m+k*n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=k;i++)
	{
		int c;
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			int a;
			cin>>a;
			r[m+j+(i-1)*n]={n+i,j,a+c};
		}
	}
	sort(r+1,r+m+k*n+1,cmp);
	int ans=0;
	int cnt=m+k*n;
	for(int i=1;i<=m+k*n;i++)
	{
		if(cnt==1)
		{
			break;
		}
		int u=r[i].u;
		int v=r[i].v;
		int w=r[i].w;
		if(find(u)!=find(v))
		{
			cnt--;
			f[find(u)]=find(v);
			ans+=w;
		}
	}
	cout<<ans;
	return 0;
}
