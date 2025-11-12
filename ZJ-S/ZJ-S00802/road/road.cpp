#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;++i)
#define dFor(i,j,k) for(int i=j;i>=k;--i)
#define FIO(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
using namespace std;
namespace DEBUG{
	template<class T> void _debug(const char *s,T x){cout<<s<<'='<<x<<'\n';}
	template<class F,class...Nxt> void _debug(const char *s,F x,Nxt...nxt){
		int d=0;
		while(*s!=','||d) d+=*s=='(',d-=*s==')',cout<<*s++;
		cout<<'='<<x<<',';
		_debug(s+1,nxt...);
	}
	#define debug(...) _debug(#__VA_ARGS__,__VA_ARGS__)
}
using namespace DEBUG;
const int Mmod=1e9+7;
const int MAXN=11005;
int n,m,k,fa[MAXN];long long a[11][MAXN],W[MAXN],ans=1e18;
struct Edge{int u,v;long long w;}E[MAXN*100],e[MAXN*100];
inline bool cmp(Edge x,Edge y){return x.w==y.w?((x.u<=n)+(x.v<=n)<(y.u<=n)+(y.v<=n)):x.w<y.w;}
int getf(int x){return fa[x]==x?x:fa[x]=getf(fa[x]);}
bitset<MAXN>f;
inline long long Kruskal(int N,int M){
	For(i,1,m) e[i]=E[i];sort(e+1,e+M+1,cmp);
	For(i,1,N) W[i]=0,fa[i]=i,f[i]=false;
	int tot=0;long long res=0;
	For(i,1,M){
		int u=getf(e[i].u),v=getf(e[i].v),w=e[i].w;
		if(u==v) continue;
		res+=w,fa[v]=u;
		if(u<=n&&f[u]==false) ++tot;
		if(v<=n&&f[v]==false) ++tot;
		f[u]=f[v]=true;
		if(u>n) W[u]+=w;
		if(tot==n) break;
	}
	return res;
}
bool flagA=true;
inline void solveA(){
	int u=0,M=m,N=n;
	For(i,1,k){
		For(j,1,n) if(a[i][j]==0) u=j;
		For(v,1,n) if(u!=v) e[++M]=Edge{u,v,a[i][v]};
	}
	cout<<Kruskal(N,M);
	exit(0);
}
clock_t ST;
int tot=0,ok[MAXN],tmp[MAXN];
inline void solve(){
	ans=Kruskal(n,m);
	For(i,1,k){
		if((double)(clock()-ST)/CLOCKS_PER_SEC>0.9) break;
		int N=n,M=m,tot1=0;long long res=0;
		ok[++tot]=i;
		For(j,1,tot){
			int u=ok[j];
			++N,res+=a[u][0];
			For(v,1,n) e[++M]=Edge{N,v,a[u][v]};
		}
		res+=Kruskal(N,M);
		if(res>=ans){--tot;continue;}
		ans=res;
		For(j,1,tot) if(f[j+n]==true) tmp[++tot1]=ok[j];
		tot=tot1;For(j,1,tot) ok[j]=tmp[j];
	}
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	FIO("road");
	ST=clock();
	cin>>n>>m>>k;
	For(i,1,m) cin>>E[i].u>>E[i].v>>E[i].w;
	For(i,1,k) For(j,0,n) cin>>a[i][j],flagA&=(a[i][0]==0);
	if(flagA==true) solveA();
	solve();
	For(st,0,(1<<tot)-2){
		if((double)(clock()-ST)/CLOCKS_PER_SEC>0.9) break;
		For(i,1,m) e[i]=E[i];
		int M=m,N=n;long long res=0;
		For(i,1,tot){
			if(((st>>(i-1))&1)==0) continue;
			res+=a[ok[i]][0],++N;
			For(v,1,n) e[++M]=Edge{N,v,a[ok[i]][v]};
		}
		res+=Kruskal(N,M);
		if(res<ans) ans=res;
	}
	cout<<ans;
	return 0;
}

