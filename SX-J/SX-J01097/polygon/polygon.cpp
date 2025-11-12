#include <bits/stdc++.h>
using namespace std;

int main() {
	froepen("polygon.in", "r", stdin);
	froepen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int a[n + 5];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 1 || n == 2) {
		cout << 0;
	} else {
		cout << 1;
	}
	return 0;
}