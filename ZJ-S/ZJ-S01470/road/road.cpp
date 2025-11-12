#include <bits/stdc++.h>
#define ll unsigned long long
#define endl '\n'
using namespace std;
const ll N = 1e4+5,M = 1e6+5;
ll n,m,k;
struct node{ll u,v,w;}e[N+M];
bool cmp(node x,node y){return x.w < y.w;}
ll fa[N];
void init(int nn){for (ll i = 0;i <= nn;i++) fa[i] = i;}
ll find(ll x){return (fa[x] == x) ? x : (fa[x] = find(fa[x]));}
void unite(ll x,ll y){x = find(x);y = find(y);fa[x] = y;}
ll kkk(ll en,node ee[],ll nn){
	init(nn);
	sort(e+1,e+1+en,cmp);
	ll cnt = 0,res = 0;
	ll i;
	for (i = 1;;i++){
		ll u = ee[i].u,v = ee[i].v,w = ee[i].w;
		if (find(u) == find(v)) continue;
		unite(u,v);
		res += w;
		++cnt;
		if (cnt+1 == nn) break;
	}
	return res;
}
void sub1(){
	cin >> n >> m >> k;
	for (ll i = 1;i <= m;i++) cin >> e[i].u >> e[i].v >> e[i].w;
	ll ans = kkk(m,e,n);
	for (ll i = 1;i <= k;i++){
		ll c;cin >> c;
		for (ll j = 1;j <= n;j++){
			cin >> e[m+j].w;
			e[m+j].u = n+1;e[m+j].v = j;
		}
		ans = min(ans,c+kkk(n+m,e,n+1));
	}
	cout << ans << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	sub1();
	return 0;
} 
/*
3 3 1
1 2 1
1 3 3
2 3 3
1 1 1 1
*/
