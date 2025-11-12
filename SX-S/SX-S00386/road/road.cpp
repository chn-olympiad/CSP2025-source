#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=2e6+10;
int n,m,k,c[N],r[11][N],cnt=0,f[N];
ll ans;
struct node{
	int u,v,k;
}a[N];
int find(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
bool issame(int x,int y)
{
	return find(x)==find(y);
}
void build(int x,int y)
{
	if(issame(x,y)==0)
	{
		f[find(x)]=find(y);
	}
}
bool cmp(node p,node b)
{
	return p.k<b.k;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].k);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		int z=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&r[i][j]);
			if(r[i][j]==0)
			{
				z=j;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(j==z) continue;
			m++;
			a[m].u=j,a[m].v=z,a[m].k=r[i][j];
		}
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(cnt==n-1) break;
		else
		{
			if(issame(a[i].u,a[i].v))
			{
				continue;
			}
			else
			{
				ans+=a[i].k;
				build(a[i].u,a[i].v);
			}
		}
	}
	cout<<ans;
	return 0;
}
