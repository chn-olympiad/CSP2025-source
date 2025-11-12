#include <bits/stdc++.h>
using namespace std;

int n, cnt, s;
int a[5005];

int main() {

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j <= n; j++) {
			s = a[i] + a[i + 1] + a[i + 2];
			if (2 * a[i].max <= s) {
				cnt++;
			}

		}
	}

	cout << cnt;

	return 0;
}