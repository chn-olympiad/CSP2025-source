#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
int const N=1e4+50;
int n,m,k,o,d[12],a[12][N],fa[N];
struct node{int u,v,w;}B[N*100];
inline int find(int x){return (x==fa[x])?(x):(fa[x]=find(fa[x]));}
inline void merge(int x,int y){fa[find(x)]=find(y);}
inline void solve(){
	cin>>n>>m>>k;
	rep(i,1,m) cin>>B[i].u>>B[i].v>>B[i].w;
	rep(i,0,k-1){
		cin>>d[i];
		rep(j,1,n) cin>>a[i][j];
	}
	LL ans=1e18;
	rep(S,0,(1<<k)-1){
		rep(i,1,n+k) fa[i]=i;
		LL res=0;
		vector<node>V;
		rep(i,1,m) V.push_back(B[i]);
		rep(i,0,k-1) if (S>>i&1){
			res+=d[i];
			rep(j,1,n) V.push_back((node){n+i+1,j,a[i][j]});
		}
		sort(V.begin(),V.end(),[](node A,node B){return A.w<B.w;});
		for (auto it:V){
			int u=it.u,v=it.v,w=it.w;
			if (find(u)==find(v)) continue;
			fa[find(u)]=find(v),res+=w;
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	while (t--) solve();
	return 0;
}