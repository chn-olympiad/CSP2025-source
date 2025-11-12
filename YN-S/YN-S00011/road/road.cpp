#include <bits/stdc++.h>
using namespace std;

struct road {
	int u;
	int v;
	int w;
} roads [1000000];
int a[10][1001];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	int min = 0;
	int b = 1000000000;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> roads[i].u >> roads[i].v >> roads[i].w;
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n + 1; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int x = 0; x < k; x++) {
			if (b > roads[i].w && b > a[x][roads[i].u] + a[x][roads[i].v] + a[x][0]) {
				if (roads[i].w > a[x][roads[i].u] + a[x][roads[i].v] + a[x][0]) {
					n = a[x][roads[i].u] + a[x][roads[i].v] + a[x][0];
				}
				if (a[x][roads[i].u] + a[x][roads[i].v] + a[x][0] > roads[i].w) {
					n = roads[i].w;
				}
				min = min + n;
			}
		}
		b = 1000000000;
	}
	cout << min;
	return 0;
}