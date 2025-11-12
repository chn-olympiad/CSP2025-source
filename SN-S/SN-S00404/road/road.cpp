#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[10010],sum,mm;
int kk[11],kc[11][10010],vis[1011];
long long ans;
struct node
{
	int x,y,z;
}a[1100010];
bool cmp(node a,node b)
{
	if(a.z<b.z) return true;
	else return false;
}
int find(int x)
{
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
void merge(int x,int y)
{
	f[find(x)]=find(y);
	if(x<=m) sum--;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	sum=n;
	mm=m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&kk[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&kc[i][j]);
			mm++;
			a[mm].x=i+1000;
			a[mm].y=j;
			a[mm].z=kc[i][j]+kk[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=mm;i++)
	{
		int u=a[i].z;
		if(find(a[i].x)!=find(a[i].y))
		{
			merge(a[i].x,a[i].y);
			if(a[i].x>m)
			{
				if(vis[a[i].x]==0) 
				{
					u+=kk[a[i].x-m];
					vis[a[i].x]=1;
				}
			}
			ans+=u;
		}
		if(sum==1) break;
	}
	printf("%lld",ans);
	return 0;
}
