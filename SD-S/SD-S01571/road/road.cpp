#include<bits/stdc++.h>
#include<vector>
#define int long long
#define F(i,l,r) for(int i=(l); i<=(r); ++i)
using namespace std;
const int N=2e4+50,INF=0x3f3f3f3f3f3f3f3f;
const int M=1e6+50;

int n,m,K,ans=INF,tot_bas;
int c[20],a[20][N];
int fa[N];
struct node{
	int u,v,w;
};
node bas[N];
node ve[M];

inline void init(){
	F(i,1,n+K) fa[i]=i;
}
inline int find(int x){ return x==fa[x]?x:fa[x]=find(fa[x]); }
inline void Kruskal(int t){
	init();
	int res=0,tot=0;
//	vector<node> ve;
	if(t){
		F(i,1,tot_bas) ve[++tot]=bas[i];
		F(k,1,K) if(t&(1<<(k-1))){
			res+=c[k];
			F(i,1,n) ve[++tot]={i,n+k,a[k][i]};
		}
	}else tot=m;
	
	sort(ve+1,ve+tot+1,[](node a,node b){ return a.w<b.w; });
	int cnt=0, pc=__builtin_popcount(t);
	F(i,1,tot){
		if(cnt >= n+pc-1) break;
		int u=find(ve[i].u), v=find(ve[i].v);
		if(u==v) continue;
		++cnt;
		fa[u]=v;
		res+=ve[i].w;
		if(!t) bas[++tot_bas]=ve[i];
	}
//	cout<<t<<' '<<res<<'\n';
	ans=min(ans,res);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>K;
	F(i,1,m) cin>>ve[i].u>>ve[i].v>>ve[i].w;
	Kruskal(0);
	
	F(t,1,K){
		cin>>c[t];
		F(i,1,n) cin>>a[t][i];
	}
	for(int t=1; t<(1<<K); ++t){
		Kruskal(t);
	}
	cout<<ans<<'\n';
	
	return 0;
}
