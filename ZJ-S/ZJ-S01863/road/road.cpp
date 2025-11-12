#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
	int l,r,lu,fa;
};
node a[1100005];
int c[10005],fa[10005];
bool A;
long long now,minn=1e14;
int n,m,k,x,cnt,xiang;
bool cmp(node x,node y)
{
	return x.lu<y.lu;
}
int read()
{
	char c=getchar();
	int x=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) a[++cnt].l=read(),a[cnt].r=read(),a[cnt].lu=read();
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		if(c[i]) A=1;
		for(int j=1;j<=n;j++) x=read(),a[++cnt]=(node){n+i,j,x,i};
	}
	sort(a+1,a+1+cnt,cmp);
	for(int g=0;g<(1<<k);g++)
	{
		now=0;xiang=0;
		int j=0;
		for(int i=1;i<=k;i++) if(g&(1<<i-1)) now+=c[i],xiang++;
		if(now>=minn) continue;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=cnt;i++)
		{
			if(a[i].fa&&!(g&(1<<a[i].fa-1))) continue;
			int xx=find(a[i].l);
			int yy=find(a[i].r);
			if(xx!=yy) fa[xx]=yy,now+=a[i].lu,j++;
			if(now>=minn||j==n+xiang-1) break;
		}
		minn=min(minn,now);
	}
	printf("%lld",minn);
}
