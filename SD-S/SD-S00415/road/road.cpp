#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10010],cnt[10010];
long long ans=0;
struct node{
	int l,r;
	long long value;
}a[1000100];
int cmp(node x,node y)
{
	return x.value<y.value;
}
int Find(int x)
{
	if(fa[x]==x) return fa[x];
	return fa[x]=Find(fa[x]);
}
void uni(int x,int y)
{
	if(cnt[Find(x)]>cnt[Find(y)])
	{
		cnt[Find(x)]+=cnt[Find(y)];
		fa[Find(y)]=Find(x);	
	}
	else
	{
		cnt[Find(y)]+=cnt[Find(x)];
		fa[Find(x)]=Find(y);
	}
}
void krus()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		cnt[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int x=a[i].l,y=a[i].r;
		if(Find(x)!=Find(y))
		{
			uni(x,y);
			ans+=a[i].value;
		}
	}
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld",&a[i].l,&a[i].r,&a[i].value);
	sort(a+1,a+m+1,cmp);
	krus();
	printf("%lld",ans);
	return 0;
} 
