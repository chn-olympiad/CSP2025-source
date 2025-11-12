#include <bits/stdc++.h>
using namespace std;
int n, l;
int ans;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n >> l;
	cin >> ans;
	for (int i = 3; i <= n; i++) {
		if (ans % 2 == 0) {
			cout << ans << ans*ans / 2 + ans*n * 2 + n * n * 2 << n + ans;
		}
		if (ans % 2 == 1) {
			cout << ans << n*ans - n + ans*ans / 2 - ans / 2 << n + ans;
		}
		if (ans == 0)
			continue;
	}
	return 0;
}
