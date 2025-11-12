#include <bits/stdc++.h>
using namespace std;

struct road {
	int a, b, c;
} p[100010];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	int n, m, k, o = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> p[i].a >> p[i].b >> p[i].c;
		o += p[i].c;
	}
	cout << o;
	return 0;
}
