#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 10020;
const int M = 1e6+10 + N * 10;
int n, m, k, u, v, w, fa[N], py[12][N];
ll lst;
bool flag[12], tag[12];
struct info {
	int u, v, w, id;
	bool operator < (const info &A) const {
		return w < A.w;
	}
} edges[M];

int find(int p) {
	if(p == fa[p]) return p;
	return fa[p] = find(fa[p]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	int tm = m, tn = n + k;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		edges[i] = {u, v, w, 0};
	}
	for(int i = 1; i <= k; i++) {
		for(int j = 0; j <= n; j++)
			scanf("%d", &py[i][j]);
	}
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	sort(edges + 1, edges + m + 1);
	for(int i = 1; i <= m; i++) {
		u = edges[i].u, v = edges[i].v;
		u = find(u), v = find(v);
		if(u != v) {
			fa[u] = v;
			lst += edges[i].w;
		}
	}
	if(k == 0) {
		printf("%lld\n", lst);
		return 0;
	}
//	cout << lst << "\n";
	for(int i = 1; i <= k; i++) {
		memset(flag, 0, sizeof(flag));
		ll now = 0;
		for(int j = 1; j <= n; j++)
			edges[++tm] = {n + i, j, py[i][j], i};
		sort(edges + 1, edges + tm + 1);
		for(int j = 1; j <= tn; j++)
			fa[j] = j;
		for(int j = 1; j <= tm; j++) {
			u = edges[j].u, v = edges[j].v;
			if(u > n) {
				if(tag[u - n]) continue;
			}
			int id = edges[j].id;
			if(tag[id]) continue;
			u = find(u), v = find(v);
			if(u != v) {
//				cout << edges[j].u << " " << edges[j].v << "\n";
				fa[u] = v;
				now += edges[j].w;
				if((!flag[id]) && id) {
					flag[id] = 1;
					now += py[id][0];
				}
			}
		}
		if(now > lst) tag[i] = 1;
		else lst = now;
//		cout << now << "\n";
	}
	for(int i = 1; i <= k; i++) {
		if(tag[i]) continue;
		tag[i] = 1;
		memset(flag, 0, sizeof(flag));
		ll now = 0;
		for(int j = 1; j <= tn; j++)
			fa[j] = j;
		for(int j = 1; j <= tm; j++) {
			u = edges[j].u, v = edges[j].v;
			if(u > n) {
				if(tag[u - n]) continue;
			}
			int id = edges[j].id;
			if(tag[id]) continue;
			u = find(u), v = find(v);
			if(u != v) {
				fa[u] = v;
				now += edges[j].w;
				if((!flag[id]) && id) {
					flag[id] = 1;
					now += py[id][0];
				}
			}
		}
		if(now < lst) lst = now;
		else tag[i] = 0;
	}
	printf("%lld\n", lst);
	return 0;
}
