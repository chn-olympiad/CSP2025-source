#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+5;
int n, h;
int a[N], qz[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	if (n == 3) {
		if (a[1] + a[2] > a[3]) {
			cout << 1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	}
	for (int i = 1; i <= n - 2; i++) {
		h += i;
	}
	cout << h;
	return 0;
}
