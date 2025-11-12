#include<bits/stdc++.h>
using namespace std;
int n,m,k,c,a[10005],f[10005],siz,ans;
struct rd
{
	int u,v,w;
	friend bool operator<(const rd& a,const rd& b)
	{
		return a.w<b.w;
	}
}r[1000005];
int find(int x)
{
	return x==f[x]?x:(f[x]=find(f[x]));
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	siz=n-1;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].w);
	scanf("%d",&c);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(r+1,r+m+1);
	for(int i=1;i<=m;i++)
	{
		if(siz==0) break;
		if(find(r[i].u)!=find(r[i].v))
		{
			f[find(r[i].u)]=find(r[i].v);
			ans+=r[i].w;
			siz--;
		}
	}
	printf("%d",ans);
	return 0;
}
