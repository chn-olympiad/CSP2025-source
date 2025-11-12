#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int N =1e4 + 2, M = 1e7 + 2;
int n,m,k, kr[11][N], pa[N];
struct Node {
	int u,v,w;
}a[M];
bool cmp(const Node &x, const Node &y) {
	return x.w < y.w;
}
int find(int x) {
	return pa[x] == x ? x : pa[x] = find(pa[x]);
}
void marge(int x, int y) {
	if(find(x) != find(y)) pa[pa[x]] = pa[y];
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i) pa[i] =i;
	for(int i = 1; i <= m; ++i) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i = 1,f; i <= k; ++i) {
		cin >> f;
		for(int j = 1; j <= n; ++j) {
			cin >> kr[i][j];
		}
		for(int s=1; s < n; ++s) {
			for(int t = s + 1; t <= n; ++ t) {
				a[++m].u = s;
				a[m].v = t;
				a[m].w = kr[i][s] + kr[i][t];
			}
		}
	}
	stable_sort(a +1, a + 1 + m,cmp);
	int cnt = 0;
	long long ans = 0;
	for(int i = 1; cnt < n; ++i) {
		long long u = a[i].u, v = a[i].v, w = a[i].w;
		if(find(u) == find(v)) continue;
		ans += w;
		marge(u, v);
		++cnt;
	}
	cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
