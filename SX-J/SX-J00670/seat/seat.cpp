#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a = 0, k;
	cin >> k;
	for (int i = 2; i <= n * m; i++) {
		int ls;
		cin >> ls;
		if (ls > k) {
			a++;
		}
	}
	int l = a / n, h = a % n;
	if (l % 2 == 0) {
		cout << l + 1 << ' ' << h + 1;
	} else {
		cout << l + 1 << ' ' << n - h;
	}
}