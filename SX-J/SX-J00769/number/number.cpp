#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n = 1;
	char a[1000001] = {0};
	for (int i = 1; i <= 1000001; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= 1000001; i++) {
		if (a[i] != 0)
			n++;
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) {
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0) {
			cout << a[i];
		} else {
			continue;
		}
	}
	cout << endl;
	return 0;
}
