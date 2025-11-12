#include <bits/stdc++.h>
using namespace std;
int a1[100000], a2[100000], a3[100000];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t, n, sum = 0;
	cin >> t;

	for (int i = 1; i <= t; i++) {

		cin >> n;

		for (int j = 1; j <= n; j++) {

			cin >> a1[j] >> a2[j] >> a3[j];
		}

		sort(a1 + 1, a1 + 1 + n);

		for (int i = n; i >= n / 2; i--) {

			sum += a1[i];
		}
	}

	cout << sum;
	return 0;
}