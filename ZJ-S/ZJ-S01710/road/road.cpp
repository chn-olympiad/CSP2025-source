#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[10000100],ans,b[10000100];
struct BYM
{
	long long x,y,s;
}a[3000100];
bool cmp(BYM a,BYM b)
{
	return a.s<b.s;
}
long long find(long long x)
{
	if(x==fa[x])
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
int main( )
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].s);
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
		}
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++)
		{
			if(find(a[i].x)!=find(a[i].y))
			{
				fa[find(a[i].x)]=find(a[i].y);
				ans+=a[i].s;
			}
		}
		cout<<ans;
		return 0;
	}
	long long nn=n;
	for(int i=1;i<=k;i++)
	{
		scanf("%ld",&b[i]);
		nn+=1;
		for(int j=1;j<=n;j++)
		{
			long long s1;
			scanf("%lld",&s1);
			a[++m].x=nn;
			a[m].y=j;
			a[m].s=s1;
		}
		/*
		for(int j=1;j<=n;j++)
		{
			for(int k1=1;k1<=n;k1++)
			{
				if(j==k1)
				{
					continue;
				}
				if(c[i][j]+c[i][k1]>=minn[j][k1]||c[i][j]+c[i][k1]>=minn[k1][j])
				{
					continue;
				}
				minn[j][k1]=c[i][j]+c[i][k1];
				minn[k1][j]=c[i][j]+c[i][k1];
			}
		}
		*/
	}
	n=nn;
	/*
	for(int i=1;i<=m;i++)
	{
		a[i].x=a[i].y=a[i].s=0;
	}
	m=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(minn[i][j]!=INT_MAX)
			{
				a[++m].x=i;
				a[m].y=j;
				a[m].s=minn[i][j];
			}
			else
			{
				for(int k1=1;k1<=k;k1++)
				{
					if(f[k1][i]==f[k1][j]&&f[k1][i]==1)
					{
						a[++m].x=i;
						a[m].y=j;
						a[m].s=minn[i][j];
						break;
					}
				}
			}
		}
	}
	*/
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].x)!=find(a[i].y))
		{
			fa[find(a[i].x)]=find(a[i].y);
			ans+=a[i].s;
		}
	}
	cout<<ans;
	return 0;
}
//zha le
//QwQ
