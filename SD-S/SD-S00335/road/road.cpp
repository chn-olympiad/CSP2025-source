#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define int long long
#define R(x) x=read()
#define W(X) write(x)
#define MAXN 1000010
inline int read()
{
	int x,y;
	x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') y=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
	return x*y;
}
inline void write(int x)
{
	if(x<0) {putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
struct node
{
	int nxt;
	int to;
	int w;
}edge[MAXN*15];
int head[MAXN],num_edge=0;
int n,m,k;
void add_edge(int,int,int);
int cmp(node x,node y)
{
	return x.w<y.w;
}
int r[15][MAXN];
int c[MAXN];
int f[MAXN];
int findf(int);
int x[MAXN],y[MAXN],z[MAXN];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	R(n);R(m);R(k);
	for(int i=1;i<=m;i++)
	{
		R(x[i]);R(y[i]);R(z[i]);
		add_edge(x[i],y[i],z[i]);
//		add_edge(y[i],x[i],z[i]);
	}
	int ans=0;
	bool fl=true;
	for(int i=1;i<=k;i++)
	{
		R(c[i]);
		if(c[i]!=0) fl=false;
		for(int j=1;j<=n;j++)
			R(r[i][j]);
	}
	if(k<=5&&!fl)
	{
		int tot=0;
		int minn=1e12;
		for(int s=0;s<(1<<k);s++)
		{
			for(int i=1;i<=k;i++)
			{
				if(s&(1<<(i-1))) 
				{
					ans+=c[i];
					for(int j=1;j<=n;j++)
						for(int k=j+1;k<=n;k++)
						{
							add_edge(j,k,r[i][j]+r[i][k]);
//							add_edge(k,j,r[i][j]+r[i][k]);
						}
				}
			}
			sort(edge+1,edge+1+num_edge,cmp);
//			cout<<num_edge<<endl;
			for(int i=1;i<=num_edge;i++)
			{
				int fx,fy;
				fx=findf(edge[i].nxt),fy=findf(edge[i].to);
				if(fx!=fy)
				{
					f[fx]=fy;
					ans+=edge[i].w;
				}
			}
			minn=min(minn,ans);
			ans=0;
			num_edge=0;
			for(int i=1;i<=m;i++)
			{
				add_edge(x[i],y[i],z[i]);
//				add_edge(y[i],x[i],z[i]);
			}
			memset(f,0,sizeof(f));
		}
//		cout<<tot<<endl;
		cout<<minn;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
			{
				add_edge(j,k,r[i][j]+r[i][k]);
//				add_edge(k,j,r[i][j]+r[i][k]);
			}
	}
	sort(edge+1,edge+1+num_edge,cmp);
	for(int i=1;i<=num_edge;i++)
	{
		int fx,fy;
		fx=findf(edge[i].nxt),fy=findf(edge[i].to);
		if(fx!=fy)
		{
			f[fx]=fy;
			ans+=edge[i].w;
		}
	}
	cout<<ans;
	return 0;
}
int findf(int x)
{
	if(!f[x]) return x;
	return f[x]=findf(f[x]);
}
void add_edge(int u,int v,int w)
{
	num_edge++;
	edge[num_edge].nxt=u;
	edge[num_edge].to=v;
	edge[num_edge].w=w;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
