#include <bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
using namespace std;
int n,m,k;
ll sum;
int c[25],b[25][10025],f[10025];
struct ilj{
	int u,v,w;
}a[2000025];
bool cmp(ilj s,ilj q)
{
	return s.w<q.w;
}
int find(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w; 
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>b[i][j];
			a[++m].u=i+n;
			a[m].v=j;
			a[m].w=b[i][j];
		}
	}
	
	for(int i=1;i<=n+k;i++) f[i]=i;
	sort(a+1,a+1+m,cmp);
	
	for(int i=1;i<=m;i++)
	{
		int x=find(a[i].u),y=find(a[i].v);
		if(x!=y)
		{
			f[x]=y;
			sum+=1ll*a[i].w;
		}
	}
	
	cout<<sum<<'\n';
	
	return 0;
}
