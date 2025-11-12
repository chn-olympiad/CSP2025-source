#include <bits/stdc++.h>
using namespace std;

int n, m, s, cnt, sum;
int a[505];

int main() {

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		cin >> a[i];
		if (s == 1) {
			if (sum <= a[i]) {
				sum++;
			}
		}
	}

	cout << sum;

	return 0;
}