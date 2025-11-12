#include <bits/stdc++.h>
using namespace std;
int t;
int n, maxn;
int a[10010][5];
bool b[10010];
int c[10010], d[5];

void dfs(int pos) {
	if (pos == n + 1) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += c[i];
		}
		maxn = max(maxn, sum);
		pos--;
	} else {
		for (int i = 1; i <= n; i++) {
			if (!b[i]) {
				b[i] = true;
				for (int j = 1; j <= 3; j++) {
					if (d[j] < n / 2) {
						c[i] = a[i][j];
						d[j]++;
						pos++;
						dfs(pos);
						pos--;
//						b[i] = false;
					}
					memset(d, 0, sizeof(d));
				}
//				b[i] = false;

			}
			memset(b, false, sizeof(b));

		}

	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int k = 1; k <= t; k++) {
		maxn = 0;
		memset(b, false, sizeof(b));
		memset(d, 0, sizeof(d));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		dfs(1);
		cout << maxn << endl;
	}
	return 0;
}