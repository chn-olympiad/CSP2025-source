// SD-S01603

#include <bits/stdc++.h>
#define int long long

using namespace std;

inline int read () {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}

	return x * f;
}

const int N = 1e4 + 10 + 10, VM = 1e6 + 10, VMK = 1e5 + 10;

struct Edge {
	int u, v, val;
} g[VM], gn[N];

int n, m, k, fa[N], cost[11], ncnt, ans1;
int dis[11][N], sum[11];

inline int find (int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

inline bool cmp (Edge a, Edge b) {
	return a.val < b.val;
}

signed main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = read(); m = read(); k = read();
	
	for (int i = 1; i <= n + k; ++i) 
		fa[i] = i;
	
	for (int i = 1; i <= m; ++i) {
		int u = read(), v = read(), val = read();
		g[i] = Edge {u, v, val};
	}
	
	sort (g + 1, g + m + 1, cmp);
	
	for (int i = 1; i <= m; ++i) {
		int u = g[i].u, v = g[i].v, val = g[i].val;
		int fu = find(u), fv = find(v);
		if (fu != fv) {
			fa[fu] = fv;
			ncnt ++; ans1 += val;
			gn[ncnt] = g[i];
			if (ncnt == n - 1) break;
		}
	}
	
	if (k == 0) {
		printf("%lld\n", ans1);
		return 0;
	}
	
	for (int i = 1; i <= k; ++i) {
		cost[i] = read();
		for (int j = 1; j <= n; ++j)
			dis[i][j] = read(),
			sum[i] += dis[i][j];
//		printf("%lld\n\n", sum[i]);
	}
	
	int ans2 = 1e18;
	
	for (int i = 1; i <= k; ++i) {
		int delta = 0;
		for (int j = 1; j <= m; ++j) {
//			int u = gn[j].u, v = gn[j].v, val = gn[j].val;
			int u = g[j].u, v = g[j].v, val = g[j].val;
			if (val < max(dis[i][u], dis[i][v])) {
				if (dis[i][u] > dis[i][v])
					delta += dis[i][u] - val,
					dis[i][u] = 0;
				else 
					delta += dis[i][v] - val,
					dis[i][v] = 0;
//				printf("Case : %lld %lld %lld\n", u, v, val);
			}
		}
		
//		printf("%lld\n", delta);
		
		ans2 = min(ans2, cost[i] + sum[i] - delta);
	}
	
	printf("%lld\n", min(ans1, ans2));
	
	return 0;
}

// Block 3.
// 如果由一个乡村建出的边集是答案的一部分，这个边集连接的点边权和一定比原图上这个点集的最小生成树更优。
// 遍历每一个乡村引出的树，尝试用原图上的边去更新这棵树。
// 如果原图上这条边比新树上两条边更优就更新。 
// 但是有可能一条边在一棵树上能更新但是在另一棵树上不能更新。因此考虑答案合并。
// 记录每一棵树更新了哪些边以及每条边更新后答案变化值 
// 注意到如果建了一个乡村一定会先连最便宜的边。
// 连一条边后对原树进行链更新用新边优化掉原树路径上最长的一条边。 

//	4 4 2
//	1 4 6
//	2 3 7
//	4 2 5
//	4 3 4
//	1 1 8 2 4
//	100 1 3 2 4
