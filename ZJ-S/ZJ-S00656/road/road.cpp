#include <bits/stdc++.h>
using namespace std;
const int N = 10020;
struct node {
	int u, v, w;
};
vector <pair <int, int> > v[N];
//priority_queue <int> q, p[12];
int c[N], a[20][N], f[N], lft[12];
node E[1100010];
int n, m, k;
int cmp(node A, node B) {
	return A.w < B.w;
}
int Find(int x) {
	return (f[x] == x ? x : Find(f[x]));
}
long long D() {
	for (int i = 1; i <= n; i++) f[i] = i;
	sort(E + 1, E + m + 1, cmp);
	long long ans = 0;
	for (int i = 1; i <= m; i++) {
		int Fa = Find(E[i].u), Fb = Find(E[i].v);
		if (Fa != Fb) {
			ans += E[i].w;
			f[Fa] = Fb;
		}
	}
	return ans;
}
//void DD() {
//	int t = n - 1;
//	for (int i = 1; i <= n; i++) f[i] = i;
//	sort(E + 1, E + m + 1, cmp);
//	int now = 1;
//	while (t > 0) {
//		for (int id = 1; id <= k; id++) {
//			int j = now + 1;
//			int cnt = ;
//			while (j <= m) {
//			}
//		}
//	}
//}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u_i, v_i, w_i;
		scanf("%d%d%d", &u_i, &v_i, &w_i);
		E[i] = {u_i, v_i, w_i};
//		v[u_i].push_back({v_i, w_i});
//		v[v_i].push_back({u_i, w_i});
	}
	int flg = 1;
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		if (c[i] != 0) flg = 0;
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	if (k == 0) {
		printf("%lld\n", D());
		return 0;
	}
	if (flg) {
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				E[++m] = (node){n + i, j, a[i][j]};
			}
		}
		n += k;
		printf("%lld\n", D());
		return 0;
	}
	long long ret = 1e18;
	for (int msk = 0; msk < (1 << k); msk++) {
		long long cnt = 0;
		for (int i = 1; i <= k; i++) if (msk & (1 << (i - 1))) {
			cnt += c[i];
			for (int j = 1; j <= n; j++) {
				E[++m] = (node){n + i, j, a[i][j]};
			}
		}
		ret = min(ret, D() + cnt);
	}
	printf("%lld\n", ret);
//	for (int i = 1; i <= k; i++) {
//		for (int j = 1; j <= n; j++) {
//		}
//	}
//	DD();
//	Flg[1] = 1;
//	for (int i = 0; i < (int)v[1].size(); i++) {
//		q.push({-v[1][i].second, v[1][i].first});
//	}
//	for (int i = 1; i <= k; i++) {
//		for (int j = 2; j <= n; j++) {
//			p[i].push_back({-a[i][j], j});
//		}
//		lft[i] = a[i][1];
//	}
//	for (int i = 1; i < n; i++) {
//		pair <int, int> u = q.top();
//		int mn = -u.first, id = u.second;
//		for (int j = 1; j <= k; j++) {
//			int _ = lft[j] - p[j].top().first + c[j];
//		}
//	}
	return 0;
}
//long long