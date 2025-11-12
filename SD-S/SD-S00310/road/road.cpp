#include<bits/stdc++.h>
typedef long long ll;
typedef __int128 lll;
typedef double db;
typedef long double ld;
#define fir first
#define sec second
#define pb push_back
#define ppc __builtin_popcountll
using namespace std;
void rd(){}
template<typename T,typename ...U> void rd(T &x,U &...arg){
	x=0;int f=1,c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
	x*=f;rd(arg...);
}

const int maxn=1e4+20,maxm=1e6+5,maxk=13;
const ll infll=1e18;

struct raw_edge{
	int u,v,w,fr;
	inline friend bool operator<(raw_edge i,raw_edge j){
		return i.w<j.w;
	}
}e[maxm];

int N,M,K,c[maxk],a[maxk][maxn];

struct DSU{
	int us[maxn],sz[maxn];
	void clear(){
		for(int i=1;i<=N+K;i++) us[i]=i,sz[i]=1;
	}
	inline int fd(int n){return us[n]==n?n:us[n]=fd(us[n]);}
	inline void mg(int x,int y){
		x=fd(x),y=fd(y);
		if(x==y) return;
		if(sz[x]<sz[y]) swap(x,y);
		us[y]=x,sz[x]+=sz[y];
	}
}dsu;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	rd(N,M,K);
	for(int i=1;i<=M;i++) rd(e[i].u,e[i].v,e[i].w),e[i].fr=0;
	for(int i=1;i<=K;i++){
		rd(c[i]);
		for(int j=1;j<=N;j++)
			rd(a[i][j]);
	}

	sort(e+1,e+M+1);
	dsu.clear();
	vector<raw_edge> vce;
	for(int i=1;i<=M;i++){
		int x=dsu.fd(e[i].u),y=dsu.fd(e[i].v);
		if(x!=y){
			dsu.mg(x,y);
			vce.pb(e[i]); 
		}
	}

	for(int i=1;i<=K;i++)
		for(int j=1;j<=N;j++)
			vce.pb({j,i+N,a[i][j],i});
	sort(vce.begin(),vce.end());

	ll ans=infll;
	auto at=[](int s,int i){return (s>>i)&1;};
	for(int s=0;s<(1<<K);s++){
		ll now=0;
		for(int i=1;i<=K;i++)
			if(at(s,i-1))
				now+=c[i];
		dsu.clear();
		for(auto e:vce){
			if(e.fr&&!at(s,e.fr-1)) continue;
			int x=dsu.fd(e.u),y=dsu.fd(e.v);
			if(x!=y){
				now+=e.w;
				dsu.mg(x,y);
			}
		}
		ans=min(ans,now);
	}

	printf("%lld\n",ans);
	return 0;
}

