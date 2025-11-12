#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

const int N = 1e4 + 20;
const int M = 1e6 + 10;
const int K = 20;
const i64 INF = 1e18;
const int INF2 = 1e9 + 10;

struct node {
	int to, w;
};

struct A {
	int f, x, dis;
	bool operator < (const A &tmp) const {
		return tmp.dis < dis;
	}
};

int n, m, k;
int u[M], v[M], w[M];

int c[K], a[K][N];

bool vis[1 << 10][N];

i64 res;

int fr[1 << 10][N];

std::priority_queue <A> q;
std::vector <node> edge[N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	//clock_t st = clock();
	std::cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		std::cin >> u[i] >> v[i] >> w[i];
		edge[u[i]].push_back((node){v[i], w[i]});
		edge[v[i]].push_back((node){u[i], w[i]});
	}
	bool taga = 1;
	for (int i = 1; i <= k; ++i) {
		std::cin >> c[i];
		if (c[i]) {
			taga = 0;
		}
		for (int j = 1; j <= n; ++j) {
			std::cin >> a[i][j];
			edge[j].push_back((node){n + i, a[i][j]});
			edge[n + i].push_back((node){j, a[i][j]});
		}
	}

	for (int i = 0; i < (1 << k); ++i) {
		if (taga && i < (1 << k) - 1) {
			continue;
		}
		q.push((A){i, 1, 0});
		for (int j = 2; j <= n + k; ++j) {
			fr[i][j] = INF2;
		}
	}
	while (!q.empty()) {
		A now = q.top();
		q.pop();
		if (vis[now.f][now.x]) {
			continue;
		}
		vis[now.f][now.x] = 1;

		for (auto to : edge[now.x]) {
			if (to.to > n) {
				int p = to.to - n - 1;
				if (((1 << p) & now.f) == 0) {
					continue;
				}
			}

			if (!vis[now.f][to.to]) {
				if (to.w < fr[now.f][to.to]) {
					fr[now.f][to.to] = to.w;
					q.push((A){now.f, to.to, fr[now.f][to.to]});
				}
			}
		}
	}

	i64 ans = INF;
	for (int i = 0; i < (1 << k); ++i) {
		if (taga && i < (1 << k) - 1) {
			continue;
		}
		i64 res = 0;
		for (int j = 1; j <= n; ++j) {
			if (i & (1 << j - 1)) {
				res += c[j];
			}
		}
		for (int j = 1; j <= n + k; ++j) {
			if (fr[i][j] == INF2) {
				continue;
			}
			res += fr[i][j];
		}
		ans = std::min(ans, res);
	}
	std::cout << ans;

	//std::cerr << clock() - st;

	return 0;
}