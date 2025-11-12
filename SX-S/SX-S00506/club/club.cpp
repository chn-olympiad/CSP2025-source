#include <bits/stdc++.h>
using namespace std;

int s[10000][10000] = {0, 0};
int A(int x) {
	int w[10000] = {0};
	int c = 0, e = 0, h;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> s[i][j];
		}
	}
	int g = 0;
	while (g < x) {
		if (g + 1 == x) {
			e = 0;
			for (int j = 1; j <= 3; j++) {
				for (int i = 1; i <= x; i++) {
					if (s[i][j] > e) {
						e = s[i][j];
					}
				}
			}
			g++;
			c += e;
		} else {
			for (int j = 1; j <= 3; j++) {
				e = 0;
				for (int i = 1; i <= x; i++) {
					if (s[i][j] > e) {
						e = s[i][j];
						h = i;
					}
				}
				w[j]++;
				if (w[j] <= x / 2 && g < x) {
					g++;
					c += e;
					s[h][1] = s[h][2] = s[h][3] = 0;
				}
			}
		}
	}
	return c;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << A(n);
	}
	return 0;
}