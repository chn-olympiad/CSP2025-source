#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,M=1e6+5;
int nw[15][N],a[20],f[N];
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
		f[fx]=fy;
}
struct node{
	int u,v,l;
};
node b[N];
bool cmp(node p,node q)
{
	return p.l<q.l;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i].u>>b[i].v>>b[i].l;
	}	
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		for(int j=1;j<=n;j++)
		{
			cin>>nw[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int ij=1;ij<=k;ij++)
			{
				m++;
				b[m].u=i;
				b[m].v=j;
				b[m].l=nw[ij][i]+nw[ij][j];
			} 
		}
	}
	int ans=0;
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(find(b[i].u)!=find(b[i].v)) 
		{
			ans+=b[i].l;
			merge(b[i].u,b[i].v);
		}
	}
	cout<<ans<<'\n';
	return 0;
}

