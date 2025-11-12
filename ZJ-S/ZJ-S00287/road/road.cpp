#include <cstdio>
#include <algorithm>
#define N 10010
#define M 1000010
#define ll long long
int n,m,k;
int f[N+11];
int u[M],v[M],w[M];
int p[M],rl[N],cnt;
struct pr{
	int u,v,w;
}P[N*12];int ct;
ll ans;
int c[11],a[11][N];
int ff(const int& x){
	return f[x]==x?x:(f[x]=ff(f[x]));
}
bool cmp(const int& u,const int& v)
{
	return w[u]<w[v];
}
bool cmp2(const pr& x,const pr& y)
{
	return x.w<y.w;
}
inline int rd()
{
	static int x;static unsigned char c;x=0;
	a:c=getc(stdin);if(c<'0'||c>'9') goto a;
	b:x=(x<<1)+(x<<3)+(c&0xf),c=getc(stdin);if(c>='0'&&c<='9') goto b;
	return x;
}
bool fg=1;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd();m=rd();k=rd();
	for(int i=1;i<=m;i++) u[i]=rd(),v[i]=rd(),w[i]=rd(),p[i]=i;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=0;i<k;i++)
	{
		c[i]=rd();
		if(c[i]) fg=0;
		bool fg2=0;
		for(int j=1;j<=n;j++)
		{
			a[i][j]=rd();
			if(!a[i][j]) fg2=1;
		}
		fg=fg&&fg2;
	}
	std::sort(p+1,p+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=ff(u[p[i]]),y=ff(v[p[i]]);
		if(x==y) continue;
		f[x]=y,ans+=w[p[i]],rl[++cnt]=p[i];
	}
	int mx=(1<<k);
	if(fg)
	{
		int st=mx-1;
		ll res=0;
		ct=0;
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=cnt;i++) P[++ct]={u[rl[i]],v[rl[i]],w[rl[i]]};
		for(int j=0;j<k;j++)
			if(st>>j&1)
			{
				res+=c[j];
				f[n+j+1]=n+j+1;
				for(int i=1;i<=n;i++) P[++ct]={n+j+1,i,a[j][i]};
			}
		std::sort(P+1,P+1+ct,cmp2);
		for(int i=1;i<=ct;i++)
		{
			int x=ff(P[i].u),y=ff(P[i].v);
			if(x==y) continue;
			f[x]=y,res+=P[i].w;
		}
		ans=std::min(ans,res);
	}
	else
	{
		for(int st=0;st<mx;st++)
		{
			ll res=0;
			ct=0;
			for(int i=1;i<=n;i++) f[i]=i;
			for(int i=1;i<=cnt;i++) P[++ct]={u[rl[i]],v[rl[i]],w[rl[i]]};
			for(int j=0;j<k;j++)
				if(st>>j&1)
				{
					res+=c[j];
					f[n+j+1]=n+j+1;
					for(int i=1;i<=n;i++) P[++ct]={n+j+1,i,a[j][i]};
				}
			std::sort(P+1,P+1+ct,cmp2);
			for(int i=1;i<=ct;i++)
			{
				int x=ff(P[i].u),y=ff(P[i].v);
				if(x==y) continue;
				f[x]=y,res+=P[i].w;
			}
			ans=std::min(ans,res);
		}	
	}
	fprintf(stdout,"%lld",ans);
	return 0;
}
