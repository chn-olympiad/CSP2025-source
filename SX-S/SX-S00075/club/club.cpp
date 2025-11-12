#include <bits/stdc++.h>
using namespace std;
int a1[100005], a2[100005], a3[100005], daan[10];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, xz, ans = 0, max = 0;
	xz = n / 2;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a1[j] >> a2[j] >> a3[j];
		}
		max = 0;
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				if (b == a) {
					b++;
				}
				for (int c = 1; c <= n; c++) {
					if (c == b || c == a) {
						c++;
					}
					ans = a1[a] + a2[b] + a3[c];
					if (ans > max) {
						max = ans;
					}
				}
			}
		}
		daan[i] = max;
	}
	for (int i = 1; i <= t; i++) {
		cout << daan[i] << endl;
	}

	return 0;
}