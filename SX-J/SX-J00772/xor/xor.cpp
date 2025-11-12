#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n, k, a[N], ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (k == 0) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0)
				ans++;
			if (a[i] == a[i + 1])
				ans++, i++;
		}
	} else if (k == 1) {
		for (int i = 1; i <= n; i++) {
			if (a[i] % 2 == 1 && a[i + 1] == a[i] - 1 && i + 1 <= n)
				ans++;
			if (a[i] == 1)
				ans++;
		}
	}
	cout << ans;
	return 0;
}
