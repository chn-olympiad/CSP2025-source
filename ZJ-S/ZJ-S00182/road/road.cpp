#include <cstdio>
#include <algorithm>
#include <vector>
#include <ctime>
typedef long long ll;
constexpr int MAXN = 1e4, MAXM = 1e6, MAXK = 10;

inline int read() {
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	int ret = 0;
	while (ch >= '0' && ch <= '9') {
		ret = ((ret << 3) + (ret << 1)) + ch - '0';
		ch = getchar();
	}
	return ret;
}

int n, m, k, cost[MAXK + 5];
struct Road { int to, w; } arr[MAXK + 5][MAXN + 5];
bool cmp(Road a, Road b) { return a.w < b.w; }

struct Edge { int u, v, w; };
std::vector<Edge> e, alle;
bool cmp1(Edge a, Edge b) { return a.w < b.w; }

ll calc(ll mid, unsigned state) {
	ll ret = 0;
	for (register int i = 0; i < k; i++) {
		if (!((state >> i) & 1)) continue;
		i++;
		int k = 1;
		for (register int j = 1; j <= n; j++) {
			while (k <= n && arr[i][j].w + arr[i][k].w <= mid) k++;
			if (k < j) k = j;
			ret += k - j;
			//std::upper_bound(arr[i] + j + 1, arr[i] + 1 + n,
			//	(Road){0, (int)mid - arr[i][j].w}, cmp) - arr[i] - 1 - j;
		}
		i--;
	}
	// printf("mid -> %d; ret %lld\n", mid, ret);
	return ret;
}

namespace set {
	int f[MAXN + 5] {};
	void init() { for (int i = 1; i <= n; i++) f[i] = i; }
	int find(int x) {
		if (f[x] != x) f[x] = find(f[x]);
		return f[x];
	}
	bool merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx == fy) return false;
		f[fx] = fy;
		return true;
	}
}

ll handle(unsigned state) {
	// printf("stata -> %u\n", state);
	ll ret = 0;
	for (int i = 0; i < k; i++) {
		if ((state >> i) & 1) { ret += cost[i + 1]; }
	}

	ll ll = 0, rr = 1e9, mid = 5e7;
	while (ll <= rr) {
		mid = (ll + rr) >> 1;
		if (calc(mid, state) > (int)1e4) rr = mid - 1;
		else ll = mid + 1;
	}
	// double start = time(0);
	for (int i = 0; i < k; i++) {
		if (!((state >> i) & 1)) { continue; }
		i++;
		for (register int j = 1; j <= n; j++) {
			for (register int k = j + 1; k <= n; k++) {
				if (arr[i][j].w + arr[i][k].w > mid) break;
				alle.push_back({arr[i][j].to, arr[i][k].to, arr[i][j].w + arr[i][k].w});
			}
		}
		i--;
	}
	std::sort(alle.begin(), alle.end(), cmp1);
	// printf("1 %d %lf\n", alle.size(), time(0) - start);
	using namespace set;
	init();
	int cnt = 0, l = 0, r = 0, maxl = m, maxr = alle.size();
	while (l < maxl && r < maxr) {
		while (l < maxl && e[l].w <= alle[r].w) {
			if (merge(e[l].u, e[l].v)) ret += e[l].w, cnt++;
			l++;
		}
		while (r < maxr && alle[r].w <= e[l].w) {
			if (merge(alle[r].u, alle[r].v)) ret += alle[r].w, cnt++;
			r++;
		}
		if (cnt == n - 1) break;
	}

	while (l < maxl) {
		if (merge(e[l].u, e[l].v))
			ret += e[l].w, cnt++;
		l++;
	}
	while (r < maxr) {
		if (merge(alle[r].u, alle[r].v))
			ret += alle[r].w, cnt++;
		r++;
	}

	alle.clear();

	return ret;
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
	// double start = time(0);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, u, v, w; i <= m; i++) {
		u = read(), v = read(), w = read();
		// scanf("%d%d%d", &u, &v, &w);
		// printf("%d %d %d\n", u, v, w);
		e.push_back({ u, v, w });
	}
	// printf("1================\n");
	std::sort(e.begin(), e.end(), cmp1);

	for (int i = 1; i <= k; i++) {
		scanf("%d", cost + i);
		for (int j = 1; j <= n; j++) {
			arr[i][j].w = read();
			// scanf("%d", &arr[i][j].w);
			arr[i][j].to = j;
		}
		std::sort(arr[i] + 1, arr[i] + 1 + n, cmp);
	}
	// printf("1================\n");

	ll ans = 1e15;
	for (unsigned i = 0; i < (1u << k); i++) {
		ans = std::min(handle(i), ans);
	}
	printf("%lld\n", ans);
	// printf("%lf\n", time(0) - start);
	fclose(stdin);
	fclose(stdout);
	return 0;
}