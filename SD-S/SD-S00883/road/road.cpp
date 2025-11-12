#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e4 + 5;
const int MAXM = 1e7 + 1e6 + 5;
const ll INF = 9e18 + 5;
const int MOD = 1e9 + 7;

struct Node {
	int u, v; ll w;
} E[MAXM];
bool cmp(const Node &x, const Node &y) {
	return x.w < y.w;
}
int F[MAXN], n, m, k;
ll C[15], A[15][MAXN];
int cnt = 0;

int Find(int x) {
	return x == F[x] ? F[x] : F[x] = Find(F[x]);
}

void Solve_1() {
	for(int i = 1; i <= n; i ++) F[i] = i;
	for(int i = 1; i <= m; i ++) {
		int u, v; ll w; cin >> u >> v >> w;
		E[i] = {u, v, w};
	}
	for(int i = 1; i <= k; i ++) {
		cin >> C[i];
		for(int j = 1; j <= n; j ++) cin >> A[i][j];
	}
	sort(E + 1, E + m + 1, cmp);
	ll ans = 0;
	for(int i = 1; i <= m; i ++) {
		int u = E[i].u, v = E[i].v; ll w = E[i].w;
		int Fu = Find(u), Fv = Find(v);
		if(Fu == Fv) continue ;
		ans += w;
		F[Fu] = Fv;
	}
	cout << ans;
	return ;
}

void Solve_2() {
	for(int i = 1; i <= n; i ++) F[i] = i;
	cnt = m;
	for(int i = 1; i <= k; i ++) {
		for(int u = 1; u <= n; u ++) {
			if(A[i][u] != 0) continue ;
			for(int v = 1; v <= n; v ++) {
				if(v == u) continue ;
				E[++cnt] = {u, v, A[i][v]};
			}
		}
	}
	sort(E + 1, E + cnt + 1, cmp);
	ll ans = 0;
	for(int i = 1; i <= cnt; i ++) {
		int u = E[i].u, v = E[i].v; ll w = E[i].w;
		int Fu = Find(u), Fv = Find(v);
		if(Fu == Fv) continue ;
		ans += w;
		F[Fu] = Fv;
	}
	cout << ans;
	return ;
}

void Solve_3() {
	cnt = m;
	ll ans = INF;
	for(int i = 0; i <= (1 << k) - 1; i ++) {
		ll now = 0; cnt = m;
		for(int j = 1; j <= k; j ++) if(i & (1 << (j - 1))) {
			now += C[j];
			for(int u = 1; u <= n; u ++) E[++cnt] = {j + n, u, A[j][u]};
		}
		for(int j = 1; j <= n + k; j ++) F[j] = j;
		sort(E + 1, E + cnt + 1, cmp);
		for(int j = 1; j <= cnt; j ++) {
			int u = E[j].u, v = E[j].v; ll w = E[j].w;
			int Fu = Find(u), Fv = Find(v);
			if(Fu == Fv) continue ;
			now += w;
			F[Fu] = Fv;
		}
		ans = min(ans, now);
	}
	cout << ans;
	return ;
}

int main() {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	if(k == 0) {
		Solve_1();
		return 0;
	}
	for(int i = 1; i <= m; i ++) {
		int u, v; ll w;
		cin >> u >> v >> w;
		E[i] = {u, v, w};
	}
	for(int i = 1; i <= k; i ++) {
		cin >> C[i];
		for(int j = 1; j <= n; j ++) cin >> A[i][j];
	}
	bool bj = true;
	for(int i = 1; i <= k; i ++) if(C[i] != 0) bj = false;
	for(int i = 1; i <= k; i ++) {
		bool flag = 0;
		for(int j = 1; j <= n; j ++) if(A[i][j] == 0) flag = 1;
		if(!flag) bj = 0;
	}
	if(bj) {
		Solve_2();
		return 0;
	}
	Solve_3();
	
	return 0;
	
}

