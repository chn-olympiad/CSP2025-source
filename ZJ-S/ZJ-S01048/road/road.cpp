#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb emplace_back
inline ll read(){ ll x; scanf("%lld",&x); return x; }

int n,m,k;
namespace dsu{
	int fa[20005],sz[20005];
	inline void clear(){
		for(int i=1;i<=n+k;i++) fa[i]=i, sz[i]=1;
	}
	inline int find(int x){
		if(x!=fa[x]) fa[x]=find(fa[x]);
		return fa[x];
	}
	inline void merge(int x,int y){
		x=find(x), y=find(y);
		if(x==y) return; if(sz[x]>sz[y]) swap(x,y);
		fa[x]=y; sz[y]+=sz[x];
	}
	inline void easy_merge(int x,int y){
		if(sz[x]>sz[y]) swap(x,y);
		fa[x]=y; sz[y]+=sz[x];
	}
}
vector<tuple<int,int,int>>E;

struct Node{
	int i,j,val;
}K[200005], G[200005], tmp[200005], all[200005];

int c[10], a[10][10005], tl, org;

void procedure(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		E.pb(w,u,v);
	}
	dsu::clear();
	sort(E.begin(), E.end());

	ll out = 0;
	for(auto [w,u,v]: E){
		if(dsu::find(u) == dsu::find(v)) continue;
		dsu::merge(u,v);
		out += w;
		G[++org] = (Node){u,v,w};
	}

	for(int i=0;i<k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read(), K[++tl]=(Node){n+i+1,j,a[i][j]};
	}

	sort(K+1, K+tl+1, [](Node A,Node B){ return A.val < B.val; });

	for(int s=1;s<(1<<k);s++){
		dsu::clear();
		ll ans=0;
		int edge = n-1+__builtin_popcount(s);
		for(int j=0;j<k;j++)
			if((s>>j)&1) ans += c[j];
		int sz=0;
		for(int j=1;j<=tl;j++)
			if((s>>K[j].i-n-1)&1) tmp[++sz] = K[j];

		merge(G+1, G+org+1, tmp+1, tmp+sz+1, all+1, [](Node A,Node B){ return A.val < B.val; });

		for(int j=1;j<=org+sz;j++){
			int x = dsu::find(all[j].i), y = dsu::find(all[j].j);
			if(x == y) continue;
			edge --;
			ans += all[j].val;
			dsu::easy_merge(x,y);
		}
		// assert(edge == 0);
		if(edge == 0) out = min(out, ans);
	}
	printf("%lld\n", out);
}
int main(){
	assert(freopen("road.in","r",stdin));
	assert(freopen("road.out","w",stdout));
	ll T=1;
	while(T--) procedure();
}