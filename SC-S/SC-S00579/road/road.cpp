#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 1e6 + 15, M = 1e4 + 15;

int n, m, k, mm;
ll c[20], a[20][M];
int fa[M];
struct edge {
	int u, v;
	ll w;
}e[N + 10 * M];
ll ans = 1e18;

bool cmp (edge x, edge y) {
	return x.w < y.w;
}

int find (int x) {
	return (x == fa[x]) ? x : (fa[x] = find (fa[x]));
}

inline void join (int x, int y) {
	int f1 = find (x), f2 = find (y);
	if (f1 != f2) fa[f1] = f2;
}

inline ll kruskal (int p) {
	int cnt = 0;
	ll sum = 0;
	sort (e + 1, e + mm + 1, cmp);
//	printf ("%d\n", mm);
	for (int i = 1; i <= mm; ++ i) {
		if (find (e[i].u) != find (e[i].v)) {
			join (e[i].u, e[i].v);
			sum += e[i].w;
			++ cnt;
		}
		if (cnt == n + p - 1) break;
	}
	return sum;
}

int main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++ i) {
		int u, v;
		ll w;
		scanf ("%d%d%lld", &u, &v, &w);
		e[i] = (edge){u, v, w};
	}
	bool flag = true; 
	for (int j = 1; j <= k; ++ j) {
		scanf ("%lld", &c[j]);
		if (c[j] != 0) flag = false;
		for (int i = 1; i <= n; ++ i) {
			scanf ("%lld", &a[j][i]);
		}
	}
	int S = (1 << k) - 1;
	for (int i = 0; i <= S; ++ i) {
		mm = m;
		int s = n;
		ll sum = 0;
		for (int j = 1; j <= k; ++ j) {
			if (i & (1 << (j - 1))) {
				++ s;
				sum += c[j];
				for (int l = 1; l <= n; ++ l) {
					if (flag) if (a[j][l] == 0) e[++ mm] = (edge){s, l, a[j][l]};
				}
			}
		}
		for (int j = 1; j <= n; ++ j) fa[j] = j;
		ans = min (ans, kruskal (s) + sum);
	}
	printf ("%lld\n", ans);
	return 0;
}
/*
思路：

k<=10 状态压缩是可行的

对于每一个状态 S，如果 S_i==1，就对第 i 个乡镇进行改造

然后跑一边 kruskal 找到最小的花费

每一个状态答案取 min 

可恶竟然 TLE

我还不想保龄啊 

TLE 原因是边数过多，需要优化

我只知道线段树优化建图，但我不会写哈哈

其实真不用优化建图，堆优化 prim 就可以，但还是有点悬 

但我忘了怎么写了哈哈 

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/