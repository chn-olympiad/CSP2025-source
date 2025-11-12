#include <bits/stdc++.h>
using namespace std;
int t, n;
const int N = 1e5 + 5;
int m[N];

struct ren {
	int b1, b2, b3;
} a[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		int a12 = 0, a22 = 0, a32 = 0, sum = 0;
		for (int j = 1; j <= n; j++) {
			cin >> a[j].b1 >> a[j].b2 >> a[j].b3;
			int a1 = a[j].b1, a2 = a[j].b2, a3 = a[j].b3;
			m[j] = max(a1, max(a2, a3));
			if (m[j] == a1) {
				a12++;
				if (a12 > n / 2) {
					m[j] = max(a2, a3);
				}
			}
			if (m[j] == a2) {
				a22++;
				if (a22 > n / 2) {
					m[j] = max(a1, a3);
				}
			}
			if (m[j] == a3) {
				a32++;
				if (a32 > n / 2) {
					m[j] = max(a2, a1);
				}
			}
		}
		for (int i2 = 1; i2 <= n; i2++) {
			sum += m[i2];
		}
		cout << sum << endl;
	}
	return 0;
}