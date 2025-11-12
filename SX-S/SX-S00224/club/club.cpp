#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
int b[N];
int c[N];

int cmp(int q, int p) {
	return q < p;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	long long s, n, t;
	cin >> t;
	for (int j = 1; j <= t; j++) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		if (b[1] == 0 || c[1] == 0) {
			sort(a + 1, a + n + 1);
			for (int i = n; i > n / 2; i--) {
				s = s + a[i];
			}
		} else {
			if (c[1] == 0) {
				sort(a + 1, a + n + 1);
				sort(b + 1, b + n + 1);
				for (int i = n; i > n / 2; i--) {
					s = s + a[i];
				}
				for (int i = n; i > n / 2; i--) {
					s = s + b[i];
				}
			}
		}
		cout << s << endl;
		s = 0;
	}
	return 0;
}
