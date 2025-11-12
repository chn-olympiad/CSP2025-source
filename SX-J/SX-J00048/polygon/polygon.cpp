#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, s[5005];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	if (n == 3) {
		if (s[0] + s[1] > s[2] && s[0] + s[2] > s[1] && s[1] + s[2] > s[0]) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	return 0;
}
