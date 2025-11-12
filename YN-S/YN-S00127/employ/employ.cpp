#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, p[1000001], s[100001], sum = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> p[i];
	}

	for (int i = 1; i <= n; i++) {

		cin >> s[i];
	}

	int z = 0;

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= n; j++) {

			if (z < m && s[j] > 3) {
				for (int l = 3; l <= n; l++) {

					sum++;
				}
			} else {
				for (int r = 1; r < 3; r++) {

					sum++;
				}
			}
		}

	}

	cout << sum;
}
