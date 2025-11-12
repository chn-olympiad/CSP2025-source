#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fp(s) string ssssss=s;freopen((ssssss+".in").c_str(),"r",stdin);freopen((ssssss+".out").c_str(),"w",stdout);
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define pb push_back
#define inl inline
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define mt(x,y) memset(x,y,sizeof x)
#define INF 1e18
using namespace std;
const int N=1e4+5,M=1e6+5,K=15,P=(1ll<<10)+5;
struct edge{
	int u,v,w;
	inl edge(){
		u=v=w=0;
	}
	inl edge(int uu,int vv,int ww){
		u=uu; 
		v=vv;
		w=ww;
	}
	inl friend bool operator<(edge x,edge y){
		return x.w<y.w;
	}
}g[M],gx[P][N];
struct dsus{
	int fa[N];
	inl dsus(){
		mt(fa,0);
	}
	inl void init(int n){
		rep(i,1,n) fa[i]=i;
	}
	inl int find(int x){
		if(fa[x]==x) return x;
		return fa[x]=find(fa[x]);
	}
	inl bool merge(int u,int v){
		int fu=find(u),fv=find(v);
		if(fu==fv) return 0;
		fa[fu]=fv;
		return 1;
	}
}dsu;
int c[K],a[K][N];
inl int kruskal(int n,int m,int id){
	dsu.init(n);
	sort(g+1,g+m+1);
	int ans=0,cnt=0;
	rep(i,1,m)
		if(dsu.merge(g[i].u,g[i].v)){
			ans+=g[i].w;
			gx[id][++cnt]=g[i];
		}
	return ans;
}
signed main(){
	fp("road");
	fst;
	int n,m,k;
	cin>>n>>m>>k;
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	rep(i,1,m) cin>>g[i].u>>g[i].v>>g[i].w;
	int ans=kruskal(n,m,0);
	rep(i,1,k){
		cin>>c[i];
		rep(j,1,n) cin>>a[i][j];
	}
	rep(S,1,(1ll<<k)-1){
		int len=__builtin_popcount(S),cnt=n+len-2,sum=0,u=__lg(S&-S)+1;
		rep(i,1,n+len-2) g[i]=gx[S^(S&-S)][i];
		rep(u,1,k)
			if(S>>u-1&1) sum+=c[u];
		rep(i,1,n) g[++cnt]=edge(n+len,i,a[u][i]);
		ans=min(ans,kruskal(n+len,cnt,S)+sum);
	}
	cout<<ans<<endl;
	return 0;
} 
