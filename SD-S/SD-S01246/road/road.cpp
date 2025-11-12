#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#define pb push_back
#define LL long long
const int maxn=10005;
const int maxm=2000005;
const LL inf=1e13;
using namespace std;
struct pii {int fr,se;};
bool operator < (pii a,pii b) {return a.fr==b.fr?a.fr<b.fr:a.se<b.se;}
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(LL x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
struct Edge
{
	int x,y;LL z;
}e[maxm],E[maxm];
int fa[maxn];
int fd(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=fd(fa[x]);
}
bool operator <(Edge a,Edge b) {return a.z<b.z;}
int vis[maxn];LL c[maxn];
int n,m,k;
LL mnt(int m,int pv)
{
	for (int i=1;i<=n+k;i++) fa[i]=i;
	LL vn=0;
	for (int i=1;i<=k;i++) if (vis[i]) vn+=c[i];
//	cout<<vn<<endl;
	sort(e+1,e+m+1);
	for (int i=1;i<=m;i++)
	{             
		int x=fd(e[i].x),y=fd(e[i].y);
		if (x!=y)
		{
			vn+=e[i].z;
			fa[x]=y;
		}
	}
	return vn;
}
int a[20][maxn];
void sub1()
{
	for (int i=1;i<=k;i++)
	{
		int p;
		for (int j=1;j<=n;j++) if (!a[i][j]) p=j;
		for (int j=1;j<=n;j++) E[++m]={p,j,a[i][j]};
	}
	sort(E+1,E+m+1);
	LL ans=0;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int x=fd(E[i].x),y=fd(E[i].y);
		if (x!=y)
		{
			fa[x]=y;
			ans+=E[i].z;
		}
	}
	write(ans);
}
void sub2()
{
	sort(E+1,E+m+1);
	LL ans=0;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int x=fd(E[i].x),y=fd(E[i].y);
		if (x!=y)
		{
			fa[x]=y;
			ans+=E[i].z;
		}
	}
	write(ans);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for (int i=1;i<=m;i++)
	{
		 E[i].x=read();E[i].y=read();E[i].z=read();
	}
	for (int i=1;i<=k;i++)
	{
		c[i]=read();
		LL mn=inf;
		for (int j=1;j<=n;j++) a[i][j]=read();
	}
	int ed=(1<<k)-1;
	for (int i=1;i<=n;i++) fa[i]=i;
	sort(E+1,E+m+1);
	LL vn=0;
	for (int i=1;i<=m;i++)
	{             
		int x=fd(E[i].x),y=fd(E[i].y);
		if (x!=y) fa[x]=y;
		else E[i].z=inf;
	}
	sort(E+1,E+m+1);
	LL ans=inf;
	for (int i=0;i<=ed;i++)
	{
		int np=n-1;
		for (int i=1;i<=k;i++) vis[i]=0;
		for (int j=0;j<k;j++) if ((i>>j)&1) vis[j+1]=1;
		for (int i=1;i<n;i++) e[i]=E[i];
		for (int i=1;i<=k;i++) if (vis[i])
			for (int j=1;j<=n;j++) e[++np]={n+i,j,a[i][j]};
//		cout<<i<<endl;
//		for (int i=1;i<=k;i++) cout<<vis[i];cout<<endl;
//		for (int i=1;i<=np;i++) cout<<e[i].x<<" "<<e[i].y<<" "<<e[i].z<<endl;
		ans=min(ans,mnt(np,i));
	}
	write(ans);
	return 0;
}
/*
对于 c=0,我们直接把边建上求最小生成树就好
如果我们能做到 2^kn就做完了
然后你考虑加边
然后我们尝试对现在这些边做最小生成树
原图中有价值的边只有 O(n) 条
首先，既然你选了，那你肯定至少选两个
最后去掉多余的边吧
卧槽你选了一定联通
*/

