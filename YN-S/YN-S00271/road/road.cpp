#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y, z;
} p[100010];
int a[100010];

bool cmp(node a, node b) {
	return a.z < b.z;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> p[i].x >> p[i].y >> p[i].z;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i];
		}
	}
	sort(p + 1, p + m + 1, cmp);
	int sum = 0;
	for (int i = 1; i <= m - 1; i++) {
		sum += p[i].z;
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}