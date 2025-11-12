#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
	int u, v, w;
} edges[2000005], edg[100005];

struct node2 {
	int u, v, w;
	bool tg;
};

bool cmp(node a, node b) {
	return a.w <= b.w;
}

ll n, m, k, tot, ans;
int fa[100005], a[15][100005], c[15];
int tg[15][100005];

int oldest(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = oldest(fa[x]);
}

bool check(int x, int y) {
	return oldest(x) == oldest(y);
}

void merge(int x, int y) {
	fa[oldest(x)] = oldest(y);
}

void kskr() {
	for (int i = 1; i <= m; i++) {
		int nu = edges[i].u, nv = edges[i].v, nw = edges[i].w;
		if (check(nu, nv))
			continue;
		merge(nu, nv);
		edg[++tot] = {nu, nv, nw};
		ans += nw;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}
	sort(edges + 1, edges + m + 1, cmp);
	kskr();
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	ll minres = 0;
	for (int i = 1; i < 1 << k; i++) {
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= n; j++)
				tg[i][j] = 1;
		ll res = 0;
		for (int j = 0; j < k; j++)
			if (i & (1 << j))
				res += c[j + 1];
		for (int l = tot; l >= 1 ; l--) {
			int minn = 1145141919;
			int nu = edg[l].u, nv = edg[l].v, nw = edg[l].w;
			int id;
			for (int j = 0; j < k; j++) {
				if (i & (1 << j))
					if (minn > tg[j + 1][nu]*a[j + 1][nu] + tg[j + 1][nv]*a[j + 1][nv]) {
						minn = tg[j + 1][nu] * a[j + 1][nu] + tg[j + 1][nv] * a[j + 1][nv];
						id = j + 1;
					}
			}
			if (minn <= nw) {
				res -= nw - minn;
				tg[id][nu] = tg[id][nv] = 0;
			}
		}
		minres = min(minres, res);
	}
	cout << ans + minres;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

评价：T2<<T1<T3<<<<<<<<<<T4
（虽然T3，T4没看）
哎，
感觉这次有2022的难度了
这次比24和23的都难很多
我回去之后有50%的概率写游记，我可以投稿吗（
想看别的？看看别的
*/