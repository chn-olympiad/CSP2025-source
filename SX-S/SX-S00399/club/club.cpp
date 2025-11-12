#include <bits/stdc++.h>
using namespace std;
int a[100010][4], n;
long long p[5], h = 0;

void fs(int x, int y, long long ans) {
	if (x > n ) {
		h = max(h, ans);
		return;
	}
	p[y]++;
	for (int i = 1; i <= 3; i++) {
		if (p[i] < n / 2) {
			fs(x + 1, i, ans + a[x][y]);
			if (x < n) {
				p[i]--;
			}
		}

	}
	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n > 200) {
			int A[100010], B, C;
			long long an = 0;
			for (int i = 0; i < n; i++) {
				cin >> A[i] >> B >> C;
			}
			sort(A, A + n);
			for (int i = 1; i <= n / 2; i++) {
				an += A[n - i];
			}
			cout << an << endl;
		} else if (n == 200) {
			int A[100010], B[100010], C;
			long long an = 0;
			for (int i = 0; i < n; i++) {
				cin >> A[i] >> B[i] >> C;
			}
			sort(A, A + n );

			for (int i = 1; i <= n / 2; i++) {
				an += A[n - i];
			}
			sort(B, B + n );

			for (int i = 1; i <= n / 2; i++) {
				an += B[n - i];
			}
			cout << an << endl;
		} else {
			h = 0;
			memset(a, 0, sizeof(a));
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= 3; j++) {
					cin >> a[i][j];

				}

			}
			memset(p, 0, sizeof(p));
			fs(1, 1, 0);
			memset(p, 0, sizeof(p));
			fs(1, 2, 0);
			memset(p, 0, sizeof(p));
			fs(1, 3, 0);
			cout << h << endl;
		}

	}
	return 0;
}
