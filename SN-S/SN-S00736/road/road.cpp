#include<bits/stdc++.h>
using ll = long long;
using db = double;
#define For(i,j,k) for(ll i = j;i <= k;i++)
#define Rep(i,j,k) for(ll i = j;i >= k;i--)
#define fi first
#define se second
#define pll pair<ll,ll>
#define tll tuple<ll,ll,ll>
#define pb push_back
#define eb emplace_back
using namespace std;
const ll N = 1e6 + 10,p = 998244353,inf = 1e18;
struct DSU{ll n;vector<ll> fa,sz;
	void it(ll _n){n = _n,fa.resize(n + 1),sz.assign(n + 1,0),iota(fa.begin(),fa.end(),0ll);}
	ll fd(ll x){return fa[x] == x ? x : fa[x] = fd(fa[x]);}
	void mrg(ll u,ll v){u = fd(u),v = fd(v);if(u == v) return;
		if(sz[u] == sz[v]) sz[u]++;if(sz[u] < sz[v]) swap(u,v);fa[v] = u; 
	}
}f;struct P{ll u,v,w;};vector<P> e;ll q,t;
bool operator < (P x,P y){return x.w > y.w;}
void sol(){ll n,m,k,u,v,w;cin >> n >> m >> k,f.it(n + k);ll o = 1e18;bool fl = 1;
	For(i,1,m) cin >> u >> v >> w,e.pb({u,v,w});vector<ll> c(k + 1),vi(k + 1);
	For(i,1,k){cin >> c[i],fl &= !c[i];For(j,1,n) cin >> w,e.pb({i + n,j,w});}
	sort(e.begin(),e.end(),[&](P x,P y){return x.w < y.w;});
	For(s,0,(1 << k) - 1){For(i,0,k - 1) vi[i + 1] = s >> i & 1;t = 0;
		if(fl && s < (1 << k) - 1) continue;//For(i,1,k) cout << vi[i] << " \n"[i == k];
		ll r = 0;f.it(n + k),q = n + __builtin_popcount(s);
		For(i,0,(ll)e.size() - 1) if(e[i].u <= n || vi[e[i].u - n]){if(t == q - 1) break;
			ll u = e[i].u,v = e[i].v,w = e[i].w;
			if(f.fd(u) != f.fd(v)) f.mrg(u,v),r += w,t++;
		}For(i,1,k) if(vi[i]) r += c[i];o = min(o,r);
	}cout << o << '\n';
}int main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll T = 1;while(T--) sol();return 0;
}
