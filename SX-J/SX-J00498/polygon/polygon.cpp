#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("xor.in", "r", stdin);
	///freopen(".out", "w", stdout);
	int n, a[100], q = 0, w = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		w += a[i];
	}
	sort(a, a + n);
	for (int i = n; i > 0; i--) {
		if (w > a[i] * 2) {
			q++;

		}

	}
	cout << q;
}