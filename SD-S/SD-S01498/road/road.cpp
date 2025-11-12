//by OldDriverTree
#include<bits/stdc++.h>
#define range(vec) vec.begin(),vec.end()
#define tup array<int,3>
#define P pair<int,int>
#define int long long
#define mid (l+r>>1)
using namespace std;
const int N=10011,M=1e6,K=10;
int n,m,k,tot,ans,fa[N],a[K][N];
tup e[M],E[M]; bool st[M];

int read() {
	int x=0; bool f=true; char c=0;
	while (!isdigit(c) ) f&=(c!='-'),c=getchar();
	while (isdigit(c) ) x=x*10+(c&15),c=getchar();
	return f?x:-x;
}
int find(int x) {
	return fa[x]^x?fa[x]=find(fa[x]):x; 	
}
main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read(),ans=LLONG_MAX;
	for (int i=0;i<m;i++) e[i]={read(),read(),read()};
	for (int i=0;i<k;i++)
		for (int j=0;j<=n;j++)
			a[i][j]=read();
	
	for (int i=1;i<=n;i++) fa[i]=i;
	sort(e,e+m,[&](tup x,tup y){ return x[2]<y[2]; });
	for (int i=0;i<m;i++)
		if (find(e[i][0])^find(e[i][1]) )
			fa[find(e[i][0])]=find(e[i][1]),st[i]=true;
	
	for (int i=0;i<m;i++)
	if (st[i]) E[tot++]=e[i];
	for (int S=0;S<1<<k;S++)
	{
		int res=0;
		for (int i=1;i<=n+k;i++) fa[i]=i;
		for (int i=0;i<n-1;i++) e[i]=E[i]; tot=n-1;
		for (int i=0;i<k;i++) if (S>>i&1) {
			res+=a[i][0]; for (int j=1;j<=n;j++)
			e[tot++]={j,n+i+1,a[i][j]};
		}
		sort(e,e+tot,[&](tup x,tup y){ return x[2]<y[2]; });
		for (int i=0;i<tot&&res<ans;i++) if (find(e[i][0])^find(e[i][1]) )
		res+=e[i][2],fa[find(e[i][0])]=find(e[i][1]); ans=min(ans,res);
	}
	printf("%lld",ans); 
	return 0;
}
/*
k=0 和 A 性质是简单的，即最小生成树
扩展到没有 A 性质， 我们要减少跑 kruskal 的次数或每次的边数 
比如说，我们能不能提前把一些边缩掉或删掉  
对于不在原图最小生成树上的边，他是没用的
 O(mlog m+n2^k*k)？哦哦哦 
 15:52 过掉了大样例，但是大样例怎么没有 n=1e4 
 随了一组 n=1e4，跑了 3.5s，开始卡常 
 卡不动，下一题 
*/ 
