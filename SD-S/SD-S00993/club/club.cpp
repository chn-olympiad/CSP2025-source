#include <bits/stdc++.h>
using namespace std;

namespace myb {
	
	using ll = long long;
	const int N = 1e5 + 5;
	#define fi first
	#define se second
	typedef pair<ll, ll> pll;
	
	int n;
	ll a[N], b[N], c[N];
	pair<ll, ll> x[N][4];
	
	void init() {}
	
	struct node {
		ll x, w, to;
		bool operator < (const node &t) const {
			return w < t.w;
		}
	}; 
	
	void solve() {
		cin >> n;
		init();
		for (int i = 1;i <= n;i++) cin >> a[i] >> b[i] >> c[i];
		
		
		/*
		考虑如果有一个超了，那么另外两个定然没有超
		我可以找一个 -x + y 最大的加进去
		
		即 当我有一个超了，而当前点的最大值是这个 t
		我去比较 q.top() + t > 0
		那么我把 q.top() 对应点加入其对应的 queue 
		*/
		
		
		for (int i = 1;i <= n;i++) {
			x[i][0] = {a[i], 0};
			x[i][1] = {b[i], 1};
			x[i][2] = {c[i], 2};
			x[i][3] = {0, 114};
			sort(x[i], x[i] + 3, [] (pll p, pll q) {
				return p.fi > q.fi;
			});
//			for (int j = 0;j < 3;j++) cout << x[i][j].fi << " " << x[i][j].se << "\n";
//			cout << "\n";
		}
		
		ll ans = 0;
		priority_queue<node> q[3];
		for (int i = 1;i <= n;i++) {
			
			pll maxn = {-1, -1};
			for (int j = 0;j < 3;j++) {
				int now = x[i][j].se;
				if ((ll)q[now].size() < n / 2) {
					maxn = max(maxn, {x[i][j].fi, j});
				}
				else if (q[now].size() && x[i][j].fi + q[now].top().w >= 0) {
					maxn = max(maxn, {x[i][j].fi + q[now].top().w, j});
				}
			}
			
//			cout << maxn.fi << " " << x[i][maxn.se].fi << "\n";
			
			int j = maxn.se;
			int now = x[i][j].se;
			
			if ((int)q[now].size() < n / 2) {
				ans += x[i][j].fi;
				q[now].push({i, -x[i][j].fi + x[i][j + 1].fi, x[i][j + 1].se});
			}
			else if (q[now].size() && x[i][j].fi + q[now].top().w >= 0) {
				auto t = q[now].top(); q[now].pop();
				ll X = t.x, W = t.w, to = t.to;
				ans += x[i][j].fi + W; 
				
				q[now].push({i, -x[i][j].fi + x[i][j + 1].fi, x[i][j + 1].se});
				
				q[to].push({X, -x[X][to].fi + x[X][to + 1].fi, x[X][to + 1].se});
			}
		}
		cout << ans << "\n";
//		cout << "\n";
	}
	
	void main() {
		int T;
		cin >> T;
		while (T--) {
			solve();
		} 
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	myb::main();
	return 0;
}


