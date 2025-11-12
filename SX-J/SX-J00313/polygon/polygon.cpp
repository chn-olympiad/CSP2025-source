#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	if (n == 3) {
		int s = 0, ma = 0;
		for (int i = 10; i > 0; i--) {
			if (a[i] > 0) {
				ma = max(ma, i);
				s += i * a[i];
			}
		}
		if (s > (ma * 2)) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	return 0;
}
