#include<bits/stdc++.h>
#define int long long
#define rint register int
using namespace std;
const int N=1005,M=1000005,K=15;
bool f1;
int n,m,k,sum,ans,flag=1,f[N],c[K],a[K][N],g[N][N],d[N][N],siz[N];
struct data{
	int u,v,w;
}e[M],E[M];
bool f2;
void read(rint &s)
{
	s=0;char c=getchar();int f=1;
	for(;c<48||c>57;c=getchar()) (c=='-')&&(f=-1);
	for(;c>47&&c<58;c=getchar()) s=(s<<1)+(s<<3)+(c^48);
	s*=f;
}
bool cmp(data x,data y){return x.w<y.w;}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void kruskal()
{
	sum=0;
	int S=0;
	for(rint i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+m+1,cmp);
	for(rint i=1;i<=m;i++)
	{
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy) continue;
		sum+=e[i].w;
		f[fx]=fy;
		S++;
		if(S==n-1) break;
	}
	ans=sum;
}
void kruskal2()
{
	int cnt=0,S=0;
	for(rint i=1;i<=n;i++) f[i]=i;
	for(rint i=1;i<=n;i++) for(rint j=i+1;j<=n;j++) E[++cnt]={i,j,d[i][j]};
	sort(E+1,E+cnt+1,cmp);
	for(rint i=1;i<=cnt;i++)
	{
//		cout<<E[i].u<<' '<<E[i].v<<' '<<E[i].w<<'\n';
		int fx=find(E[i].u),fy=find(E[i].v);
		if(fx==fy) continue;
		sum+=E[i].w;
		f[fx]=fy;
		S++;
		if(S==n-1) break;
	}
//	cout<<sum<<'\n';
	ans=min(ans,sum);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cout<<(&f2-&f1)/1024.0/1024.0;
	read(n);read(m);read(k);
	memset(g,0x3f,sizeof g);
	for(rint i=1;i<=m;i++)
	{
		read(e[i].u);read(e[i].v);read(e[i].w);
		g[e[i].u][e[i].v]=g[e[i].v][e[i].u]=min(g[e[i].u][e[i].v],e[i].w);
	}
	for(rint i=1;i<=k;i++)
	{
		read(c[i]);
		if(c[i]) flag=0;
		for(rint j=1;j<=n;j++) read(a[i][j]);
	}
	kruskal();
	if(flag)
	{
		int s=(1<<k)-1;
		sum=0;
		for(rint j=1;j<=n;j++)
		{
			for(rint l=j+1;l<=n;l++)
			{
				d[j][l]=d[l][j]=g[j][l];
			}
		}
		for(rint i=1;i<=k;i++)
		{
			if((s&(1<<(i-1)))==0) continue;
			sum+=c[i];
			for(rint j=1;j<=n;j++)
			{
				for(rint l=j+1;l<=n;l++)
				{
					
					d[j][l]=d[l][j]=min(d[j][l],a[i][j]+a[i][l]);
				}
			}
		}
		kruskal2();
	}
	else for(rint s=1;s<(1<<k);s++)
	{
		sum=0;
		for(rint j=1;j<=n;j++)
		{
			for(rint l=j+1;l<=n;l++)
			{
				d[j][l]=d[l][j]=g[j][l];
			}
		}
		for(rint i=1;i<=k;i++)
		{
			if((s&(1<<(i-1)))==0) continue;
			sum+=c[i];
			for(rint j=1;j<=n;j++)
			{
				for(rint l=j+1;l<=n;l++)
				{
					d[j][l]=d[l][j]=min(d[j][l],a[i][j]+a[i][l]);
				}
			}
		}
		kruskal2();
	}
	cout<<ans;
	return 0;
}
