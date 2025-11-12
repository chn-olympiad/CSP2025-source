#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,m,k,f[N],siz[N];
struct st
{
	ll x,y,z;
}w[N];
ll dis[1010][1010],tmp[1010][1010];
ll a[15][10010],c[15]; 
bool cmp(st a,st b)
{
	return a.z<b.z;
}
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int read()
{
	int x=0;char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int flag=1;
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		ll x=read(),y=read(),z=read();
		if(x>y) swap(x,y);
		w[i]={x,y,z};
	}
	for(int i=1;i<=k;++i)
	{
		c[i]=read();flag&=(c[i]==0);
		for(int j=1;j<=n;++j) a[i][j]=read();
	}
	if(k==0)
	{
		ll sum=0;
		sort(w+1,w+1+m,cmp);
		for(int i=1;i<=n;++i) f[i]=i,siz[i]=1;
		for(int i=1;i<=m;++i)
		{
			int x=find(w[i].x),y=find(w[i].y);
			if(x!=y)
			{
				sum+=w[i].z;
				if(siz[x]>siz[y]) swap(x,y);
				f[x]=y;siz[y]+=siz[x]; 
			}
		}
		printf("%lld",sum);
		return 0;
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++) dis[w[i].x][w[i].y]=min(dis[w[i].x][w[i].y],w[i].z);
	if(flag==1)
	{
		ll sum=0;
		for(int i=0;i<k;++i)
		{
			for(int x=1;x<=n;++x)
			{
				for(int y=x+1;y<=n;++y)
				{
					dis[x][y]=min(dis[x][y],a[i+1][x]+a[i+1][y]);
				}
			}
		}
		int q=0;
		for(int x=1;x<=n;++x)
			for(int y=x+1;y<=n;++y)
			{
				if(dis[x][y]<=1e10) w[++q]={x,y,dis[x][y]};
			}
		sort(w+1,w+1+q,cmp);
		for(int i=1;i<=n;++i) f[i]=i,siz[i]=1;
		for(int i=1;i<=q;++i)
		{
			int x=find(w[i].x),y=find(w[i].y);
			if(x!=y)
			{
				sum+=w[i].z;
				if(siz[x]>siz[y]) swap(x,y);
				f[x]=y;siz[y]+=siz[x]; 
			}
		}
		printf("%lld",sum);
		return 0;
	}
	int len=(1<<k)-1;
	ll res=1e18;
	for(int s=0;s<=len;++s)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=i;j<=n;++j)
			{
				tmp[i][j]=dis[i][j];
			}
		}
		ll sum=0;
		for(int i=0;i<k;++i)
		{
			if(s>>i&1) 
			{
				sum+=c[i+1];
				for(int x=1;x<=n;++x)
				{
					for(int y=x+1;y<=n;++y)
					{
						tmp[x][y]=min(tmp[x][y],a[i+1][x]+a[i+1][y]);
					}
				}
			}
		}
		int q=0;
		for(int x=1;x<=n;++x)
			for(int y=x+1;y<=n;++y)
			{
				if(tmp[x][y]<=1e10) w[++q]={x,y,tmp[x][y]};
			}
		sort(w+1,w+1+q,cmp);
		for(int i=1;i<=n;++i) f[i]=i,siz[i]=1;
		for(int i=1;i<=q;++i)
		{
			int x=find(w[i].x),y=find(w[i].y);
			if(x!=y)
			{
				sum+=w[i].z;
				if(siz[x]>siz[y]) swap(x,y);
				f[x]=y;siz[y]+=siz[x]; 
			}
		}
		res=min(res,sum);
	}
	printf("%lld",res);
	return 0;
}