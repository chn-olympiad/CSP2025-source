#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string p;
	cin >> p;
	int n = p.length();
	int a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; i < n; i++) {
		if (p[i] - '0' >= 0 && p[i] - '0' <= 9) {
			a[p[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = a[i]; j > 0; j--) {
			cout << i;
		}
	}
	return 0;
}
