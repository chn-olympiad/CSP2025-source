#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;
const int NN = 1e5 + 5;
int n, m, k, u, v, w, cnt, cmt, f[NN], c[15], d[NN];
ll ans;
struct node{
	int u, v, w;
}a[N + NN];
int find(int x) {
	if (f[x] == x)	return x;
	f[x] = find(f[x]);
	return f[x];
}
void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	f[fx] = fy;
	return ;
}
bool cmp(node a, node b) {
	return a.w < b.w;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	while (m--) {
		cin >> u >> v >> w;
		a[++cmt].u = u;
		a[cmt].v = v;
		a[cmt].w = w;
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) {
			cin >> d[j];
			for (int k = 1; k < j; ++k) {
				a[++cmt].u = k;
				a[cmt].v = j;
				a[cmt].w = d[k] + d[j] + c[i];
			}
		}
	}
	sort(a + 1, a + cmt + 1, cmp);
	for (int i = 1; i <= n; ++i) {
		f[i] = i;
	}
	for (int p = 1; p <= cmt; ++p) {
		node i = a[p];
		if (find(i.u) != find(i.v)) {
			merge(i.u, i.v);
			ans += i.w;
			++cnt;
		}
		if (cnt == n - 1) {
			break;
		}
	}
	cout << ans;
	return 0;
}