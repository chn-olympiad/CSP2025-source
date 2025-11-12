#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int s, a[20];
	cin >> s;
	for (int i = 0; i <= s; i++) {
		cin >> a[i];
		if (a[i] <= 9) {
			cout << a[i];
		}
	}
	return 0;
}
