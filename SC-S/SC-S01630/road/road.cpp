#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define rep(i, l, r) for(int i = (l), END##i = (r); i <= END##i; ++i)
#define per(i, r, l) for(int i = (r), END##i = (l); i >= END##i; --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define ML debug("\n%.2lf MB\n", (&Med-&Mst)/1024.0/1024)
#define TL debug("\n%.2lf s\n", 1.0*clock()/CLOCKS_PER_SEC)
#define fileI(x) freopen(x, "r", stdin)
#define fileO(x) freopen(x, "w", stdout)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define pq priority_queue
bool Mst;
namespace IO{
const int MSZ=1<<20;
char buf[MSZ],*p1=buf,*p2=buf;
char gc(){
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,MSZ,stdin),p1==p2)?EOF:*p1++;
}
template<typename T>
void read(T &x){
	x=0;
	char ch=gc();
	while(ch<'0'||ch>'9')ch=gc();
	while(!(ch<'0'||ch>'9'))x=(x<<3)+(x<<1)+(ch^48),ch=gc(); 
}
}
using IO::read;
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k,U;
int c[K];
pii a[K][N];
struct Edge{ int u,v,w; }e[M],e2[1<<10][N+K];
bool cmpW(Edge &x,Edge &y){
	return x.w<y.w;
}
int m2;


int id[N+K];
int fa[N+K],sz[N+K],ecnt;
int gf(int v){ return fa[v]==v?v:fa[v]=gf(fa[v]); }
bool Merge(int x,int y){
	x=gf(x),y=gf(y);
	if(x!=y){
		if(sz[x]>sz[y])swap(x,y);
		sz[y]+=sz[x];
		fa[x]=y;
		return 1;
	}
	return 0;
}
ll ans;

bool Med;
int main(){
	fileI("road.in");
	fileO("road.out");
//	ML;
//	scanf("%d%d%d",&n,&m,&k);
	read(n),read(m),read(k);
	rep(i,1,m){
//		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		read(e[i].u),read(e[i].v),read(e[i].w);
	}
	rep(i,1,k){
//		scanf("%d",&c[i]);
		read(c[i]);
		rep(j,1,n){
//			scanf("%d",&a[i][j].fi);
			read(a[i][j].fi);
			a[i][j].se=j;
		}
	}
	rep(i,1,k)sort(a[i]+1,a[i]+n+1);

	sort(e+1,e+m+1,cmpW);
	rep(i,1,n)fa[i]=i,sz[i]=1; ecnt=0;
	rep(i,1,m){
		if(Merge(e[i].u,e[i].v)){
			ans+=e[i].w;
			e[++m2]=e[i];
			if(++ecnt==n-1){
				break;
			}
		}
	}
	assert(m2==n-1);
	m=m2;

	rep(i,1,n)id[i]=i;
	U=(1<<k)-1;
	rep(i,1,m)e2[0][i]=e[i];
	rep(S,1,U){
		ll res=0;
		int x=__builtin_ctz(S)+1,T,tot=n;
		assert(S>>x-1&1);
		T=S^1<<x-1;
		rep(i,1,k)if(S>>i-1&1){
			id[i+n]=++tot;
			res+=c[i];
		}
		if(res>=ans)continue;
		
		rep(i,1,tot)fa[i]=i,sz[i]=1; ecnt=0;
		int l=1,r=1;
		while(l<=tot-2&&r<=n){
			if(e2[T][l].w<=a[x][r].fi){
				if(Merge(id[e2[T][l].u],id[e2[T][l].v])){
					res+=e2[T][l].w;
					e2[S][++ecnt]=e2[T][l];
					if(ecnt==tot-1){
						break;
					}
				}
				++l;
			}
			else{
				if(Merge(id[x+n],a[x][r].se)){
					res+=a[x][r].fi;
					e2[S][++ecnt]=Edge{x+n,a[x][r].se,a[x][r].fi};
					if(ecnt==tot-1){
						break;
					}
				}
				++r;
			}
		}
		while(l<=tot-2&&ecnt<tot-1){
			if(Merge(id[e2[T][l].u],id[e2[T][l].v])){
				res+=e2[T][l].w;
				e2[S][++ecnt]=e2[T][l];
				if(ecnt==tot-1){
					break;
				}
			}
			++l;
		}
		while(r<=n&&ecnt<tot-1){
			if(Merge(id[x+n],a[x][r].se)){
				res+=a[x][r].fi;
				e2[S][++ecnt]=Edge{x+n,a[x][r].se,a[x][r].fi};
				if(ecnt==tot-1){
					break;
				}
			}
			++r;
		}
		assert(ecnt==tot-1);
		ans=min(ans,res);
	}
	printf("%lld",ans);
//	TL;
	return 0;
}
