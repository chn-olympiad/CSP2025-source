#include <bits/stdc++.h>
using namespace std;
int n, w[100001][4], ans = 0, mxas = 0, ls[4];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++)
				scanf("%d", &w[i][j]);
		}
		for (int i = 1; i <= n; i++) {
			ans += w[i][1];
		}
		cout << ans << endl;
	}
	return 0;
}
