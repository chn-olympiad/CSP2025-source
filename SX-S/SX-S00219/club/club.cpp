#include <bits/stdc++.h>
using namespace std;
long long n, m, a[121225][5], T, maxx2[121225], maxx[121225], ans, num, bumen[5], man[121225];
bool paixu, maxle, manbu[5];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		for (long long i = 1; i <= n; i++) {
			for (long long j = 1; j <= 3; j++)
				cin >> a[i][j];
			if (a[i][1] >= max(a[i][2], a[i][3]))
				maxx[i] = 1;
			else if (a[i][2] >= a[i][3])
				maxx[i] = 2;
			else
				maxx[i] = 3;
			if (a[i][1] > max(a[i][2], a[i][3])) {
				if (a[i][2] > a[i][3])
					maxx2[i] = 2;
				else
					maxx2[i] = 3;
			} else if (a[i][2] > max(a[i][1], a[i][3])) {
				if (a[i][3] > a[i][1])
					maxx2[i] = 3;
				else
					maxx2[i] = 1;
			} else if (a[i][3] > max(a[i][2], a[i][1])) {
				if (a[i][2] > a[i][1])
					maxx2[i] = 2;
				else
					maxx2[i] = 1;
			}

		}
		paixu = 0;
		while (!paixu) {
			for (long long i = 1; i <= n; i++) {
				if (a[i][maxx[i]] < a[i + 1][maxx[i + 1]]) {
					swap(a[i][1], a[i + 1][1]);
					swap(a[i][2], a[i + 1][2]);
					swap(a[i][3], a[i + 1][3]);
					swap(maxx[i], maxx[i + 1]);
				} else if (a[i][maxx[i]] == a[i + 1][maxx[i + 1]]
				           and a[i][1] + a[i][2] + a[i][3] < a[i + 1][1] + a[i + 1][2] + a[i + 1][3]) {
					swap(a[i][1], a[i + 1][1]);
					swap(a[i][2], a[i + 1][2]);
					swap(a[i][3], a[i + 1][3]);
					swap(maxx[i], maxx[i + 1]);
				}
			}
			paixu = 1;
			for (long long i = 1; i <= n; i++) {
				if (a[i][maxx[i]] < a[i + 1][maxx[i + 1]]) {
					swap(a[i][1], a[i + 1][1]);
					swap(a[i][2], a[i + 1][2]);
					swap(a[i][3], a[i + 1][3]);
					swap(maxx[i], maxx[i + 1]);
					paixu = 0;
				}
				if (a[i][maxx[i]] == a[i + 1][maxx[i + 1]]  and a[i][1] + a[i][2] + a[i][3] < a[i + 1][1] + a[i + 1][2] + a[i + 1][3]) {
					swap(a[i][1], a[i + 1][1]);
					swap(a[i][2], a[i + 1][2]);
					swap(a[i][3], a[i + 1][3]);
					swap(maxx[i], maxx[i + 1]);
					paixu = 0;
				}
			}
		}
		ans = 0;
		bumen[1] = 0;
		bumen[2] = 0;
		bumen[3] = 0;
		for (long long i = 1; i <= n; i++) {
			if (bumen[maxx[i]] * 2 >= n) {
				man[i]++;
				maxle = 1;
				manbu[maxx[i]] = 1;
				continue;
			} else {
				bumen[maxx[i]]++;
				ans += a[i][maxx[i]];
				a[i][maxx[i]] = 0;
				maxx[i] = 0;
			}
		}
		if (maxle) {
			for (long long i = 1; i <= n; i++) {
				if (man[i] == 1) {
					ans += a[i][maxx2[i]];
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}