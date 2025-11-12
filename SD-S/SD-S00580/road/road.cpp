//这道题，我们可以给他先跑一遍最小生成树，然后再把最小生成的树剖一下，最后再开棵线段树存一下，然后枚举每一个乡村，看看给他通上那条路会花多少钱-------暴力做法 
#include <bits/stdc++.h>
#define ll int
#define inf 0x3f3f3f3f
#define mem(a , b) memset(a , b , sizeof a)
using namespace std;
const int N = 2e6+10;
ll n , m , k;
struct DS {
	ll fa[N];
	void init(ll tot) {
		for(int i = 1 ; i <= tot ; i++) {
			fa[i] = i;
		}
	}
	ll find(ll x) {
		if(fa[x] == x) return x;
		return (fa[x] = find(fa[x]));
	}
}q;
struct GFX {
	ll u , v;
	ll w;
	bool operator<(const GFX&b) const {
		return w < b.w;
	}
}a[N];
ll kl() {
	q.init(n+k);
	ll ans = 0;
	for(int i = 1 ; i <= m ; i++) {
		ll fu = q.find(a[i].u) , fv = q.find(a[i].v);
		if(fu == fv) continue;
		q.fa[fu] = fv;
		ans += a[i].w;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	ll aikhdgiuadhskjsbjgkbads;
	for(int i = 1 ; i <= k ; i++) {
		cin >> aikhdgiuadhskjsbjgkbads;
		for(int j = 1 ; j <= n ; j++) {
			m++;
			a[m].u = i + n;
			a[m].v = j;
			cin >> a[m].w;
		}
	}
	sort(a + 1 , a + 1 + m);
	cout << kl();
	return 0;
}

/*
#define WA AC
#define AC AC
#define TLE AC
#define MLE AC
#define UKE AC
#define OLE AC
#define RE AC
#define SD-S00580 std
Ad-hoc
HoLuc1078
*/

