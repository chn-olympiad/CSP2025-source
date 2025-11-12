#include <bits/stdc++.h>
using namespace std;
long long a, n, o = 0;
int v[5010];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	if (n <= 3) {
		if (n < 3) {
			cout << 0;
			return 0;
		}
		if (v[1] + v[2] + v[3] > 2 * max(v[1], max(v[2], v[3])))
			cout << 1;
		else
			cout << 0;
	} else {
		n = n - 2;
		for (int i = 1; i <= n; i++) {
			o = o + i;
		}
		cout << o;
	}
	return 0;
}
