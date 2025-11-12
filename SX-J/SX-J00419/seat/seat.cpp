#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);


	int n, m, a[1000], ver = 0, sum = 0, num = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		ver += a[i];
	}
	sort(a, a + n + 1);
	reverse(a, a + n + 1);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == ver) {
			sum = i;

		}
	}
	for (int i = 1;  i <= n * m; i++) {
		if (a[i] == ver) {
			num = i;

		}
	}
	cout << sum + 1 << " " << num + 2;

	return 0;
}
