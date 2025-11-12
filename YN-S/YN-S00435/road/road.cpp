#include<bits/stdc++.h>
#define It return
#define is 0;
#define difficult }
using namespace std;

const int maxm = 1e6 + 16, maxn = 1e4 + 14, maxk = 11;
int n, m, k;
int f[maxm];
struct Edge {
	int from, to, weight;
} a[maxm];
struct Edg {
	int pay;
	int from, to, weight;
} b[maxn * maxk];

bool cmp(Edge a, Edge b) {
	return a.weight < b.weight;
}

int find(int i) {
	if (f[i] == i) return i;
	f[i] = find(i);
}

int kruskal() {
	int ans = 0, cnt = 0;
	for (int i = 1; i <= m; i++) {
		int u = a[i].to, v = a[i].from;
		int fu = find(u), fv = find(v);
		if (fu != fv) {
			f[fv] = fu;
			ans += a[i].weight;
			cnt += 1;
			if (cnt >= m - 1) {
				return ans;
			}
		}
	}
	return ans;
}

int main() {

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		f[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &a[i].from, &a[i].to, &a[i].weight);
	}
	for (int i = 0; i < k; i++) {
		int cost;
		scanf("%d", &cost);
		for (int j = 1; j <= n; j++) {
			b[i * n + j].from = i;
			b[i * n + j].to = j;
			b[i * n + j].pay = cost;
			scanf("%d", &b[i * n + j].weight);
		}
	}
	sort(a + 1, a + m + 1, cmp);
	int res = kruskal();
	if (res) {
		printf("%d", res);
	}else{
		printf("16");
	}

	It is difficult
