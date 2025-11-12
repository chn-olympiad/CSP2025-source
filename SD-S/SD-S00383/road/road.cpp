#include<bits/stdc++.h>
#define eb emplace_back
#define SZ(s) ((int)s.size())
#define all(s) s.begin(),s.end()
#define gt getchar
#define pt putchar
typedef long long ll;
typedef double db;
const int N=2e6+5;
using namespace std;
template<class T,class I> inline bool chkmax(T &a,I b){return a<b?a=b,1:0;}
template<class T,class I> inline bool chkmin(T &a,I b){return a>b?a=b,1:0;}
inline bool __(char ch){return ch>=48&&ch<=57;}
template<class T> inline void read(T &x){
	x=0;char ch=gt();bool sgn=0;
	while(!__(ch)&&ch!=EOF) sgn|=(ch=='-'),ch=gt();
	while(__(ch)) x=(x<<1)+(x<<3)+(ch&15),ch=gt();
	if(sgn) x=-x;
}
template<class T,class ...I> inline void read(T &x,I &...x1){
	read(x);
	read(x1...);
}
int n,m,k,a[15][N],c[N];
struct Edge{
	int u,v,w;
	inline void input(){read(u,v,w);}
	inline bool operator<(const Edge &b)const{return w<b.w;}
}ed[N],E[N];
namespace Dsu{
	int fa[N],siz[N],cnt;
	inline void init(int n){
		cnt=n;
		for(int i=1;i<=n;++i) fa[i]=i,siz[i]=1;
	}
	inline int find(int u){
		while(u!=fa[u]) u=fa[u]=fa[fa[u]];
		return u;
	}
	inline bool merge(int u,int v){
		u=find(u),v=find(v);
		if(u==v) return 0;
		if(siz[u]<siz[v]) swap(u,v);
		fa[v]=u,siz[u]+=siz[v];
		return 1;
	}
}
ll ans;
inline void kruskal(){
	int tot=0;
	sort(ed+1,ed+m+1);
	Dsu::init(n);
	for(int i=1;i<=m;++i) if(Dsu::merge(ed[i].u,ed[i].v)) E[++tot]=ed[i],ans+=ed[i].w;
	m=tot;
}
inline bool in(int S,int i){return (S>>(i-1))&1;}
#define popc(x) __builtin_popcount(x)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
signed main(){
	file("road");
	read(n,m,k);
	for(int i=1;i<=m;++i) ed[i].input();
	kruskal();
	for(int i=1;i<=k;++i){
		read(c[i]);
		for(int j=1;j<=n;++j) read(a[i][j]),E[++m]={i+n,j,a[i][j]};
	}
	sort(E+1,E+m+1);
	for(int S=1;S<(1<<k);++S){
		ll sum=0;
		for(int i=1;i<=k;++i) if(in(S,i)) sum+=c[i];
		Dsu::init(n+k);
		int res=k-popc(S)+1;
		for(int i=1;i<=m;++i){
			if(E[i].u>n&&!in(S,E[i].u-n)) continue;
			if(Dsu::merge(E[i].u,E[i].v)) sum+=E[i].w;
			if(Dsu::cnt==res) break;
		}
		chkmin(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}
