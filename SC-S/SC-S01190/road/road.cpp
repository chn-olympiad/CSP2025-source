#include<bits/stdc++.h>
//#define int long long 
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define Rep(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
const int N=2e5+10;

int n,m,k;
inline int read() {
	int res=0,f=1;
	char op=getchar();
	while (op<'0' or op>'9') {
		if (op=='-') f=-1;
		op=getchar();
	}
	while (op>='0' and op<='9') res=(res<<1)+(res<<3)+(op-'0'),op=getchar();
	return res*f;
}
namespace Baoli {
	const int M=2e6+10;
	struct node {
		int u,v,w;
	}e[M],p[M];
	int cnt=0,fa[M];
	int cst[N],a[11][N],b[N];
	bitset<N> vis;
	inline int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
	inline void Div(int S) {
		int len=0;
		while (S) {
			b[++len]=S&1;
			S>>=1;
		}
		return ;
	}
	inline ll krushkal() {
		ll res=0;
		sort(e+1,e+cnt+1,[](node x,node y){return x.w<y.w;});
		rep(i,1,n) fa[i]=i;
		rep(i,1,cnt) {
			int u=e[i].u,v=e[i].v,w=e[i].w;
			int x=find(u),y=find(v);
			if (x==y) continue;
			res+=w,fa[x]=y;
		}
		return res;
	}
	inline ll Krushkal() {
		ll res=0;
		sort(p+1,p+cnt+1,[](node x,node y){return x.w<y.w;});
		rep(i,1,n) fa[i]=i;
		rep(i,1,cnt) {
			int u=p[i].u,v=p[i].v,w=p[i].w;
			int x=find(u),y=find(v);
			if (x==y) continue;
			res+=w,fa[x]=y;
		}
		return res;
	}
	inline void solve1() {
		cnt=m;
		rep(i,1,m) {
			int u=read(),v=read(),w=read();
			e[i]={u,v,w};
		}
		rep(i,1,k) {
			cst[i]=read();
			rep(j,1,n) a[i][j]=read();
		}
		ll res=krushkal();
		cnt=0;
		rep(i,1,m) if (vis[i]) p[++cnt]=e[i];
		rep(S,0,(1<<k)-1) {
			Div(S);cnt=n-1;
			ll sum=0;
			rep(i,1,k) if (b[i]) {
				fa[n+i]=n+i;
				rep(j,1,n) p[++cnt]={n+i,j,a[i][j]};
				sum+=cst[i];
			}
			sum=sum+Krushkal();
			res=min(res,sum);
		}
		cout<<res<<endl;	
		return ;
	}
	inline void solve() {
		cnt=m;
		rep(i,1,m) {
			int u=read(),v=read(),w=read();
			e[i]={u,v,w};
		}
		rep(i,1,k) {
			cst[i]=read();
			rep(j,1,n) a[i][j]=read();
		}
		ll res=krushkal();
		rep(S,0,(1<<k)-1) {
			Div(S);cnt=m;
			ll sum=0;
			rep(i,1,k) if (b[i]) {
				fa[n+i]=n+i;
				rep(j,1,n) e[++cnt]={n+i,j,a[i][j]};
				sum+=cst[i];
			}
			sum=sum+krushkal();
			res=min(res,sum);
		}
		cout<<res<<endl;
		return ;
	}
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("read.out","w",stdout);
	n=read(),m=read(),k=read();
	if (k<=5) Baoli::solve();
	else Baoli::solve1();
	return 0;
}
/*
显然是先对原来的跑最小生成树
然后尝试替换掉边
考虑一下，把最小生成树上的边都存下来
然后每一个都考虑替换掉
68 pts
*/