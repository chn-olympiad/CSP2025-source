#include <bits/stdc++.h>
using namespace std;
long long n,m,k,c[20],d2[20][10010],m2,n2,rans=1000000000000000000,ans,hm,fa[20010];
struct l3{
	long long f,t,d;
}r[2000010],rr[2000010];
int cmp(l3 x,l3 y)
{
	return x.d<y.d;
}
long long find(long long x)
{
	if(fa[x]!=x)
	{
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
void onion(long long x,long long y)
{
	fa[find(x)]=find(y);
}
void solve()
{
	long long mn=0;
	for(int i=1;i<=n+20;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m2;i++)
	{
		rr[i].f=r[i].f;
		rr[i].t=r[i].t;
		rr[i].d=r[i].d;
	}
	sort(rr+1,rr+m2+1,cmp);
	for(int i=1;i<=m2;i++)
	{
		if(find(rr[i].f)!=find(rr[i].t))
		{
			mn++;
			onion(rr[i].f,rr[i].t);
			ans+=rr[i].d;
			if(ans>=rans)
			{
				ans=1000000000000000000;
				return ;
			}
		}
		if(mn==n2-1)
		{
			return;
		}
	}
}
void dfs(long long num)
{
	if(num==k+1)
	{
		solve();
		rans=min(rans,ans);
		return;
	}
	long long tll=ans;
	dfs(num+1);
	ans=tll;
	if(ans+c[num]>=rans)
	{
		return ;
	}
	ans+=c[num];
	n2++;
	for(int i=1;i<=n;i++)
	{
		r[++m2].f=n+num;
  		r[m2].t=i;
		r[m2].d=d2[num][i];
	}
	dfs(num+1);
	m2-=n;
	n2--;
	ans=tll;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&r[i].f,&r[i].t,&r[i].d);
	}
	long long ppt=1;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		if(c[i]!=0)
		{
			ppt=0;
		}
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&d2[i][j]);
		}
	}
	m2=m;
	n2=n;
	if(ppt && k>5)
	{
		long long mn=0;
		for(int i=1;i<=n+k;i++)
		{
			fa[i]=i;
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				r[++m2].f=n+i;
				r[m2].t=j;
				r[m2].d=d2[i][j];
			}
		}
		sort(r+1,r+m2+1,cmp);
		for(int i=1;i<=m2;i++)
		{
			if(find(r[i].f)!=find(r[i].t))
			{
				mn++;
				onion(r[i].f,r[i].t);
				ans+=r[i].d;
			}
			if(mn==n+k-1)
			{
				printf("%lld",ans);
				return 0;
			}
		}
	}
	dfs(1);
	printf("%lld",rans);
	return 0;
}