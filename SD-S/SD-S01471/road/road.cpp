#include<bits/stdc++.h>
using namespace std;
#define vec vector
#define pb push_back
#define eb emplace_back
#define siz(a) (int)((a).size())
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair
#define exc(expr) if(expr)continue;
#define stop(expr) if(expr)break;
#define ret(expr) if(expr)return;
#define deb(var) cerr<<#var<<'='<<(var)<<"; "
#define debl(var) cerr<<#var<<'='<<(var)<<";\n"
#define inf (long long)(1e18)
#define ll long long
template<class T>bool Min(T &x,T y){return x>y?x=y,1:0;}
template<class T>bool Max(T &x,T y){return x<y?x=y,1:0;}
const int mod=998244353;
void Add(int &x,int y){x=x+y<mod?x+y:x+y-mod;}
int fpm(int x,int y){
	int ans=1;for(;y;y>>=1,(x*=x)%=mod)if(y&1)(ans*=x)%=mod;return ans;
}
int n,m,k,c[15];
struct Edge{
	int u,v,w;
}E[110010],E2[1100010];
int fa[10015],siz[10015];
int find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
int cc;
void work(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>E2[i].u>>E2[i].v>>E2[i].w;
	} 
	sort(E2+1,E2+m+1,[&](auto x,auto y){
		return x.w<y.w;
	});
	iota(fa+1,fa+n+1,1);
	int cnte=0;
	for(int i=1;i<=m;i++){
		int u=E2[i].u,v=E2[i].v;
		u=find(u),v=find(v);
		if(u!=v){
			fa[u]=v;
			E[++cnte]=E2[i];
		}
	}
//	assert(cnte==n-1);
	m=cnte;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			++m;
			E[m].u=i+n,E[m].v=j;
			cin>>E[m].w;
		}
	}
	sort(E+1,E+m+1,[&](auto x,auto y){
		return x.w<y.w;
	});
	ll ans=inf;
	for(int S=0;S<(1<<k);S++){
		ll cost=0;
		for(int i=0;i<k;i++)if(S>>i&1)cost+=c[i+1];
		iota(fa+1,fa+n+k+1,1);
		fill(siz+1,siz+n+k+1,1);
		int cc=__builtin_popcount(S)+n; 
		for(int i=1;i<=m;i++){
			int u=E[i].u,v=E[i].v;
			exc(u>n&&(~S>>(u-n-1)&1));
			u=find(u),v=find(v);
			exc(u==v);
			if(siz[u]>siz[v])swap(u,v);
			fa[u]=v;
			siz[v]+=siz[u];
			cost+=E[i].w;
			--cc;
			if(cc==1||cost>=ans)break;
		}
		if(cc==1)Min(ans,cost);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),
	cin.tie(0),cout.tie(0);
	int T=1;while(T--)work();
}
/*
- CONTINUE, NON-STOPPING, FOR THE FAITH
- START TYPING IF YOU DON'T KNOW WHAT TO DO
- STOP TYPING IF YOU DON'T KNOW WHAT YOU'RE DOING
*/

