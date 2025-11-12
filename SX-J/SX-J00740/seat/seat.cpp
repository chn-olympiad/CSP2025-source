#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n, a[200], v;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
		if (a[i] < a[i + 1]) {
			v = a[i];
			a[i] = a[i + 1];
			a[i + 1] = v;
			cout << a[i];
		}
	}
	return 0;
}