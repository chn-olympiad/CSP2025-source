#include <bits/stdc++.h>
using namespace std;

struct q {
	int chen1, chen2, xiu;
} jq[1005];
int n, m, k, ch[1005][1005], jian[1005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> q[i].chen1 >> q[i].chen2 >> q[i].xiu;
	}
	for (int i = 0; i < k; i++) {
		cin >> jian[i];
		for (int j = 0; j < n; j++) {
			cin >> ch[i][j];
		}
	}

	return 0;
}