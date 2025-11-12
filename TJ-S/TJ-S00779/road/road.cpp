#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e4+15, M = 2e6+5, K = 15;

struct E
{
	ll u, v; ll w;
} e[M];
inline bool cmp(E &l, E &r)
{
	return l.w<r.w;
}

ll n, m, k; 
ll c[N];

struct ufs
{
	ll fa[N];
	inline void init()
	{
		for(ll i = 1; i <= n+k; i++) {
			fa[i] = i;
		}
	}
	inline ll find(ll x)
	{
		return (fa[x] == x) ? x : (fa[x] = find(fa[x]));
	}
	inline void merge(ll fu, ll fv)
	{
		fa[fu] = fv;
	}
} s;

ll ans = 0;
inline void kus()
{
	s.init();
	for(ll i = 1; i <= m+k*n; i++) {
		ll u = e[i].u, v = e[i].v;
		ll fu = s.find(u), fv = s.find(v);
		if(fu != fv) {
			s.merge(fu,fv);
			ans += e[i].w;
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%lld%lld%lld", &n, &m, &k);
	for(ll i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
	}
	ll cnt = m;
	for(ll i = 1; i <= k; i++) {
		scanf("%lld", &c[i]); ans += c[i];
		for(ll j = 1, w; j <= n; j++) {
			scanf("%lld", &w);
			e[++cnt].u = n+i; e[cnt].v=j; e[cnt].w = w;
		}
	}
	sort(e+1,e+1+cnt,cmp);
	kus();
	printf("%lld\n", ans);
	
	
	return 0;
}

//check WA/RE/MLE/TLE

