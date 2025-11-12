#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,fa[10005],ans1,ans2;
struct node
{
	int u,v,w;
}a[3000005];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int fnd(int x)
{
	return x==fa[x]?x:fa[x]=fnd(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[++cnt]={x,y,z};
		a[++cnt]={y,x,z};
	}
	sort(a+1,a+cnt+1,cmp);
	int flag=n;
	for(int i=1;i<=cnt;i++)
	{
		int x=a[i].u;
		int y=a[i].v;
		int xx=fnd(x);
		int yy=fnd(y);
		if(xx!=yy)
		{
			fa[xx]=yy;
			flag--;
			ans1+=a[i].w;	
		}
		if(flag==1) break;
	}
	if(k==0)
	{
		cout<<ans1;
		return 0;
	}
	for(int i=0;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++)
	{
		int c;
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			a[++cnt]={0,j,c+w};
			a[++cnt]={j,0,c+w};
		}
	}
	sort(a+1,a+cnt+1,cmp);
	flag=n+1;
	for(int i=1;i<=cnt;i++)
	{
		int x=a[i].u;
		int y=a[i].v;
		int xx=fnd(x);
		int yy=fnd(y);
		if(xx!=yy)
		{
			fa[xx]=yy;
			flag--;
			ans2+=a[i].w;
		}
		if(flag==1) break;
	}
	cout<<min(ans1,ans2);
	return 0;
}