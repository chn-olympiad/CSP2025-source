#include <bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int X=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {X=X*10+(ch-'0'); ch=getchar();}
	return X*f;
}
int n,m,k,tot;
struct edge
{
	int u,v,w,tp;
}e[2000005];
bool cmp0(edge xx,edge yy)
{
	return xx.w<yy.w;
}
struct cnty
{
	int v,w,id;
}c[12];
bool cmp(cnty xx,cnty yy)
{
	return xx.w<yy.w;
}
void adde(int u,int v,int w,int tp)
{
	e[++tot].u=u;
	e[tot].v=v;
	e[tot].w=w;
	e[tot].tp=tp;
}
int fa[200005];
int find(int x)
{
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
void merge(int x,int y)
{
	fa[find(x)]=find(y);
}
int cw[25];
long long ans=1e18;
long long kruskal(int s)
{
	long long as=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=0;i<k;i++)
	{
		if(s>>i&1) as+=cw[i+1];
	}
	for(int i=1;i<=tot;i++)
	{
		if(e[i].tp&&!(s>>(e[i].tp-1)&1)) continue;
		if(find(e[i].v)==find(e[i].u)) continue;
		merge(e[i].v,e[i].u);
		as+=e[i].w;
	}
	ans=min(ans,as);
	return as;
}
void work()
{
	n=read(),m=read(),k=read();
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		x=read(),y=read(),z=read();
		if(x<y) swap(x,y);
		adde(x,y,z,0);
	}
	bool pd=1;
	for(int i=1;i<=k;i++)
	{
		cw[i]=read();
		if(cw[i]) pd=0;
		bool ck=1;
		for(int j=1;j<=n;j++)
		{
			//c[i][j].w=read(),c[i][j].v=j;
			adde(n+i,j,read(),i);
			if(!e[tot].w) ck=0;
		}
		if(ck) pd=0;
		//sort(c[i]+1,c[i]+n+1,cmp);
	}
	sort(e+1,e+tot+1,cmp0);
	if(1||(!pd&&k>5))
	{
		int ts=0;
		for(int i=k-1;~i;i--)
		{
			int t1=ts+(1<<(i+1))-1;
			int t2=ts+(1<<(i))-1;
			if(kruskal(t1)<kruskal(t2)) ts+=(1<<i);
		}
		cout<<ans;
		return ;
	}
	for(int i=(1<<k)-1;~i;i--)
	{
		kruskal(i);
		if(pd) break;
	}
	cout<<ans;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int tt=1;
	while(tt--) work();
	return 0;
} 