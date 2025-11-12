#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int as = 0, k;
	cin >> k;
	for (int i = 2; i <= n * m; i++) {
		int ls;
		cin >> ls;
		if (ls > k)
			as++;
	}
	int l = as / n, h = as % n;
	if (l % 2 == 0) {
		cout << l + 1 << ' ' << h + 1;
	} else {
		cout << l + 1 << ' ' << n - h;
	}
}
