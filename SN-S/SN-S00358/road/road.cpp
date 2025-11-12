#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c,x[1010],fa[1010];
long long ans;
bool book[1010];
struct node
{
	int l,r,x;
}a[1010];
inline bool cmp(node f,node g)
{
	return f.x<g.x;
}
inline int find(int x)
{
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].x);
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>x[i];
		}
		for(int j=1;j<=n;j++)
		{
			for(int p=i+1;p<=n;p++)
			{
				a[++m].l=j,a[m].r=p,a[m].x=x[j]+x[p]+c;
			}
		}
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].l)!=find(a[i].r))
		{
			fa[find(a[i].l)]=find(a[i].r);
			ans+=a[i].x;
		}
	}
	printf("%d\n",ans);
	return 0;
}
