#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
/*
#include<stack>
#include<map>
#include<set>
#include<string>
#include<unordered_map>
*/
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define bug cout<<"-------\n";
#define debug(x) cout<<#x<<'='<<x<<'\n';
#define file(FILENAME) freopen(FILENAME ".in","r",stdin),freopen(FILENAME ".out","w",stdout);
#define CLOSE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define endl '\n'

const ll N = 10005;
ll n, m, k;
ll fa[N];
struct {
	ll c;
	ll a[N];
} country_side[N];
priority_queue<pair<ll, pair<ll, ll>>> qu;
ll ans;
ll ffind(ll x) {
	if(fa[x] == x)return x;
	else return (fa[x] = ffind(fa[x]));
}
void min_road() {
	while(!qu.empty()) {
		pair<ll, pair<ll, ll>> T = qu.top();
		qu.pop();
		ll u = T.second.first, v = T.second.second;
		ll w = T.first;
		ll uu = ffind(u), vv = ffind(v);
		if(uu == vv)continue;
		else {
			fa[vv] = u;
			ans -= w;
		}
	}
}
int main() {
	file("road")
	CLOSE
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)fa[i] = i;
	for(int i = 1; i <= m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		qu.push({ -w, {u, v}});
	}
	for(int i = 1; i <= k; i++) {
		cin >> country_side[i].c;
		for(int j = 1; j <= n; j++) {
			cin >> country_side[i].a[j];
		}
	}
	min_road();
	cout << ans;
	return 0;
}

