#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, x1 = 0, x2 = 0;
	cin >> n >> m;
	string a;
	int b[n];
	cin >> a;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == '1' && x2 < b[i]) {
			x1++;
			x2 = 0;
		} else {
			x2++;
		}
	}
	cout << x1;
	return 0;
}