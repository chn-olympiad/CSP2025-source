#include<bits/stdc++.h>
using namespace std;
const int maxm=1e6,maxn=1e4,maxp=10;
struct edg
{
	int u,v;
	long long w;
	friend bool operator<(const edg&x,const edg&y)
	{
		return x.w>y.w;
	}
}ea;
int cnt[1<<maxp|20],f[1<<maxp|20][maxn+20],po[1<<maxp|20];
int b,m,n,p,x,y;
long long a[maxn+20],c[maxp+20],sumn[1<<maxp|20],ans;
priority_queue<edg,vector<edg>,less<edg> >pq,pqa,pqb;
int getf(int x,int y)
{
	if(f[x][y]==y)
		return y;
	return f[x][y]=getf(x,f[x][y]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j;
	scanf("%d%d%d",&n,&m,&p);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%lld",&ea.u,&ea.v,&ea.w);
		pq.push(ea);
	}
	for(i=1;i<=n;++i)
		f[0][i]=i;
	while(pq.size()&&cnt[0]<=n-2)
	{
		ea=pq.top();
		pq.pop();
		x=getf(0,ea.u);
		y=getf(0,ea.v);
		if(x!=y)
		{
			f[0][y]=x;
			++cnt[0];
			pqa.push(ea);
		}
	}
	cnt[0]=0;
	for(i=1;i<=p;++i)
	{
		scanf("%d",&c[i]);
		for(j=1;j<=n;++j)
		{
			scanf("%d",&a[j]);
			ea.u=n+i;
			ea.v=j;
			ea.w=a[j];
			pqa.push(ea);
		}
	}
	b=(1<<p)-1;
	for(i=0;i<=b;++i)
	{
		po[i]=n;
		for(j=1;j<=p;++j)
		{
			if(i&(1<<j-1))
			{
				sumn[i]+=c[j];
				++po[i];
			}
		}
		for(j=1;j<=po[i];++j)
			f[i][j]=j;
	}
	while(pqa.size())
	{
		ea=pqa.top();
		pqa.pop();
		if(ea.u<=n)
		{
			for(i=0;i<=b;++i)
			{
				if(cnt[i]<=po[i]-2&&getf(i,ea.u)!=getf(i,ea.v))
				{
					f[i][getf(i,ea.v)]=getf(i,ea.u);
					++cnt[i];
					sumn[i]+=ea.w;
				}
			}
		}
		else
		{
			for(i=0;i<=(b>>1);++i)
			{
				x=(i>>ea.u-n-1)<<ea.u-n|(1<<ea.u-n-1);
				x|=(i&((1<<ea.u-n-1)-1));
				if(cnt[x]<=po[x]-2&&getf(x,ea.u)!=getf(x,ea.v))
				{
					f[x][getf(x,ea.v)]=getf(x,ea.u);
					++cnt[x];
					sumn[x]+=ea.w;
				}
			}
		}
	}
	ans=sumn[0];
	for(i=0;i<=b;++i)
		if(cnt[i]==po[i]-1)
			ans=min(ans,sumn[i]);
	printf("%lld",ans);
	return 0;
}
