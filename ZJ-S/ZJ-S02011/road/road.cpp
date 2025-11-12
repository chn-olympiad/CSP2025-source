#include<bits/stdc++.h>
using namespace std;
struct info{
	int from,to,val;
}a[5000010];
int fa[10010],b[10086],n,m,k;
bool cmp(info a,info b)
{
	return a.val<b.val;
}
int findFa(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=findFa(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].from,&a[i].to,&a[i].val);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",b+i);
		for(int j=1;j<=n;j++)
		{
			m++;
			a[m].from=i+n;
			a[m].to=j;
			scanf("%d",&a[m].val);
		}
	}
	stable_sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
//		for(int j=1;j<=n;j++)
//			printf("%d ",fa[j]);
//		printf("\n");
		int x=a[i].from,y=a[i].to;
		if(findFa(x)==findFa(y))
			continue;
		x=findFa(x);
		y=findFa(y);
		fa[x]=y;
		ans+=a[i].val;
	}
	printf("%d",ans);
	return 0;
}
