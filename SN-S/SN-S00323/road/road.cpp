//李倏嘉 SN-S00323 西安铁一中国际合作学校
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k,ans,cnt,a[K],id[N],fa[N+K];
struct node{
	int x,y,z;
}edge[M],p[N*K];
bool operator<(node a,node b)
{
	return a.z<b.z;
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)return 0;
	fa[x]=y;
	return 1;
}
int read()
{
	char c;
	int ret=0;
	while(1)
	{
		c=getchar();
		if(c>='0'&&c<='9')break;
	}
	ret=c-'0';
	while(1)
	{
		c=getchar();
		if(c<'0'||c>'9')break;
		ret=ret*10+c-'0';
	}
	return ret;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)edge[i]={read(),read(),read()};
	sort(edge+1,edge+m+1);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)if(merge(edge[i].x,edge[i].y))ans+=edge[i].z,p[++cnt]=edge[i];
	for(int i=0;i<k;i++)
	{
		a[i]=read();
		for(int j=1;j<=n;j++)cnt++,p[cnt]={n+i+1,j,0},p[cnt].z=read();
	}
	sort(p+1,p+cnt+1);
	for(int i=1;i<1<<k;i++)
	{
		int sum=0;
		for(int j=0;j<k;j++)if((i>>j)&1)sum+=a[j];
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=1;j<=cnt;j++)if((p[j].x<=n||((i>>p[j].x-n-1)&1))&&merge(p[j].x,p[j].y))sum+=p[j].z;
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
