//SN-S00493 PR++ 47 GXYZ
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int M=1e6+5,N=1e4+30;
int n,m,cnt,f[N],k,c[N];
ll val[N],ans;
bool fl[M];
inline int find(int x)
{
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
struct edge{
	int u,v,w;
}e[M],b[N],a[11][N],e1[M];
inline bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
inline int get(int x)
{
	int res=0;
	while(x)
	{
		if(x&1) res++;
		x>>=1;
	}
	return res;
}
inline ll mst(int p)
{
	ll sum=0;
	int tmp=get(p)+n-1;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=cnt;i++)
	{
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		sum+=e[i].w,f[x]=y,tmp--,fl[i]=1;
		if(tmp==0) return sum;
	}
	return sum;
}
inline void merge(int x)
{
	int t=1,sum=0;
	for(int i=1;i<=cnt;i++)
	{
		while(t<=n&&a[x][t].w<=e[i].w) e1[++sum]=a[x][t],t++;
		e1[++sum]=e[i];
	}
	cnt=sum;
	for(int i=1;i<=cnt;i++) e[i]=e1[i];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[i]=(edge){u,v,w};
	}
	cnt=m;
	sort(e+1,e+cnt+1,cmp);
	ans=mst(0),cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(fl[i]) e[++cnt]=e[i];
	}
//	printf("a");
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			int x;
			scanf("%d",&x);
			e1[j]=(edge){i+n,j,x};
		}
		sort(e1+1,e1+n+1,cmp);
		for(int j=1;j<=n;j++)
		{
			a[i][j]=e1[j];
		}
	}
	for(int i=1;i<=cnt;i++) b[i]=e[i];
	for(int s=1;s<(1<<k);s++)
	{
		val[s]=1e18;
		ll s1=0;
		cnt=n-1;
		for(int i=1;i<=cnt;i++) e[i]=b[i];
		for(int j=1;j<=k;j++)
		{
			if(!((s>>(j-1))&1)) continue;
			merge(j);
			s1+=c[j];
		}
		val[s]=mst(s)+s1;
//		printf("%d %lld %lld %d\n",s,val[s],s1,cnt);
		if(val[s]<ans) ans=val[s];
	}
	printf("%lld",ans);
	return 0;
}
