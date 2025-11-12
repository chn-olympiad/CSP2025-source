#include <bits/stdc++.h>
using namespace std;
int t, n, num[100005][5];
long long  tot[505][505][505], ans = 0;

int main() {
	freopen("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> t;
	for (int o = 1; o <= t ; ++o) {
		ans = 0;
		memset( tot, 0, sizeof tot);
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> num[i][1] >> num[i][2] >> num[i][3];
		}

		for (int a = 0; a <= n / 2; ++a) {
//
			//a俱乐部选了的人数a
			for (int b = 0; b <= n / 2; ++b) {
				for (int c = 0; c <= n / 2; ++c) {
					int i = a + b + c;


					//  choose a or b or c
					if (a - 1 != -1)
						tot[a][b][c] = max(tot[a][b][c], tot[a - 1][b][c] + num[i][1]);

					if (b - 1 != -1)
						tot[a][b][c] = max(tot[a][b][c], tot[a][b - 1][c] + num[i][2]);

					if (c - 1 != -1)
						tot[a][b][c] = max(tot[a][b][c], tot[a][b][c - 1] + num[i][3]);
					if (i == n) {
//						printf("%d a\n", tot[a][b][c]);
						ans = max(ans, tot[a][b][c]);
						break;
					}
				}
			}

		}
		printf("%lld\n", ans);
	}
	return 0;
}