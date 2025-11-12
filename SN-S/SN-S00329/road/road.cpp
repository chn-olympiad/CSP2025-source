#include <bits/stdc++.h>
#define int int64_t

const int maxk = 16;
const int maxn = 16384;
const int maxm = 1048576;

int n, m, k;
int cost[maxk], add[maxk][maxn];

class edge {
public:
	int u, v, w;
} e[maxm * 4];

bool condition() {
	for (int i = 1; i <= k; i++) {
		if (cost[i]) {
//			std::cout << i << "\n"; 
			return false;
		} 
		bool flag = false;
		for (int j = 1; j <= n; j++) 
			if (!add[i][j]) {
				flag = true;
				break;
			} 
		if (!flag) return false;
	}
	return true;
}

void addedge(int u, int v, int w) {
	m += 1;
	e[m].u = u;
	e[m].v = v;
	e[m].w = w;
}

int f[maxn];

int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

int kruskal(int edgecnt) {
	std::sort(e + 1, e + edgecnt + 1,
		[&] (const edge& a, const edge& b) {
			return a.w < b.w; });
	
	for (int i = 1; i <= n; i++)
		f[i] = i;
	
	int sum = 0;
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int fx = find(f[e[i].u]);
		int fy = find(f[e[i].v]);
		if (fx != fy) {
			sum += e[i].w;
			cnt += 1;
			f[fx] = fy;
			if (cnt == n - 1) break; 
		}
	} 
	return sum;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);
	
	std::cin >> n >> m >> k;
	
	for (int i = 1; i <= m; i++) 
		std::cin >> e[i].u >> e[i].v >> e[i].w;
	
	for (int i = 1; i <= k; i++) {
		std::cin >> cost[i];
//		std::cerr << cost[i] << "\n"; 
		for (int j = 1; j <= n; j++)
			std::cin >> add[i][j]; 
	}
	
	if (k == 0) {
		std::cout << kruskal(m) << "\n";
	} else if (condition()) {
		for (int i = 1; i <= k; i++) {
			int rooter = -1;
			for (int j = 1; j <= n; j++)
				if (add[i][j] == 0)
					rooter = j;
		
			for (int j = 1; j <= n; j++)
				addedge(rooter, j, add[i][j]);
		}
		std::cout << kruskal(m) << "\n";
	}
	
	return 0;
}
