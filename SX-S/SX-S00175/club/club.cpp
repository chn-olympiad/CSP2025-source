#include <bits/stdc++.h>
using namespace std;
int a[10005][5];
int b[10005][5];
int c[10005];
int a1[10005];
int a2[10005];
int a3[10005];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 2) {
			int maxn = 0;
			cin >> a[1][1] >> a[1][2] >> a[1][3] >> a[2][1] >> a[2][2] >> a[2][3];
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (i != j) {
						maxn = max(maxn, a[1][i] + a[2][j]);
					}
				}
			}
			cout << maxn << endl;
		}

	}
	return 0;
}
