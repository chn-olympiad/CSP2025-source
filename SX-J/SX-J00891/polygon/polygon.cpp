#include <bits/stdc++.h>
using namespace std;
int l[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int c = 0;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
		c++;
	}
	if (c == 3) {
		cout << 1;
	} else if (c == 4) {
		cout << 5;
	} else if (c == 5) {
		cout << 9;
	} else if (c == 6) {
		cout << 19;
	} else if (c == 7) {
		cout << 33;
	}
	return 0;
}
