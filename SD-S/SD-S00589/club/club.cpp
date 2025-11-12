#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 100;

struct peo{
	ll d1, d2, d3;
} peo[N];

struct state{
	ll idx, w, id;	
	
	bool operator<(const state & s) const {
		return w < s.w;
	}
};

ll n, T;
ll ans, vis[N];

void dfs(int dep, int a, int b, int c, ll tot) {
	if (dep == n) {
		ans = max(ans, tot);	
	}
	
	if (a + 1 <= n /2) {
		dfs(dep + 1, a + 1, b, c, tot + peo[dep + 1].d1);
	}
	if (b + 1 <= n /2) {
		dfs(dep + 1, a, b + 1, c, tot + peo[dep + 1].d2);
	}
	if (c + 1 <= n /2) {
		dfs(dep + 1, a, b, c + 1, tot + peo[dep + 1].d3);
	}
}

void solve() {
	ans = 0;
	cin >> n;
	bool f1 = false, f2 = false, f3 = false;
	for (int i = 1; i <= n; i++) {
		cin >> peo[i].d1 >> peo[i].d2 >> peo[i].d3;
		if (peo[i].d1) f1 = true;
		if (peo[i].d2) f2 = true;
		if (peo[i].d3) f3 = true;
	}
	if (n <= 30) {
		dfs(0, 0, 0, 0, 0);
		cout << ans << endl;
	} else if ((!f1 && !f2) || (!f2 && !f3) || (!f1 && !f3)) {
		priority_queue<ll> pq;
		for (int i = 1; i <= n; i++) {
			if (f1) {
				pq.push(peo[i].d1);
			} else if (f2) {
				pq.push(peo[i].d2);
			} else {
				pq.push(peo[i].d3);
			}
		}
		for (int i = 1; i <= n/2; i++) {
			ll now = pq.top();
			pq.pop();
			ans += now;
		}
		cout << ans << endl;
	} else if (!f1 || !f2 || !f3) {
		priority_queue<ll> pq;
		if (!f1) {
			for (int i = 1; i <= n; i++) {
				ans += peo[i].d2;
				pq.push(peo[i].d3 - peo[i].d2);
			}
			for (int i = 1; i <= n/2; i++) {
				ll now = pq.top();
				pq.pop();
				ans += now;
			}
		} else if (!f2) {
			for (int i = 1; i <= n; i++) {
				ans += peo[i].d1;
				pq.push(peo[i].d3 - peo[i].d1);
			}
			for (int i = 1; i <= n/2; i++) {
				ll now = pq.top();
				pq.pop();
				ans += now;
			}
		} else {
			for (int i = 1; i <= n; i++) {
				ans += peo[i].d1;
				pq.push(peo[i].d2 - peo[i].d1);
			}
			for (int i = 1; i <= n/2; i++) {
				ll now = pq.top();
				pq.pop();
				ans += now;
			}
		}
		cout << ans << endl; 
	} else {
		
	}
}

int main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	for (int i = 1; i <= T; i++) solve();
		
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
