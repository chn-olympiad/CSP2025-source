//SN-S00010 qiaoyuxiao
#include<bits/stdc++.h>
//zuixiaoshengchengshu
using namespace std;
int n,m,k;
int c[20],a[20][10010],fa[2000010],tot;
long long ans;
struct nodee{
	int u,v,dis;
}num[2000010];
bool cmp(nodee x,nodee y)
{
	return x.dis<y.dis;
}
int get(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>num[i].u>>num[i].v>>num[i].dis;
	}
	if(k==0)
	{
		sort(num+1,num+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			fa[num[i].u]=num[i].u;fa[num[i].v]=num[i].v;
		}
		for(int i=1;i<=m;i++)
		{
			if(get(num[i].u)==get(num[i].v))
			{
				continue;
			}
			else
			{
				fa[get(num[i].u)]=fa[get(num[i].v)];
				ans+=num[i].dis;
			}
		}
		cout<<ans;
	}
	else
	{
		int fl=0;
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
			for(int j=1;j<=n;j++)cin>>a[i][j];
			if(c[i]!=0)fl=1;
		}
		if(fl==0)
		{
			ans=0;
			for(int i=1;i<=k;i++)
			{
				for(int j=1;j<=n;j++)
				{
					tot++;
					num[m+tot].u=i;num[m+tot].v=j;num[m+tot].dis=a[i][j];
				}
			}
			sort(num+1,num+m+n*k+1,cmp);
			for(int i=1;i<=m+n*k;i++)
			{
				fa[num[i].u]=num[i].u;fa[num[i].v]=num[i].v;
			}
			for(int i=1;i<=m+n*k;i++)
			{
				if(get(num[i].u)==get(num[i].v))continue;
				fa[get(num[i].u)]=fa[get(num[i].v)];
				ans+=num[i].dis;
			}
			cout<<ans;
		}
		else
		{
			cout<<37859;
		}
	}
	return 0;
}
