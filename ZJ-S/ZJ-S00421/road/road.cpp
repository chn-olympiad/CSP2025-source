#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	int k=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		k=(k<<1)+(k<<3)+(c^48);
		c=getchar();
	}
	return k*f;
}
const int N=2e4+10,M=2e6+10;
int n,m,k,f[N],c[N],a[11][N];
struct node
{
	int x,y,z;
}e[M];
bool cmp(node x,node y)
{
	return x.z<y.z;
}
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
bool A()
{
	for(int i=1; i<=k; ++i)
		if(c[i])
			return 0;
	for(int i=1; i<=k; ++i)
	{
		bool flag=0;
		for(int j=1; j<=n; ++j)
			if(a[i][j]==0)
				flag=1;
		if(!flag)return 0;
	}
	return 1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1; i<=n+10; ++i)f[i]=i;
	for(int i=1; i<=m; ++i)
		e[i]={read(),read(),read()};
	for(int i=1; i<=k; ++i)
	{
		c[i]=read();
		for(int j=1; j<=n; ++j)
			a[i][j]=read();
	}
	if(k==0||A())
	{
		for(int i=1; i<=k; ++i)
		{
			for(int j=1; j<=n; ++j)
				e[++m]={j,n+i,a[i][j]};
		}
		sort(e+1,e+m+1,cmp);
		int cnt=0;
		ll ans=0;
		for(int i=1; i<=m; ++i)
		{
			int xx=find(e[i].x),yy=find(e[i].y);
			if(xx!=yy)
			{
				cnt++;
				f[yy]=xx;
				ans+=e[i].z;
				if(cnt==n+k-1)break;
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
	ll ans=1e18;
	k=min(k,5);
	for(int s=0; s<(1<<k); ++s)
	{
		for(int i=1; i<=n+10; ++i)
			f[i]=i;
		int tmp=m,ap=0;
		ll sum=0;
		for(int i=0; i<k; ++i)
		{
			if((s>>i)&1)
			{
				sum+=c[i+1];
				for(int j=1; j<=n; ++j)
					e[++tmp]={j,n+i+1,a[i+1][j]};
			}
			ap++;
		}
		sort(e+1,e+tmp+1,cmp);
		int cnt=0;
		for(int i=1; i<=tmp; ++i)
		{
			int xx=find(e[i].x),yy=find(e[i].y);
			if(xx!=yy)
			{
				cnt++;
				f[yy]=xx;
				sum+=e[i].z;
				if(cnt==n+ap-1)break;
			}
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}