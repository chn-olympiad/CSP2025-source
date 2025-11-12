#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5, M = 1e4+5;

struct node {
	int x, y, z;
} a[N];
int n, m, k, f[M], dis[15], ans = 0;

bool cmp(node x, node y) {
	return x.z < y.z;
}

int find(int x) {
	if (f[x] == x)
		return x;
	else
		return f[x] = find(f[x]);
}

void merge(int x, int y) {
	f[find(x)] = find(y);
}

void Kruskal() {
	int e = 0;
	int k1, k2;
	for (int i = 1; i <= m + n * k; i++) {
		k1 = find(a[i].x);
		k2 = find(a[i].y);
		if (k1 == k2)
			continue;
		e++;
		merge(k1, k2);
		ans += a[i].z;
		if (e == n - 1)
			break;
	}
	cout << ans;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	int j = m + 1;
	for (int i = m + 1; i <= m + k; i++) {
		cin >> dis[i];
		for (; j <= m + n * (i - m); j++) {
			cin >> a[j].z;
			a[j].x = i;
			a[j].y = j - i * m;
		}
	}
	for (int i = 1; i <= n + k; i++)
		f[i] = i;
	sort(a + 1, a + 1 + m + n *k, cmp);
	Kruskal();
	return 0;
}
