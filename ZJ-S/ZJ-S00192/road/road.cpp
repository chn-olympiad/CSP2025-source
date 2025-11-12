#include<bits/stdc++.h>
#define rep(i,x,y) for(ll i=x;i<=y;++i)
#define repp(i,x,y) for(ll i=x;i>=y;--i)
#define ll long long
#define scan scanf
#define prin printf
using namespace std;
const ll K=10,N=1e3,M=1e6;
struct Line {
	ll u,v,w;
	bool operator < (const Line &a) {
		return w<a.w;
	}
}l[M+(N*N*K)+100];
ll c[K+10];
ll cnt=0;
ll w[N+10];
void add(ll u,ll v,ll w) {
	l[++cnt]={u,v,w};
}
struct Union_set {
	ll fa[N+100];
	void init(ll n) {
		rep(i,1,n) fa[i]=i;
	}
	ll find(ll x) {
		if(x==fa[x]) return x;
		return fa[x]=find(fa[x]);
	}
	bool query(ll x,ll y) {
		return find(x)==find(y);
	}
	void update(ll x,ll y) {
		fa[x]=y;
	}
}us;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	scan("%lld%lld%lld",&n,&m,&k);
	rep(i,1,m) {
		ll u,v,w;
		scan("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
	}
	rep(i,1,k) {
		scanf("%lld",c+i);
//		memset(w,0,sizeof w);
		rep(j,1,n) scan("%lld",w+j);
//		rep(j,1,n) cerr<<w[j]<<" ";
//		cerr<<endl;
		rep(j,1,n-1)
			rep(k,j+1,n)
				add(j,k,w[j]+w[k]);
	}
	us.init(n);
	sort(l+1,l+1+cnt);
	ll ans=0,s=0;
	rep(i,1,cnt) {
		ll u=l[i].u,v=l[i].v,w=l[i].w;
//		cerr<<u<<" "<<v<<" "<<w<<endl;
		if(us.query(u,v)) continue;
		ans+=w;
		us.update(u,v);
		++s;
		if(s==n-1) break;
	}
	prin("%lld",ans);
	return 0;
}
/*
4 5 2
1 2 2
1 3 4
1 4 3
2 4 0
1 3 4
0 2 0 1 2
0 2 1 4 0 
*/
