#include <bits/stdc++.h>
using namespace std;
int a[1000000][3];

int maxn = 0;
int club1 = 0, club2 = 0, club3 = 0, k, cnt = 0, m = 0;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int q = 1; q <= t; q++) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];


			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				if (a[i][j] > maxn) {
					maxn = a[i][j];
					k = j;
				}
			}
			if (k == 1) {
				club1++;
			} else if (k == 2) {
				club2++;
			} else if (k == 3) {
				club3++;
			}
			cnt += maxn;
		}

		cout << cnt << endl;

	}



	fclose(stdin);
	fclose(stdout);
	return 0;
}
