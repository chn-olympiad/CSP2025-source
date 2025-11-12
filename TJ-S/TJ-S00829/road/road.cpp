#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 11000;
struct node {
	int u, v;
	ll w;
} e[1050001];
int n, m, k;
ll c, fa[N], ans = 0;

bool cmp(node a, node b) {
	return a.w < b.w;
}

int find1(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find1(fa[x]);
}
void merge(int x, int y) {
	x = find1(x), y = find1(y);
	if(x == y) return;
	fa[x] = y;
}

void kruskal() {
	for(int i=1; i<=n+k; i++) fa[i] = i;
	sort(e+1, e+m+1, cmp);
	for(int i=1; i<=m; i++) {
		if(find1(e[i].u) != find1(e[i].v)) {
			//cout << e[i].u <<  " " << e[i].v << "\n";
			ans += e[i].w;
			merge(e[i].u, e[i].v);
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for(int i=1; i<=m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		//cout << e[i].u << " " << e[i].v << "\n";
	}
	int cnt = n;
	for(int i=1; i<=k; i++) {
		cin >> c; ++cnt;
		for(int j=1; j<=n; j++) {
			++m;
			e[m].u = cnt, e[m].v = j;
			cin >> e[m].w;
		}
	}
	kruskal();
	cout << ans;
	//cout << " " << log2(1050000);

	return 0;
}


