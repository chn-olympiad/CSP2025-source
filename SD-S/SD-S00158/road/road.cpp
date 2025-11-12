#include <bits/stdc++.h>
//#define int long long
using namespace std;
using ll = long long;
const int N = 1e4 + 5;

ll n, m, k;
ll ans;

ll fa[N << 1];

ll find(int x) {
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
void merge(ll x, ll y) {
	ll fx = find(x), fy = find(y);
	if(fx != fy)
		fa[fx] = fy;
}

struct Edge {
	ll u, v, w;
	bool operator < (const Edge& x) const {
		return w < x.w;
	}
};
ll c[N];
ll dis[15][N];

vector<Edge> E;
void debug(vector<Edge>& es) {
	cout << "---------------------\n";
	for(auto i : es)
		printf("(%d %d %d) ", i.u, i.v, i.w);
	cout << "\n---------------------\n";
}
ll MST(vector<Edge>& es, int num, vector<Edge>& ks) {
	ll cnt = 0, sum = 0;
	for(ll i = 1; i <= n + 2*k; i++)
		fa[i] = i;

	vector<Edge> ess;
	for(auto i : ks)
		ess.push_back(i);

	for(auto i : es)
		ess.push_back(i);

	sort(ess.begin()+num/2, ess.end());
//	debug(ess);
	for(auto e : ess) {

		ll u = e.u, v = e.v, w = e.w;
//		printf("CHOSEN:(%d %d %d)\n", u, v, w);
		if(find(u) != find(v)) {
			merge(u, v);
			sum += w;
			cnt++;
		}
		if(cnt == n + num - 1)
			break;
	}
//	printf("SUM:%d\n\n",sum);
	return sum;
}
ll _count(ll num) {
	ll tot = 0;
	for(int i = 0; i < 11; i++)
		if(num & (1 << i))
			tot++;
	return tot;
}
void solve1() {
	for(ll S = 0; S < (1 << k); S++) {
		ll tot = 0;
		for(ll i = 0 ; i < k; i++) {
			if(S & (1 << i)) {
				for(ll j = 1; j <= n; j++) {
					tot += 2;
					E.emplace_back(Edge {j, n + 2 * (i + 1), dis[i+1][j]});
					E.emplace_back(Edge {n + 2 * (i + 1) - 1, j, dis[i+1][j]});
				}
			}
		}
		vector<Edge> K;
		for(ll i = 0 ; i < k; i++) {
			if(S & (1 << i)) {
				K.emplace_back(Edge {n + 2 * (i+1), n + 2 * (i+1) - 1, c[i+1]});
			}
		}
//		printf("S:%d\n", S);

		ans = min(ans, MST(E, 2 * _count(S), K));
		while(tot--) E.pop_back();

	}
}
void solve0() {
	ll cnt = 0, sum = 0;
	for(ll i = 1; i <= n; i++)
		fa[i] = i;
	sort(E.begin(), E.end());
	for(auto e : E) {
		ll u = e.u, v = e.v, w = e.w;
		if(find(u) != find(v)) {
			merge(u, v);
			sum += w;
			cnt++;
		}
		if(cnt == n - 1)
			break;
	}
	ans = sum;
}
bool checkA() {
	for(ll i = 1; i <= k; i++)
		if(c[i] != 0)
			return 0;
	return 1;
}
void solveA() {
	ll cnt = 0, sum = 0;
	for(ll i = 1; i <= n + k; i++)
		fa[i] = i;
	for(ll i = 1 ; i <= k; i++) {
		for(ll j = 1; j <= n; j++) {
			E.push_back(Edge {n+i, j, dis[i][j]});
		}
	}
	sort(E.begin(), E.end());
//	debug(E);
	for(auto e : E) {

		ll u = e.u, v = e.v, w = e.w;

		if(find(u) != find(v)) {
//			printf("CHOSEN:(%d %d %d)\n", u, v, w);
			merge(u, v);
			sum += w;
			cnt++;
		}
		if(cnt == n + k - 1)
			break;
	}
//	cout << cnt << '\n';
	ans = sum;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;

	for(ll i = 1; i <= m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		E.push_back(Edge {u, v, w});
	}

	for(ll i = 1; i <= k; i++) {
		cin >> c[i];
		for(ll j = 1 ; j <= n; j++) {
			cin >> dis[i][j];
		}
	}
	ans = 0x3f3f3f3f;

	if(k == 0) {
		solve0();
	} else if(checkA()) {
		solveA();
	} else {
		solve1();
	}
	cout << ans;
	return 0;
}
/*
solve0

4 4 0
1 4 6
2 3 7
4 2 5
4 3 4



solveA

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4

*/
