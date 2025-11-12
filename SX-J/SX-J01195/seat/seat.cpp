#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n, m, a[110], sum, b, c;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	fast;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	sum = a[1];
	for (int i = 1; i <= n * m; i++) {
		for (int j = i + 1; j <= n * m; j++) {
			if (a[i] < a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
	for (int i = 1; i <= n * m; i++) {
		if (sum == a[i]) {
			sum = i;
			break;
		}
	}
	b = (sum - 1) / n + 1;
	if (b % 2 != 0) {
		c = sum - (b - 1) * n;
	} else if (b % 2 == 0) {
		c = b * n - sum + 1;
	}
	cout << b << " " << c;
	return 0;
}