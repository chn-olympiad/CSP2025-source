#include<bits/stdc++.h>
using namespace std;
int m,n,a[15][10010],sum,x,y,z,MIN,fa[10020],c[20],k;
struct node
{
	int u,v,w;
}rd[1200010];
int cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void wk(int now)
{
	int sum=0,cnt=m;
	for(int i=0;i<k&&now>0;i++)
	{
		if(now&1) 
		{
			sum+=c[i];
			for(int j=1;j<=n;j++)
			{
				cnt++;
				rd[cnt].u=n+i+1;
				rd[cnt].v=j;
				rd[cnt].w=a[i][j];
			}
		}
		now>>=1;
	}
	if(sum>=MIN) return;
	for(int i=1;i<=n+10;i++) fa[i]=i;
	sort(rd+1,rd+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(find(rd[i].u)!=find(rd[i].v))
		{
			fa[find(rd[i].u)]=find(rd[i].v);
			sum+=rd[i].w;
		}
		if(sum>=MIN) return;
	}
	MIN=min(MIN,sum);
}
int pd(int i)
{
	for(int j=1;j<=n;j++)
	if(a[i][j]==0) return 1;
	return 0;
}
int A()
{
	for(int i=1;i<=k;i++)
	if(c[i]!=0||!pd(i))return 0;
	return 1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;MIN=0x3f3f3f3f;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&rd[i].u,&rd[i].v,&rd[i].w);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	if(!A())for(int i=0;i<(1<<k);i++)wk(i);
	else wk((1<<k)-1);
	cout<<MIN<<endl;
	return 0;
}
