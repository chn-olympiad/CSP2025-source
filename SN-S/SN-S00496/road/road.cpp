#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
struct data
{
	int u,v,w;
}a[maxn];
int c[maxn];
int mer[10001][10001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int ans=0;
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		ans+=a[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&mer[i][j]);
		}
	}
	
} 
