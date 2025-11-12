#include <bits/stdc++.h>
using namespace std;
int n, m, k, c[15], d[10005], num;
bool flag, flag1, x, y;

struct node {
	int u, v, w;
} a[1000005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i] == 0)
			flag = 1;
		else
			x = 1;
		for (int j = 1; j <= n; j++) {
			cin >> d[j];
			if (d[j] == 0)
				flag1 = 1;
			else
				y = 1;
		}
	}
	for (int i = 1; i <= m; i++) {
		num += a[i].w;
	}
	cout << num;
	return 0;
}