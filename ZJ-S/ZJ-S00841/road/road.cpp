#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
int const N=1e4+50;
int n,m,k,o,d[12],a[12][N],b[12][N],fa[N],tail[15];
struct node{int u,v,w;}B[N*100],c[N];
inline int find(int x){return (x==fa[x])?(x):(fa[x]=find(fa[x]));}
inline void merge(int x,int y){fa[find(x)]=find(y);}
inline void solve(){
	cin>>n>>m>>k;
	rep(i,1,m) cin>>B[i].u>>B[i].v>>B[i].w;
	sort(B+1,B+m+1,[](node A,node B){return A.w<B.w;});
	rep(i,1,n+k) fa[i]=i;
	int t=0;
	rep(i,1,m){
		if (find(B[i].u)==find(B[i].v)) continue;
		fa[find(B[i].u)]=find(B[i].v),c[++t]=B[i];
	}
	rep(i,0,k-1){
		cin>>d[i];
		rep(j,1,n) cin>>a[i][j],b[i][j]=j;
	}
	rep(i,0,k-1) o=i,sort(b[i]+1,b[i]+n+1,[](int x,int y){return a[o][x]<a[o][y];});
	LL ans=1e18;
	rep(S,0,(1<<k)-1){
		rep(i,1,n+k) fa[i]=i;
		int e=0,tt=n-1;
		LL res=0;
		rep(i,0,k) tail[i]=1;
		vector<int>V;
		rep(i,0,k-1) if (S>>i&1) res+=d[i],++tt,V.push_back(i);
		while (e<tt){
			int mi=-1;
			for (auto i:V){
				while (tail[i]<=n && find(b[i][tail[i]])==find(n+i+1)) ++tail[i];
				if (tail[i]>n) continue;
				if (mi==-1 || a[i][b[i][tail[i]]]<a[mi][b[mi][tail[mi]]]) mi=i;
			}
			while (tail[k]<=t && find(c[tail[k]].u)==find(c[tail[k]].v)) ++tail[k];
			if (tail[k]<=t && (mi==-1 || c[tail[k]].w<a[mi][b[mi][tail[mi]]])) mi=k;
			if (mi==-1 || res>=ans) break;
			if (mi!=k) merge(n+mi+1,b[mi][tail[mi]]),res+=a[mi][b[mi][tail[mi]]];
			else merge(c[tail[k]].u,c[tail[k]].v),res+=c[tail[k]].w;
			++tail[mi],++e;
		}
		if (e==tt) ans=min(ans,res);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	while (t--) solve();
	return 0;
}