#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m, k;

struct road{
	ll u, v, w;
}r[2000010];

ll fa[10010];

bool cmp(road A, road B){
	return A.w < B.w;
}

ll find(ll x){
	if(fa[x] == x) return fa[x];
	return fa[x] = find(fa[x]);
}

void merge(ll x, ll y){
	if(find(x) == find(y)) return;
	fa[find(x)] = y; return;
}

bool pan(){
	ll t = find(1);
	for(ll i = 2; i <= n; i++){
		if(t != find(i))
			return 0;
	}
	return 1;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	ll p = m + 1;
	for(ll i = 1; i <= n; i++)
		fa[i] = i;
	for(ll i = 1; i <= m; i++)
		scanf("%d%d%d", &r[i].u, &r[i].v, &r[i].w);
	for(ll i = 1; i <= k; i++){
		ll c;
		scanf("%d", &c);
		ll d[10010];
		for(ll j = 1; j <= n; j++)
			scanf("%d", &d[j]);
		for(ll x = 1; x < n; x++){
			for(ll y = x + 1; y <= n; y++){
				r[p].u = x;
				r[p].v = y;
				r[p].w = d[x] + d[y] + c;
				p++;
			}
		}
	}
	sort(r + 1, r + p + 1, cmp);
	ll ans = 0;
	for(ll i = 2; i <= p; i++){
		if(find(r[i].u) == find(r[i].v)) continue;
		merge(r[i].u, r[i].v);
		ans += r[i].w;
		if(pan()){
			cout << ans;
			return 0;
		}
	}
	return 0;
}
